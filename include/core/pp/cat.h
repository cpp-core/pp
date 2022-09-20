// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once

/// Expands to the concatenation of its two arguments.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_CAT(a, b)   // ab
/// ```
/// \endverbatim
#define CORE_PP_CAT(a, b) a ## b

/// Expands to the concatenation of its first row arguments sequenced
/// with the remaining arguments.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_CATN(a, b, c)   // ab, c
/// ```
/// \endverbatim
#define CORE_PP_CATN(a, ...) a ##  __VA_ARGS__

