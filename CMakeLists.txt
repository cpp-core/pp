cmake_minimum_required (VERSION 3.24 FATAL_ERROR)
project (pp VERSION 0.1 LANGUAGES C CXX)

# Make including this file idempotent
#
if(TARGET pp OR TARGET pp::pp)
  return()
endif()

# New behavior allows overriding option with normal variable.
#
cmake_policy(VERSION 3.24)

# If this is the current project.
#
if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
  if(CPP_CORE_DEV AND NOT CPP_CORE_DIR)
    set(CPP_CORE_DIR "${CMAKE_CURRENT_LIST_DIR}/..")
  endif()

  if(CPP_CORE_DIR AND EXISTS ${CPP_CORE_DIR}/cmake)
    set(CPP_CORE_CMAKE_DIR ${CPP_CORE_DIR}/cmake)
  else()
    include(FetchContent)
    FetchContent_Declare(
      cmake
      GIT_REPOSITORY https://github.com/cpp-core/cmake
      GIT_TAG main
      )
    FetchContent_MakeAvailable(cmake)
    set(CPP_CORE_CMAKE_DIR ${CMAKE_BINARY_DIR}/_deps/cmake-src)
  endif()

  include(${CPP_CORE_CMAKE_DIR}/utils/all.cmake)
  include(${CPP_CORE_CMAKE_DIR}/recipes/all.cmake)

  # Generate the tests and documentation by default
  #
  option(PP_TEST "Generate the tests." ON)
  option(PP_DOCS "Generate the docs." OFF)

  # compile_commands.json
  #
  symlink_compile_commands()

  # Convenience targets for git operations
  make_submodule_pull_target()
  
else()
  option(PP_TEST "Generate the tests." OFF)
  option(PP_DOCS "Generate the docs." OFF)
endif()

# Put executables in the top-level binary directory
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Output configuration
#
message("-- pp: Configuration: ${CMAKE_CURRENT_SOURCE_DIR}")
message("-- pp: Included from: ${CMAKE_SOURCE_DIR}")
message("-- pp: Install prefix: ${CMAKE_INSTALL_PREFIX}")
message("-- pp: Project source dir: ${PROJECT_SOURCE_DIR}")
message("-- pp: Project binary dir: ${PROJECT_BINARY_DIR}")
message("-- pp: Cmake binary dir: ${CMAKE_BINARY_DIR}")
message("-- pp: test: ${PP_TEST}")
message("-- pp: docs: ${PP_DOCS}")

# Setup compilation
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
add_compile_options(-stdlib=libc++)
add_compile_options(-O)
add_link_options(-stdlib=libc++)

# Build the library
#
add_library(pp INTERFACE)
add_library(pp::pp ALIAS pp) # Allow interop between FetchContent and FindPackage.

# Define the header files for this library.
#
file(GLOB_RECURSE PUBLIC_INCLUDE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} include/*.h)
target_sources(pp INTERFACE FILE_SET HEADERS BASE_DIRS include FILES ${PUBLIC_INCLUDE_FILES})
  
# Optionally configure the tests
#
if(PP_TEST)
  add_gtest()
  add_subdirectory(test)
endif()

# Optionally configure the documentation
#
if(PP_DOCS)
  add_subdirectory(docs)
endif()

# Installation
#
install_config(pp)
