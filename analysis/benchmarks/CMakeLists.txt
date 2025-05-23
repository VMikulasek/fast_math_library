set(CMAKE_BUILD_TYPE Release)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang") # google benchmark generates warnings for Clang that cannot be influenced
    add_compile_options(-Wno-c++17-attribute-extensions)
endif()

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY ${GOOGLETEST_REPO}
    GIT_TAG        ${GOOGLETEST_GITTAG}
)

FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG        12235e24652fc7f809373e7c11a5f73c5763fc4c # version 1.9.0
)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        0af55ccecd98d4e5a8d1fad7de25ba429d60e863 # version 1.0.1
)

FetchContent_Declare(
    boostmath
    GIT_REPOSITORY https://github.com/boostorg/math.git
    GIT_TAG        f1b0b95a04f56717b3454cb599e0647770c5852e # version 1.87
)

FetchContent_MakeAvailable(googletest benchmark glm boostmath)

set(ACCELERATED_SQRT_BENCHMARKS_SOURCE
mathops/local/accelerated/accelerated_sqrt_benchmarks.cpp)
set(STD_SQRT_BENCHMARKS_SOURCE
mathops/std/std_sqrt_benchmarks.cpp)
set(ACCELERATED_GONIOMETRIC_BENCHMARKS_SOURCE
mathops/local/accelerated/accelerated_goniometric_benchmarks.cpp)
set(STD_GONIOMETRIC_BENCHMARKS_SOURCE
mathops/std/std_goniometric_benchmarks.cpp)
set(AVX_SUM_BENCHMARKS_SOURCE
mathops/local/AVX/avx_sum_benchmarks.cpp)
set(SEQ_SUM_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_sum_benchmarks.cpp)
set(AVX_PREFIXSUM_BENCHMARKS_SOURCE
mathops/local/AVX/avx_prefixsum_benchmarks.cpp)
set(SEQ_PREFIXSUM_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_prefixsum_benchmarks.cpp)
set(AVX_SQRTARR_BENCHMARKS_SOURCE
mathops/local/AVX/avx_sqrtarr_benchmarks.cpp)
set(SEQ_SQRTARR_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_sqrtarr_benchmarks.cpp)
set(AVX_INVSQRTARR_BENCHMARKS_SOURCE
mathops/local/AVX/avx_invsqrtarr_benchmarks.cpp)
set(SEQ_INVSQRTARR_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_invsqrtarr_benchmarks.cpp)
set(AVX_SINARR_BENCHMARKS_SOURCE
mathops/local/AVX/avx_sinarr_benchmarks.cpp)
set(SEQ_SINARR_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_sinarr_benchmarks.cpp)
set(AVX_COSARR_BENCHMARKS_SOURCE
mathops/local/AVX/avx_cosarr_benchmarks.cpp)
set(SEQ_COSARR_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_cosarr_benchmarks.cpp)
set(AVX_MIN_BENCHMARKS_SOURCE
mathops/local/AVX/avx_min_benchmarks.cpp)
set(SEQ_MIN_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_min_benchmarks.cpp)
set(AVX_MAX_BENCHMARKS_SOURCE
mathops/local/AVX/avx_max_benchmarks.cpp)
set(SEQ_MAX_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_max_benchmarks.cpp)
set(AVX_ARITHMETICMEAN_BENCHMARKS_SOURCE
mathops/local/AVX/avx_arithmeticmean_benchmarks.cpp)
set(SEQ_ARITHMETICMEAN_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_arithmeticmean_benchmarks.cpp)
set(AVX_GEOMETRICMEAN_BENCHMARKS_SOURCE
mathops/local/AVX/avx_geometricmean_benchmarks.cpp)
set(SEQ_GEOMETRICMEAN_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_geometricmean_benchmarks.cpp)
set(AVX_WEIGHTEDMEAN_BENCHMARKS_SOURCE
mathops/local/AVX/avx_weightedmean_benchmarks.cpp)
set(SEQ_WEIGHTEDMEAN_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_weightedmean_benchmarks.cpp)
set(AVX_VARIANCE_BENCHMARKS_SOURCE
mathops/local/AVX/avx_variance_benchmarks.cpp)
set(AVX_SAMPLEVARIANCE_BENCHMARKS_SOURCE
mathops/local/AVX/avx_samplevariance_benchmarks.cpp)
set(AVX_VARIANCEWITHPROBABILITIES_BENCHMARKS_SOURCE
mathops/local/AVX/avx_variancewithprobabilities_benchmarks.cpp)
set(SEQ_VARIANCE_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_variance_benchmarks.cpp)
set(SEQ_SAMPLEVARIANCE_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_samplevariance_benchmarks.cpp)
set(SEQ_VARIANCEWITHPROBABILITIES_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_variancewithprobabilities_benchmarks.cpp)
set(AVX_STDDEVIATION_BENCHMARKS_SOURCE
mathops/local/AVX/avx_stddeviation_benchmarks.cpp)
set(AVX_SAMPLESTDDEVIATION_BENCHMARKS_SOURCE
mathops/local/AVX/avx_samplestddeviation_benchmarks.cpp)
set(AVX_STDDEVIATIONWITHPROBABILITIES_BENCHMARKS_SOURCE
mathops/local/AVX/avx_stddeviationwithprobabilities_benchmarks.cpp)
set(SEQ_STDDEVIATION_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_stddeviation_benchmarks.cpp)
set(SEQ_SAMPLESTDDEVIATION_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_samplestddeviation_benchmarks.cpp)
set(SEQ_STDDEVIATIONWITHPROBABILITIES_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_stddeviationwithprobabilities_benchmarks.cpp)
set(GLM_VEC4_BENCHMARKS_SOURCE
vec/glm/glm_vec4_benchmarks.cpp)
set(GLM_VEC3_BENCHMARKS_SOURCE
vec/glm/glm_vec3_benchmarks.cpp)
set(GLM_VEC2_BENCHMARKS_SOURCE
vec/glm/glm_vec2_benchmarks.cpp)
set(AVX_VEC4_BENCHMARKS_SOURCE
vec/local/AVX/avx_vec4_benchmarks.cpp)
set(AVX_VEC3_BENCHMARKS_SOURCE
vec/local/AVX/avx_vec3_benchmarks.cpp)
set(AVX_VEC2_BENCHMARKS_SOURCE
vec/local/AVX/avx_vec2_benchmarks.cpp)
set(SEQ_VEC4_BENCHMARKS_SOURCE
vec/local/SEQ/seq_vec4_benchmarks.cpp)
set(SEQ_VEC3_BENCHMARKS_SOURCE
vec/local/SEQ/seq_vec3_benchmarks.cpp)
set(SEQ_VEC2_BENCHMARKS_SOURCE
vec/local/SEQ/seq_vec2_benchmarks.cpp)
set(STD_SUM_BENCHMARKS_SOURCE
mathops/std/std_sum_benchmarks.cpp)
set(STD_PREFIXSUM_BENCHMARKS_SOURCE
mathops/std/std_prefixsum_benchmarks.cpp)
set(STD_MIN_BENCHMARKS_SOURCE
mathops/std/std_min_benchmarks.cpp)
set(STD_MAX_BENCHMARKS_SOURCE
mathops/std/std_max_benchmarks.cpp)
set(BOOST_ARITHMETICMEAN_BENCHMARKS_SOURCE
mathops/boost/boost_arithmeticmean_benchmarks.cpp)
set(BOOST_VARIANCE_BENCHMARKS_SOURCE
mathops/boost/boost_variance_benchmarks.cpp)
set(BOOST_SAMPLEVARIANCE_BENCHMARKS_SOURCE
mathops/boost/boost_samplevariance_benchmarks.cpp)
set(BOOST_MODE_BENCHMARKS_SOURCE
mathops/boost/boost_mode_benchmarks.cpp)
set(BOOST_MEDIAN_BENCHMARKS_SOURCE
mathops/boost/boost_median_benchmarks.cpp)
set(SEQ_MODE_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_mode_benchmarks.cpp)
set(SEQ_MEDIAN_BENCHMARKS_SOURCE
mathops/local/SEQ/seq_median_benchmarks.cpp)

