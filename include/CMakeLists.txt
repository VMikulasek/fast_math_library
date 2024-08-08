add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>")

set(SIMD_INCLUDE
simd/simd_common.hpp
simd/simd_operations.hpp
simd/simd_operations_avx.hpp
simd/simd_vector.hpp
simd/simd_vector_avx.hpp)

set(SIMD_OPERATIONS
simd/detail/operations/simd_operations_avx_float.hpp
simd/detail/operations/simd_operations_avx_float.inl
simd/detail/operations/simd_operations_base.hpp)

set(SIMD_VECTOR
simd/detail/vector/simd_vector_avx_float.hpp
simd/detail/vector/simd_vector_avx_float.inl
simd/detail/vector/simd_vector_base.hpp)

set(INCLUDE_CMAKELISTS
CMakeLists.txt)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/simd PREFIX "SIMD include" FILES ${SIMD_INCLUDE})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/simd/detail/operations PREFIX "SIMD operations" FILES ${SIMD_OPERATIONS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/simd/detail/vector PREFIX "SIMD vector" FILES ${SIMD_VECTOR})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Include CMake" FILES ${INCLUDE_CMAKELISTS})

add_custom_target(LIB_SOURCE SOURCES ${SIMD_INCLUDE} ${SIMD_OPERATIONS} ${SIMD_VECTOR} ${INCLUDE_CMAKELISTS})

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
