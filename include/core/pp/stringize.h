// Copyright 2017, 2019 by Mark Melton
//

#pragma once

// STRINGIZE
// STRINGIZE(a) == "a"
// STRINGIZE(a,b) == "a,b"
#define CORE_PP_STRINGIZE1(...) #__VA_ARGS__
#define CORE_PP_STRINGIZE(...) CORE_PP_STRINGIZE1(__VA_ARGS__)
