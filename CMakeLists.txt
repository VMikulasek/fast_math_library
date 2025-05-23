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

check_runtime_program(check_sse_support SSE_SUPPORTED)
check_runtime_program(check_sse2_support SSE2_SUPPORTED)
check_runtime_program(check_sse3_support SSE3_SUPPORTED)
check_runtime_program(check_sse41_support SSE41_SUPPORTED)
check_runtime_program(check_sse42_support SSE42_SUPPORTED)
check_runtime_program(check_avx_support AVX_SUPPORTED)
check_runtime_program(check_avx2_support AVX2_SUPPORTED)
check_runtime_program(check_avx512_support AVX512_SUPPORTED)

add_subdirectory(include)

if (BUILD_INSTALL)
    install(
		    DIRECTORY include/
		    DESTINATION "include"
		    PATTERN "CMakeLists.txt" EXCLUDE
	    )
endif()

add_subdirectory(analysis)