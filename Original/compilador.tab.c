/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "compilador.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_simbolos.h"


int num_vars = 0;
int num_vars_temp = 0;
int nivel_lexico = -1;
int desloc = 0;
int last_rotulo = 0;
int error = 1;
int print_wait = 0;
int leit_wait = 0;
int func_proc = 1;
int par_subrt = 0;
int num_subrt = 0;
int dec_var = 0;
int print_r0 = 0;


pilha_tipos tabela_simbolos;
pilha_rotulos desvios;
pilha_tipos pilha_par;
fila_tipos fila_simbolos;
char print_list[TAM_TOKEN];
char name_func[TAM_TOKEN];
char erro_char[100];


#line 104 "compilador.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "compilador.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_TYPE = 4,                       /* TYPE  */
  YYSYMBOL_ARRAY = 5,                      /* ARRAY  */
  YYSYMBOL_ABRE_PARENTESES = 6,            /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 7,           /* FECHA_PARENTESES  */
  YYSYMBOL_A_COLCHETES = 8,                /* A_COLCHETES  */
  YYSYMBOL_F_COLCHETES = 9,                /* F_COLCHETES  */
  YYSYMBOL_OF = 10,                        /* OF  */
  YYSYMBOL_LABEL = 11,                     /* LABEL  */
  YYSYMBOL_PROCEDURE = 12,                 /* PROCEDURE  */
  YYSYMBOL_FUNCTION = 13,                  /* FUNCTION  */
  YYSYMBOL_T_IF = 14,                      /* T_IF  */
  YYSYMBOL_T_THEN = 15,                    /* T_THEN  */
  YYSYMBOL_T_ELSE = 16,                    /* T_ELSE  */
  YYSYMBOL_T_WHILE = 17,                   /* T_WHILE  */
  YYSYMBOL_T_DO = 18,                      /* T_DO  */
  YYSYMBOL_T_IGUAL = 19,                   /* T_IGUAL  */
  YYSYMBOL_T_DIFERENTE = 20,               /* T_DIFERENTE  */
  YYSYMBOL_T_MAIOR_IGUAL = 21,             /* T_MAIOR_IGUAL  */
  YYSYMBOL_T_MENOR_IGUAL = 22,             /* T_MENOR_IGUAL  */
  YYSYMBOL_T_MAIOR = 23,                   /* T_MAIOR  */
  YYSYMBOL_T_MENOR = 24,                   /* T_MENOR  */
  YYSYMBOL_T_MAIS = 25,                    /* T_MAIS  */
  YYSYMBOL_T_MENOS = 26,                   /* T_MENOS  */
  YYSYMBOL_T_OR = 27,                      /* T_OR  */
  YYSYMBOL_T_MULT = 28,                    /* T_MULT  */
  YYSYMBOL_T_DIV = 29,                     /* T_DIV  */
  YYSYMBOL_T_AND = 30,                     /* T_AND  */
  YYSYMBOL_T_NOT = 31,                     /* T_NOT  */
  YYSYMBOL_VIRGULA = 32,                   /* VIRGULA  */
  YYSYMBOL_PONTO_E_VIRGULA = 33,           /* PONTO_E_VIRGULA  */
  YYSYMBOL_DOIS_PONTOS = 34,               /* DOIS_PONTOS  */
  YYSYMBOL_PONTO = 35,                     /* PONTO  */
  YYSYMBOL_T_BEGIN = 36,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 37,                     /* T_END  */
  YYSYMBOL_VAR = 38,                       /* VAR  */
  YYSYMBOL_NUMERO = 39,                    /* NUMERO  */
  YYSYMBOL_IDENT = 40,                     /* IDENT  */
  YYSYMBOL_ATRIBUICAO = 41,                /* ATRIBUICAO  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_programa = 43,                  /* programa  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_bloco = 46,                     /* bloco  */
  YYSYMBOL_47_3 = 47,                      /* $@3  */
  YYSYMBOL_48_4 = 48,                      /* $@4  */
  YYSYMBOL_tipo = 49,                      /* tipo  */
  YYSYMBOL_parte_declara_vars = 50,        /* parte_declara_vars  */
  YYSYMBOL_51_5 = 51,                      /* $@5  */
  YYSYMBOL_declara_vars = 52,              /* declara_vars  */
  YYSYMBOL_lista_ident = 53,               /* lista_ident  */
  YYSYMBOL_parte_declara_subrotinas = 54,  /* parte_declara_subrotinas  */
  YYSYMBOL_procedimento_funcao = 55,       /* procedimento_funcao  */
  YYSYMBOL_declara_procedimento = 56,      /* declara_procedimento  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_declara_funcao = 59,            /* declara_funcao  */
  YYSYMBOL_60_8 = 60,                      /* $@8  */
  YYSYMBOL_61_9 = 61,                      /* $@9  */
  YYSYMBOL_identificador_subrotina = 62,   /* identificador_subrotina  */
  YYSYMBOL_identificador_func = 63,        /* identificador_func  */
  YYSYMBOL_parametros_formais = 64,        /* parametros_formais  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_66_11 = 66,                     /* $@11  */
  YYSYMBOL_sec_parametros_formais = 67,    /* sec_parametros_formais  */
  YYSYMBOL_lista_ident_par_r = 68,         /* lista_ident_par_r  */
  YYSYMBOL_lista_ident_par_f = 69,         /* lista_ident_par_f  */
  YYSYMBOL_comando_composto = 70,          /* comando_composto  */
  YYSYMBOL_comando = 71,                   /* comando  */
  YYSYMBOL_comando_s_rotulo = 72,          /* comando_s_rotulo  */
  YYSYMBOL_variavel_ident = 73,            /* variavel_ident  */
  YYSYMBOL_74_12 = 74,                     /* $@12  */
  YYSYMBOL_funcao_atr = 75,                /* funcao_atr  */
  YYSYMBOL_chamada_proced = 76,            /* chamada_proced  */
  YYSYMBOL_77_13 = 77,                     /* $@13  */
  YYSYMBOL_comando_condicional = 78,       /* comando_condicional  */
  YYSYMBOL_79_14 = 79,                     /* $@14  */
  YYSYMBOL_80_15 = 80,                     /* $@15  */
  YYSYMBOL_else_condicional = 81,          /* else_condicional  */
  YYSYMBOL_82_16 = 82,                     /* $@16  */
  YYSYMBOL_comando_repetitivo = 83,        /* comando_repetitivo  */
  YYSYMBOL_84_17 = 84,                     /* $@17  */
  YYSYMBOL_85_18 = 85,                     /* $@18  */
  YYSYMBOL_86_19 = 86,                     /* $@19  */
  YYSYMBOL_lista_de_expressao = 87,        /* lista_de_expressao  */
  YYSYMBOL_expressao_bool = 88,            /* expressao_bool  */
  YYSYMBOL_relacao = 89,                   /* relacao  */
  YYSYMBOL_expressao_simples = 90,         /* expressao_simples  */
  YYSYMBOL_termo = 91,                     /* termo  */
  YYSYMBOL_fator = 92,                     /* fator  */
  YYSYMBOL_chamada_func = 93,              /* chamada_func  */
  YYSYMBOL_94_20 = 94,                     /* $@20  */
  YYSYMBOL_par_func = 95,                  /* par_func  */
  YYSYMBOL_identificador = 96              /* identificador  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    53,    48,    61,    65,    61,    95,   105,
     104,   118,   124,   130,   139,   144,   150,   151,   151,   155,
     155,   160,   190,   159,   231,   255,   230,   293,   301,   311,
     313,   310,   316,   321,   328,   333,   339,   345,   350,   355,
     360,   366,   373,   377,   382,   384,   386,   388,   394,   393,
     415,   432,   449,   448,   454,   460,   464,   459,   482,   481,
     499,   510,   523,   528,   509,   548,   557,   567,   578,   579,
     580,   581,   582,   583,   588,   590,   598,   610,   612,   620,
     631,   633,   635,   639,   650,   649,   673,   680
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "TYPE",
  "ARRAY", "ABRE_PARENTESES", "FECHA_PARENTESES", "A_COLCHETES",
  "F_COLCHETES", "OF", "LABEL", "PROCEDURE", "FUNCTION", "T_IF", "T_THEN",
  "T_ELSE", "T_WHILE", "T_DO", "T_IGUAL", "T_DIFERENTE", "T_MAIOR_IGUAL",
  "T_MENOR_IGUAL", "T_MAIOR", "T_MENOR", "T_MAIS", "T_MENOS", "T_OR",
  "T_MULT", "T_DIV", "T_AND", "T_NOT", "VIRGULA", "PONTO_E_VIRGULA",
  "DOIS_PONTOS", "PONTO", "T_BEGIN", "T_END", "VAR", "NUMERO", "IDENT",
  "ATRIBUICAO", "$accept", "programa", "$@1", "$@2", "bloco", "$@3", "$@4",
  "tipo", "parte_declara_vars", "$@5", "declara_vars", "lista_ident",
  "parte_declara_subrotinas", "procedimento_funcao",
  "declara_procedimento", "$@6", "$@7", "declara_funcao", "$@8", "$@9",
  "identificador_subrotina", "identificador_func", "parametros_formais",
  "$@10", "$@11", "sec_parametros_formais", "lista_ident_par_r",
  "lista_ident_par_f", "comando_composto", "comando", "comando_s_rotulo",
  "variavel_ident", "$@12", "funcao_atr", "chamada_proced", "$@13",
  "comando_condicional", "$@14", "$@15", "else_condicional", "$@16",
  "comando_repetitivo", "$@17", "$@18", "$@19", "lista_de_expressao",
  "expressao_bool", "relacao", "expressao_simples", "termo", "fator",
  "chamada_func", "$@20", "par_func", "identificador", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-85)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -68,    45,    31,   -68,    11,   -68,    35,    11,     1,   -68,
      25,    11,   -68,   -68,   -68,    39,    27,   -68,   -68,     5,
      11,   -68,   -68,     5,   -68,   -68,   -68,    11,    -7,    36,
      37,    43,   -68,    -3,    11,   -68,    69,   -68,    69,    -8,
     -68,    11,    47,   -68,   -68,    49,    50,   -68,   -68,   -68,
     -68,   -18,   -68,   -68,   -68,   -68,    53,   -68,   -14,   -68,
      11,     7,     7,    -1,    -8,   -68,   -68,    11,    56,    16,
     -68,   -68,    58,     7,   -68,   -68,    78,    13,    41,   -68,
      77,   -68,   -68,     7,   -68,   -68,   -68,    23,   -68,    21,
      85,    11,    11,    60,   -68,    87,    80,   -68,   -68,   -68,
     -68,   -68,   -68,     7,     7,     7,     7,     7,    98,    88,
       7,   -68,    11,    11,    11,    30,   -68,   -68,   -68,   -68,
     -68,   -68,    -8,   -68,   -68,   -68,   -68,   -68,     7,   -68,
     -68,     3,   -68,   -68,   -68,    34,    11,    72,    91,     4,
      -8,   -68,     7,    11,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,    -8,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,    87,     0,     0,     0,    15,
       0,     0,     3,    14,     5,     0,    11,     4,     9,    18,
       0,    21,    24,     6,    17,    19,    20,    10,     0,     0,
       0,     0,    16,     0,     0,    27,    32,    28,    32,     0,
       7,     0,     0,     8,    29,     0,     0,    55,    61,    48,
      45,     0,    43,    44,    46,    47,     0,    13,     0,    22,
       0,     0,     0,    54,     0,    41,    12,     0,    30,     0,
      40,     5,     0,     0,    83,    56,     0,    74,    77,    81,
      80,    62,    52,     0,    49,    51,    42,     0,    38,     0,
       0,     0,     0,     0,    25,     0,     0,    68,    69,    73,
      71,    72,    70,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,     0,     0,    31,    39,    36,    23,
       5,    82,     0,    67,    75,    76,    78,    79,     0,    85,
      63,     0,    66,    37,    34,     0,     0,     0,    60,     0,
       0,    53,     0,     0,    35,    26,    58,    57,    86,    64,
      65,    33,     0,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,   -68,   -68,   -67,   -68,   -68,   -40,   -68,   -68,
     -68,    -6,   -68,    89,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,    73,   -68,   -68,   -68,     0,    24,    84,   -68,
     -62,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -12,    55,   -68,   -61,   -68,
     -35,   -68,   -68,   -68,    -4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    14,    15,    16,    31,    42,    19,    20,
      27,     8,    23,    24,    25,    29,    71,    26,    30,   120,
      36,    38,    45,    58,    90,    68,    87,    69,    50,    51,
      52,    53,    63,    84,    85,   110,    54,    61,    96,   147,
     152,    55,    62,   109,   140,   131,    75,   103,    76,    77,
      78,    79,   108,   129,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,    56,    86,     9,    93,    82,    47,    13,    10,    48,
     141,   148,    95,    73,    28,    64,     9,    21,    22,    65,
      72,    33,   111,     9,    67,    11,     5,    34,    39,    11,
      43,    41,    49,    11,     4,   142,   142,    43,   104,   105,
      83,     7,   123,   124,   125,     3,    74,     5,    91,   132,
      92,     5,   118,   137,    70,   112,    43,   113,    12,   114,
     138,     5,    91,    88,   136,    18,   112,   132,   143,   106,
     107,   126,   127,   134,    17,    44,    35,    37,   149,    39,
      57,   150,    59,   -84,    60,    70,    66,   117,    43,    89,
     153,    94,   116,   119,   121,   122,   144,    97,    98,    99,
     100,   101,   102,   151,   128,   145,   130,   146,   133,    43,
      88,    46,    32,   115,   135,    40,   139,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,     0,     0,     0,     0,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
       4,    41,    64,     7,    71,     6,    14,    11,     7,    17,
       7,     7,    73,     6,    20,    33,    20,    12,    13,    37,
      60,    27,    83,    27,    38,    32,    40,    34,    36,    32,
      34,    34,    40,    32,     3,    32,    32,    41,    25,    26,
      41,     6,   103,   104,   105,     0,    39,    40,    32,   110,
      34,    40,    92,   120,    58,    32,    60,    34,    33,    38,
     122,    40,    32,    67,    34,    38,    32,   128,    34,    28,
      29,   106,   107,   113,    35,     6,    40,    40,   140,    36,
      33,   142,    33,     6,    34,    89,    33,    91,    92,    33,
     152,    33,     7,    33,     7,    15,   136,    19,    20,    21,
      22,    23,    24,   143,     6,    33,    18,    16,   112,   113,
     114,    38,    23,    89,   114,    31,   128,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    44,     0,     3,    40,    96,     6,    53,    96,
       7,    32,    33,    96,    45,    46,    47,    35,    38,    50,
      51,    12,    13,    54,    55,    56,    59,    52,    53,    57,
      60,    48,    55,    53,    34,    40,    62,    40,    63,    36,
      70,    34,    49,    96,     6,    64,    64,    14,    17,    40,
      70,    71,    72,    73,    78,    83,    49,    33,    65,    33,
      34,    79,    84,    74,    33,    37,    33,    38,    67,    69,
      96,    58,    49,     6,    39,    88,    90,    91,    92,    93,
      96,    88,     6,    41,    75,    76,    72,    68,    96,    33,
      66,    32,    34,    46,    33,    90,    80,    19,    20,    21,
      22,    23,    24,    89,    25,    26,    28,    29,    94,    85,
      77,    90,    32,    34,    38,    69,     7,    96,    49,    33,
      61,     7,    15,    90,    90,    90,    92,    92,     6,    95,
      18,    87,    90,    96,    49,    68,    34,    46,    72,    87,
      86,     7,    32,    34,    49,    33,    16,    81,     7,    72,
      90,    49,    82,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    44,    45,    43,    47,    48,    46,    49,    51,
      50,    50,    52,    52,    53,    53,    54,    54,    54,    55,
      55,    57,    58,    56,    60,    61,    59,    62,    63,    65,
      66,    64,    64,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    71,    71,    72,    72,    72,    72,    74,    73,
      75,    75,    77,    76,    76,    79,    80,    78,    82,    81,
      81,    84,    85,    86,    83,    87,    87,    88,    89,    89,
      89,    89,    89,    89,    90,    90,    90,    91,    91,    91,
      92,    92,    92,    92,    94,    93,    95,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,    10,     0,     0,     5,     1,     0,
       3,     0,     5,     4,     3,     1,     2,     1,     0,     1,
       1,     0,     0,     8,     0,     0,    10,     1,     1,     0,
       0,     5,     0,     6,     4,     5,     3,     3,     1,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     0,     3,
       2,     1,     0,     4,     0,     0,     0,     7,     0,     3,
       0,     0,     0,     0,     7,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       1,     1,     3,     1,     0,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 48 "compilador.y"
             {
             geraCodigo (NULL, "INPP");
             }
#line 1301 "compilador.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 53 "compilador.y"
                         {num_vars_temp = 0; num_vars = 0;}
#line 1307 "compilador.tab.c"
    break;

  case 4: /* programa: $@1 PROGRAM identificador ABRE_PARENTESES lista_ident FECHA_PARENTESES PONTO_E_VIRGULA $@2 bloco PONTO  */
