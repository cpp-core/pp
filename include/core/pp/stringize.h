// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once

/// Expands to a string of its arguments.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// Converts arguments into a string.
/// CORE_PP_STRINGIZE(a)    // "a"
/// CORE_PP_STRINGIZE(a,b)  // "a,b"
/// ```
/// \endverbatim
#define CORE_PP_STRINGIZE1(...) #__VA_ARGS__
#define CORE_PP_STRINGIZE(...) CORE_PP_STRINGIZE1(__VA_ARGS__)
