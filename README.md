# Fast math library

Library with support for summation and transcedental <!--TOADD types of functions-->functions, where some of them are accelerated (see table with supported functions below).

Library also wraps some Intel SIMD intrinsics into templated API.

## Supported functions

| Summation | Acceleration | Transcedental | Acceleration |
|-----------|--------------|---------------|--------------|
| Sum        | <span style="color: green;">SIMD Accelerated</span> | Sin | TODO |
| Prefix sum (Inclusive scan) | <span style="color: green;">SIMD Accelerated</span> | Cos | TODO |

## SIMD support

| Type of unit | Support |
|--------------|---------|
| SSE          | <span style="color: red;">Not yet</span> |
| AVX          | <span style="color: green;">Yes</span> |
| AVX-512      | <span style="color: red;">Not yet</span> |

## Wrapped Intel SIMD intrinsics

- some AVX float intrinsics <!--TOADD types of intrinsics-->

For more details see API.

## Project health

| Service | Status |
|---------|--------|
| [GitHub Actions](https://github.com/VMikulasek/fast_math_library/actions) | [![math_lib Actions](https://github.com/VMikulasek/fast_math_library/actions/workflows/math_lib_actions.yml/badge.svg?branch=main)](https://github.com/VMikulasek/fast_math_library/actions/workflows/math_lib_actions.yml) |

## Library usage

There are three ways to use this library:
- using CMake with FetchContent,
- using CMake as subdirectory,
- installation into system headers (not recommended)

### Using CMake with FetchContent

Add into CMakeLists.txt:

```cmake
include(FetchContent)
FetchContent_Declare(
    fast_math_library
    GIT_REPOSITORY https://github.com/VMikulasek/fast_math_library.git
    GIT_TAG 5da0d6c7f3c863e41bc697f3f3314d950e0e157e # put the highest version commit hash here
)
FetchContent_MakeAvailable(fast_math_library)
target_link_libraries(main PRIVATE math_lib)
```

### Using CMake as subirectory

Clone or download a copy of repository, place it on directory level of CMakeLists.txt, where the dependency should be registered and add following into the CMakeLists.txt:
```cmake
add_subdirectory(fast_math_library)
target_link_libraries(main PRIVATE math_lib)
```

### Installation into system headers

Clone or download copy of repository, run native CLI as superuser/administrator, navigate into fast_math_library root directory and run following commands:

```
mkdir build
cd build
cmake .. -DBUILD_TESTS=OFF -DBUILD_BENCHMARKS=OFF
cmake --build . --target install
```

This usage of library is not recommended due to definitions of macros, that are defined in build systems by CMake. These macros affect compilation based on whether machine contains specific SIMD units. In case of using this option, macros have to be defined explicitly.

## Tests and benchmarks

This library also provides tests and benchmarks implemented using [Google test](https://github.com/google/googletest) and [Google benchmark](https://github.com/google/benchmark).

By default both tests and benchmarks CMake options are turned:

- ON when CMake is run on fast_math_library as main project or
- OFF when CMake is run on fast_math_library as subdirectory

and can be influenced by setting CMake options BUILD_TESTS and BUILD_BENCHMARKS.

When these options are set to ON, build targets will be generated.

### Building and running tests

Ubuntu:
```
cd build/analysis/tests
make
ctest
```
Windows:
Open solution in Visual Studio, build `math_lib_tests` target and run produced binary.

### Building and running benchmarks

Ubuntu:
```
cd build/analysis/benchmarks
make
sudo cpupower frequency-set --governor performance > /dev/null 2>&1
./seq_math_lib_benchmarks
./avx_math_lib_benchmarks
...
sudo cpupower frequency-set --governor powersave > /dev/null 2>&1
```

Windows:
Open solution in Visual Studio, build targets `seq_math_lib_benchmarks`, `avx_math_lib_benchmarks`,... and run produced binaries.

### Comparing benchmarks

[Google benchmark](https://github.com/google/benchmark) also provides a tool for benchmarks comparison, that can be applied here. For more informations see [Google benchmark tooling documentation](https://github.com/google/benchmark/blob/main/docs/tools.md).

### Benchmarks example results

Note: BigArr is array with 15 000 000 elements.

Example machine specifications:
- CPU: 12th Gen Intel® Core™ i5-1240P × 16
- Memory: DDR4 SDRAM 16GB 3200 MT/s

SEQ variant benchmarks:

```
Run on (16 X 399.906 MHz CPU s)
CPU Caches:
  L1 Data 48 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 1280 KiB (x8)
  L3 Unified 12288 KiB (x1)
Load Average: 0.56, 0.53, 0.55
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Sum1Elem              4.65 ns         4.65 ns    111321905
BM_Sum8Elem              16.0 ns         16.0 ns     40761902
BM_Sum9Elem              17.0 ns         17.0 ns     39209635
BM_Sum16Elem             28.5 ns         28.5 ns     24300963
BM_Sum17Elem             29.9 ns         29.9 ns     23995941
BM_Sum24Elem             43.8 ns         43.8 ns     13501744
BM_Sum25Elem             48.7 ns         48.7 ns     11679415
BM_SumBigArr         41002047 ns     41001495 ns           17
BM_PrefixSum1Elem        8.06 ns         8.06 ns     76598028
BM_PrefixSum8Elem        43.5 ns         43.5 ns     13224711
BM_PrefixSum9Elem        47.7 ns         47.7 ns     11021302
BM_PrefixSum16Elem       85.0 ns         85.0 ns      7404701
BM_PrefixSum17Elem       86.1 ns         86.1 ns      7087142
BM_PrefixSum24Elem        122 ns          122 ns      5365408
BM_PrefixSum25Elem        128 ns          128 ns      4624743
BM_PrefixSumBigArr   89506467 ns     89506529 ns            6
```

AVX variant benchmarks:
```
Run on (16 X 429.564 MHz CPU s)
CPU Caches:
  L1 Data 48 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 1280 KiB (x8)
  L3 Unified 12288 KiB (x1)
Load Average: 0.62, 0.54, 0.55
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Sum1Elem              7.76 ns         7.76 ns     76160339
BM_Sum8Elem              19.9 ns         19.9 ns     34446003
BM_Sum9Elem              21.0 ns         21.0 ns     32964084
BM_Sum16Elem             28.3 ns         28.3 ns     24501203
BM_Sum17Elem             28.2 ns         28.2 ns     24287702
BM_Sum24Elem             33.7 ns         33.7 ns     20707784
BM_Sum25Elem             35.5 ns         35.5 ns     19984736
BM_SumBigArr         13922567 ns     13921868 ns           52
BM_PrefixSum1Elem        6.13 ns         6.13 ns     96893672
BM_PrefixSum8Elem        43.7 ns         43.7 ns     13020772
BM_PrefixSum9Elem        43.7 ns         43.7 ns     13103114
BM_PrefixSum16Elem       75.0 ns         75.0 ns      8351937
BM_PrefixSum17Elem       78.6 ns         78.6 ns      7995868
BM_PrefixSum24Elem        110 ns          110 ns      5511200
BM_PrefixSum25Elem        115 ns          115 ns      5560749
BM_PrefixSumBigArr   71857144 ns     71854350 ns            7
```

Comparison SEQ vs AVX:
```
Benchmark                            Time             CPU      Time Old      Time New       CPU Old       CPU New
-----------------------------------------------------------------------------------------------------------------
BM_Sum1Elem                       +0.6688         +0.6690             5             8             5             8
BM_Sum8Elem                       +0.2459         +0.2464            16            20            16            20
BM_Sum9Elem                       +0.2376         +0.2381            17            21            17            21
BM_Sum16Elem                      -0.0069         -0.0069            28            28            28            28
BM_Sum17Elem                      -0.0551         -0.0545            30            28            30            28
BM_Sum24Elem                      -0.2318         -0.2319            44            34            44            34
BM_Sum25Elem                      -0.2725         -0.2725            49            35            49            35
BM_SumBigArr                      -0.6604         -0.6605      41002047      13922567      41001495      13921868
BM_PrefixSum1Elem                 -0.2393         -0.2389             8             6             8             6
BM_PrefixSum8Elem                 +0.0039         +0.0042            44            44            44            44
BM_PrefixSum9Elem                 -0.0822         -0.0822            48            44            48            44
BM_PrefixSum16Elem                -0.1180         -0.1177            85            75            85            75
BM_PrefixSum17Elem                -0.0874         -0.0871            86            79            86            79
BM_PrefixSum24Elem                -0.0962         -0.0962           122           110           122           110
BM_PrefixSum25Elem                -0.1039         -0.1039           128           115           128           115
BM_PrefixSumBigArr                -0.1972         -0.1972      89506467      71857144      89506529      71854350
OVERALL_GEOMEAN                   -0.1055         -0.1053             0             0             0             0
```