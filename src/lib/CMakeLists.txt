include(GNUInstallDirs)
# Set the source files of the library.
file(GLOB GENUTILS_SOURCE_CODE_FILE_LIST CONFIGURE_DEPENDS "GenUtils/*.c")
# Set the header files of the library.
file(GLOB GENUTILS_HEADERS_FILE_LIST CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_LIST_DIR}/../include/GenUtils/*.h")
# Add the static library.
add_library(GenUtils-Static STATIC ${GENUTILS_SOURCE_CODE_FILE_LIST})
# Add the shared library.
add_library(GenUtils-Shared SHARED ${GENUTILS_SOURCE_CODE_FILE_LIST})
# Set the properties of the static library.
set_target_properties(GenUtils-Static PROPERTIES OUTPUT_NAME genutils)
# Set the properties of the shared library.
set_target_properties(
  GenUtils-Shared
  PROPERTIES OUTPUT_NAME genutils
             VERSION 1.0.0
             SOVERSION 1
             PUBLIC_HEADER "${GENUTILS_HEADERS_FILE_LIST}")
# Install the libraries.
install(TARGETS GenUtils-Static GenUtils-Shared
  EXPORT GenUtilsConfig
  RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/GenUtils/
)
# Properties of the cmake project configure file.
export(TARGETS GenUtils-Shared GenUtils-Static
  NAMESPACE GenUtils::
  FILE "${CMAKE_CURRENT_BINARY_DIR}/GenUtilsConfig.cmake"
)
# Install the configuration file of this project.
install(EXPORT GenUtilsConfig
  DESTINATION "${CMAKE_INSTALL_DATADIR}/GenUtilsConfig/cmake"
  NAMESPACE GenUtils::
)
