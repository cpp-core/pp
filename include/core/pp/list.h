// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once

/// Expands to the first argument.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_HEAD(a, b, c)   // a
/// ```
/// \endverbatim
#define CORE_PP_HEAD(a, ...) a

/// Expands to the remaining arguments.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_REST(a, b, c)   // b, c
/// ```
/// \endverbatim
#define CORE_PP_REST(a, ...) __VA_ARGS__

/// Expands to the second argument.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_SECOND(a, b, c)   // b
/// ```
/// \endverbatim
#define CORE_PP_SECOND(a, b, ...) b

/// Expands to the third argument.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_THIRD(a, b, c)   // c
/// ```
/// \endverbatim
#define CORE_PP_THIRD(a, b, c, ...) c

