include(GNUInstallDirs)
# Set the source files of the library.
file(GLOB UtilsFileList CONFIGURE_DEPENDS "Utils/*.c")
# Set the header files of the library.
file(GLOB UtilsHeaderFiles CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_LIST_DIR}/../include/Utils/*.h")
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
             SOVERSION 1
             PUBLIC_HEADER "${UtilsHeaderFiles}")
# Install the libraries.
install(TARGETS UtilsStatic UtilsShared
  RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Utils/
)