#line 54 "compilador.y"
                         {
             geraCodigo (NULL, "PARA");
             }
#line 1315 "compilador.tab.c"
    break;

  case 5: /* $@3: %empty  */
#line 61 "compilador.y"
                {	nivel_lexico++; desloc = 0; 
		}
#line 1322 "compilador.tab.c"
    break;

  case 6: /* $@4: %empty  */
#line 65 "compilador.y"
                { 	
			if (nivel_lexico == 0 && print_r0 == 0 && func_proc == 0){
			char instrucao[50];
			sprintf(instrucao, "R00");
			geraCodigo(instrucao, "NADA");
			print_r0++;
		} 
		}
#line 1335 "compilador.tab.c"
    break;

  case 7: /* bloco: $@3 parte_declara_vars parte_declara_subrotinas $@4 comando_composto  */
#line 74 "compilador.y"
                { 
			//print_pilha(&tabela_simbolos); printf("\n----------\n");
			num_vars_temp = pilha_para_lista(&fila_simbolos, &tabela_simbolos);
			nivel_lexico--;
			char instrucao[30];
			sprintf(instrucao, "DMEM %d", num_vars_temp);
			num_vars_temp = 0;
			geraCodigo(NULL, instrucao);
			tipo_t aux = fila_simbolos.fila[fila_simbolos.end];
			fila_simbolos.end--;
			while (aux.tipo == PROCEDIMENTO || aux.tipo == FUNCAO){
				pull(&tabela_simbolos, aux);
				aux  = fila_simbolos.fila[fila_simbolos.end];
				fila_simbolos.end--;
			}
			limpa_lista(&fila_simbolos);
		}
