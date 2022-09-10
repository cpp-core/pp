// Copyright 2017, 2019 by Mark Melton
//

#pragma once

// COUNT -- count number of arguments
//
// CORE_PP_COUNT() == 0
// CORE_PP_COUNT(a) == 1
// CORE_PP_COUNT(a,b) == 2
// CORE_PP_COUNT((a,b),(c,d)) == 2
//
#define _CORE_PP_ARGN(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10,		\
		      _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,	\
		      _21, _22, _23, _24, _25, _26, _27, _28, _29, _30,	\
		      N, ...) N
    
#define CORE_PP_COUNT(...) _CORE_PP_ARGN(ignored, ##__VA_ARGS__,		\
					 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
					 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
					 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define CORE_PP_COUNT_SEQ(seq) CORE_PP_COUNT seq
