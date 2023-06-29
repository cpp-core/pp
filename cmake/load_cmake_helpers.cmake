
if(NOT CPP_CORE_CMAKE_DIR)
  include(FetchContent)
  set(NAME cpp_core_cmake)
  FetchContent_Declare(
    ${NAME}
    GIT_REPOSITORY https://github.com/cpp-core/cmake
    GIT_TAG main
    )
  FetchContent_MakeAvailable(${NAME})
  set(CPP_CORE_CMAKE_DIR ${CMAKE_BINARY_DIR}/_deps/${NAME}-src)
endif()

include(${CPP_CORE_CMAKE_DIR}/utils/all.cmake)
include(${CPP_CORE_CMAKE_DIR}/recipes/all.cmake)