#line 1357 "compilador.tab.c"
    break;

  case 8: /* tipo: identificador  */
#line 96 "compilador.y"
                { 
			if (strcmp("integer", token) != 0)
				imprimeErro("Identificador com tipo invalido");
		}
#line 1366 "compilador.tab.c"
    break;

  case 9: /* $@5: %empty  */
#line 105 "compilador.y"
                {
		limpa_lista(&fila_simbolos); dec_var = 1;
		}
#line 1374 "compilador.tab.c"
    break;

  case 10: /* parte_declara_vars: VAR $@5 declara_vars  */
#line 109 "compilador.y"
                { 
			num_vars_temp = lista_para_pilha(&fila_simbolos, &tabela_simbolos);
			char instrucao[30];
			sprintf(instrucao, "AMEM %d", num_vars_temp);
			geraCodigo(NULL, instrucao);
			num_vars_temp = 0;
			limpa_lista(&fila_simbolos);
			dec_var = 0;
		}
#line 1388 "compilador.tab.c"
    break;

  case 14: /* lista_ident: lista_ident VIRGULA identificador  */
#line 142 "compilador.y"
        {tipo_t s = create_var_s(); in(&fila_simbolos, s); desloc++; }
#line 1394 "compilador.tab.c"
    break;

  case 15: /* lista_ident: identificador  */
