add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>")

set(INCLUDE_CMAKELISTS
CMakeLists.txt)	
	
set(SIMD_INCLUDE
simd/simd_common.hpp
simd/simd_operations.hpp
simd/simd_operations_avx.hpp)

set(MATHOPS_INCLUDE
mathops/sums.hpp)

set(SIMD_OPERATIONS
simd/detail/operations/simd_operations_avx_float.hpp
simd/detail/operations/simd_operations_avx_float.inl
simd/detail/operations/simd_operations_base.hpp)

set(MATHOPS_DETAIL
mathops/detail/sums.inl)

set(MATHOPS_AVX
mathops/detail/AVX/avx_sums.hpp
mathops/detail/AVX/avx_sums.inl)

set(MATHOPS_SEQ
mathops/detail/SEQ/seq_sums.hpp
mathops/detail/SEQ/seq_sums.inl)


source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Include CMake" FILES ${INCLUDE_CMAKELISTS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/simd PREFIX "SIMD include" FILES ${SIMD_INCLUDE})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/mathops PREFIX "Math include" FILES ${MATHOPS_INCLUDE})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/simd/detail/operations PREFIX "SIMD operations" FILES ${SIMD_OPERATIONS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/simd/detail/vector PREFIX "SIMD vector" FILES ${SIMD_VECTOR})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/mathops/detail PREFIX "Math detail" FILES ${MATHOPS_DETAIL})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/mathops/detail/AVX PREFIX "Math AVX" FILES ${MATHOPS_AVX})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/mathops/detail/SEQ PREFIX "Math SEQ" FILES ${MATHOPS_SEQ})

add_custom_target(LIB_SOURCE SOURCES ${SIMD_INCLUDE} ${SIMD_OPERATIONS} ${SIMD_VECTOR} ${INCLUDE_CMAKELISTS})

if (AVX_SUPPORTED)
	message(STATUS "AVX supported")
	list(APPEND MATH_LIB_DEFINITIONS HAS_AVX=1)

	if ((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		list(APPEND MATH_LIB_OPTIONS -mavx)
	elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		list(APPEND MATH_LIB_OPTIONS /arch:AVX)
	endif ()
else ()
	message(STATUS "AVX not supported")
endif()

if (AVX2_SUPPORTED)
	message(STATUS "AVX2 supported")
    list(APPEND MATH_LIB_DEFINITIONS HAS_AVX2=1)
    
	if ((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		list(APPEND MATH_LIB_OPTIONS -mavx2)
	elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		list(APPEND MATH_LIB_OPTIONS /arch:AVX2)
	endif ()
else ()
	message(STATUS "AVX2 not supported")
endif()

if (AVX512_SUPPORTED)
	message(STATUS "AVX512F supported")
    list(APPEND MATH_LIB_DEFINITIONS HAS_AVX512F=1)

	if ((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		list(APPEND MATH_LIB_OPTIONS -mavx512f)
	elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		list(APPEND MATH_LIB_OPTIONS /arch:AVX512)
	endif ()
else ()
	message(STATUS "AVX512F not supported")
endif()

target_compile_definitions(${PROJECT_NAME} INTERFACE ${MATH_LIB_DEFINITIONS})
target_compile_options(${PROJECT_NAME} INTERFACE ${MATH_LIB_OPTIONS})
