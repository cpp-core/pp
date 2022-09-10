// Copyright 2017, 2019 by Mark Melton
//

#pragma once
#include "core/pp/bool.h"

// HAS_ARGS() // 0
// HAS_ARGS(a) // 1
// HAS_ARGS(a,b) // 1
// HAS_ARGS((a,b)) // 1
//    
#define CORE_PP_HAS_ARGS(...) _CORE_PP_HAS_ARGS(CORE_PP_UNPAREN(__VA_ARGS__))
#define _CORE_PP_HAS_ARGS(...) CORE_PP_BOOL(CORE_PP_HEAD(_CORE_PP_END_OF_ARGUMENTS_ __VA_ARGS__)())
#define _CORE_PP_END_OF_ARGUMENTS_() 0
