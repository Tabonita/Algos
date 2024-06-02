cmake_minimum_required(VERSION 3.23)

project(
  Algos
  VERSION 0.0.0
  DESCRIPTION "An implementation of various algorithms in C++ for training purposes."
  HOMEPAGE_URL https://github.com/threeal/cpp-starter
  LANGUAGES CXX
)

# Append the module path.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Enable warning checks if testing is enabled.
find_package(CheckWarning REQUIRED)
include(CheckWarning)
add_check_warning()

find_package(argparse REQUIRED)

add_library(algos
  src/bubble_sort.cpp
)
target_sources(
  algos PUBLIC
  FILE_SET HEADERS
  BASE_DIRS include
  FILES
    include/bubble/bubble_sort.hpp
)
target_compile_features(algos PRIVATE cxx_std_17)

add_executable(main src/main.cpp)
target_link_libraries(main PUBLIC argparse::argparse algos)

enable_testing()

find_package(Catch2 REQUIRED)

add_library(algos_test_lib OBJECT
  test/bubble_test.cpp
)
target_link_libraries(algos_test_lib PUBLIC algos Catch2::Catch2)

add_executable(algos_test)
target_link_libraries(algos_test PRIVATE algos_test_lib Catch2::Catch2WithMain)

include(CheckCoverage)
# target_check_coverage(sequence_test)

include(Catch)
catch_discover_tests(algos_test)

# Enable automatic formatting if it is not a subproject and testing is enabled.
find_package(FixFormat REQUIRED)
include(FixFormat)
# add_fix_format()
