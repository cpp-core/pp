cmake_minimum_required (VERSION 3.22 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

include(../cmake/cpp_core_find_package.cmake)
cpp_core_find_package(googletest)

find_package(Threads REQUIRED)

set(TESTS
  pp/base
  )

set(LIBRARIES
  pp
  GTest::gtest
  Threads::Threads
  )

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/configure_tests.cmake)
configure_tests("core" "${LIBRARIES}" ${TESTS})
