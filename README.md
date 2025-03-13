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
BM_Sum9Elem         1.03 ns         1.03 ns    673131667
BM_Sum10kElem       4523 ns         4522 ns       154253
BM_Sum15MElem    7362057 ns      7361368 ns           95
```

* AVX variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Sum9Elem         1.20 ns         1.20 ns    583417049
BM_Sum10kElem        534 ns          534 ns      1305213
BM_Sum15MElem    2584427 ns      2583452 ns          266
```

* STD parallel variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Sum9Elem         1.59 ns         1.59 ns    437486050
BM_Sum10kElem       1142 ns         1142 ns       613476
BM_Sum15MElem    3623347 ns      3622787 ns          193
```

#### Prefix sum

* SEQ variant
```
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
BM_PrefixSum9Elem         1.14 ns         1.14 ns    611974361
BM_PrefixSum10kElem       4559 ns         4557 ns       153804
BM_PrefixSum15MElem    8174227 ns      8171111 ns           76
```

* AVX variant
```
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
BM_PrefixSum9Elem         1.40 ns         1.40 ns    498937982
BM_PrefixSum10kElem       2295 ns         2294 ns       305734
BM_PrefixSum15MElem    6833926 ns      6832964 ns           91
```

* STD variant
```
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
BM_PrefixSum9Elem         1.14 ns         1.14 ns    612365532
BM_PrefixSum10kElem       4552 ns         4551 ns       153813
BM_PrefixSum15MElem    8180068 ns      8178854 ns           75
```

#### Sqrt and inverse sqrt of single number

* STD variant

```
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_InvSqrt       1.37 ns         1.37 ns    511136026
BM_Sqrt         0.750 ns        0.750 ns    932197730
```

* SW accelerated variant

```
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_InvSqrt       1.03 ns         1.03 ns    683110723
BM_Sqrt          1.16 ns         1.16 ns    604074164
```

#### Sin and cos of single number

* STD variant
```
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Sin           2.30 ns         2.30 ns    303753915
BM_Cos           2.26 ns         2.26 ns    309710539
```

* SW accelerated variant
```
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Sin           2.39 ns         2.39 ns    293522043
BM_Cos           2.19 ns         2.19 ns    319141046
```

#### Vectorized variant of SW accelerated sqrt vs sequential std sqrt

* SEQ variant
```
---------------------------------------------------------
Benchmark               Time             CPU   Iterations
---------------------------------------------------------
BM_Sqrt9Elem         26.1 ns         26.1 ns     26882733
BM_Sqrt10kElem      21674 ns        21673 ns        32332
BM_Sqrt15MElem   33395274 ns     33391740 ns           21
```

* AVX variant
```
---------------------------------------------------------
Benchmark               Time             CPU   Iterations
---------------------------------------------------------
BM_Sqrt9Elem         2.29 ns         2.28 ns    306831019
BM_Sqrt10kElem       1428 ns         1427 ns       490973
BM_Sqrt15MElem    6549794 ns      6547715 ns           94
```

#### Vectorized variant of SW accelerated inverse sqrt vs sequential 1 / std sqrt 

* SEQ variant
```
------------------------------------------------------------
Benchmark                  Time             CPU   Iterations
------------------------------------------------------------
BM_InvSqrt9Elem         12.3 ns         12.3 ns     56645998
BM_InvSqrt10kElem      13702 ns        13701 ns        51118
BM_InvSqrt15MElem   21370932 ns     21364061 ns           31
```

* AVX variant
```
------------------------------------------------------------
Benchmark                  Time             CPU   Iterations
------------------------------------------------------------
BM_InvSqrt9Elem         1.39 ns         1.39 ns    500358432
BM_InvSqrt10kElem        769 ns          769 ns       909012
BM_InvSqrt15MElem    6583573 ns      6582923 ns           94
```

#### Vectorized variant of SW accelerated sin vs sequential std sin

* SEQ variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Sin9Elem         26.0 ns         26.0 ns     26877200
BM_Sin10kElem      21661 ns        21659 ns        32324
BM_Sin15MElem   33448188 ns     33442077 ns           21
```

