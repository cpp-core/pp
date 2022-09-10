// Copyright 2017, 2019 by Mark Melton
//

#pragma once

// CAT(a, b) -> ab
// CATN(a, b, c) -> ab, c
//
#define CORE_PP_CAT(a, b) a ## b
#define CORE_PP_CATN(a, ...) a ##  __VA_ARGS__

