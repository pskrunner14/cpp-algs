cmake_minimum_required(VERSION 3.0)

project (cpp_algs)

set (CMAKE_BUILD_TYPE Debug)

set (cpp_algs_VERSION_MAJOR 1)
set (cpp_algs_VERSION_MINOR 0)
set (cpp_algs_VERSION_PATCH 1)

set (CMAKE_CXX_STANDARD 11)

configure_file (
    "${PROJECT_SOURCE_DIR}/config.hpp.in"
    "${PROJECT_SOURCE_DIR}/config.hpp"
)

include_directories (data_structures)

# need to write implementation in headers itself 
# since this project relies heavily on template 
# classes and compiler needs to see interface along
# with implementation at the same time for templated fxns
file (GLOB_RECURSE SOURCES "data_structures/*.cpp")
add_library (cpp_algs SHARED ${SOURCES})

install (TARGETS cpp_algs DESTINATION /usr/lib)