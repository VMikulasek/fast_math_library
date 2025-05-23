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
    set(STD_SQRT_BENCHMARKS std_sqrt_benchmarks)
    set(ACCELERATED_GONIOMETRIC_BENCHMARKS accelerated_goniometric_benchmarks)
    set(STD_GONIOMETRIC_BENCHMARKS std_goniometric_benchmarks)
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
    set(AVX_SAMPLEVARIANCE_BENCHMARKS avx_samplevariance_benchmarks)
    set(AVX_VARIANCEWITHPROBABILITIES_BENCHMARKS avx_variancewithprobabilities_benchmarks)
    set(SEQ_VARIANCE_BENCHMARKS seq_variance_benchmarks)
    set(SEQ_SAMPLEVARIANCE_BENCHMARKS seq_samplevariance_benchmarks)
    set(SEQ_VARIANCEWITHPROBABILITIES_BENCHMARKS seq_variancewithprobabilities_benchmarks)
    set(AVX_STDDEVIATION_BENCHMARKS avx_stddeviation_benchmarks)
    set(AVX_SAMPLESTDDEVIATION_BENCHMARKS avx_samplestddeviation_benchmarks)
    set(AVX_STDDEVIATIONWITHPROBABILITIES_BENCHMARKS avx_stddeviationwithprobabilities_benchmarks)
    set(SEQ_STDDEVIATION_BENCHMARKS seq_stddeviation_benchmarks)
    set(SEQ_SAMPLESTDDEVIATION_BENCHMARKS seq_samplestddeviation_benchmarks)
    set(SEQ_STDDEVIATIONWITHPROBABILITIES_BENCHMARKS seq_stddeviationwithprobabilities_benchmarks)
    set(GLM_VEC4_BENCHMARKS glm_vec4_benchmarks)
    set(GLM_VEC3_BENCHMARKS glm_vec3_benchmarks)
    set(GLM_VEC2_BENCHMARKS glm_vec2_benchmarks)
    set(AVX_VEC4_BENCHMARKS avx_vec4_benchmarks)
    set(AVX_VEC3_BENCHMARKS avx_vec3_benchmarks)
    set(AVX_VEC2_BENCHMARKS avx_vec2_benchmarks)
    set(SEQ_VEC4_BENCHMARKS seq_vec4_benchmarks)
    set(SEQ_VEC3_BENCHMARKS seq_vec3_benchmarks)
    set(SEQ_VEC2_BENCHMARKS seq_vec2_benchmarks)
    set(STD_SUM_BENCHMARKS std_sum_benchmarks)
    set(STD_PREFIXSUM_BENCHMARKS std_prefixsum_benchmarks)
    set(STD_MIN_BENCHMARKS std_min_benchmarks)
    set(STD_MAX_BENCHMARKS std_max_benchmarks)
    set(BOOST_ARITHMETICMEAN_BENCHMARKS boost_arithmeticmean_benchmarks)
    set(BOOST_VARIANCE_BENCHMARKS boost_variance_benchmarks)
    set(BOOST_SAMPLEVARIANCE_BENCHMARKS boost_samplevariance_benchmarks)
    set(BOOST_MODE_BENCHMARKS boost_mode_benchmarks)
    set(BOOST_MEDIAN_BENCHMARKS boost_median_benchmarks)
    set(SEQ_MODE_BENCHMARKS seq_mode_benchmarks)
    set(SEQ_MEDIAN_BENCHMARKS seq_median_benchmarks)

    set(BENCHMARKS
    ${ACCELERATED_SQRT_BENCHMARKS}
    ${STD_SQRT_BENCHMARKS}
    ${ACCELERATED_GONIOMETRIC_BENCHMARKS}
    ${STD_GONIOMETRIC_BENCHMARKS}
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
    ${AVX_SAMPLEVARIANCE_BENCHMARKS}
    ${AVX_VARIANCEWITHPROBABILITIES_BENCHMARKS}
    ${SEQ_VARIANCE_BENCHMARKS}
    ${SEQ_SAMPLEVARIANCE_BENCHMARKS}
    ${SEQ_VARIANCEWITHPROBABILITIES_BENCHMARKS}
    ${AVX_STDDEVIATION_BENCHMARKS}
    ${AVX_SAMPLESTDDEVIATION_BENCHMARKS}
    ${AVX_STDDEVIATIONWITHPROBABILITIES_BENCHMARKS}
    ${SEQ_STDDEVIATION_BENCHMARKS}
    ${SEQ_SAMPLESTDDEVIATION_BENCHMARKS}
    ${SEQ_STDDEVIATIONWITHPROBABILITIES_BENCHMARKS}
    ${GLM_VEC4_BENCHMARKS}
    ${GLM_VEC3_BENCHMARKS}
    ${GLM_VEC2_BENCHMARKS}
    ${AVX_VEC4_BENCHMARKS}
    ${AVX_VEC3_BENCHMARKS}
    ${AVX_VEC2_BENCHMARKS}
    ${SEQ_VEC4_BENCHMARKS}
    ${SEQ_VEC3_BENCHMARKS}
    ${SEQ_VEC2_BENCHMARKS}
    ${STD_SUM_BENCHMARKS}
    ${STD_PREFIXSUM_BENCHMARKS}
    ${STD_MIN_BENCHMARKS}
    ${STD_MAX_BENCHMARKS}
    ${BOOST_ARITHMETICMEAN_BENCHMARKS}
    ${BOOST_VARIANCE_BENCHMARKS}
    ${BOOST_SAMPLEVARIANCE_BENCHMARKS}
    ${BOOST_MODE_BENCHMARKS}
    ${BOOST_MEDIAN_BENCHMARKS}
    ${SEQ_MODE_BENCHMARKS}
    ${SEQ_MEDIAN_BENCHMARKS})

    add_subdirectory(benchmarks)

    foreach(BENCHMARK ${BENCHMARKS})
        target_include_directories(
            ${BENCHMARK}
            PRIVATE ${GLOBAL_FIXTURES_DIRECTORY}
        )
    endforeach()
endif()