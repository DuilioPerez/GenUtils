# Set up CMake.
cmake_minimum_required(VERSION 3.12)
project(GenUtils VERSION 1.0.0.0 LANGUAGES C)
# Option to build the test.
option(GENUTILS_BUILD_TESTS "Build the tests programs" OFF)
# Add the source files.
add_subdirectory(src)
