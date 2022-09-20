// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/pp/bool.h"

/// Expands to 1 if the macro is passed arguments, 0 otherwise.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_HAS_ARGS()      // 0
/// CORE_PP_HAS_ARGS(a)     // 1
/// CORE_PP_HAS_ARGS(a,b)   // 1
/// CORE_PP_HAS_ARGS((a,b)) // 1
/// ```
/// \endverbatim
#define CORE_PP_HAS_ARGS(...) _CORE_PP_HAS_ARGS(CORE_PP_UNPAREN(__VA_ARGS__))

#define _CORE_PP_HAS_ARGS(...) CORE_PP_BOOL(CORE_PP_HEAD(_CORE_PP_END_OF_ARGUMENTS_ __VA_ARGS__)())
#define _CORE_PP_END_OF_ARGUMENTS_() 0
