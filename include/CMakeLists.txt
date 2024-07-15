file(GLOB SIMD_INCLUDE ./simd/*.hpp)
file(GLOB SRC_SIMD_OPERATIONS ../src/simd/operations/*)
file(GLOB SRC_SIMD_VECTOR ../src/simd/vector/*)

add_library(math_lib INTERFACE)
target_include_directories(math_lib INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")