#line 145 "compilador.y"
        {tipo_t s = create_var_s(); in(&fila_simbolos, s); desloc++;}
#line 1400 "compilador.tab.c"
    break;

  case 21: /* $@6: %empty  */
#line 160 "compilador.y"
        {
		rotulo r;
		r.enter = last_rotulo;
		r.exit = last_rotulo+1;
		last_rotulo++;
		char instrucao[50];
		if (func_proc == 1){
			sprintf(instrucao, "DSVS R%02d", r.enter);
			geraCodigo(NULL, instrucao);
			func_proc = 0;
		}

		num_subrt++;
		if (num_subrt > 1){
				char instrucao[50];
				sprintf(instrucao, "DSVS R%02d", r.enter);
				geraCodigo(NULL, instrucao);
			}

		sprintf(instrucao, "R%02d", r.exit);
		char n_lex[50];
		sprintf(n_lex, "ENPR %d", nivel_lexico+1);
		geraCodigo(instrucao, n_lex);
		pull_r(&desvios, r);
		limpa_lista(&fila_simbolos);
		par_subrt = 1;
	}
#line 1432 "compilador.tab.c"
    break;

  case 22: /* $@7: %empty  */
#line 190 "compilador.y"
                {
			tipo_t temp;
			tipo_simbolos t[10];
			int n_temp = 0;
			while(pilha_par.topo >=0){
				temp =  push(&pilha_par);
				t[n_temp] = temp.tipo;
				set_desloc(&temp, -4-n_temp);
				n_temp++;
				in(&fila_simbolos, temp);
			}
			temp = out(&fila_simbolos);
			temp.atributos.proc.num_vars = n_temp;
			for (int i = n_temp-1; i >= 0; i--)
				temp.atributos.proc.par[n_temp-i-1] = t[i];
			pull(&tabela_simbolos, temp);
			lista_para_pilha(&fila_simbolos, &tabela_simbolos);
			//print_pilha(&tabela_simbolos);
			par_subrt = 0;
		}
