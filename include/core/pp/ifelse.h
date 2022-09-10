// Copyright 2017, 2019 by Mark Melton
//

#pragma once
#include "core/pp/cat.h"
#include "core/pp/bool.h"

// IF(123)(t) // t
// IF(0)(t) // 
//
#define CORE_PP_IF(c) _CORE_PP_IF(CORE_PP_BOOL(c))
#define _CORE_PP_IF(c) CORE_PP_CAT(_CORE_PP_IF_,c)
#define _CORE_PP_IF_0(...)
#define _CORE_PP_IF_1(...) __VA_ARGS__

// IF_ELSE(123)(true,false) // true
// IF_ELSE(0)(true,false) // false
//
#define CORE_PP_IF_ELSE(c) _CORE_PP_IF_ELSE(CORE_PP_BOOL(c))
#define _CORE_PP_IF_ELSE(c) CORE_PP_CAT(_CORE_PP_IF_ELSE_, c)
#define _CORE_PP_IF_ELSE_0(t,f) f
#define _CORE_PP_IF_ELSE_1(t,f) t
