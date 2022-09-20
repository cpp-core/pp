// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/pp/cat.h"
#include "core/pp/bool.h"

/// Expands to either a macro that returns its arguments (if the given
/// condition is true) or a macro that returns nothing (if the given
/// condition is false). When invoked with with two pairs of
/// parentheses, this acts much like a traditional if statement:
/// `CODE_PP_IF(condition)(then-clause)`
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_IF(123)(true) // true
/// CORE_PP_IF(0)(true)   // 
/// ```
/// \endverbatim
#define CORE_PP_IF(c) _CORE_PP_IF(CORE_PP_BOOL(c))

#define _CORE_PP_IF(c) CORE_PP_CAT(_CORE_PP_IF_,c)
#define _CORE_PP_IF_0(...)
#define _CORE_PP_IF_1(...) __VA_ARGS__

/// Expands to either a macro that returns its first argument (if the
/// given condition is true) or a macro that return its second
/// argument (if the given condition is false). When invoked with two
/// pairs of parentheses, this works much like a traditional
/// if-then-else statement:
/// `CODE_PP_IF_ELSE(condition)(then-clause,else-clause)`.
/// 
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_IF_ELSE(123)(true,false) // true
/// CORE_PP_IF_ELSE(0)(true,false)   // false
/// ```
/// \endverbatim
#define CORE_PP_IF_ELSE(c) _CORE_PP_IF_ELSE(CORE_PP_BOOL(c))

#define _CORE_PP_IF_ELSE(c) CORE_PP_CAT(_CORE_PP_IF_ELSE_, c)
#define _CORE_PP_IF_ELSE_0(t,f) f
#define _CORE_PP_IF_ELSE_1(t,f) t
