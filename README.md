# Fast math library

Library with support for summation, transcedental and statistical functions, where some of them are accelerated (see table with supported functions below), wrapped SIMD instructions into templated interface and vector type with vectorized operations with SIMD instructions.

## Supported math functions

| Summation | Acceleration | Transcedental | Acceleration | Statistical | Acceleration |
|-----------|--------------|---------------|--------------|-------------|--------------|
| Sum        | SIMD Accelerated | Sin | Approximation + SIMD Accelerated | Min | SIMD Accelerated |
| Prefix sum (Inclusive scan) | SIMD Accelerated | Cos | Approximation + SIMD Accelerated | Max | SIMD Accelerated |
| | | Tan | None | Mode (int[]) | None |
| | | Cot | None | Median (int[]) | None |
| | | Sqrt | Approximation + SIMD Accelerated | Median (float[]) | None |
| | | InvSqrt | Approsimation + SIMD Accelerated | Arithmetic mean | SIMD Accelerated |
| | | | | Geometric mean | SIMD Accelerated |
| | | | | Weighted mean | SIMD Accelerated |
| | | | | Variance | SIMD Accelerated |
| | | | | Variance with specifiable probabilities | SIMD Accelerated |
| | | | | Sample variance | SIMD Accelerated |
| | | | | Standard deviation | SIMD Accelerated |
| | | | | Standard deviation with specifiable probabilities | SIMD Accelerated |
| | | | | Sample standard deviation | SIMD Accelerated |

## Supported vector data type operations

- Operator +
- Operator -
- Operator *
- Operator /
- Absolute value
- Minimum
- Maximum
- Square root (only floating point vector)
- Approximated square root (only floating point vector)
- Inverse square root (only floating point vector)
- Approximated inverse square root (only floating point vector)
- Sine (only floating point vector)
- Cosine (only floating point vector)
- Tangent (only floating point vector)
- Cotangent (only floating point vector)
- Approximated sine (only floating point vector)
- Approximated cosine (only floating point vector)
- Cross product (only for 3 dimensional vector)
- Dot product
- Length (only floating point vector)
- Normalize (only floating point vector)
- xy - Creates 2 dimensional vector (only for 3 and 4 dimensional vector)
- xyz - Creates 3 dimensional vector (only for 4 dimensional vector)

## SIMD support

| Type of unit | Support |
|--------------|---------|
| SSE          | Not yet |
| AVX          | Yes |
| AVX-512      | Not yet |

## Wrapped Intel SIMD intrinsics

- some AVX float intrinsics
- some AVX2 int intrinsics

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
./{benchmark binaries}
...
sudo cpupower frequency-set --governor powersave > /dev/null 2>&1
```

Windows:
Open solution in Visual Studio, build targets `seq_math_lib_benchmarks`, `avx_math_lib_benchmarks`,... and run produced binaries.

### Comparing benchmarks

[Google benchmark](https://github.com/google/benchmark) also provides a tool for benchmarks comparison, that can be applied here. For more informations see [Google benchmark tooling documentation](https://github.com/google/benchmark/blob/main/docs/tools.md).

### Benchmarks example results

Example machine specifications:
- CPU: 12th Gen Intel® Core™ i5-1240P × 16
- Memory: DDR4 SDRAM 16GB 3200 MT/s
- Compiler: GCC (optimizations O3)

#### Classic sum

* SEQ variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Sum9Elem        0.114 ns        0.114 ns   6056030219
BM_Sum10kElem       4520 ns         4518 ns       154891
BM_Sum15MElem    7489348 ns      7486537 ns           93
```

