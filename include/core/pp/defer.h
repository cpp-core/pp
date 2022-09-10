// Copyright 2017, 2019 by Mark Melton
//

#pragma once
#include "core/pp/base.h"

// DEFER{1,2,3,4} - Force the pre-processor to defer expanding the
// given macro over N passes.
//
#define CORE_PP_DEFER1(id) id CORE_PP_EMPTY()
#define CORE_PP_DEFER2(id) id CORE_PP_EMPTY CORE_PP_EMPTY()()
#define CORE_PP_DEFER3(id) id CORE_PP_EMPTY CORE_PP_EMPTY CORE_PP_EMPTY()()()
#define CORE_PP_DEFER4(id) id CORE_PP_EMPTY CORE_PP_EMPTY CORE_PP_EMPTY CORE_PP_EMPTY()()()()

