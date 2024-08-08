cmake_minimum_required(VERSION 3.14)

project(math_lib)

option(BUILD_INSTALL "Generate install target" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CheckCXXSourceRuns)

function(check_runtime_program PROGRAM_NAME RESULT_VAR)
    try_run(${RESULT_VAR} COMPILE_RESULT
            ${CMAKE_BINARY_DIR}/CMakeTmp
            ${CMAKE_CURRENT_SOURCE_DIR}/runtimechecks/${PROGRAM_NAME}.cpp)
    if (NOT COMPILE_RESULT)
        message(FATAL_ERROR "compilation failed")
        set(${RESULT_VAR} FALSE)
    endif()
endfunction()

message(STATUS "Checking for SIMD units")

check_runtime_program(check_avx_support AVX_SUPPORTED)
check_runtime_program(check_avx2_support AVX2_SUPPORTED)
check_runtime_program(check_avx512_support AVX512_SUPPORTED)

add_subdirectory(include)

if (BUILD_INSTALL)
    install(TARGETS math_lib EXPORT math_lib)
    install(
		    DIRECTORY include/
		    DESTINATION "include"
		    PATTERN "CMakeLists.txt" EXCLUDE
	    )
endif()

option(BUILD_TESTS "Build tests for math_lib")

if (CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    set(BUILD_TESTS ON)
else()
    set(BUILD_TESTS OFF)
endif()

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()