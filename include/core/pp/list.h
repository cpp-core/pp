// Copyright 2017, 2019 by Mark Melton
//

#pragma once

// HEAD(a, b, c)   // a
// REST(a, b, c)   // b,c
// SECOND(a, b, c) // b
// THIRD(a, b, c)  // c
//
#define CORE_PP_HEAD(a, ...) a
#define CORE_PP_REST(a, ...) __VA_ARGS__
#define CORE_PP_SECOND(a, b, ...) b
#define CORE_PP_THIRD(a, b, c, ...) c

