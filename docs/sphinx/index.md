
# C++ Preprocessor Library

Primitives for ~~abusing~~ using the preprocessor in a structured fashion.

# Brief Tour

If you find youself using the preprocessor to generate code, just
don't. Take a walk in the woods and clear you head. Re-evaluate the
problem and come up with a better option. Maybe use a code-generation
tool designed for the task at hand. Using the preprocessor should be a
last resort.

But, for those times when using the preprocessor is the lessor of the
evils, can we all agree to use it in a structured fashion. For
example, to generate class template instatiations for several integral
types:

```c++
#include "core/pp/pp.h"

#define GEN_MYCLASS(N,T) template<> class N<T>;
#define GEN_MYCLASS_SEQ(SEQ) CORE_PP_EVAL_MAP_WITH_SEQ(MYCLASS,MyClass,SEQ)
#define TYPE_SEQ (int8, int16, int32, int64)

GEN_MYCLASS_SEQ(TYPE_SEQ)
```

Produces the following:

```c++
template<> class MyClass<int>; template<> class MyClass<long int>; template<> class MyClass<unsigned int>;
```

Yes, I know, if only we could get the proprocessor to emit some
newlines. Like I said, don't go there unless you must.

# Installation

```bash
git clone https://github.com/cpp-core/pp
mkdir pp/build && cd pp/build
CC=clang-mp-14 CXX=clang++-mp-14 cmake -DCMAKE_INSTALL_PREFIX=$HOME/opt ..
make -j4 check # Run tests
make install   # Do the install
```

To build the documentation (requires doxygen and sphinx-build to be installed)::

```bash
CC=clang-11 CXX=clang++11 cmake -DCORE_DOCS ..
make cxx_core_pp_docs # root of html tree is docs/html/index.html
```

# Background

*cxx-core-pp* is part of the *cxx-core** family of C++20 based
libraries. The *cxx-core* libraries have two primary goals:

- **Ergonomics**. In the spirit of the `CppCoreGuideLines`, cxx-core
  aspires to facilitate writing concise, idiomatic code not by force,
  but by providing a clear path that produces robust, easy to read
  code. Good code should be fun to write.
  
- **Components**. Modern language platforms provide broad support for
  first-class library components, while C++ has traditionally only
  provided a very minimal standard library. *cxx-core* aspires to
  provide support for a broad range of libraries that feel like part
  of the language.
  
# License

This software is licensed under the BSD 3-clause license. See the LICENSE file for details.

# Appendix

```{toctree}
---
caption: API REFERENCE
---
api/conditional
api/list
api/map
api/sequence
api/utilities
```

```{toctree}
---
caption: FILE REFERENCE
maxdepth: 5
---
include/ <generated/include/dir>
test/ <generated/test/dir>
```
