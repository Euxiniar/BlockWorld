﻿# Specify the minimum CMAKE version required
cmake_minimum_required(VERSION 2.8)

# Your project's name
project(BlockWorld)

# Make your header file accessible to the compiler
include_directories(include)

# Add all files from the source/ folder to CMake
file(GLOB_RECURSE SRC
    "src/*.cpp"
    "src/*.h"
    "src/*.hpp"
)

# Define the executable
add_executable(${PROJECT_NAME} ${SRC})

include_directories(deps/SFML/include)
add_definitions(-DSFML_STATIC)
include_directories(deps/glm/glm)
include_directories(deps/glew/include)
add_definitions(-DGLEW_STATIC)

if(MSVC)
  set(CMAKE_EXE_LINKER_FLAGS
      "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:LIBCMT")
endif()

enable_testing()

set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(deps/SFML)
add_subdirectory(deps/glew)

# Copy static files
# Tired of manually copying it
file(COPY Data/ DESTINATION Debug/Data/)

target_link_libraries(${PROJECT_NAME} sfml-network sfml-graphics sfml-window sfml-system sfml-audio ../../glew32s)

# Enable C++ 14
if (NOT UNIX)
	set_target_properties(${PROJECT_NAME} PROPERTIES
	    CXX_STANDARD 14
	    CXX_STANDARD_REQUIRED ON
	    CXX_EXTENSIONS OFF
	)
else()
	add_definitions(-std=c++14)
endif()
