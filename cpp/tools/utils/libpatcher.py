import argparse
import hashlib
import importlib
import os
import pathlib
import sys


def main():
    parser = argparse.ArgumentParser(
        description='Patch files in library based on given configuration')
    parser.add_argument('-i', '--input_dir', required=True,
                        help='Comma separated list of input directories')
    parser.add_argument('-o', '--output', required=True,
                        help='Output file indicating that patching is complete (to be used by build system)')
    parser.add_argument('-p', '--patch_script', required=True,
                        help='Path to Python patching script')

    args = parser.parse_args()

    with open(args.patch_script, 'rb') as f:
        patch_script_hash = hashlib.md5(f.read()).hexdigest()

    if os.path.exists(args.output):
        output_hash = None
        with open(args.output, 'r') as f:
            for line in f:
                output_hash = line.strip()
                break
        if output_hash == patch_script_hash:
            return

    script_path = pathlib.Path(args.patch_script)

    sys.path.append(str(script_path.parent))
    module = importlib.import_module(script_path.stem)
    if not hasattr(module, 'should_patch_file'):
        raise Exception(
            f'Patching script: {script_path} must define the function: def should_patch_file(path: str) -> object:')
    if not hasattr(module, 'process_file_line'):
        raise Exception(
            f'Patching script: {script_path} must define the function: def process_file_line(lineno: int, line: str, arg: object) -> str:')

    patched_files = patch_files(args.input_dir.split(','), module)

    with open(args.output, 'w') as f:
        f.write(patch_script_hash + '\n')
        f.write(f'This file was generated by {script_path}\n')
        f.write(
            'This file indicates that the patching script has successfully completed.\n')
        f.write(
            'To cause the patch script to run again, delete this file or update the patching script.\n\n')
        f.write('Files patched:\n')
        f.write('\n'.join(patched_files))


# pylint: disable=too-many-locals
def patch_files(input_dirs, patch_module):
    patched_files = []
    for input_dir in input_dirs:
        for root, _, files in os.walk(input_dir):
            for fn in files:
                p = os.path.join(root, fn).replace('\\', '/')
                arg = patch_module.should_patch_file(p)
                if arg:
                    patched_data = ''
                    updated = False
                    stop_processing = False
                    with open(p, 'r') as f:
                        for lineno, line in enumerate(f):
                            if stop_processing:
                                if not updated:
                                    break
                                patched_data += line
                                continue

                            patched_line = patch_module.process_file_line(
                                lineno, line, arg)
                            if not patched_line:
                                stop_processing = True
                                patched_data += line
                                continue

                            patched_data += patched_line

                            if not updated and patched_line != line:
                                updated = True

                    if updated:
                        patched_files.append(p)
                        with open(p, 'w') as f:
                            f.write(patched_data)
    return patched_files


if __name__ == '__main__':
    try:
        main()
    except Exception as e:
        cmd = ' '.join(sys.argv)
        raise Exception(f'Patching failed:\n\n{cmd}\n\nerr: {e}') from e
