/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    TYPE = 259,                    /* TYPE  */
    ARRAY = 260,                   /* ARRAY  */
    ABRE_PARENTESES = 261,         /* ABRE_PARENTESES  */
    FECHA_PARENTESES = 262,        /* FECHA_PARENTESES  */
    A_COLCHETES = 263,             /* A_COLCHETES  */
    F_COLCHETES = 264,             /* F_COLCHETES  */
    OF = 265,                      /* OF  */
    LABEL = 266,                   /* LABEL  */
    PROCEDURE = 267,               /* PROCEDURE  */
    FUNCTION = 268,                /* FUNCTION  */
    T_IF = 269,                    /* T_IF  */
    T_THEN = 270,                  /* T_THEN  */
    T_ELSE = 271,                  /* T_ELSE  */
    T_WHILE = 272,                 /* T_WHILE  */
    T_DO = 273,                    /* T_DO  */
    T_IGUAL = 274,                 /* T_IGUAL  */
    T_DIFERENTE = 275,             /* T_DIFERENTE  */
    T_MAIOR_IGUAL = 276,           /* T_MAIOR_IGUAL  */
    T_MENOR_IGUAL = 277,           /* T_MENOR_IGUAL  */
    T_MAIOR = 278,                 /* T_MAIOR  */
    T_MENOR = 279,                 /* T_MENOR  */
    T_MAIS = 280,                  /* T_MAIS  */
    T_MENOS = 281,                 /* T_MENOS  */
    T_OR = 282,                    /* T_OR  */
    T_MULT = 283,                  /* T_MULT  */
    T_DIV = 284,                   /* T_DIV  */
    T_AND = 285,                   /* T_AND  */
    T_NOT = 286,                   /* T_NOT  */
    VIRGULA = 287,                 /* VIRGULA  */
    PONTO_E_VIRGULA = 288,         /* PONTO_E_VIRGULA  */
    DOIS_PONTOS = 289,             /* DOIS_PONTOS  */
    PONTO = 290,                   /* PONTO  */
    T_BEGIN = 291,                 /* T_BEGIN  */
    T_END = 292,                   /* T_END  */
    VAR = 293,                     /* VAR  */
    NUMERO = 294,                  /* NUMERO  */
    IDENT = 295,                   /* IDENT  */
    ATRIBUICAO = 296               /* ATRIBUICAO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */
