// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once

/// Evaluates to nothing.
///
#define CORE_PP_EMPTY()

/// Evaluates to a literal comma character
///
#define CORE_PP_COMMA() ,

/// Evaluates to a literal left parenthesis character.
///
#define CORE_PP_LPAREN() (

/// Evaluates to a literal right parenthesis character.
///
#define CORE_PP_RPAREN() )

/// Evaluates to the zero-or-more passed arguments.
///
#define CORE_PP_PASS(...) __VA_ARGS__
