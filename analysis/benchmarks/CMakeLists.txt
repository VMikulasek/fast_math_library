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

set(CMAKE_BUILD_TYPE Release)

set(AVX_BENCHMARKS_SOURCE
mathops/AVX/avx_sums_benchmarks.cpp)
set(SEQ_BENCHMARKS_SOURCE
mathops/SEQ/seq_sums_benchmarks.cpp)

add_executable(${AVX_BENCHMARKS} ${AVX_BENCHMARKS_SOURCE})
add_executable(${SEQ_BENCHMARKS} ${SEQ_BENCHMARKS_SOURCE})

foreach(BENCHMARK ${BENCHMARKS})
    target_compile_options(${BENCHMARK} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-O0>
    $<$<CXX_COMPILER_ID:MSVC>:/Od>)

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