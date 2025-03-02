if (CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    set(BUILD_TESTS_DEFAULT ON)
    set(BUILD_BENCHMARKS_DEFAULT ON)
else()
    set(BUILD_TESTS_DEFAULT OFF)
    set(BUILD_BENCHMARKS_DEFAULT OFF)
endif()

option(BUILD_TESTS "Build tests for math_lib" ${BUILD_TESTS_DEFAULT})
option(BUILD_BENCHMARKS "Build benchmarks for math_lib" ${BUILD_BENCHMARKS_DEFAULT})

set(GOOGLETEST_REPO https://github.com/google/googletest.git)
set(GOOGLETEST_GITTAG ff233bdd4cac0a0bf6e5cd45bda3406814cb2796) # version 1.15.2

set(GLOBAL_FIXTURES_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/globalfixtures)

if (BUILD_TESTS)
    set(TESTS_NAME math_lib_tests)
    add_subdirectory(tests)
    target_include_directories(
        ${TESTS_NAME}
        PRIVATE ${GLOBAL_FIXTURES_DIRECTORY}
    )
endif()

if (BUILD_BENCHMARKS)
    set(ACCELERATED_SQRT_BENCHMARKS accelerated_sqrt_benchmarks)
    set(BASIC_SQRT_BENCHMARKS basic_sqrt_benchmarks)
    set(ACCELERATED_GONIOMETRIC_BENCHMARKS accelerated_goniometric_benchmarks)
    set(BASIC_GONIOMETRIC_BENCHMARKS basic_goniometric_benchmarks)
    set(AVX_SUM_BENCHMARKS avx_sum_benchmarks)
    set(SEQ_SUM_BENCHMARKS seq_sum_benchmarks)
    set(AVX_PREFIXSUM_BENCHMARKS avx_prefixsum_benchmarks)
    set(SEQ_PREFIXSUM_BENCHMARKS seq_prefixsum_benchmarks)
    set(AVX_SQRTARR_BENCHMARKS avx_sqrtarr_benchmarks)
    set(SEQ_SQRTARR_BENCHMARKS seq_sqrtarr_benchmarks)
    set(AVX_INVSQRTARR_BENCHMARKS avx_invsqrtarr_benchmarks)
    set(SEQ_INVSQRTARR_BENCHMARKS seq_invsqrtarr_benchmarks)
    set(AVX_SINARR_BENCHMARKS avx_sinarr_benchmarks)
    set(SEQ_SINARR_BENCHMARKS seq_sinarr_benchmarks)
    set(AVX_COSARR_BENCHMARKS avx_cosarr_benchmarks)
    set(SEQ_COSARR_BENCHMARKS seq_cosarr_benchmarks)
    set(SEQ_MIN_BENCHMARKS seq_min_benchmarks)
    
    set(BENCHMARKS
    ${ACCELERATED_SQRT_BENCHMARKS}
    ${BASIC_SQRT_BENCHMARKS}
    ${ACCELERATED_GONIOMETRIC_BENCHMARKS}
    ${BASIC_GONIOMETRIC_BENCHMARKS}
    ${AVX_SUM_BENCHMARKS}
    ${SEQ_SUM_BENCHMARKS}
    ${AVX_PREFIXSUM_BENCHMARKS}
    ${SEQ_PREFIXSUM_BENCHMARKS}
    ${AVX_SQRTARR_BENCHMARKS}
    ${SEQ_SQRTARR_BENCHMARKS}
    ${AVX_INVSQRTARR_BENCHMARKS}
    ${SEQ_INVSQRTARR_BENCHMARKS}
    ${AVX_SINARR_BENCHMARKS}
    ${SEQ_SINARR_BENCHMARKS}
    ${AVX_COSARR_BENCHMARKS}
    ${SEQ_COSARR_BENCHMARKS}
    ${SEQ_MIN_BENCHMARKS})
    
    add_subdirectory(benchmarks)

    foreach(BENCHMARK ${BENCHMARKS})
        target_include_directories(
            ${BENCHMARK}
            PRIVATE ${GLOBAL_FIXTURES_DIRECTORY}
        )
    endforeach()
endif()