// Copyright 2017, 2019 by Mark Melton
//

#pragma once
#include "core/pp/list.h"

// HEAD_SEQ((a,b,c))   == a
// REST_SEQ((a,b,c))   == (b,c)
// SECOND_SEQ((a,b,c)) == b
// THIRD_SEQ((a,b,c))  == c
//
#define CORE_PP_HEAD_SEQ(seq) CORE_PP_HEAD seq
#define CORE_PP_REST_SEQ(seq) (CORE_PP_REST seq)
#define CORE_PP_SECOND_SEQ(seq) CORE_PP_SECOND seq
#define CORE_PP_THIRD_SEQ(seq) CORE_PP_THIRD seq

// IS_SEQ()      == 0
// IS_SEQ(a)     == 0
// IS_SEQ(a,b)   == 0
// IS_SEQ(())    == 1
// IS_SEQ((a))   == 1
// IS_SEQ((a,b)) == 1
//
#define _CORE_PP_ZERO(...) 0
#define _CORE_PP_IS_ZERO(...) CORE_PP_NOT(CORE_PP_BOOL(CORE_PP_HEAD(__VA_ARGS__)))
#define CORE_PP_IS_SEQ(...) _CORE_PP_IS_ZERO(_CORE_PP_ZERO __VA_ARGS__)

// HEAD_LIST_OR_SEQ(a)     == a
// HEAD_LIST_OR_SEQ(a,b)   == a
// HEAD_LIST_OR_SEQ((a))   == a
// HEAD_LIST_OR_SEQ((a,b)) == a
//
#define CORE_PP_HEAD_LIST_OR_SEQ(seq_or_value, ...)			\
    CORE_PP_IF_ELSE(CORE_PP_IS_SEQ(seq_or_value))			\
    (CORE_PP_HEAD_SEQ(seq_or_value), seq_or_value)
