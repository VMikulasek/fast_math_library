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
    set(AVX_MIN_BENCHMARKS avx_min_benchmarks)
    set(SEQ_MIN_BENCHMARKS seq_min_benchmarks)
    set(AVX_MAX_BENCHMARKS avx_max_benchmarks)
    set(SEQ_MAX_BENCHMARKS seq_max_benchmarks)
    set(AVX_ARITHMETICMEAN_BENCHMARKS avx_arithmeticmean_benchmarks)
    set(SEQ_ARITHMETICMEAN_BENCHMARKS seq_arithmeticmean_benchmarks)
    set(AVX_GEOMETRICMEAN_BENCHMARKS avx_geometricmean_benchmarks)
    set(SEQ_GEOMETRICMEAN_BENCHMARKS seq_geometricmean_benchmarks)
    set(AVX_WEIGHTEDMEAN_BENCHMARKS avx_weightedmean_benchmarks)
    set(SEQ_WEIGHTEDMEAN_BENCHMARKS seq_weightedmean_benchmarks)
    set(AVX_VARIANCE_BENCHMARKS avx_variance_benchmarks)
    set(SEQ_VARIANCE_BENCHMARKS seq_variance_benchmarks)
    set(AVX_STDDEVIATION_BENCHMARKS avx_stddeviation_benchmarks)
    set(SEQ_STDDEVIATION_BENCHMARKS seq_stddeviation_benchmarks)
    set(GLM_SEQ_VEC4_BENCHMARKS glm_seq_vec4_benchmarks)
    set(GLM_SIMD_VEC4_BENCHMARKS glm_simd_vec4_benchmarks)
    set(GLM_SEQ_VEC3_BENCHMARKS glm_seq_vec3_benchmarks)
    set(GLM_SIMD_VEC3_BENCHMARKS glm_simd_vec3_benchmarks)
    set(GLM_SEQ_VEC2_BENCHMARKS glm_seq_vec2_benchmarks)
    set(GLM_SIMD_VEC2_BENCHMARKS glm_simd_vec2_benchmarks)
    
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
    ${AVX_MIN_BENCHMARKS}
    ${SEQ_MIN_BENCHMARKS}
    ${AVX_MAX_BENCHMARKS}
    ${SEQ_MAX_BENCHMARKS}
    ${AVX_ARITHMETICMEAN_BENCHMARKS}
    ${SEQ_ARITHMETICMEAN_BENCHMARKS}
    ${AVX_GEOMETRICMEAN_BENCHMARKS}
    ${SEQ_GEOMETRICMEAN_BENCHMARKS}
    ${AVX_WEIGHTEDMEAN_BENCHMARKS}
    ${SEQ_WEIGHTEDMEAN_BENCHMARKS}
    ${AVX_VARIANCE_BENCHMARKS}
    ${SEQ_VARIANCE_BENCHMARKS}
    ${AVX_STDDEVIATION_BENCHMARKS}
    ${SEQ_STDDEVIATION_BENCHMARKS}
    ${GLM_SEQ_VEC4_BENCHMARKS}
    ${GLM_SIMD_VEC4_BENCHMARKS}
    ${GLM_SEQ_VEC3_BENCHMARKS}
    ${GLM_SIMD_VEC3_BENCHMARKS}
    ${GLM_SEQ_VEC2_BENCHMARKS}
    ${GLM_SIMD_VEC2_BENCHMARKS})

    add_subdirectory(benchmarks)

    foreach(BENCHMARK ${BENCHMARKS})
        target_include_directories(
            ${BENCHMARK}
            PRIVATE ${GLOBAL_FIXTURES_DIRECTORY}
        )
    endforeach()
endif()