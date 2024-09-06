option(BUILD_TESTS "Build tests for math_lib")
option(BUILD_BENCHRMARKS "Build benchmarks for math_lib")

if (CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    set(BUILD_TESTS ON)
    set(BUILD_BENCHRMARKS ON)
else()
    set(BUILD_TESTS OFF)
    set(BUILD_BENCHRMARKS OFF)
endif()

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

if (BUILD_BENCHRMARKS)
    set(BENCHMARKS_NAME math_lib_benchmarks)
    add_subdirectory(benchmarks)
    target_include_directories(
        ${BENCHMARKS_NAME}
        PRIVATE ${GLOBAL_FIXTURES_DIRECTORY}
    )
endif()