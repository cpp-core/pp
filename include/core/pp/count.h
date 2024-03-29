// Copyright 2017, 2019, 2022, 2023 by Mark Melton
//

#pragma once

#define _CORE_PP_ARGN(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10,		\
		      _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,	\
		      _21, _22, _23, _24, _25, _26, _27, _28, _29, _30,	\
		      N, ...) N
    
/// Expands to the number of elements in the given list.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_COUNT()          // 0
/// CORE_PP_COUNT(a)         // 1
/// CORE_PP_COUNT(a,b)       // 2
/// CORE_PP_COUNT(a,b,c)     // 3
/// ```
/// \endverbatim
#define CORE_PP_COUNT(...) _CORE_PP_ARGN(ignored __VA_OPT__(,) ##__VA_ARGS__, \
					 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
					 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
					 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

/// Expands to the number of elements in the given sequence.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_COUNT_SEQ(())          // 0
/// CORE_PP_COUNT_SEQ((a))         // 1
/// CORE_PP_COUNT_SEQ((a,b))       // 2
/// CORE_PP_COUNT_SEQ((a,b,c))     // 3
/// CORE_PP_COUNT_SEQ((a,b),(c,d)) // 2
/// ```
/// \endverbatim
#define CORE_PP_COUNT_SEQ(seq) CORE_PP_COUNT seq
