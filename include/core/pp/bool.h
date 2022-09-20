// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/pp/cat.h"
#include "core/pp/list.h"

#define CORE_PP_IS_PROBE(...) CORE_PP_SECOND(__VA_ARGS__, 0)
#define CORE_PP_PROBE() ~, 1

/// Expands to 0 if the given arguemnt is not false, 1 otherwise.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_NOT(0)   // 1
/// CORE_PP_NOT(1)   // 0
/// CORE_PP_NOT(123) // 0
/// ```
/// \endverbatim
#define CORE_PP_NOT(x) CORE_PP_IS_PROBE(CORE_PP_CAT(_CORE_PP_NOT_, x))

#define _CORE_PP_NOT_0 CORE_PP_PROBE()

/// Expands to 1 if the given argument is not false, 0 otherwise.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_BOOL(0)   // 0
/// CORE_PP_BOOL(1)   // 1
/// CORE_PP_BOOL(123) // 1
/// ```
/// \endverbatim
#define CORE_PP_BOOL(x) CORE_PP_NOT(CORE_PP_NOT(x))

