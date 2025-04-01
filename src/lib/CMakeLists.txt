include(GNUInstallDirs)
# Set the source files of the library.
file(GLOB UtilsSourceFileList CONFIGURE_DEPENDS "Utils/*.c")
# Set the header files of the library.
file(GLOB UtilsHeaderFileList CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_LIST_DIR}/../include/Utils/*.h")
# Add the object libraries.
add_library(Utils-Objects OBJECT "${UtilsSourceFileList}")
# Add the static library.
add_library(Utils-Static STATIC $<TARGET_OBJECTS:Utils-Objects>)
set_target_properties(Utils-Static PROPERTIES OUTPUT_NAME Utils)
# Add the shared library.
add_library(Utils-Shared SHARED $<TARGET_OBJECTS:Utils-Objects>)
set_target_properties(
  Utils-Shared
  PROPERTIES OUTPUT_NAME Utils
             VERSION 1.0.0
             SOVERSION 1
             PUBLIC_HEADER "${UtilsHeaderFileList}")
# Install the libraries.
install(TARGETS Utils-Static Utils-Shared
  EXPORT UtilsConfig
  RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Utils/
)
# Properties of the cmake project configure file.
export(TARGETS Utils-Shared Utils-Static
  NAMESPACE Utils::
  FILE "${CMAKE_CURRENT_BINARY_DIR}/UtilsConfig.cmake"
)
# Install the configuration file of this project.
install(EXPORT UtilsConfig
  DESTINATION "${CMAKE_INSTALL_DATADIR}/UtilsConfig/cmake"
  NAMESPACE Utils::
)
