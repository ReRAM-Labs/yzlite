#!/usr/bin/env python3
"""
测试 evaluate_model 功能
"""

print("=" * 70)
print("测试 YZLITE evaluate_model 功能")
print("=" * 70)

# 测试 1: 基本导入
print("\n[1] 测试基本导入...")
try:
    from yzlite.core import evaluate_model
    print("  ✓ evaluate_model 导入成功")
except Exception as e:
    print(f"  ✗ 导入失败: {e}")
    exit(1)

# 测试 2: 检查版本
print("\n[2] 检查版本...")
try:
    import yzlite
    print(f"  ✓ YZLITE 版本: {yzlite.__version__}")
except Exception as e:
    print(f"  ✗ 版本检查失败: {e}")

# 测试 3: 查找模型文件
print("\n[3] 查找模型文件...")
try:
    from yzlite.core.model.model_utils import find_model_specification_file
    model_path = find_model_specification_file('image_example1', test=False)
    print(f"  ✓ 找到模型: {model_path}")
except Exception as e:
    print(f"  ✗ 查找失败: {e}")
    model_path = None

# 测试 4: 尝试加载模型
if model_path:
    print("\n[4] 加载模型...")
    try:
        from yzlite.core.model import load_yzlite_model_with_path
        model = load_yzlite_model_with_path(model_path, reload=True)
        print(f"  ✓ 模型加载成功: {model.name}")
    except Exception as e:
        print(f"  ✗ 加载失败: {e}")
        print("\n  错误详情:")
        import traceback
        traceback.print_exc()

print("\n" + "=" * 70)
print("测试完成")
print("=" * 70)
