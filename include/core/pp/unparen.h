// Copyright 2017, 2019 by Mark Melton
//

#pragma once
#include "core/pp/cat.h"

// UNPAREN(a)     // a
// UNPAREN((a))   // a
// UNPAREN((a,b)) // a,b
//
#define _CORE_PP_NOTHING__CORE_PP_EXTRACT
#define _CORE_PP_EXTRACT(...) _CORE_PP_EXTRACT __VA_ARGS__
#define CORE_PP_EVALUATING_PASTE(x, ...) CORE_PP_CATN(x, __VA_ARGS__)
#define CORE_PP_UNPAREN(...)						\
    CORE_PP_EVALUATING_PASTE(_CORE_PP_NOTHING_, _CORE_PP_EXTRACT __VA_ARGS__)
