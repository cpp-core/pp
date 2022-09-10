// Copyright 2017, 2019 by Mark Melton
//

#pragma once
#include "core/pp/cat.h"
#include "core/pp/list.h"

// BOOL(0) // 0
// BOOL(1) // 1
// BOOL(123) // 1
//
#define CORE_PP_IS_PROBE(...) CORE_PP_SECOND(__VA_ARGS__, 0)
#define CORE_PP_PROBE() ~, 1
#define CORE_PP_NOT(x) CORE_PP_IS_PROBE(CORE_PP_CAT(_CORE_PP_NOT_, x))
#define _CORE_PP_NOT_0 CORE_PP_PROBE()
#define CORE_PP_BOOL(x) CORE_PP_NOT(CORE_PP_NOT(x))

