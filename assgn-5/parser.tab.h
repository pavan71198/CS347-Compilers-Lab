/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    GTE = 258,
    LTE = 259,
    LT = 260,
    GT = 261,
    NEQ = 262,
    EQ = 263,
    ASGN = 264,
    AND = 265,
    OR = 266,
    NOT = 267,
    PLUS = 268,
    MINUS = 269,
    TIMES = 270,
    DIVIDE = 271,
    MODULO = 272,
    INCREMENT = 273,
    DECREMENT = 274,
    IF = 275,
    ELSE = 276,
    SWITCH = 277,
    CASE = 278,
    DEFAULT = 279,
    BREAK = 280,
    CONTINUE = 281,
    THEN = 282,
    WHILE = 283,
    FOR = 284,
    OPEN_PAR = 285,
    OPEN_CURLY = 286,
    CLOSE_PAR = 287,
    CLOSE_CURLY = 288,
    COMMA = 289,
    SEMI = 290,
    OPEN_BRAC = 291,
    CLOSE_BRAC = 292,
    COLON = 293,
    INT = 294,
    FLOAT = 295,
    VOID = 296,
    RETURN = 297,
    CONST = 298,
    EXTERN = 299,
    STATIC = 300,
    REAL = 301,
    ID = 302,
    ERROR = 303,
    END = 304,
    NEG = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "parser.y" /* yacc.c:1927  */

	Node *node;

#line 113 "parser.tab.h" /* yacc.c:1927  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */