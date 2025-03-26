add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>")

set(INCLUDE_CMAKELISTS
CMakeLists.txt)	
	
set(SIMD_INCLUDE
simd/simd_common.hpp
simd/simd_operations.hpp
simd/simd_operations_avx.hpp
simd/simd_operations_avx2.hpp
simd/simd_vec.hpp)

set(MATHOPS_INCLUDE
mathops/sums.hpp
mathops/transcedentals.hpp
mathops/statisticals.hpp)

set(SIMD_OPERATIONS
simd/detail/operations/simd_operations_avx_float.hpp
simd/detail/operations/simd_operations_avx_float.inl
simd/detail/operations/simd_operations_avx2_int.hpp
simd/detail/operations/simd_operations_avx2_int.inl
simd/detail/operations/simd_operations_base.hpp)

set(SIMD_VECTOR_DETAIL
simd/detail/vec/simd_vec_t.hpp
simd/detail/vec/simd_vec_t.inl
simd/detail/vec/simd_vec2.hpp
simd/detail/vec/simd_vec2.inl
simd/detail/vec/simd_vec3.hpp
simd/detail/vec/simd_vec3.inl
simd/detail/vec/simd_vec4.hpp
simd/detail/vec/simd_vec4.inl)

set(SIMD_VECTOR_DETAIL_SEQ
simd/detail/vec/SEQ/simd_vec_seq.hpp
simd/detail/vec/SEQ/simd_vec_seq.inl)

set(SIMD_VECTOR_DETAIL_VEC
simd/detail/vec/VEC/simd_vec_vec.hpp
simd/detail/vec/VEC/simd_vec_vec.inl
simd/detail/vec/VEC/simd_vec2_vec.hpp
simd/detail/vec/VEC/simd_vec2_vec.inl
simd/detail/vec/VEC/simd_vec3_vec.hpp
simd/detail/vec/VEC/simd_vec3_vec.inl
simd/detail/vec/VEC/simd_vec4_vec.hpp
simd/detail/vec/VEC/simd_vec4_vec.inl)

set(MATHOPS_DETAIL
mathops/detail/sums.inl
mathops/detail/transcedentals.inl
mathops/detail/statisticals.inl)

set(MATHOPS_VEC
mathops/detail/VEC/avx_sums.hpp
mathops/detail/VEC/avx_sums.inl
mathops/detail/VEC/avx_transcedentals.hpp
mathops/detail/VEC/avx_transcedentals.inl
mathops/detail/VEC/vec_statisticals.hpp
mathops/detail/VEC/vec_statisticals.inl)

set(MATHOPS_SEQ
mathops/detail/SEQ/seq_sums.hpp
mathops/detail/SEQ/seq_sums.inl
mathops/detail/SEQ/seq_transcedentals.hpp
mathops/detail/SEQ/seq_transcedentals.inl
mathops/detail/SEQ/seq_statisticals.hpp
mathops/detail/SEQ/seq_statisticals.inl)

set(COMMON_DETAIL
common/detail/memory_common.inl)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Include CMake" FILES ${INCLUDE_CMAKELISTS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/simd PREFIX "SIMD include" FILES ${SIMD_INCLUDE})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/mathops PREFIX "Math include" FILES ${MATHOPS_INCLUDE})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/simd/detail/operations PREFIX "SIMD operations" FILES ${SIMD_OPERATIONS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/simd/detail/vec PREFIX "SIMD vector detail" FILES ${SIMD_VECTOR_DETAIL})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/mathops/detail PREFIX "Math detail" FILES ${MATHOPS_DETAIL})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/mathops/detail/VEC PREFIX "Math VEC" FILES ${MATHOPS_VEC})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/mathops/detail/SEQ PREFIX "Math SEQ" FILES ${MATHOPS_SEQ})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/common/detail PREFIX "Common detail" FILES ${COMMON_DETAIL})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/simd/detail/vec/SEQ PREFIX "SIMD vector detail seq" FILES ${SIMD_VECTOR_DETAIL_SEQ})

add_custom_target(LIB_SOURCE SOURCES
${SIMD_INCLUDE}
${SIMD_OPERATIONS}
${SIMD_VECTOR_DETAIL}
${INCLUDE_CMAKELISTS}
${MATHOPS_INCLUDE}
${MATHOPS_DETAIL}
${MATHOPS_VEC}
${MATHOPS_SEQ}
${COMMON_DETAIL}
${SIMD_VECTOR_DETAIL_SEQ}
${SIMD_VECTOR_DETAIL_VEC})

if (SSE_SUPPORTED)
	message(STATUS "SSE supported")
	list(APPEND MATH_LIB_DEFINITIONS HAS_SSE=1)

	if ((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		list(APPEND MATH_LIB_OPTIONS -msse)
	endif ()
else ()
	message(STATUS "SSE not supported")
endif()

if (SSE2_SUPPORTED)
	message(STATUS "SSE2 supported")
	list(APPEND MATH_LIB_DEFINITIONS HAS_SSE2=1)

	if ((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		list(APPEND MATH_LIB_OPTIONS -msse2)
	elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		list(APPEND MATH_LIB_OPTIONS /arch:SSE2)
	endif ()
else ()
	message(STATUS "SSE2 not supported")
endif()

if (SSE3_SUPPORTED)
	message(STATUS "SSE3 supported")
	list(APPEND MATH_LIB_DEFINITIONS HAS_SSE3=1)

	if ((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		list(APPEND MATH_LIB_OPTIONS -msse3)
	elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		list(APPEND MATH_LIB_OPTIONS /arch:SSE2)
	endif ()
else ()
	message(STATUS "SSE3 not supported")
endif()

if (SSE41_SUPPORTED)
	message(STATUS "SSE4.1 supported")
	list(APPEND MATH_LIB_DEFINITIONS HAS_SSE41=1)

	if ((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		list(APPEND MATH_LIB_OPTIONS -msse4.1)
	elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		list(APPEND MATH_LIB_OPTIONS /arch:SSE2)
	endif ()
else ()
	message(STATUS "SSE4.1 not supported")
endif()

if (SSE42_SUPPORTED)
	message(STATUS "SSE4.2 supported")
	list(APPEND MATH_LIB_DEFINITIONS HAS_SSE42=1)

	if ((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		list(APPEND MATH_LIB_OPTIONS -msse4.2)
	elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		list(APPEND MATH_LIB_OPTIONS /arch:SSE2)
	endif ()
else ()
	message(STATUS "SSE4.2 not supported")
endif()

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
