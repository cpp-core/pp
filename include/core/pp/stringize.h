// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once

/// Converts arguments into a string.
/// STRINGIZE(a) == "a"
/// STRINGIZE(a,b) == "a,b"
#define CORE_PP_STRINGIZE1(...) #__VA_ARGS__
#define CORE_PP_STRINGIZE(...) CORE_PP_STRINGIZE1(__VA_ARGS__)
