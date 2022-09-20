// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/pp/eval.h"
#include "core/pp/map.h"

#define _CORE_PP_CARTESIAN_MAP(a, b) (a,b),

#define _CORE_PP_CARTESIAN_PRODUCT_ITEM_SEQ(bseq, aitem) \
    CORE_PP_DEFER2(_CORE_PP_DEFERRED_MAP_WITH_SEQ)()(_CORE_PP_CARTESIAN_MAP, aitem, bseq)
#define _CORE_PP_DEFERRED_MAP_WITH_SEQ() CORE_PP_MAP_WITH_SEQ

#define CORE_PP_CARTESIAN_PRODUCT_SEQ(aseq, bseq) \
    CORE_PP_MAP_WITH_SEQ(_CORE_PP_CARTESIAN_PRODUCT_ITEM_SEQ, bseq, aseq)

/// Expands to a sequence of sequences representing the cartesian product of the
/// two given sequences.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// CORE_PP_EVAL_CARTESIAN_PRODUCT_SEQ((a,b,c),(1,2)) // ((a,1),(a,2),(b,1),(b,2),(c,1),(c,2))
/// ```
/// \endverbatim
#define CORE_PP_EVAL_CARTESIAN_PRODUCT_SEQ(aseq, bseq) \
    CORE_PP_EVAL(CORE_PP_LPAREN() CORE_PP_CARTESIAN_PRODUCT_SEQ(aseq, bseq) CORE_PP_RPAREN())
