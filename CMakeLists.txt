############################################################
#           Cmake Build of NavTypes Unit Testing           #
############################################################

# Project Setup
cmake_minimum_required(VERSION 3.22.0)
project(navtypes_test)
set(CMAKE_CXX_STANDARD 11)

# Define Variables
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# Google Test Dependencies
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Add Header List
set(HEADER_LIST ${PROJECT_SOURCE_DIR}/include/Quaternion.hpp)

# Unit Testing Build
enable_testing()
add_executable( test_navtypes ${PROJECT_SOURCE_DIR}/test/testMain.cpp 
	                      ${PROJECT_SOURCE_DIR}/test/QuaternionTest.cpp ${HEADER_LIST})
target_link_libraries(
  test_navtypes
  GTest::gtest_main
)

# Target Include Directories
target_include_directories(test_navtypes PUBLIC ${PROJECT_SOURCE_DIR}/include)

include(GoogleTest)
gtest_discover_tests(test_navtypes)
