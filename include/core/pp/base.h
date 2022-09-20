// Copyright 2017, 2019, 2022 by Mark Melton
//

#pragma once

/// Expands to nothing.
///
#define CORE_PP_EMPTY()

/// Expands to a literal comma character
///
#define CORE_PP_COMMA() ,

/// Expands to a literal left parenthesis character.
///
#define CORE_PP_LPAREN() (

/// Expands to a literal right parenthesis character.
///
#define CORE_PP_RPAREN() )

/// Expands to the zero-or-more passed arguments.
///
#define CORE_PP_PASS(...) __VA_ARGS__
