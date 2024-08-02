include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        ff233bdd4cac0a0bf6e5cd45bda3406814cb2796 # version 1.15.2
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TESTS_NAME math_lib_tests)
set(TESTS_SOURCES test.cpp)

add_executable(${TESTS_NAME} ${TESTS_SOURCES})

target_link_libraries(
    ${TESTS_NAME}
    PRIVATE ${PROJECT_NAME}
    PRIVATE GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(${TESTS_NAME})