#line 1457 "compilador.tab.c"
    break;

  case 23: /* declara_procedimento: PROCEDURE $@6 identificador_subrotina parametros_formais PONTO_E_VIRGULA $@7 bloco PONTO_E_VIRGULA  */
#line 212 "compilador.y"
                {
			tipo_t temp;
			temp = top(&tabela_simbolos);
			char instrucao[100];
        	sprintf(instrucao, "RTPR %d, %d", temp.atributos.proc.nivel_lexico, temp.atributos.proc.num_vars);
        	geraCodigo(NULL, instrucao);
			num_subrt--;

			rotulo r = push_r(&desvios);
			if(r.enter != 0 && num_subrt != 0){
				sprintf(instrucao, "R%02d", r.enter);
				geraCodigo(instrucao, "NADA");
			}
		}
#line 1476 "compilador.tab.c"
    break;

  case 24: /* $@8: %empty  */
#line 231 "compilador.y"
        {
		rotulo r;
		r.enter = last_rotulo;
		r.exit = last_rotulo+1;
		last_rotulo++;
		char instrucao[50];
		if (func_proc == 1){
			sprintf(instrucao, "DSVS R%02d", r.enter);
			geraCodigo(NULL, instrucao);
			func_proc = 0;
		}
		sprintf(instrucao, "R%02d", r.exit);
		char n_lex[50];
		sprintf(n_lex, "ENPR %d", nivel_lexico+1);
		geraCodigo(instrucao, n_lex);
		pull_r(&desvios, r);
		limpa_lista(&fila_simbolos);
		par_subrt = 1;
	}
#line 1500 "compilador.tab.c"
    break;

  case 25: /* $@9: %empty  */
#line 255 "compilador.y"
        {
			tipo_t temp;
			tipo_simbolos t[10];
			int n_temp = 0;
			while(pilha_par.topo >= 0){
				temp =  push(&pilha_par);
				set_desloc(&temp, -4-n_temp);
				t[n_temp] = temp.tipo;
				n_temp++;
				in(&fila_simbolos, temp);
			}
			temp = out(&fila_simbolos);
			temp.atributos.func.num_vars = n_temp;
			temp.atributos.func.deslocamento = -4-n_temp;
			for (int i = n_temp-1; i >= 0; i--)
				temp.atributos.func.par[n_temp-i-1] = t[i];
			pull(&tabela_simbolos, temp);
			lista_para_pilha(&fila_simbolos, &tabela_simbolos);
			par_subrt = 0;
		}
#line 1525 "compilador.tab.c"
    break;

  case 26: /* declara_funcao: FUNCTION $@8 identificador_func parametros_formais DOIS_PONTOS tipo PONTO_E_VIRGULA $@9 bloco PONTO_E_VIRGULA  */
#line 277 "compilador.y"
                {
			tipo_t temp;
			temp = top(&tabela_simbolos);
			char instrucao[100];
        	sprintf(instrucao, "RTPR %d, %d", temp.atributos.func.nivel_lexico, temp.atributos.func.num_vars);
        	geraCodigo(NULL, instrucao);

			rotulo r = push_r(&desvios);
			if(r.enter != 0){
				sprintf(instrucao, "R%02d", r.enter);
				geraCodigo(instrucao, "NADA");
			}
		}
#line 1543 "compilador.tab.c"
    break;

  case 27: /* identificador_subrotina: IDENT  */
#line 294 "compilador.y"
                { 
			tipo_t p = create_proc();
			in(&fila_simbolos, p);
		}
#line 1552 "compilador.tab.c"
    break;

  case 28: /* identificador_func: IDENT  */
#line 302 "compilador.y"
                { 
			tipo_t p = create_func();
			in(&fila_simbolos, p);
		}
#line 1561 "compilador.tab.c"
    break;

  case 29: /* $@10: %empty  */
#line 311 "compilador.y"
        {desloc = -4;}
#line 1567 "compilador.tab.c"
    break;

  case 30: /* $@11: %empty  */
#line 313 "compilador.y"
        {//print_pilha(&pilha_par);
	}
#line 1574 "compilador.tab.c"
    break;

  case 37: /* lista_ident_par_r: lista_ident_par_r VIRGULA identificador  */
#line 348 "compilador.y"
        {num_vars++; num_vars_temp++; tipo_t s = create_var_r(); pull(&pilha_par, s); desloc--;}
