// Copyright 2017, 2019 by Mark Melton
//

#pragma once

// EVAL - Force the pre-processor to expand the given macro over a
// large number of passes.
//
// #define A(x) x+1
// #define EMPTY
// #define NEEDS_TWO_PASSES(x) A EMPTY (x)
// NEEDS_TWO_PASSES(2)        // A (2)
// EVAL(NEEDS_TWO_PASSES(2))  // 2 +1
//
#define CORE_PP_EVAL(...) CORE_PP_EVAL1024(__VA_ARGS__)
#define CORE_PP_EVAL1024(...) CORE_PP_EVAL512(CORE_PP_EVAL512(__VA_ARGS__))
#define CORE_PP_EVAL512(...) CORE_PP_EVAL256(CORE_PP_EVAL256(__VA_ARGS__))
#define CORE_PP_EVAL256(...) CORE_PP_EVAL128(CORE_PP_EVAL128(__VA_ARGS__))
#define CORE_PP_EVAL128(...) CORE_PP_EVAL64(CORE_PP_EVAL64(__VA_ARGS__))
#define CORE_PP_EVAL64(...) CORE_PP_EVAL32(CORE_PP_EVAL32(__VA_ARGS__))
#define CORE_PP_EVAL32(...) CORE_PP_EVAL16(CORE_PP_EVAL16(__VA_ARGS__))
#define CORE_PP_EVAL16(...) CORE_PP_EVAL8(CORE_PP_EVAL8(__VA_ARGS__))
#define CORE_PP_EVAL8(...) CORE_PP_EVAL4(CORE_PP_EVAL4(__VA_ARGS__))
#define CORE_PP_EVAL4(...) CORE_PP_EVAL2(CORE_PP_EVAL2(__VA_ARGS__))
#define CORE_PP_EVAL2(...) CORE_PP_EVAL1(CORE_PP_EVAL1(__VA_ARGS__))
#define CORE_PP_EVAL1(...) __VA_ARGS__
