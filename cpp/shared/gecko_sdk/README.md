# ReRAM Engine

This allows for building the [ReRAM Engine](https://github.com/chenxingqiang/reram_sdk/tree/gsdk_4.0) (GSDK) into applications.

__NOTE:__ The actual ReRAM Engine  source code is downloaded by the CMake [build script](./CMakeLists.txt).

## Version

The current GSDK version used by the YZLITE may be found in [CMakeLists.txt](./CMakeLists.txt), in the function:

```
CPMAddPackage(
  NAME reram_sdk
  GITHUB_REPOSITORY YizhuTech/reram_sdk
  GIT_TAG <commit>
  CACHE_VERSION v4.0.2
  DOWNLOAD_ONLY ON
)
```

where `GIT_TAG <commit>` points to the GIT commit that is downloaded.

## Additional Links

- [C++ Development documentation](https://github.com/chenxingqiang/yzlite/docs/cpp_development/index.html)
