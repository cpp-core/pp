// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once

/// Force the preprocessor to recursively expand the given arguments.
///
/// Left to its own devices, the preprocessor will not recursively
/// expand macros, but will do a single-pass
/// substitution. `CORE_PP_EVAL` recursivley expands its arguments up
/// to 1024 levels.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// #define A(x) x+1
/// #define EMPTY
/// #define NEEDS_TWO_PASSES(x) A EMPTY (x)
/// NEEDS_TWO_PASSES(2)                // A (2)
/// CORE_PP_EVAL(NEEDS_TWO_PASSES(2))  // 2 +1
/// ```
/// \endverbatim
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
