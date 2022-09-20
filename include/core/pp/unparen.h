// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/pp/cat.h"

#define _CORE_PP_NOTHING__CORE_PP_EXTRACT
#define _CORE_PP_EXTRACT(...) _CORE_PP_EXTRACT __VA_ARGS__
#define CORE_PP_EVALUATING_PASTE(x, ...) CORE_PP_CATN(x, __VA_ARGS__)

/// Expands to its arguments removing a pair of enclosing parentheses if possible.
///
/// Invoking this macro on a sequence produces a list.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_UNPAREN(a)     // a
/// CORE_PP_UNPAREN((a))   // a
/// CORE_PP_UNPAREN((a,b)) // a,b
/// ```
/// \endverbatim
#define CORE_PP_UNPAREN(...)						\
    CORE_PP_EVALUATING_PASTE(_CORE_PP_NOTHING_, _CORE_PP_EXTRACT __VA_ARGS__)
