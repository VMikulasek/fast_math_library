cmake_minimum_required(VERSION 3.0.2)

project(math_lib)

option(BUILD_INSTALL "Generate install target" OFF)

add_subdirectory(include)

if (BUILD_INSTALL)
    install(TARGETS math_lib EXPORT math_lib)
    install(
		    DIRECTORY include/
		    DESTINATION "include"
		    PATTERN "CMakeLists.txt" EXCLUDE
	    )
endif()