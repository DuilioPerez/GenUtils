# Add the include directory for all the targets.
include_directories(include)
# Add the linke directory.
link_directories("${CMAKE_CURRENT_BINARY_DIR}/lib")
# Add the library.
add_subdirectory(lib)
# Build the test programs.
if(GENUTILS_BUILD_TESTS)
  add_subdirectory(tests)
endif()