#line 1580 "compilador.tab.c"
    break;

  case 38: /* lista_ident_par_r: identificador  */
#line 351 "compilador.y"
        {num_vars++; num_vars_temp++; tipo_t s = create_var_r(); pull(&pilha_par, s); desloc--;}
#line 1586 "compilador.tab.c"
    break;

  case 39: /* lista_ident_par_f: lista_ident_par_f VIRGULA identificador  */
#line 358 "compilador.y"
        {num_vars++; num_vars_temp++; tipo_t s = create_var_f(); pull(&pilha_par, s); desloc--;}
#line 1592 "compilador.tab.c"
    break;

  case 40: /* lista_ident_par_f: identificador  */
#line 361 "compilador.y"
        {num_vars++; num_vars_temp++; tipo_t s = create_var_f(); pull(&pilha_par, s); desloc--;}
#line 1598 "compilador.tab.c"
    break;

  case 48: /* $@12: %empty  */
#line 394 "compilador.y"
        {
		strcpy(print_list,"");
		if (strcmp("write", token) == 0){
			char instrucao[30];
			sprintf(instrucao, "IMPR");
			strcpy(print_list, instrucao);	
		} else if (strcmp("read", token) == 0){
			leit_wait = 1;
		}
		else { strcpy(print_list,token);
			strcpy(name_func,token);
		}
		print_wait = 1;
	}
#line 1617 "compilador.tab.c"
    break;

  case 49: /* variavel_ident: IDENT $@12 funcao_atr  */
#line 409 "compilador.y"
        {
		strcpy(name_func,"");
	}
#line 1625 "compilador.tab.c"
    break;

  case 50: /* funcao_atr: ATRIBUICAO expressao_simples  */
#line 417 "compilador.y"
                {		
			tipo_t temp = busca_ident_char(&tabela_simbolos, print_list);
			if(error){
				char instrucao[30];
				if (temp.tipo == PARAMETRO_REAL){
					sprintf(instrucao, "ARMI %d, %d", get_n_lex(temp), get_n_desloc(temp));
					geraCodigo(NULL, instrucao); 
				} else {
					sprintf(instrucao, "ARMZ %d, %d", get_n_lex(temp), get_n_desloc(temp));
					geraCodigo(NULL, instrucao); 
				}
			}
			error = 1;
		}
#line 1644 "compilador.tab.c"
    break;

  case 51: /* funcao_atr: chamada_proced  */
#line 433 "compilador.y"
                {
			tipo_t temp = busca_ident_char(&tabela_simbolos, print_list);
			if(error){
				char instrucao[30];
				sprintf(instrucao, "CHPR R%02d, %d", temp.atributos.proc.rotulo, nivel_lexico);
				geraCodigo(NULL, instrucao); 
			}
			//print_pilha(&tabela_simbolos);
			//printf("%s\n", print_list);
		}
#line 1659 "compilador.tab.c"
    break;

  case 52: /* $@13: %empty  */
#line 449 "compilador.y"
                {
			num_vars_temp = 0;
			par_subrt = 1;
		}
#line 1668 "compilador.tab.c"
    break;

  case 53: /* chamada_proced: ABRE_PARENTESES $@13 lista_de_expressao FECHA_PARENTESES  */
#line 454 "compilador.y"
                         {leit_wait = 0; print_wait = 0; par_subrt = 0;}
#line 1674 "compilador.tab.c"
    break;

  case 55: /* $@14: %empty  */
#line 460 "compilador.y"
                {
			strcpy(erro_char,"Expressão não booleana");
		}
#line 1682 "compilador.tab.c"
    break;

  case 56: /* $@15: %empty  */
#line 464 "compilador.y"
                {	
			strcpy(erro_char, "Erro de sintaxe");
			rotulo r;
			r.enter = last_rotulo;
			r.exit = last_rotulo+1;
			last_rotulo += 2;
			char instrucao[50];
			sprintf(instrucao, "DSVF R%02d", r.exit);
        	geraCodigo(NULL, instrucao);
			pull_r(&desvios, r);
		}
#line 1698 "compilador.tab.c"
    break;

  case 58: /* $@16: %empty  */
#line 482 "compilador.y"
                {
			rotulo r = top_r(&desvios);
			char instrucao[50];
			sprintf(instrucao, "DSVS R%02d", r.enter);
			geraCodigo(NULL, instrucao);

			sprintf(instrucao, "R%02d", r.exit);
			geraCodigo(instrucao, "NADA");
		}
#line 1712 "compilador.tab.c"
    break;

  case 59: /* else_condicional: T_ELSE $@16 comando_s_rotulo  */
#line 492 "compilador.y"
                {
			rotulo r = push_r(&desvios);
			char instrucao[50];
			sprintf(instrucao, "R%02d", r.enter);
			geraCodigo(instrucao, "NADA");
		}
#line 1723 "compilador.tab.c"
    break;

  case 60: /* else_condicional: %empty  */
#line 499 "compilador.y"
                {
			rotulo r = push_r(&desvios);
			char instrucao[50];
			sprintf(instrucao, "R%02d", r.exit);
			geraCodigo(instrucao, "NADA");
		}
#line 1734 "compilador.tab.c"
    break;

  case 61: /* $@17: %empty  */