* AVX variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Sum9Elem        0.116 ns        0.116 ns   5969257709
BM_Sum10kElem        535 ns          534 ns      1311620
BM_Sum15MElem    2472825 ns      2472624 ns          283
```

#### Prefix sum

* SEQ variant
```
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
BM_PrefixSum9Elem        0.229 ns        0.229 ns   3035709879
BM_PrefixSum10kElem       4554 ns         4553 ns       153452
BM_PrefixSum15MElem    8137949 ns      8134959 ns           76
```

* AVX variant
```
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
BM_PrefixSum9Elem        0.228 ns        0.228 ns   3067050881
BM_PrefixSum10kElem       2290 ns         2290 ns       305769
BM_PrefixSum15MElem    6592298 ns      6590846 ns           93
```

#### Sqrt and inverse sqrt of single number

* Std variant

```
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_InvSqrt       1.38 ns         1.38 ns    510940939
BM_Sqrt         0.748 ns        0.748 ns    936036432
```

* SW accelerated variant

```
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_InvSqrt       1.03 ns         1.03 ns    682728778
BM_Sqrt          1.15 ns         1.15 ns    607345544
```
Note: As you can see here, the std variant is overall pretty even with the software accelerated one. It could be because the compiler generates some hardware accelerated instruction for std::sqrt on example machine. Still for some CPUs with no such hardware acceleration the software one can be useful. 

#### Sin and cos of single number

* Std variant
```
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Sin           2.25 ns         2.25 ns    311946997
BM_Cos           2.25 ns         2.25 ns    311502174
```

* SW accelerated variant
```
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Sin           2.38 ns         2.38 ns    294400478
BM_Cos           2.19 ns         2.19 ns    319676165
```
Note: Same effect as above can be seen here.

#### Sequential and vectorized variant of SW accelerated sqrt

* SEQ variant
```
---------------------------------------------------------
Benchmark               Time             CPU   Iterations
---------------------------------------------------------
BM_Sqrt9Elem        0.228 ns        0.228 ns   3066448171
BM_Sqrt10kElem      10651 ns        10649 ns        65710
BM_Sqrt15MElem   16999889 ns     16979607 ns           39
```

* AVX variant
```
---------------------------------------------------------
Benchmark               Time             CPU   Iterations
---------------------------------------------------------
BM_Sqrt9Elem        0.229 ns        0.228 ns   3066857825
BM_Sqrt10kElem       1427 ns         1426 ns       490675
BM_Sqrt15MElem    6546102 ns      6540871 ns           94
```

#### Sequential and vectorized variant of SW accelerated inverse sqrt

* SEQ variant
```
------------------------------------------------------------
Benchmark                  Time             CPU   Iterations
------------------------------------------------------------
BM_InvSqrt9Elem        0.229 ns        0.229 ns   3064980646
BM_InvSqrt10kElem      10101 ns        10095 ns        69195
BM_InvSqrt15MElem   16358004 ns     16351044 ns           41
```

* AVX variant
```
------------------------------------------------------------
Benchmark                  Time             CPU   Iterations
------------------------------------------------------------
BM_InvSqrt9Elem        0.229 ns        0.229 ns   3062259083
BM_InvSqrt10kElem        769 ns          769 ns       909799
BM_InvSqrt15MElem    6510188 ns      6509565 ns           94
```

#### Sequential and vectorized variant of SW accelerated sin

* SEQ variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Sin9Elem        0.231 ns        0.231 ns   3061087941
BM_Sin10kElem      22657 ns        22654 ns        30722
BM_Sin15MElem   35023796 ns     35021230 ns           20
```

* AVX variant
```
---------------------------------------------------------
Benchmark               Time             CPU   Iterations
---------------------------------------------------------
BM_Sqrt9Elem        0.228 ns        0.228 ns   3051461401
BM_Sqrt10kElem       1695 ns         1695 ns       413045
BM_Sqrt15MElem    7074127 ns      7073352 ns           87
```

#### Sequential and vectorized variant of SW accelerated cos

* SEQ variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Cos9Elem        0.228 ns        0.228 ns   3064457336
BM_Cos10kElem      20730 ns        20728 ns        33650
BM_Cos15MElem   31969216 ns     31951642 ns           21
```

* AVX variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Cos9Elem        0.228 ns        0.228 ns   3067976534
BM_Cos10kElem       1393 ns         1393 ns       513323
BM_Cos15MElem    6911133 ns      6909529 ns           93
```

#### Min

* SEQ variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Min9Elem        0.114 ns        0.114 ns   6108640282
BM_Min10kElem       9074 ns         9074 ns        76977
BM_Min15MElem   14285038 ns     14285889 ns           49
```

* AVX variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Min9Elem        0.114 ns        0.114 ns   6123226897
BM_Min10kElem       1063 ns         1063 ns       658679
BM_Min15MElem    2453943 ns      2452630 ns          284
```

#### Max

* SEQ variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Max9Elem        0.117 ns        0.117 ns   6110606962
BM_Max10kElem       9049 ns         9049 ns        77438
BM_Max15MElem   14202415 ns     14202311 ns           49
```

* AVX variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Max9Elem        0.114 ns        0.114 ns   6081638314
BM_Max10kElem       1063 ns         1063 ns       658598
BM_Max15MElem    2457387 ns      2457274 ns          282
```

#### Arithmetic mean

* SEQ variant
```
-------------------------------------------------------------------
Benchmark                         Time             CPU   Iterations
-------------------------------------------------------------------
BM_ArithmeticMean9Elem        0.114 ns        0.114 ns   6128642428
BM_ArithmeticMean10kElem       4520 ns         4520 ns       154866
BM_ArithmeticMean15MElem    7467186 ns      7466658 ns           94
```

* AVX variant
```
-------------------------------------------------------------------
Benchmark                         Time             CPU   Iterations
-------------------------------------------------------------------
BM_ArithmeticMean9Elem        0.116 ns        0.116 ns   6106151714
BM_ArithmeticMean10kElem        538 ns          538 ns      1302477
BM_ArithmeticMean15MElem    2502701 ns      2502678 ns          277
```

#### Geometric mean

