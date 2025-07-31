cmake_minimum_required(VERSION 3.20)

project(
  cssparser
  VERSION 1.0
  LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SRCFILES "src/*.cpp")
file(GLOB_RECURSE HEADERFILES "src/*.cpp")

add_library(cssparser SHARED ${SRCFILES})

target_include_directories(
  cssparser PUBLIC $<INSTALL_INTERFACE:include>
                   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

include(GNUInstallDirs)

configure_file(cssparser.pc.in cssparser.pc @ONLY)

install(
  TARGETS cssparser
  EXPORT cssparser-targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cssparser)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cssparser.pc
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
