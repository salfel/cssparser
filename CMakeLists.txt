cmake_minimum_required(VERSION 3.20)

project(
  cssparser
  VERSION 1.0
  LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)
pkg_check_modules(deps REQUIRED IMPORTED_TARGET)

file(GLOB_RECURSE SRCFILES "src/*.cpp")

add_executable(cssparser ${SRCFILES})
target_include_directories(cssparser PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(cssparser PRIVATE PkgConfig::deps)
target_include_directories(cssparser PRIVATE include)

install(TARGETS cssparser)
