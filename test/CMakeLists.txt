cmake_minimum_required (VERSION 3.24 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin)

find_package(Threads REQUIRED)

set(TESTS
  pp/base
  )

set(LIBRARIES
  pp
  GTest::gtest
  Threads::Threads
  )

configure_tests("core" "${LIBRARIES}" ${TESTS})
