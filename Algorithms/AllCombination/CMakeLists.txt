cmake_minimum_required(VERSION 2.6)
project(tests)

################################
# GTest
################################
#### PLEASE CHANGE PATH TOU YOUR GTEST DIRECTORY ####
ADD_SUBDIRECTORY (C:/Users/Iorwet/Documents/repoGit/C++/Algorithms/googletest gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 20)

################################
# Unit Tests
################################
# Add test cpp file
add_executable( unit_test All_Combination.cpp )
# Link test executable against gtest & gtest_main
target_link_libraries(unit_test gtest gtest_main)
add_test( unit_test unit_test )
