cmake_minimum_required(VERSION 3.0.2)

project(math_lib)

include(CheckCXXSourceRuns)

function(check_runtime_program PROGRAM_NAME RESULT_VAR)
    try_run(${RESULT_VAR} RUN_RESULT
            ${CMAKE_BINARY_DIR}/CMakeTmp
            ${CMAKE_CURRENT_SOURCE_DIR}/runtimechecks/${PROGRAM_NAME}.cpp)
    if (NOT RUN_RESULT)
        set(${RESULT_VAR} FALSE)
    endif()
endfunction()

message("-- Checking for SIMD units")

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