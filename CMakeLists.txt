cmake_minimum_required(VERSION 3.0)

project (cpp-algs)

set (CMAKE_BUILD_TYPE Release)
set (cpp_algs_VERSION_MAJOR 1)
set (cpp_algs_VERSION_MINOR 0)
set (cpp_algs_VERSION_PATCH 1)

configure_file (
    "${PROJECT_SOURCE_DIR}/include/cpp_algs_config.h.in"
    "${PROJECT_SOURCE_DIR}/include/cpp_algs_config.h"
)