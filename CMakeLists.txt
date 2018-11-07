cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(cpp_algs)

set(CMAKE_BUILD_TYPE Debug)

set(cpp_algs_VERSION_MAJOR 2)
set(cpp_algs_VERSION_MINOR 0)
set(cpp_algs_VERSION_PATCH 1)

set(CMAKE_CXX_STANDARD 11)

configure_file(
    "${PROJECT_SOURCE_DIR}/cpp_algs/config.hpp.in"
    "${PROJECT_SOURCE_DIR}/cpp_algs/config.hpp"
)

# need to write implementation in headers itself 
# since this project relies heavily on template 
# classes and compiler needs to see interface along
# with implementation at the same time for templated fxns

file(GLOB_RECURSE SOURCES "cpp_algs/*.hpp")
add_library(cpp_algs SHARED ${SOURCES})

set_target_properties(cpp_algs PROPERTIES LINKER_LANGUAGE CXX)
    
install(TARGETS cpp_algs  DESTINATION /usr/lib)