#line 510 "compilador.y"
                {
			rotulo r;
			r.enter = last_rotulo;
			r.exit = last_rotulo+1;
			last_rotulo += 2;
			char instrucao[50];
			sprintf(instrucao, "R%02d", r.enter);
			geraCodigo(instrucao, "NADA");
			pull_r(&desvios, r);
			strcpy(erro_char,"Expressão não booleana");
		
		}
#line 1751 "compilador.tab.c"
    break;

  case 62: /* $@18: %empty  */
#line 523 "compilador.y"
                {
			strcpy(erro_char, "Erro de sintaxe");
		}
#line 1759 "compilador.tab.c"
    break;

  case 63: /* $@19: %empty  */
#line 528 "compilador.y"
                {
			rotulo r = top_r(&desvios);
			char instrucao[50];
        	sprintf(instrucao, "DSVF R%02d", r.exit);
        	geraCodigo(NULL, instrucao);
		}
#line 1770 "compilador.tab.c"
    break;

  case 64: /* comando_repetitivo: T_WHILE $@17 expressao_bool $@18 T_DO $@19 comando_s_rotulo  */
#line 535 "compilador.y"
                {
			rotulo r = push_r(&desvios);
			char instrucao[50];
			sprintf(instrucao, "DSVS R%02d", r.enter);
			geraCodigo(NULL, instrucao);

			sprintf(instrucao, "R%02d", r.exit);
			geraCodigo(instrucao, "NADA");
		}
#line 1784 "compilador.tab.c"
    break;

  case 65: /* lista_de_expressao: lista_de_expressao VIRGULA expressao_simples  */
#line 551 "compilador.y"
                {
			if(par_subrt == 1){
				num_vars_temp++;
			}
		}
#line 1794 "compilador.tab.c"
    break;

  case 66: /* lista_de_expressao: expressao_simples  */
#line 558 "compilador.y"
                {
			if(par_subrt == 1){
				num_vars_temp++;
			}
		}
#line 1804 "compilador.tab.c"
    break;

  case 67: /* expressao_bool: expressao_simples relacao expressao_simples  */
#line 570 "compilador.y"
                {
			geraCodigo(NULL, print_list);
		}
#line 1812 "compilador.tab.c"
    break;

  case 68: /* relacao: T_IGUAL  */
#line 578 "compilador.y"
                {char instrucao[30]; sprintf(instrucao, "CMIG"); strcpy(print_list, instrucao);}
#line 1818 "compilador.tab.c"
    break;

  case 69: /* relacao: T_DIFERENTE  */
#line 579 "compilador.y"
                    {char instrucao[30]; sprintf(instrucao, "CMDG"); strcpy(print_list, instrucao);}
#line 1824 "compilador.tab.c"
    break;

  case 70: /* relacao: T_MENOR  */
#line 580 "compilador.y"
                {char instrucao[30]; sprintf(instrucao, "CMME"); strcpy(print_list, instrucao);}
#line 1830 "compilador.tab.c"
    break;

  case 71: /* relacao: T_MENOR_IGUAL  */
#line 581 "compilador.y"
                      {char instrucao[30]; sprintf(instrucao, "CMEG"); strcpy(print_list, instrucao);}
#line 1836 "compilador.tab.c"
    break;

  case 72: /* relacao: T_MAIOR  */
#line 582 "compilador.y"
                {char instrucao[30]; sprintf(instrucao, "CMMA"); strcpy(print_list, instrucao);}
#line 1842 "compilador.tab.c"
    break;

  case 73: /* relacao: T_MAIOR_IGUAL  */
#line 583 "compilador.y"
                      {char instrucao[30]; sprintf(instrucao, "CMAG"); strcpy(print_list, instrucao);}
#line 1848 "compilador.tab.c"
    break;

  case 75: /* expressao_simples: termo T_MAIS expressao_simples  */
#line 593 "compilador.y"
                { 	char instrucao[30];
			sprintf(instrucao, "SOMA");
			geraCodigo(NULL, instrucao); 
		}
#line 1857 "compilador.tab.c"
    break;

  case 76: /* expressao_simples: termo T_MENOS expressao_simples  */
#line 601 "compilador.y"
                { 
			char instrucao[30];
			sprintf(instrucao, "SUBT");
			geraCodigo(NULL, instrucao); 
		}
#line 1867 "compilador.tab.c"
    break;

  case 78: /* termo: fator T_MULT fator  */
#line 615 "compilador.y"
                { 	char instrucao[30];
			sprintf(instrucao, "MULT");
			geraCodigo(NULL, instrucao); 
		}
#line 1876 "compilador.tab.c"
    break;

  case 79: /* termo: fator T_DIV fator  */
#line 623 "compilador.y"
                { 	char instrucao[30];
			sprintf(instrucao, "DIVI");
			geraCodigo(NULL, instrucao); 
		}
#line 1885 "compilador.tab.c"
    break;

  case 83: /* fator: NUMERO  */
#line 640 "compilador.y"
                {
			char instrucao[30];
			sprintf(instrucao, "CRCT %s", token);
			geraCodigo(NULL, instrucao);
		}
#line 1895 "compilador.tab.c"
    break;

  case 84: /* $@20: %empty  */
#line 650 "compilador.y"
                {
			print_wait = 1;
			num_vars_temp = 0;
			par_subrt = 1;
		}
#line 1905 "compilador.tab.c"
    break;

  case 85: /* chamada_func: identificador $@20 par_func  */