add_executable(${ACCELERATED_SQRT_BENCHMARKS} ${ACCELERATED_SQRT_BENCHMARKS_SOURCE})
add_executable(${STD_SQRT_BENCHMARKS} ${STD_SQRT_BENCHMARKS_SOURCE})
add_executable(${ACCELERATED_GONIOMETRIC_BENCHMARKS} ${ACCELERATED_GONIOMETRIC_BENCHMARKS_SOURCE})
add_executable(${STD_GONIOMETRIC_BENCHMARKS} ${STD_GONIOMETRIC_BENCHMARKS_SOURCE})
add_executable(${AVX_SUM_BENCHMARKS} ${AVX_SUM_BENCHMARKS_SOURCE})
add_executable(${SEQ_SUM_BENCHMARKS} ${SEQ_SUM_BENCHMARKS_SOURCE})
add_executable(${AVX_PREFIXSUM_BENCHMARKS} ${AVX_PREFIXSUM_BENCHMARKS_SOURCE})
add_executable(${SEQ_PREFIXSUM_BENCHMARKS} ${SEQ_PREFIXSUM_BENCHMARKS_SOURCE})
add_executable(${AVX_SQRTARR_BENCHMARKS} ${AVX_SQRTARR_BENCHMARKS_SOURCE})
add_executable(${SEQ_SQRTARR_BENCHMARKS} ${SEQ_SQRTARR_BENCHMARKS_SOURCE})
add_executable(${AVX_INVSQRTARR_BENCHMARKS} ${AVX_INVSQRTARR_BENCHMARKS_SOURCE})
add_executable(${SEQ_INVSQRTARR_BENCHMARKS} ${SEQ_INVSQRTARR_BENCHMARKS_SOURCE})
add_executable(${AVX_SINARR_BENCHMARKS} ${AVX_SINARR_BENCHMARKS_SOURCE})
add_executable(${SEQ_SINARR_BENCHMARKS} ${SEQ_SINARR_BENCHMARKS_SOURCE})
add_executable(${AVX_COSARR_BENCHMARKS} ${AVX_COSARR_BENCHMARKS_SOURCE})
add_executable(${SEQ_COSARR_BENCHMARKS} ${SEQ_COSARR_BENCHMARKS_SOURCE})
add_executable(${AVX_MIN_BENCHMARKS} ${AVX_MIN_BENCHMARKS_SOURCE})
add_executable(${SEQ_MIN_BENCHMARKS} ${SEQ_MIN_BENCHMARKS_SOURCE})
add_executable(${AVX_MAX_BENCHMARKS} ${AVX_MAX_BENCHMARKS_SOURCE})
add_executable(${SEQ_MAX_BENCHMARKS} ${SEQ_MAX_BENCHMARKS_SOURCE})
add_executable(${AVX_ARITHMETICMEAN_BENCHMARKS} ${AVX_ARITHMETICMEAN_BENCHMARKS_SOURCE})
add_executable(${SEQ_ARITHMETICMEAN_BENCHMARKS} ${SEQ_ARITHMETICMEAN_BENCHMARKS_SOURCE})
add_executable(${AVX_GEOMETRICMEAN_BENCHMARKS} ${AVX_GEOMETRICMEAN_BENCHMARKS_SOURCE})
add_executable(${SEQ_GEOMETRICMEAN_BENCHMARKS} ${SEQ_GEOMETRICMEAN_BENCHMARKS_SOURCE})
add_executable(${AVX_WEIGHTEDMEAN_BENCHMARKS} ${AVX_WEIGHTEDMEAN_BENCHMARKS_SOURCE})
add_executable(${SEQ_WEIGHTEDMEAN_BENCHMARKS} ${SEQ_WEIGHTEDMEAN_BENCHMARKS_SOURCE})
add_executable(${AVX_VARIANCE_BENCHMARKS} ${AVX_VARIANCE_BENCHMARKS_SOURCE})
add_executable(${AVX_SAMPLEVARIANCE_BENCHMARKS} ${AVX_SAMPLEVARIANCE_BENCHMARKS_SOURCE})
add_executable(${AVX_VARIANCEWITHPROBABILITIES_BENCHMARKS} ${AVX_VARIANCEWITHPROBABILITIES_BENCHMARKS_SOURCE})
add_executable(${SEQ_VARIANCE_BENCHMARKS} ${SEQ_VARIANCE_BENCHMARKS_SOURCE})
add_executable(${SEQ_SAMPLEVARIANCE_BENCHMARKS} ${SEQ_SAMPLEVARIANCE_BENCHMARKS_SOURCE})
add_executable(${SEQ_VARIANCEWITHPROBABILITIES_BENCHMARKS} ${SEQ_VARIANCEWITHPROBABILITIES_BENCHMARKS_SOURCE})
add_executable(${AVX_STDDEVIATION_BENCHMARKS} ${AVX_STDDEVIATION_BENCHMARKS_SOURCE})
add_executable(${AVX_SAMPLESTDDEVIATION_BENCHMARKS} ${AVX_SAMPLESTDDEVIATION_BENCHMARKS_SOURCE})
add_executable(${AVX_STDDEVIATIONWITHPROBABILITIES_BENCHMARKS} ${AVX_STDDEVIATIONWITHPROBABILITIES_BENCHMARKS_SOURCE})
add_executable(${SEQ_STDDEVIATION_BENCHMARKS} ${SEQ_STDDEVIATION_BENCHMARKS_SOURCE})
add_executable(${SEQ_SAMPLESTDDEVIATION_BENCHMARKS} ${SEQ_SAMPLESTDDEVIATION_BENCHMARKS_SOURCE})
add_executable(${SEQ_STDDEVIATIONWITHPROBABILITIES_BENCHMARKS} ${SEQ_STDDEVIATIONWITHPROBABILITIES_BENCHMARKS_SOURCE})
add_executable(${GLM_VEC4_BENCHMARKS} ${GLM_VEC4_BENCHMARKS_SOURCE})
add_executable(${GLM_VEC3_BENCHMARKS} ${GLM_VEC3_BENCHMARKS_SOURCE})
add_executable(${GLM_VEC2_BENCHMARKS} ${GLM_VEC2_BENCHMARKS_SOURCE})
add_executable(${AVX_VEC4_BENCHMARKS} ${AVX_VEC4_BENCHMARKS_SOURCE})
add_executable(${AVX_VEC3_BENCHMARKS} ${AVX_VEC3_BENCHMARKS_SOURCE})
add_executable(${AVX_VEC2_BENCHMARKS} ${AVX_VEC2_BENCHMARKS_SOURCE})
add_executable(${SEQ_VEC4_BENCHMARKS} ${SEQ_VEC4_BENCHMARKS_SOURCE})
add_executable(${SEQ_VEC3_BENCHMARKS} ${SEQ_VEC3_BENCHMARKS_SOURCE})
add_executable(${SEQ_VEC2_BENCHMARKS} ${SEQ_VEC2_BENCHMARKS_SOURCE})
add_executable(${STD_SUM_BENCHMARKS} ${STD_SUM_BENCHMARKS_SOURCE})
add_executable(${STD_PREFIXSUM_BENCHMARKS} ${STD_PREFIXSUM_BENCHMARKS_SOURCE})
add_executable(${STD_MIN_BENCHMARKS} ${STD_MIN_BENCHMARKS_SOURCE})
add_executable(${STD_MAX_BENCHMARKS} ${STD_MAX_BENCHMARKS_SOURCE})
add_executable(${BOOST_ARITHMETICMEAN_BENCHMARKS} ${BOOST_ARITHMETICMEAN_BENCHMARKS_SOURCE})
add_executable(${BOOST_VARIANCE_BENCHMARKS} ${BOOST_VARIANCE_BENCHMARKS_SOURCE})
add_executable(${BOOST_SAMPLEVARIANCE_BENCHMARKS} ${BOOST_SAMPLEVARIANCE_BENCHMARKS_SOURCE})
add_executable(${BOOST_MODE_BENCHMARKS} ${BOOST_MODE_BENCHMARKS_SOURCE})
add_executable(${BOOST_MEDIAN_BENCHMARKS} ${BOOST_MEDIAN_BENCHMARKS_SOURCE})
add_executable(${SEQ_MODE_BENCHMARKS} ${SEQ_MODE_BENCHMARKS_SOURCE})
add_executable(${SEQ_MEDIAN_BENCHMARKS} ${SEQ_MEDIAN_BENCHMARKS_SOURCE})

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

    target_compile_options(${BENCHMARK} PRIVATE -O3)
endforeach()

set(GLM_LIB glm-header-only)

target_link_libraries(${GLM_VEC4_BENCHMARKS} PRIVATE glm-header-only)
target_link_libraries(${GLM_VEC3_BENCHMARKS} PRIVATE glm-header-only)
target_link_libraries(${GLM_VEC2_BENCHMARKS} PRIVATE glm-header-only)

target_link_libraries(${BOOST_ARITHMETICMEAN_BENCHMARKS} PRIVATE boost_math)
target_link_libraries(${BOOST_VARIANCE_BENCHMARKS} PRIVATE boost_math)
target_link_libraries(${BOOST_SAMPLEVARIANCE_BENCHMARKS} PRIVATE boost_math)
target_link_libraries(${BOOST_MODE_BENCHMARKS} PRIVATE boost_math)
target_link_libraries(${BOOST_MEDIAN_BENCHMARKS} PRIVATE boost_math)