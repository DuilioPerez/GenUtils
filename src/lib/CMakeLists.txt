# Set the source files of the library.
file(GLOB UtilsFileList CONFIGURE_DEPENDS "Utils/*.c")
# Add the object libraries.
add_library(UtilsObj OBJECT "${UtilsFileList}")
# Add the static library.
add_library(UtilsStatic STATIC $<TARGET_OBJECTS:UtilsObj>)
set_target_properties(UtilsStatic PROPERTIES OUTPUT_NAME Utils)
# Add the shared library.
add_library(UtilsShared SHARED $<TARGET_OBJECTS:UtilsObj>)
set_target_properties(
  UtilsShared
  PROPERTIES OUTPUT_NAME Utils
             VERSION 1.0.0
             SOVERSION 1)
