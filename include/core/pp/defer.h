// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/pp/base.h"

/// Defers the expansion of its argument for a single pass.
///
#define CORE_PP_DEFER1(id) id CORE_PP_EMPTY()

/// Defers the expansion of its argument for two passes.
///
#define CORE_PP_DEFER2(id) id CORE_PP_EMPTY CORE_PP_EMPTY()()

/// Defers the expansion of its argument for three passes.
///
#define CORE_PP_DEFER3(id) id CORE_PP_EMPTY CORE_PP_EMPTY CORE_PP_EMPTY()()()

/// Defers the expansion of its argument for four substitution passes.
///
#define CORE_PP_DEFER4(id) id CORE_PP_EMPTY CORE_PP_EMPTY CORE_PP_EMPTY CORE_PP_EMPTY()()()()
