cmake_minimum_required (VERSION 3.24 FATAL_ERROR)
project (pp VERSION 0.1 LANGUAGES C CXX)

# Make including this file idempotent
#
if(TARGET pp OR TARGET pp::pp)
  return()
endif()

# Options for generating tests and documentation.
#
option(PP_TEST "Generate the tests." OFF)
option(PP_DOCS "Generate the docs." OFF)

# If this is the current project.
#
if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
  # Include the cmake helpers
  #
  include(extern/cmake/utils/all.cmake)
  include(extern/cmake/recipes/all.cmake)

  # Generate the tests
  #
  set(PP_TEST ON CACHE BOOL "" FORCE)

  # compile_commands.json
  #
  symlink_compile_commands()

  # Convenience targets for git operations
  make_submodule_pull_target()
endif()

# Output configuration
#
message("-- pp: Configuration: ${CMAKE_CURRENT_SOURCE_DIR}")
message("-- pp: Included from: ${CMAKE_SOURCE_DIR}")
message("-- pp: Install prefix: ${CMAKE_INSTALL_PREFIX}")
message("-- pp: Project source dir: ${PROJECT_SOURCE_DIR}")
message("-- pp: Project binary dir: ${PROJECT_BINARY_DIR}")
message("-- pp: Cmake binary dir: ${CMAKE_BINARY_DIR}")
message("-- pp: PP_TEST ${PP_TEST}")
message("-- pp: PP_DOCS ${PP_DOCS}")

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
