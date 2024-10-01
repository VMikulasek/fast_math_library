include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY ${GOOGLETEST_REPO}
    GIT_TAG        ${GOOGLETEST_GITTAG}
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TESTS_SOURCES
tests_common.cpp
simd/simd_avx_float_tests.cpp
simd/simd_avx2_int_tests.cpp
mathops/AVX/avx_sums_tests.cpp
mathops/SEQ/seq_sums_tests.cpp
mathops/transcedentals_tests.cpp
mathops/SEQ/seq_transcedentals_tests.cpp)

add_executable(${TESTS_NAME} ${TESTS_SOURCES})

target_link_libraries(
    ${TESTS_NAME}
    PRIVATE ${PROJECT_NAME}
    PRIVATE GTest::gtest_main
)

target_include_directories(
    ${TESTS_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

include(GoogleTest)

gtest_discover_tests(${TESTS_NAME})