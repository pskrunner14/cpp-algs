cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(cpp_algs)

set(CMAKE_BUILD_TYPE Debug)

set(cpp_algs_VERSION_MAJOR 2)
set(cpp_algs_VERSION_MINOR 0)
set(cpp_algs_VERSION_PATCH 1)

set(CMAKE_CXX_STANDARD 11)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()

if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(CMAKE_C_FLAGS   "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

configure_file(
    "${PROJECT_SOURCE_DIR}/cpp_algs/config.hpp.in"
    "${PROJECT_SOURCE_DIR}/cpp_algs/config.hpp"
)

# Need to write impl. in headers itself since 
# this project relies heavily on template 
# classes and compiler needs interface and impl.
# at the same time for templated fxns.
add_library(cpp_algs SHARED "cpp_algs/cpp_algs.hpp")
set_target_properties(cpp_algs PROPERTIES LINKER_LANGUAGE CXX)
    
install(TARGETS cpp_algs  DESTINATION /usr/lib)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")