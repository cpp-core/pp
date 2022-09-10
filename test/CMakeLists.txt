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
  set(TEST_FILE1 ${PROJECT_SOURCE_DIR}/test/src/core/${DIRNAME}/test_${BASENAME}.cpp)
  set(TEST_FILE2 ${PROJECT_SOURCE_DIR}/test/src/core/${DIRNAME}/test_${CATNAME}.cpp)
  if(EXISTS ${TEST_FILE1})
    set(TEST_FILE ${TEST_FILE1})
  elseif(EXISTS ${TEST_FILE2})
    set(TEST_FILE ${TEST_FILE2})
  else()
    message(FATAL "Cannot find test file for ${NAME}")
  endif()

  list(APPEND TEST_TARGETS ${TEST_NAME})
  add_executable(${TEST_NAME} ${TEST_FILE})
  add_test(${TEST_NAME} bin/${TEST_NAME})
  target_link_libraries(${TEST_NAME} PUBLIC cxx_core_pp googletest Threads::Threads)
  target_include_directories(${TEST_NAME} PUBLIC ../include/core)
endforeach(NAME)

