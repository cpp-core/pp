cmake_minimum_required (VERSION 3.22 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

find_package(Threads REQUIRED)

add_dependencies(cxx_depends cxx_googletest)
include(${DEPENDS_SOURCE_DIR}/googletest.cmake)

set(TESTS
  pp/base
  )

foreach(NAME ${TESTS})
  get_filename_component(DIRNAME ${NAME} DIRECTORY)
  get_filename_component(BASENAME ${NAME} NAME_WE)
  string(REPLACE / _ CATNAME ${NAME})
  
  set(TEST_NAME test_${CATNAME})
  set(TEST_FILE ${PROJECT_SOURCE_DIR}/test/src/core/${DIRNAME}/test_${CATNAME}.cpp)

  list(APPEND TEST_TARGETS ${TEST_NAME})
  add_executable(${TEST_NAME} ${TEST_FILE})
  add_test(${TEST_NAME} bin/${TEST_NAME})
  target_link_libraries(${TEST_NAME} PUBLIC cxx_core_pp googletest Threads::Threads)
  add_dependencies(build_and_test ${TEST_NAME})
  add_dependencies(build_and_test_detail ${TEST_NAME})
endforeach(NAME)

