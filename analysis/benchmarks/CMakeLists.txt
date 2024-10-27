set(CMAKE_BUILD_TYPE Release)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang") # google benchmark generates warnings for Clang that cannot be influenced
    add_compile_options(-Wno-c++17-attribute-extensions)
endif()

include(FetchContent)

FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG        12235e24652fc7f809373e7c11a5f73c5763fc4c # version 1.9.0
)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY ${GOOGLETEST_REPO}
    GIT_TAG        ${GOOGLETEST_GITTAG}
)

FetchContent_MakeAvailable(benchmark googletest)

set(ACCELERATED_SQRT_BENCHMARKS_SOURCE
mathops/accelerated/accelerated_sqrt_benchmarks.cpp)
set(BASIC_SQRT_BENCHMARKS_SOURCE
mathops/basic/basic_sqrt_benchmarks.cpp)
set(ACCELERATED_GONIOMETRIC_BENCHMARKS_SOURCE
mathops/accelerated/accelerated_goniometric_benchmarks.cpp)
set(BASIC_GONIOMETRIC_BENCHMARKS_SOURCE
mathops/basic/basic_goniometric_benchmarks.cpp)
set(AVX_SUM_BENCHMARKS_SOURCE
mathops/AVX/avx_sum_benchmarks.cpp)
set(SEQ_SUM_BENCHMARKS_SOURCE
mathops/SEQ/seq_sum_benchmarks.cpp)
set(AVX_PREFIXSUM_BENCHMARKS_SOURCE
mathops/AVX/avx_prefixsum_benchmarks.cpp)
set(SEQ_PREFIXSUM_BENCHMARKS_SOURCE
mathops/SEQ/seq_prefixsum_benchmarks.cpp)
set(AVX_SQRTARR_BENCHMARKS_SOURCE
mathops/AVX/avx_sqrtarr_benchmarks.cpp)
set(SEQ_SQRTARR_BENCHMARKS_SOURCE
mathops/SEQ/seq_sqrtarr_benchmarks.cpp)
set(AVX_INVSQRTARR_BENCHMARKS_SOURCE
mathops/AVX/avx_invsqrtarr_benchmarks.cpp)
set(SEQ_INVSQRTARR_BENCHMARKS_SOURCE
mathops/SEQ/seq_invsqrtarr_benchmarks.cpp)

add_executable(${ACCELERATED_SQRT_BENCHMARKS} ${ACCELERATED_SQRT_BENCHMARKS_SOURCE})
add_executable(${BASIC_SQRT_BENCHMARKS} ${BASIC_SQRT_BENCHMARKS_SOURCE})
add_executable(${ACCELERATED_GONIOMETRIC_BENCHMARKS} ${ACCELERATED_GONIOMETRIC_BENCHMARKS_SOURCE})
add_executable(${BASIC_GONIOMETRIC_BENCHMARKS} ${BASIC_GONIOMETRIC_BENCHMARKS_SOURCE})
add_executable(${AVX_SUM_BENCHMARKS} ${AVX_SUM_BENCHMARKS_SOURCE})
add_executable(${SEQ_SUM_BENCHMARKS} ${SEQ_SUM_BENCHMARKS_SOURCE})
add_executable(${AVX_PREFIXSUM_BENCHMARKS} ${AVX_PREFIXSUM_BENCHMARKS_SOURCE})
add_executable(${SEQ_PREFIXSUM_BENCHMARKS} ${SEQ_PREFIXSUM_BENCHMARKS_SOURCE})
add_executable(${AVX_SQRTARR_BENCHMARKS} ${AVX_SQRTARR_BENCHMARKS_SOURCE})
add_executable(${SEQ_SQRTARR_BENCHMARKS} ${SEQ_SQRTARR_BENCHMARKS_SOURCE})
add_executable(${AVX_INVSQRTARR_BENCHMARKS} ${AVX_INVSQRTARR_BENCHMARKS_SOURCE})
add_executable(${SEQ_INVSQRTARR_BENCHMARKS} ${SEQ_INVSQRTARR_BENCHMARKS_SOURCE})

foreach(BENCHMARK ${BENCHMARKS})
    target_link_libraries(
        ${BENCHMARK}
        PRIVATE ${PROJECT_NAME}
        PRIVATE benchmark::benchmark
        PRIVATE benchmark::benchmark_main)

    target_include_directories(
        ${BENCHMARK} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
endforeach()