#line 656 "compilador.y"
                {
			leit_wait = 0; print_wait = 0; par_subrt = 0;
			tipo_t temp = busca_ident_char(&tabela_simbolos, name_func);

			if (num_vars_temp != temp.atributos.func.num_vars){
				imprimeErro("Numero de variaveis incompativel");
			}

			if(error){
				char instrucao[30];
				sprintf(instrucao, "CHPR R%02d, %d", temp.atributos.func.rotulo, nivel_lexico);
				geraCodigo(NULL, instrucao); 
			}
		}
#line 1924 "compilador.tab.c"
    break;

  case 87: /* identificador: IDENT  */
#line 681 "compilador.y"
   {
		if (strcmp("write", token) != 0 && strcmp("read", token) != 0){
			tipo_t temp = busca_ident(&tabela_simbolos);
			if (temp.tipo == FUNCAO){
				strcpy(name_func,temp.identificador);
				char instrucao[30];
				sprintf(instrucao, "AMEM 1");
				geraCodigo(NULL, instrucao);
			}
			else if(error && leit_wait != 1 && par_subrt != 1 && temp.tipo != PROCEDIMENTO && dec_var != 1){
				switch(temp.tipo){
					case PARAMETRO_REAL:{
						char instrucao[30];
						sprintf(instrucao, "CRVI %d, %d", get_n_lex(temp), get_n_desloc(temp));
						geraCodigo(NULL, instrucao); 
						break;
					}
					default:{
						char instrucao[30];
						sprintf(instrucao, "CRVL %d, %d", get_n_lex(temp), get_n_desloc(temp));
						geraCodigo(NULL, instrucao);
					}
				} 
			}
			error = 1;
			if (print_wait == 1){
				if (strcmp("IMPR", print_list) == 0){
					switch(temp.tipo){
					case PARAMETRO_REAL:{
						char instrucao[30];
						sprintf(instrucao, "CRVI %d, %d", get_n_lex(temp), get_n_desloc(temp));
						geraCodigo(NULL, instrucao); 
						break;
					}
					default:{
						char instrucao[30];
						sprintf(instrucao, "CRVL %d, %d", get_n_lex(temp), get_n_desloc(temp));
						geraCodigo(NULL, instrucao);
					}
				}
					geraCodigo(NULL, print_list);
				} 
			}
			if (leit_wait == 1){
				tipo_t temp = busca_ident(&tabela_simbolos);
				if(error){
					char instrucao[30];
					sprintf(instrucao, "LEIT");
					geraCodigo(NULL, instrucao);
					sprintf(instrucao, "ARMZ %d, %d", get_n_lex(temp), get_n_desloc(temp));
					geraCodigo(NULL, instrucao); 
				}
				error = 1;
			} 
			else if (par_subrt == 1 && (strcmp("IMPR", print_list) != 0)){
				tipo_t subr = busca_ident_char(&tabela_simbolos, name_func);
				tipo_simbolos t = extrai_index(subr, num_vars_temp);
				tipo_t temp = busca_ident(&tabela_simbolos);
				if (num_vars_temp < get_n_var(subr)){
				switch (temp.tipo){
					case VARIAVEL_SIMPLES: {
						if (t == PARAMETRO_FORMAL){
							//print_pilha(&tabela_simbolos);
							char instrucao[30];
							sprintf(instrucao, "CRVL %d, %d", get_n_lex(temp), get_n_desloc(temp));
							geraCodigo(NULL, instrucao);
						} else if(t == PARAMETRO_REAL){
							//print_pilha(&tabela_simbolos);
							char instrucao[30];
							sprintf(instrucao, "CREN %d, %d", get_n_lex(temp), get_n_desloc(temp));
							geraCodigo(NULL, instrucao);
						}
						break;
					}
    				case PARAMETRO_FORMAL: {
						if (t == PARAMETRO_FORMAL){
							//print_pilha(&tabela_simbolos);
							char instrucao[30];
							sprintf(instrucao, "CRVL %d, %d", get_n_lex(temp), get_n_desloc(temp));
							geraCodigo(NULL, instrucao);
						} else if(t == PARAMETRO_REAL){
							//print_pilha(&tabela_simbolos);
							char instrucao[30];
							sprintf(instrucao, "CREN %d, %d", get_n_lex(temp), get_n_desloc(temp));
							geraCodigo(NULL, instrucao);
						}
						break;
					}
    				case PARAMETRO_REAL: {
						if (t == PARAMETRO_FORMAL){
							//print_pilha(&tabela_simbolos);
							char instrucao[30];
							sprintf(instrucao, "CRVI %d, %d", get_n_lex(temp), get_n_desloc(temp));
							geraCodigo(NULL, instrucao);
						} else if(t == PARAMETRO_REAL){
							//print_pilha(&tabela_simbolos);
							char instrucao[30];
							sprintf(instrucao, "CRVL %d, %d", get_n_lex(temp), get_n_desloc(temp));
							geraCodigo(NULL, instrucao);
						}
						break;
					}
				}}
			}

		}
	}
#line 2036 "compilador.tab.c"
    break;


#line 2040 "compilador.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 791 "compilador.y"


void yyerror(const char *s) {
    imprimeErro(erro_char);
}

int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */

	tabela_simbolos = start_stack();
	pilha_par = start_stack();
	fila_simbolos = start_queue();
	desvios = start_r_stack();
	strcpy(erro_char, "Erro de sintaxe");

   yyin=fp;
   yyparse();

   return 0;
}
