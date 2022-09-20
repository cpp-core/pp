// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/pp/list.h"

/// Evaluates to the first element of the given sequence.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_HEAD_SEQ((a,b,c))     // a
/// ```
/// \endverbatim
#define CORE_PP_HEAD_SEQ(seq) CORE_PP_HEAD seq

/// Evaluates to a seeuence of the remaining elements of the given
/// sequence.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_REST_SEQ((a,b,c))     // (b,c)
/// ```
/// \endverbatim
#define CORE_PP_REST_SEQ(seq) (CORE_PP_REST seq)

/// Evaluates to the second element of the given sequence.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_SECOND_SEQ((a,b,c))   // b
/// ```
/// \endverbatim
#define CORE_PP_SECOND_SEQ(seq) CORE_PP_SECOND seq

/// Evaluates to the third element of the given sequence.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_THIRD_SEQ((a,b,c))    // c
/// ```
/// \endverbatim
#define CORE_PP_THIRD_SEQ(seq) CORE_PP_THIRD seq

// Helpers for IS_SEQ
#define _CORE_PP_ZERO(...) 0
#define _CORE_PP_IS_ZERO(...) CORE_PP_NOT(CORE_PP_BOOL(CORE_PP_HEAD(__VA_ARGS__)))

/// Evalutes to 1 if the arguments are a sequence, otherwise 0.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_IS_SEQ()      // 0
/// CORE_PP_IS_SEQ(a)     // 0
/// CORE_PP_IS_SEQ(a,b)   // 0
/// CORE_PP_IS_SEQ(())    // 1
/// CORE_PP_IS_SEQ((a,b)) // 1
/// ```
/// \endverbatim
#define CORE_PP_IS_SEQ(...) _CORE_PP_IS_ZERO(_CORE_PP_ZERO __VA_ARGS__)

/// Evaluates to the first element of the given list or sequence.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_HEAD_LIST_OR_SEQ(a)     == a
/// CORE_PP_HEAD_LIST_OR_SEQ(a,b)   == a
/// CORE_PP_HEAD_LIST_OR_SEQ((a))   == a
/// CORE_PP_HEAD_LIST_OR_SEQ((a,b)) == a
/// ```
/// \endverbatim
#define CORE_PP_HEAD_LIST_OR_SEQ(seq_or_value, ...)			\
    CORE_PP_IF_ELSE(CORE_PP_IS_SEQ(seq_or_value))			\
    (CORE_PP_HEAD_SEQ(seq_or_value), seq_or_value)
