// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/pp/args.h"
#include "core/pp/defer.h"
#include "core/pp/eval.h"
#include "core/pp/ifelse.h"
#include "core/pp/unparen.h"

#define CORE_PP_MAP(m, first, ...)				\
    m(first)							\
    CORE_PP_IF_ELSE(CORE_PP_HAS_ARGS(__VA_ARGS__))		\
    (CORE_PP_DEFER2(_CORE_PP_MAP)()(m, __VA_ARGS__),)
#define _CORE_PP_MAP() CORE_PP_MAP

/// Expands to the macro m applied to each of the remaining arguments.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// #define DOUBLER(x) x x
/// CORE_PP_EVAL_MAP(DOUBLER, 1, 2, 3) // 1 1 2 2 3 3
/// ```
/// \endverbatim
#define CORE_PP_EVAL_MAP(m, first, ...) CORE_PP_EVAL(CORE_PP_MAP(m, first, __VA_ARGS__))

#define CORE_PP_MAP_SEQ(m, seq) _CORE_PP_MAP_SEQ(m, CORE_PP_UNPAREN(seq))
#define _CORE_PP_MAP_SEQ(m, ...) CORE_PP_MAP(m, __VA_ARGS__)

/// Expands to the macro m applied to each element of the given
/// sequence.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_EVAL_MAP_SEQ(CORE_PP_HEAD, ((1, 2), (2, 3))) // 1 2
/// ```
/// \endverbatim
#define CORE_PP_EVAL_MAP_SEQ(m, seq) CORE_PP_EVAL(CORE_PP_MAP_SEQ(m, seq))

#define CORE_PP_MAPN(m, first, ...)				\
    m first							\
    CORE_PP_IF_ELSE(CORE_PP_HAS_ARGS(__VA_ARGS__))		\
	(CORE_PP_DEFER2(_CORE_PP_MAPN)()(m, __VA_ARGS__),)
#define _CORE_PP_MAPN() CORE_PP_MAPN

/// Expands to the macro m prepended to each argument in turn.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_EVAL_MAPN(int, a, b, c) // int a int b int c
/// ```
/// \endverbatim
#define CORE_PP_EVAL_MAPN(m, first, ...) CORE_PP_EVAL(CORE_PP_MAPN(m, first, __VA_ARGS__))
    
#define CORE_PP_MAPN_SEQ(m, seq) _CORE_PP_MAPN_SEQ(m, CORE_PP_UNPAREN(seq))
#define _CORE_PP_MAPN_SEQ(m, ...) CORE_PP_MAPN(m, __VA_ARGS__)

/// Expands to the first element of the given sequence prepended to
/// each remianing element of the sequence in turn.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_EVAL_MAPN_SEQ((int, a, b, c)) // int a int b int c
/// ```
/// \endverbatim
#define CORE_PP_EVAL_MAPN_SEQ(m, seq) CORE_PP_EVAL(CORE_PP_MAPN_SEQ(m, seq))

#define CORE_PP_MAP_INFIX(m, infix, first, ...)				\
    m(first)								\
    CORE_PP_IF_ELSE(CORE_PP_HAS_ARGS(__VA_ARGS__))			\
    (infix() CORE_PP_DEFER2(_CORE_PP_MAP_INFIX)()(m, infix, __VA_ARGS__),)
#define _CORE_PP_MAP_INFIX() CORE_PP_MAP_INFIX

/// Expands to the given macro m applied to each of the arguments
/// starting with first interspersed with the macro infix.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// #define DOUBLER(x) x x
/// CORE_PP_MAP_INFIX(DOUBLER, CORE_PP_COMMA, a, b, c) // a a , b b , c c
/// ```
/// \endverbatim
#define CORE_PP_EVAL_MAP_INFIX(m, infix, first, ...)			\
    CORE_PP_EVAL(CORE_PP_MAP_INFIX(m, infix, first, __VA_ARGS__))

#define CORE_PP_MAP_INFIX_SEQ(m, infix, seq) _CORE_PP_MAP_INFIX_SEQ(m, infix, CORE_PP_UNPAREN(seq))
#define _CORE_PP_MAP_INFIX_SEQ(m, infix, ...) CORE_PP_MAP_INFIX(m, infix, __VA_ARGS__)

/// Expands to the given macro m applied to each of the arguments
/// starting with first interspersed with the macro infix.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_MAP_INFIX_SEQ(SECOND_SEQ, CORE_PP_COMMA, ((a 1), (b 2), (c 3))) // 1 , 2 , 3
/// ```
/// \endverbatim
#define CORE_PP_EVAL_MAP_INFIX_SEQ(m, infix, seq)	\
    CORE_PP_EVAL(CORE_PP_MAP_INFIX_SEQ(m, infix, seq))

#define CORE_PP_MAP_WITH(m, data, first, ...)				\
    m(data, first)							\
    CORE_PP_IF_ELSE(CORE_PP_HAS_ARGS(__VA_ARGS__))			\
    (CORE_PP_DEFER2(_CORE_PP_MAP_WITH)()(m, data, __VA_ARGS__),)
#define _CORE_PP_MAP_WITH() CORE_PP_MAP_WITH

/// Expands to the given macro invoked with the given data paired with
/// each subsequent argument in turn.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// #define QUALIFY(name, value) name::value
/// CORE_PP_EVAL_MAP_WITH(QUALITY, Foo, a, b, c) // Foo::a , Foo::b , Foo::c
/// ```
/// \endverbatim
#define CORE_PP_EVAL_MAP_WITH(m, data, first, ...)		\
    CORE_PP_EVAL(CORE_PP_MAP_WITH(m, data, first, __VA_ARGS__))

#define CORE_PP_MAP_WITH_SEQ(m, data, seq) _CORE_PP_MAP_WITH_SEQ(m, data, CORE_PP_UNPAREN(seq))
#define _CORE_PP_MAP_WITH_SEQ(m, data, ...) CORE_PP_MAP_WITH(m, data, __VA_ARGS__)

/// Expands to the given macro invoked with the given data paired with
/// each element of the given sequence in turn.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// #define QUALIFY(name, seq) name::SECOND_SEQ(seq),
/// COre_PP_EVAL_MAP_WITH_SEQ(QUALIFY, Foo, ((1, a), (2, b), (3, c))) // Foo::a, Foo::b, Foo::c
/// ```
/// \endverbatim
#define CORE_PP_EVAL_MAP_WITH_SEQ(m, data, seq) CORE_PP_EVAL(CORE_PP_MAP_WITH_SEQ(m, data, seq))