* SEQ variant
```
------------------------------------------------------------------
Benchmark                        Time             CPU   Iterations
------------------------------------------------------------------
BM_GeometricMean9Elem        0.114 ns        0.114 ns   6069220044
BM_GeometricMean10kElem       9078 ns         9079 ns        76702
BM_GeometricMean15MElem   14286131 ns     14285502 ns           49
```

* AVX variant
```
------------------------------------------------------------------
Benchmark                        Time             CPU   Iterations
------------------------------------------------------------------
BM_GeometricMean9Elem        0.121 ns        0.121 ns   6103966046
BM_GeometricMean10kElem       1122 ns         1122 ns       623661
BM_GeometricMean15MElem    2534616 ns      2533730 ns          272
```

#### Weighted mean

* SEQ variant
```
-----------------------------------------------------------------
Benchmark                       Time             CPU   Iterations
-----------------------------------------------------------------
BM_WeightedMean9Elem        0.114 ns        0.114 ns   6127502311
BM_WeightedMean10kElem       4560 ns         4560 ns       153388
BM_WeightedMean15MElem    8163582 ns      8163953 ns           79
```

* AVX variant
```
-----------------------------------------------------------------
Benchmark                       Time             CPU   Iterations
-----------------------------------------------------------------
BM_WeightedMean9Elem        0.114 ns        0.114 ns   5820184566
BM_WeightedMean10kElem        568 ns          568 ns      1230526
BM_WeightedMean15MElem    2762926 ns      2762795 ns          254
```

#### Variance

* SEQ variant
```
------------------------------------------------------------------------------
Benchmark                                    Time             CPU   Iterations
------------------------------------------------------------------------------
BM_Variance9Elem                         0.114 ns        0.114 ns   6105457332
BM_Variance10kElem                       31899 ns        31887 ns        21960
BM_Variance15MElem                    48120211 ns     48078056 ns           15
BM_VarianceWithProbabilities9Elem         9.78 ns         9.78 ns     71897849
BM_VarianceWithProbabilities10kElem      31937 ns        31922 ns        21927
BM_VarianceWithProbabilities15MElem   48217724 ns     48194142 ns           15
BM_SampleVariance9Elem                   0.114 ns        0.114 ns   6124469751
BM_SampleVariance10kElem                 31897 ns        31895 ns        21953
BM_SampleVariance15MElem              48091631 ns     48091186 ns           15
```

* AVX variant
```
------------------------------------------------------------------------------
Benchmark                                    Time             CPU   Iterations
------------------------------------------------------------------------------
BM_Variance9Elem                         0.114 ns        0.114 ns   6128562265
BM_Variance10kElem                         611 ns          611 ns      1150006
BM_Variance15MElem                     2698875 ns      2690181 ns          262
BM_VarianceWithProbabilities9Elem         2.98 ns         2.98 ns    235585412
BM_VarianceWithProbabilities10kElem        743 ns          743 ns       940400
BM_VarianceWithProbabilities15MElem    4417311 ns      4415557 ns          159
BM_SampleVariance9Elem                   0.114 ns        0.114 ns   6132457705
BM_SampleVariance10kElem                   603 ns          603 ns      1154015
BM_SampleVariance15MElem               2684586 ns      2684190 ns          260
```

#### Standard deviation

* SEQ variant
```
----------------------------------------------------------------------------------
Benchmark                                        Time             CPU   Iterations
----------------------------------------------------------------------------------
BM_StdDeviation9Elem                         0.115 ns        0.115 ns   6091710599
BM_StdDeviation10kElem                       31918 ns        31919 ns        21932
BM_StdDeviation15MElem                    48132419 ns     48134073 ns           14
BM_StdDeviationWithProbabilities9Elem         10.6 ns         10.6 ns     66045375
BM_StdDeviationWithProbabilities10kElem      32012 ns        32013 ns        21884
BM_StdDeviationWithProbabilities15MElem   48293311 ns     48296485 ns           14
BM_SampleStdDeviation9Elem                   0.114 ns        0.114 ns   6126675224
BM_SampleStdDeviation10kElem                 31902 ns        31900 ns        21934
BM_SampleStdDeviation15MElem              48249314 ns     48251520 ns           14
```

* AVX variant
```
----------------------------------------------------------------------------------
Benchmark                                        Time             CPU   Iterations
----------------------------------------------------------------------------------
BM_StdDeviation9Elem                         0.114 ns        0.114 ns   6127946999
BM_StdDeviation10kElem                         599 ns          599 ns      1168140
BM_StdDeviation15MElem                     2779932 ns      2779993 ns          249
BM_StdDeviationWithProbabilities9Elem         3.19 ns         3.19 ns    219557989
BM_StdDeviationWithProbabilities10kElem        745 ns          745 ns       937726
BM_StdDeviationWithProbabilities15MElem    4448080 ns      4447677 ns          157
BM_SampleStdDeviation9Elem                   0.114 ns        0.114 ns   6119784322
BM_SampleStdDeviation10kElem                   603 ns          603 ns      1147687
BM_SampleStdDeviation15MElem               2795080 ns      2795008 ns          251
```