* AVX variant
```
---------------------------------------------------------
Benchmark               Time             CPU   Iterations
---------------------------------------------------------
BM_Sqrt9Elem         3.83 ns         3.82 ns    182419138
BM_Sqrt10kElem       1528 ns         1527 ns       458970
BM_Sqrt15MElem    6647634 ns      6640488 ns           92
```

#### Vectorized variant of SW accelerated cos vs sequential std cos

* SEQ variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Cos9Elem         26.0 ns         26.0 ns     25640053
BM_Cos10kElem      21760 ns        21758 ns        32227
BM_Cos15MElem   33697907 ns     33694146 ns           20
```

* AVX variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Cos9Elem         3.43 ns         3.43 ns    202995185
BM_Cos10kElem       1386 ns         1386 ns       514314
BM_Cos15MElem    6792748 ns      6786570 ns           93
```

#### Min

* SEQ variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Min9Elem         1.04 ns         1.04 ns    673560040
BM_Min10kElem       9048 ns         9047 ns        77382
BM_Min15MElem   14439731 ns     14398979 ns           49
```

* AVX variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Min9Elem         1.47 ns         1.47 ns    477305403
BM_Min10kElem       1062 ns         1062 ns       658650
BM_Min15MElem    2564615 ns      2564091 ns          270
```

* STD variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Min9Elem         2.01 ns         2.01 ns    347681056
BM_Min10kElem       9113 ns         9112 ns        76735
BM_Min15MElem   14376194 ns     14373715 ns           49
```

#### Max

* SEQ variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Max9Elem         1.08 ns         1.08 ns    643416700
BM_Max10kElem       9041 ns         9040 ns        77432
BM_Max15MElem   14394520 ns     14391926 ns           49
```

