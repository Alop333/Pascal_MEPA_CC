
/* -------------------------------------------------------------------
 *            Arquivo: compilador.l
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [09/08/2020, 19h:01m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, protótipos e variáveis globais do compilador (via extern)
 *
 * ------------------------------------------------------------------- */

%{


#include<stdio.h>
#include<string.h>

#include "compilador.h"
#include "compilador.tab.h"

#define IMPRIME(STR) {};
//#define IMPRIME(STR) printf("%s    # %s \n", STR, token);

int nl = 1;
simbolos simbolo, relacao;

%}

pulo_linha [\n]

descarte [\t ]+

ident [a-zA-Z][a-zA-Z0-9]*

numero [0-9]+

comentario "(*".*"*)"

%%

{pulo_linha} {nl++;}

{descarte}

{comentario}

program { simbolo  = simb_program;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("program ");
          return PROGRAM;
 }

type {  simbolo  = simb_type;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("type ");
          return TYPE;
 } 

var      { simbolo = simb_var;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("var  ");
          return VAR;
 }

array   { simbolo  = simb_array;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("array  ");
          return ARRAY;
}

\[ {simbolo  = simb_a_colchetes;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" abre colchetes");
          return A_COLCHETES;
}

\] {simbolo  = simb_f_colchetes;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" fecha colchetes");
          return F_COLCHETES;
}

of {simbolo  = simb_of;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("of  ");
          return OF;
}

label {simbolo  = simb_label;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("label  ");
          return LABEL;
}

procedure {simbolo  = simb_procedure;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("Procedure  ");
          return PROCEDURE;
}

function {simbolo  = simb_function;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("function  ");
          return FUNCTION;
}

begin { simbolo = simb_begin;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("begin ");
          return T_BEGIN;
 }

end { simbolo = simb_end;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("end  ");
          return T_END;
 }



if { simbolo = simb_if;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("if  ");
          return T_IF;
 }

then { simbolo = simb_then;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("then  ");
          return T_THEN;
 }

else { simbolo = simb_else;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("else  ");
          return T_ELSE;
 }

while { simbolo = simb_while;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("while  ");
          return T_WHILE;
 }

do { simbolo = simb_do;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("do  ");
          return T_DO;
 }



= { simbolo = simb_igual;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("igual  ");
          return T_IGUAL;
 }

\<\> { simbolo = simb_diferente;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("diferente  ");
          return T_DIFERENTE;
 }

\>= { simbolo = simb_maior_igual;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("maior igual  ");
          return T_MAIOR_IGUAL;
 }

\<= { simbolo = simb_menor_igual;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("menor igual  ");
          return T_MENOR_IGUAL;
 }

\> { simbolo = simb_maior;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("maior  ");
          return T_MAIOR;
 }

\< { simbolo = simb_menor;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("menor  ");
          return T_MENOR;
 }



\+ { simbolo = simb_mais;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("mais  ");
          return T_MAIS;
 }

- { simbolo = simb_menos;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("menos  ");
          return T_MENOS;
 }

or { simbolo = simb_or;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("or  ");
          return T_OR;
 }

\* { simbolo = simb_mult;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("multiplicação  ");
          return T_MULT;
 }

div { simbolo = simb_div;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("divisão  ");
          return T_DIV;
 }

and { simbolo = simb_and;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("and  ");
          return T_AND;
 }

not { simbolo = simb_not;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("not  ");
          return T_NOT;
 }



:= { simbolo = simb_atribuicao;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" atribuicao  ");
          return ATRIBUICAO;
 }

\; { simbolo = simb_ponto_e_virgula;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" pt_virgula  ");
          return PONTO_E_VIRGULA;
 }

\: { simbolo = simb_dois_pontos;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" dois pontos ");
          return DOIS_PONTOS;
 }

\, { simbolo = simb_virgula;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" virgula  ");
          return VIRGULA;
 }

\. { simbolo = simb_ponto;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" ponto  ");
          return PONTO;
    }

\(  { simbolo = simb_abre_parenteses;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" abre_parenteses  ");
          return ABRE_PARENTESES;
    }

\)  { simbolo = simb_fecha_parenteses;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" fecha_parenteses ");
          return FECHA_PARENTESES;
 }



{numero} { simbolo = simb_numero;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" numero ");
          return NUMERO;
        }

{ident} { simbolo = simb_identificador;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" ident  ");
          return IDENT;
        }


%%
