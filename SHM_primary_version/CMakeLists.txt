cmake_minimum_required(VERSION 3.17)

#set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe" CACHE PATH "" FORCE)
#set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe" CACHE PATH "" FORCE)
SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")

project(SHM)

set(CMAKE_CXX_STANDARD 20)

include_directories("includes/")
file(GLOB SOURCES "sources/*.cc")

add_subdirectory(tests)
add_subdirectory(googletest)

add_executable(SHM_GAME ${SOURCES})

# Create libary for tests
add_library(SHM STATIC ${SOURCES})