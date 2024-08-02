add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>")

if (AVX_SUPPORTED)
	message("AVX supported")
	list(APPEND MATH_LIB_DEFINITIONS HAS_AVX=1)
    list(APPEND MATH_LIB_OPTIONS -mavx)
else ()
	message("AVX not supported")
endif()

if (AVX2_SUPPORTED)
	message("AVX2 supported")
    list(APPEND MATH_LIB_DEFINITIONS HAS_AVX2=1)
    list(APPEND MATH_LIB_OPTIONS -mavx2)
else ()
	message("AVX2 not supported")
endif()

if (AVX512_SUPPORTED)
	message("AVX512F supported")
    list(APPEND MATH_LIB_DEFINITIONS HAS_AVX512F=1)
    list(APPEND MATH_LIB_OPTIONS -mavx512f)
else ()
	message("AVX512F not supported")
endif()

target_compile_definitions(${PROJECT_NAME} INTERFACE ${MATH_LIB_DEFINITIONS})
target_compile_options(${PROJECT_NAME} INTERFACE ${MATH_LIB_OPTIONS})
