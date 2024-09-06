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

set(BENCHMARKS_SOURCES
mathops/AVX/avx_sums_benchmarks.cpp
mathops/SEQ/seq_sums_benchmarks.cpp)

add_executable(${BENCHMARKS_NAME} ${BENCHMARKS_SOURCES})

target_link_libraries(
    ${BENCHMARKS_NAME}
    PRIVATE ${PROJECT_NAME}
    PRIVATE benchmark::benchmark
    PRIVATE benchmark::benchmark_main)

target_include_directories(
    ${BENCHMARKS_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)