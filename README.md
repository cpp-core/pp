[![Build and Unit Test](https://github.com/melton1968/cxx-core-pp/actions/workflows/build.yaml/badge.svg)](https://github.com/melton1968/cxx-core-pp/actions/workflows/build.yaml)

# Structured Preprocessor Programming

Primitives for using the preprocessor in a structured fashion.

## Installation

### Standalone

	git clone git@github.com:melton1968/cxx-core-pp
	mkdir cxx-core-pp/build && cd cxx-core-pp/build
    CC=clang-mp-11 CXX=clang++-mp-11 cmake -DCMAKE_INSTALL_PREFIX=$HOME/opt ..
	make check    # Run the tests
	make install  # Do the install
	
### Using cxx-depends

    git clone git@github.com:melton1968/cxx-depends
	mkdir cxx-depends/build && cd cxx-depends/build
    CC=clang-mp-11 CXX=clang++-mp-11 cmake -DCMAKE_INSTALL_PREFIX=$HOME/opt -DCORE_TESTS=ON ..
	make cxx_core_pp-check  # Run the tests
	make cxx_core_pp        # Do the install