* AVX variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Max9Elem         1.46 ns         1.46 ns    478139751
BM_Max10kElem       1062 ns         1062 ns       658950
BM_Max15MElem    2495363 ns      2494687 ns          277
```

* STD variant
```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Max9Elem         2.01 ns         2.01 ns    347666157
BM_Max10kElem       9124 ns         9124 ns        76532
BM_Max15MElem   14548879 ns     14546705 ns           48
```

#### Arithmetic mean

* SEQ variant
```
-------------------------------------------------------------------
Benchmark                         Time             CPU   Iterations
-------------------------------------------------------------------
BM_ArithmeticMean9Elem         1.03 ns         1.03 ns    678267509
BM_ArithmeticMean10kElem       4520 ns         4520 ns       154697
BM_ArithmeticMean15MElem    7559458 ns      7558177 ns           93
```

* AVX variant
```
-------------------------------------------------------------------
Benchmark                         Time             CPU   Iterations
-------------------------------------------------------------------
BM_ArithmeticMean9Elem         1.19 ns         1.19 ns    588792777
BM_ArithmeticMean10kElem        534 ns          534 ns      1311195
BM_ArithmeticMean15MElem    2485522 ns      2484401 ns          279
```

* Boost.Math parallel variant
```
-------------------------------------------------------------------
Benchmark                         Time             CPU   Iterations
-------------------------------------------------------------------
BM_ArithmeticMean9Elem         1.49 ns         1.49 ns    469804119
BM_ArithmeticMean10kElem       1142 ns         1142 ns       611767
BM_ArithmeticMean15MElem    3488755 ns      3486996 ns          201
```

#### Geometric mean

* SEQ variant
```
------------------------------------------------------------------
Benchmark                        Time             CPU   Iterations
------------------------------------------------------------------
BM_GeometricMean9Elem         6.66 ns         6.65 ns    104923359
BM_GeometricMean10kElem       9078 ns         9076 ns        77148
BM_GeometricMean15MElem   14433998 ns     14387405 ns           49
```

* AVX variant
```
------------------------------------------------------------------
Benchmark                        Time             CPU   Iterations
------------------------------------------------------------------
BM_GeometricMean9Elem         6.66 ns         6.66 ns    104954744
BM_GeometricMean10kElem       1122 ns         1122 ns       623694
BM_GeometricMean15MElem    2553571 ns      2548462 ns          272
```

#### Weighted mean

* SEQ variant
```
-----------------------------------------------------------------
Benchmark                       Time             CPU   Iterations
-----------------------------------------------------------------
BM_WeightedMean9Elem         2.21 ns         2.21 ns    315870335
BM_WeightedMean10kElem       4561 ns         4560 ns       153299
BM_WeightedMean15MElem    7697323 ns      7694986 ns           91
```

* AVX variant
```
-----------------------------------------------------------------
Benchmark                       Time             CPU   Iterations
-----------------------------------------------------------------
BM_WeightedMean9Elem         2.45 ns         2.45 ns    285737963
BM_WeightedMean10kElem        567 ns          566 ns      1234179
BM_WeightedMean15MElem    2796312 ns      2795222 ns          250
```

#### Variance

* SEQ variant
```
BM_Variance9Elem                          11.1 ns         11.1 ns     62859561
BM_Variance10kElem                       31912 ns        31905 ns        21957
BM_Variance15MElem                    48254200 ns     48248195 ns           15
BM_SampleVariance9Elem                    10.5 ns         10.5 ns     66555496
BM_SampleVariance10kElem                 32006 ns        32003 ns        21945
BM_SampleVariance15MElem              48198128 ns     48181503 ns           15
BM_VarianceWithProbabilities9Elem         13.6 ns         13.6 ns     51970581
BM_VarianceWithProbabilities10kElem      31922 ns        31917 ns        21922
BM_VarianceWithProbabilities15MElem   48340863 ns     48334085 ns           15
```

* AVX variant
```
------------------------------------------------------------------------------
Benchmark                                    Time             CPU   Iterations
------------------------------------------------------------------------------
BM_Variance9Elem                          3.80 ns         3.80 ns    185084509
BM_Variance10kElem                         600 ns          600 ns      1160699
BM_Variance15MElem                     2799265 ns      2798052 ns          250
BM_SampleVariance9Elem                    3.92 ns         3.92 ns    179635654
BM_SampleVariance10kElem                   609 ns          609 ns      1139890
BM_SampleVariance15MElem               2782106 ns      2781077 ns          252
BM_VarianceWithProbabilities9Elem         3.97 ns         3.97 ns    176356658
BM_VarianceWithProbabilities10kElem        745 ns          744 ns       937428
BM_VarianceWithProbabilities15MElem    4432267 ns      4430769 ns          158
```

* Boost.Math variant
```
-------------------------------------------------------------------
Benchmark                         Time             CPU   Iterations
-------------------------------------------------------------------
BM_Variance9Elem               9.37 ns         9.37 ns     73952441
BM_Variance10kElem            36970 ns        36961 ns        18939
BM_Variance15MElem         55893790 ns     55867342 ns           13
BM_SampleVariance9Elem         9.98 ns         9.97 ns     70254390
BM_SampleVariance10kElem      37057 ns        37037 ns        18935
BM_SampleVariance15MElem   55706151 ns     55686839 ns           12
```

#### Standard deviation

* SEQ variant
```
----------------------------------------------------------------------------------
Benchmark                                        Time             CPU   Iterations
----------------------------------------------------------------------------------
BM_StdDeviation9Elem                          12.0 ns         12.0 ns     58479638
BM_StdDeviation10kElem                       31918 ns        31901 ns        21958
BM_StdDeviation15MElem                    48517721 ns     48506837 ns           14
BM_SampleStdDeviation9Elem                    11.5 ns         11.5 ns     61066174
BM_SampleStdDeviation10kElem                 32078 ns        32075 ns        21928
BM_SampleStdDeviation15MElem              48292162 ns     48286491 ns           14
BM_StdDeviationWithProbabilities9Elem         14.6 ns         14.6 ns     48105866
BM_StdDeviationWithProbabilities10kElem      32004 ns        31933 ns        21923
BM_StdDeviationWithProbabilities15MElem   48322797 ns     48321619 ns           14
```

* AVX variant
```
----------------------------------------------------------------------------------
Benchmark                                        Time             CPU   Iterations
----------------------------------------------------------------------------------
BM_StdDeviation9Elem                          4.06 ns         4.06 ns    172608734
BM_StdDeviation10kElem                         601 ns          601 ns      1165038
BM_StdDeviation15MElem                     2820301 ns      2820092 ns          248
BM_SampleStdDeviation9Elem                    4.25 ns         4.25 ns    164702121
BM_SampleStdDeviation10kElem                   605 ns          605 ns      1142043
BM_SampleStdDeviation15MElem               2826539 ns      2826143 ns          248
BM_StdDeviationWithProbabilities9Elem         4.24 ns         4.24 ns    165163257
BM_StdDeviationWithProbabilities10kElem        744 ns          744 ns       932416
BM_StdDeviationWithProbabilities15MElem    4470003 ns      4469791 ns          156
```

#### Vec2

* SEQ variant
```
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Vec2Add              0.353 ns        0.353 ns   1974062678
BM_Vec2Sub              0.344 ns        0.344 ns   2045225033
BM_Vec2Mul              0.343 ns        0.343 ns   2030572544
BM_Vec2Div              0.686 ns        0.686 ns   1015901102
BM_Vec2Abs              0.434 ns        0.434 ns   1580274886
BM_Vec2Min              0.344 ns        0.344 ns   2045094575
BM_Vec2Max              0.343 ns        0.343 ns   2042970237
BM_Vec2Sqrt              1.37 ns         1.37 ns    506958267
BM_Vec2SqrtLowp          2.09 ns         2.09 ns    333937527
BM_Vec2InvSqrt           2.74 ns         2.74 ns    255706867
BM_Vec2InvSqrtLowp       1.97 ns         1.97 ns    353496024
BM_Vec2Sin               6.74 ns         6.74 ns     99722123
BM_Vec2SinLowp           3.31 ns         3.31 ns    211227844
BM_Vec2Cos               6.68 ns         6.68 ns    104201247
BM_Vec2CosLowp           2.93 ns         2.93 ns    238601868
BM_Vec2Tan               8.80 ns         8.80 ns     77486464
BM_Vec2Cot               9.12 ns         9.12 ns     79157539
BM_Vec2Dot              0.399 ns        0.399 ns   1753520196
BM_Vec2Length           0.741 ns        0.741 ns    944098345
BM_Vec2Normalize         1.37 ns         1.37 ns    507409145
```

* AVX variant
```
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Vec2Add              0.229 ns        0.229 ns   3067575117
BM_Vec2Sub              0.242 ns        0.242 ns   2957956535
BM_Vec2Mul              0.229 ns        0.229 ns   3062536385
BM_Vec2Div               1.14 ns         1.14 ns    613435998
BM_Vec2Abs              0.228 ns        0.228 ns   3056467077
BM_Vec2Min              0.229 ns        0.229 ns   3048353280
BM_Vec2Max              0.229 ns        0.229 ns   3053342482
BM_Vec2Sqrt              1.37 ns         1.37 ns    510855814
BM_Vec2SqrtLowp          1.14 ns         1.14 ns    613313648
BM_Vec2InvSqrt           2.74 ns         2.74 ns    255682910
BM_Vec2InvSqrtLowp      0.585 ns        0.585 ns   1197778074
BM_Vec2Sin               6.64 ns         6.64 ns    104362516
BM_Vec2SinLowp           1.21 ns         1.21 ns    578587384
BM_Vec2Cos               6.59 ns         6.59 ns    103954823
BM_Vec2CosLowp           1.07 ns         1.07 ns    654472889
BM_Vec2Tan               8.77 ns         8.77 ns     78106446
BM_Vec2Cot               8.98 ns         8.98 ns     79707599
BM_Vec2Dot              0.457 ns        0.456 ns   1533072687
BM_Vec2Length           0.912 ns        0.912 ns    764555871
BM_Vec2Normalize         2.36 ns         2.36 ns    297702940
```

* GLM variant
```
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Vec2Add              0.376 ns        0.376 ns   1845242000
BM_Vec2Sub              0.353 ns        0.353 ns   1979270238
BM_Vec2Mul              0.329 ns        0.329 ns   2123381645
BM_Vec2Div              0.685 ns        0.685 ns   1022691284
BM_Vec2Abs              0.957 ns        0.957 ns    735173208
BM_Vec2Min              0.230 ns        0.230 ns   3068026542
BM_Vec2Max              0.228 ns        0.228 ns   3067499409
BM_Vec2Sqrt              1.44 ns         1.44 ns    482759766
BM_Vec2SqrtLowp          1.46 ns         1.46 ns    482881346
BM_Vec2InvSqrt           2.05 ns         2.05 ns    340972145
BM_Vec2InvSqrtLowp       2.05 ns         2.05 ns    340843625
BM_Vec2Sin               6.72 ns         6.72 ns    103685879
BM_Vec2SinLowp           6.73 ns         6.73 ns    106261179
BM_Vec2Cos               6.56 ns         6.56 ns    106531104
BM_Vec2CosLowp           6.55 ns         6.55 ns    104187275
BM_Vec2Tan               15.6 ns         15.6 ns     44679150
BM_Vec2Cot               24.9 ns         24.9 ns     31272754
BM_Vec2Dot              0.496 ns        0.496 ns   1335704578
BM_Vec2Length           0.228 ns        0.228 ns   3069061894
BM_Vec2Normalize         1.44 ns         1.44 ns    485448447
```

#### Vec3

* SEQ variant
```
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Vec3Add              0.457 ns        0.457 ns   1533214363
BM_Vec3Sub              0.457 ns        0.456 ns   1534531886
BM_Vec3Mul              0.457 ns        0.456 ns   1533162148
BM_Vec3Div               1.37 ns         1.37 ns    511535225
BM_Vec3Abs              0.458 ns        0.458 ns   1527842996
BM_Vec3Min              0.457 ns        0.457 ns   1532610013
BM_Vec3Max              0.456 ns        0.456 ns   1534202115
BM_Vec3Sqrt              2.06 ns         2.05 ns    340999622
BM_Vec3SqrtLowp          3.11 ns         3.11 ns    224993252
BM_Vec3InvSqrt           4.11 ns         4.11 ns    170335681
BM_Vec3InvSqrtLowp       2.93 ns         2.93 ns    239279556
BM_Vec3Sin               9.92 ns         9.92 ns     69737851
BM_Vec3SinLowp           5.26 ns         5.26 ns    134597025
BM_Vec3Cos               9.95 ns         9.95 ns     71380385
BM_Vec3CosLowp           4.60 ns         4.60 ns    151842664
BM_Vec3Tan               13.2 ns         13.2 ns     53054107
BM_Vec3Cot               12.9 ns         12.9 ns     54237403
BM_Vec3Dot              0.675 ns        0.675 ns   1071736647
BM_Vec3Length           0.760 ns        0.759 ns    915707275
BM_Vec3Normalize         2.05 ns         2.05 ns    340946354
BM_Vec3Cross            0.654 ns        0.654 ns   1089036836
```

* AVX variant
```
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Vec3Add              0.264 ns        0.264 ns   2794247907
BM_Vec3Sub              0.229 ns        0.229 ns   3067046930
BM_Vec3Mul              0.236 ns        0.236 ns   2969000685
BM_Vec3Div               1.14 ns         1.14 ns    613043377
BM_Vec3Abs              0.228 ns        0.228 ns   3069033758
BM_Vec3Min              0.258 ns        0.258 ns   2719885955
BM_Vec3Max              0.228 ns        0.228 ns   3059222924
BM_Vec3Sqrt              2.06 ns         2.06 ns    341075507
BM_Vec3SqrtLowp          1.14 ns         1.14 ns    610432609
BM_Vec3InvSqrt           4.11 ns         4.11 ns    170450482
BM_Vec3InvSqrtLowp      0.584 ns        0.584 ns   1195392527
BM_Vec3Sin               10.0 ns         10.0 ns     69658065
BM_Vec3SinLowp           1.21 ns         1.21 ns    577571733
BM_Vec3Cos               9.80 ns         9.80 ns     70409080
BM_Vec3CosLowp           1.08 ns         1.08 ns    649001200
BM_Vec3Tan               12.9 ns         12.9 ns     53246559
BM_Vec3Cot               13.1 ns         13.1 ns     54325840
BM_Vec3Dot              0.914 ns        0.914 ns    765845036
BM_Vec3Length           0.912 ns        0.912 ns    767122951
BM_Vec3Normalize         2.35 ns         2.35 ns    297815744
BM_Vec3Cross            0.685 ns        0.685 ns   1022493155
```

* GLM variant
```
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Vec3Add              0.277 ns        0.277 ns   2521623207
BM_Vec3Sub              0.277 ns        0.277 ns   2512406623
BM_Vec3Mul              0.287 ns        0.287 ns   2442055952
BM_Vec3Div               1.37 ns         1.37 ns    511594358
BM_Vec3Abs               1.22 ns         1.22 ns    572730085
BM_Vec3Min              0.228 ns        0.228 ns   3061556887
BM_Vec3Max              0.235 ns        0.235 ns   2888904571
BM_Vec3Sqrt              2.05 ns         2.05 ns    341015488
BM_Vec3SqrtLowp          2.05 ns         2.05 ns    340350220
BM_Vec3InvSqrt           3.42 ns         3.42 ns    204620807
BM_Vec3InvSqrtLowp       3.42 ns         3.42 ns    204455056
BM_Vec3Sin               10.0 ns         10.0 ns     69744618
BM_Vec3SinLowp           10.0 ns         10.0 ns     70722641
BM_Vec3Cos               9.79 ns         9.79 ns     71427803
BM_Vec3CosLowp           9.79 ns         9.79 ns     69943596
BM_Vec3Tan               22.9 ns         22.9 ns     30542400
BM_Vec3Cot               35.6 ns         35.6 ns     21501363
BM_Vec3Dot              0.495 ns        0.495 ns   1412834442
BM_Vec3Length           0.229 ns        0.229 ns   3052043157
BM_Vec3Normalize         1.44 ns         1.44 ns    484343721
BM_Vec3Cross             1.14 ns         1.14 ns    613927295
```

#### Vec4

* SEQ variant
```
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Vec4Add              0.228 ns        0.228 ns   3066045032
BM_Vec4Sub              0.228 ns        0.228 ns   3066423736
BM_Vec4Mul              0.229 ns        0.229 ns   3069500822
BM_Vec4Div              0.687 ns        0.687 ns   1014590140
BM_Vec4Abs              0.229 ns        0.229 ns   3067972554
BM_Vec4Min              0.229 ns        0.229 ns   3063592638
BM_Vec4Max              0.234 ns        0.234 ns   3020791147
BM_Vec4Sqrt              2.74 ns         2.74 ns    255261385
BM_Vec4SqrtLowp          4.12 ns         4.12 ns    169762013
BM_Vec4InvSqrt           5.49 ns         5.49 ns    127230968
BM_Vec4InvSqrtLowp       3.87 ns         3.87 ns    180697664
BM_Vec4Sin               13.6 ns         13.6 ns     51408243
BM_Vec4SinLowp           4.26 ns         4.26 ns    165813965
BM_Vec4Cos               13.5 ns         13.5 ns     52608263
BM_Vec4CosLowp           3.96 ns         3.96 ns    173241526
BM_Vec4Tan               17.2 ns         17.2 ns     40681323
BM_Vec4Cot               16.9 ns         16.9 ns     41472608
BM_Vec4Dot              0.718 ns        0.718 ns    971991550
BM_Vec4Length           0.889 ns        0.889 ns    784548536
BM_Vec4Normalize         1.37 ns         1.37 ns    510798999
```

* AVX variant
```
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Vec4Add              0.228 ns        0.228 ns   3064858715
BM_Vec4Sub              0.228 ns        0.228 ns   3054564084
BM_Vec4Mul              0.228 ns        0.228 ns   3033756864
BM_Vec4Div               1.14 ns         1.14 ns    613510418
BM_Vec4Abs              0.316 ns        0.316 ns   2216504682
BM_Vec4Min              0.229 ns        0.229 ns   3011047486
BM_Vec4Max              0.228 ns        0.228 ns   3066700168
BM_Vec4Sqrt              2.74 ns         2.74 ns    255754855
BM_Vec4SqrtLowp          1.14 ns         1.14 ns    613767593
BM_Vec4InvSqrt           5.50 ns         5.50 ns    127786382
BM_Vec4InvSqrtLowp      0.584 ns        0.584 ns   1191745257
BM_Vec4Sin               13.5 ns         13.5 ns     51098329
BM_Vec4SinLowp           1.21 ns         1.21 ns    578109478
BM_Vec4Cos               13.3 ns         13.3 ns     51770647
BM_Vec4CosLowp           1.07 ns         1.07 ns    655652909
BM_Vec4Tan               16.9 ns         16.9 ns     40659024
BM_Vec4Cot               17.2 ns         17.2 ns     41522469
BM_Vec4Dot              0.913 ns        0.913 ns    767013241
BM_Vec4Length           0.914 ns        0.914 ns    766808598
BM_Vec4Normalize         2.36 ns         2.36 ns    294832904
```

* GLM variant
```
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_Vec4Add              0.228 ns        0.228 ns   3059758531
BM_Vec4Sub              0.425 ns        0.425 ns   1693410497
BM_Vec4Mul              0.228 ns        0.228 ns   3065016317
BM_Vec4Div              0.685 ns        0.685 ns   1018868306
BM_Vec4Abs              0.228 ns        0.228 ns   3060484468
BM_Vec4Min              0.266 ns        0.266 ns   2690022653
BM_Vec4Max              0.228 ns        0.228 ns   3064721364
BM_Vec4Sqrt             0.685 ns        0.685 ns   1021969273
BM_Vec4SqrtLowp         0.251 ns        0.251 ns   2784822262
BM_Vec4InvSqrt           1.37 ns         1.37 ns    509755738
BM_Vec4InvSqrtLowp      0.457 ns        0.457 ns   1533432191
BM_Vec4Sin               13.4 ns         13.4 ns     51894866
BM_Vec4SinLowp           13.3 ns         13.3 ns     52125440
BM_Vec4Cos               13.3 ns         13.3 ns     52750255
BM_Vec4CosLowp           13.4 ns         13.4 ns     52711546
BM_Vec4Tan               43.0 ns         43.0 ns     22640814
BM_Vec4Cot               31.2 ns         31.2 ns     16143331
BM_Vec4Dot               1.37 ns         1.37 ns    511451991
BM_Vec4Length           0.228 ns        0.228 ns   3068323342
BM_Vec4Normalize         1.37 ns         1.37 ns    511309360
```