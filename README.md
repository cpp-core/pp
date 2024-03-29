[![Build and Unit Test](https://github.com/cpp-core/pp/actions/workflows/build.yaml/badge.svg)](https://github.com/cpp-core/pp/actions/workflows/build.yaml)
[![Docs](https://github.com/cpp-core/pp/actions/workflows/docs.yaml/badge.svg)](https://github.com/cpp-core/pp/actions/workflows/docs.yaml)

# `C` Preprocessor Primitives for Structured Programming
* [Motivation](#motivation)
* [Tutorial](#tutorial)
* [Installation](#installation)
  * [Local Test And Install](#local-test-and-install)
  * [Local Install Only](#local-install-only)
* [Documentation](https://cpp-core.github.io/pp/)

## Motivation

Using the `C` preprocessor to generate code, while often derided, is
sometimes useful. From generating self-serializing `enum`s to
instantiating `template class`s over a range of types, even modern,
well structured `C++` code can sometimes benefift from simple code
generation using the preprocessor. Since the preprocessor was not
designed with explicit iteration or other common high-level
programming concepts, creating well-structured preprocessor code can
be challenging. 

The `pp` library is a light-weight, header-only, macro library
providing primitives such as lists, sequences, conditionals and map
operations, designed to facilitate using the `C` processor in a
well-structured, functional manner.

The following snippet demonstrates generating class template
instatiations for several types.

```c++
#include "core/pp/pp.h"

#define GEN_MYCLASS(N,T) template<> class N<T>;
#define GEN_MYCLASS_SEQ(SEQ) CORE_PP_EVAL_MAP_WITH_SEQ(MYCLASS,MyClass,SEQ)
#define TYPE_SEQ (int8, int16, int32, int64)

GEN_MYCLASS_SEQ(TYPE_SEQ)
```

Running through the preporcessor, generates the following code.
```c++
template<> class MyClass<int>; template<> class MyClass<long int>; template<> class MyClass<unsigned int>;
```

Yes, if only we could get the preprocessor to emit some newlines.

## Tutorial


## Installation

### Local Test and Install

```
git clone https://github.com/cpp-core/pp
mkdir pp/build && cd pp/build
CC=clang-mp-16 CXX=clang++-mp-16 cmake .. -DCMAKE_INSTALL_PREFIX=~/opt
make -j4 check
make install
```

### Local Install Only

```
git clone https://github.com/cpp-core/pp
mkdir pp/build && cd pp/build
CC=clang-mp-16 CXX=clang++-mp-16 cmake .. -DCMAKE_INSTALL_PREFIX=~/opt -DPP_TEST=OFF
make install
```

### Use FetchContent To Add At Cmake Buildtime

Add the following snippet to your cmake file and add `pp::pp` to your targets.

```
include(FetchContent)
FetchContent_Declare(cpp_core_pp GIT_REPOSITORY https://cpp-core/pp GIT_TAG main FIND_PACKAGE_ARGS)
FetchContent_MakeAvailable(cpp_core_pp)
```

### Use Cpp-Core Manager To Add Any Compatible Repo

Add the following snippet to your cmake file. You can then include any
compatible library with the `add_repo` call.

```
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

add_repo(cpp-core/pp)
```

