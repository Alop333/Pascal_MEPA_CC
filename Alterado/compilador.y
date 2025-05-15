
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
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
int var_decs = 0;

//ALTERAÇAO
int dec_type = 0;
int rel = 0;
relacao_tipo lista_relacao[20];
char tipo_atr[TAM_TOKEN];


pilha_tipos tabela_simbolos;
pilha_rotulos desvios;
pilha_tipos pilha_par;
fila_tipos fila_simbolos;
char print_list[TAM_TOKEN];
char name_func[TAM_TOKEN];
char erro_char[100];

%}

%token PROGRAM TYPE ARRAY ABRE_PARENTESES FECHA_PARENTESES
%token A_COLCHETES F_COLCHETES OF LABEL PROCEDURE FUNCTION
%token T_IF T_THEN T_ELSE T_WHILE T_DO T_IGUAL T_DIFERENTE 
%token T_MAIOR_IGUAL T_MENOR_IGUAL T_MAIOR T_MENOR T_MAIS T_MENOS
%token T_OR T_MULT T_DIV T_AND T_NOT
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR NUMERO IDENT ATRIBUICAO
%%

programa    :{
             geraCodigo (NULL, "INPP");
             }
             PROGRAM identificador
             ABRE_PARENTESES lista_ident FECHA_PARENTESES PONTO_E_VIRGULA
			 {num_vars_temp = 0; num_vars = 0;}
             bloco PONTO {
             geraCodigo (NULL, "PARA");
             }
;

//regra2
bloco:
		{	nivel_lexico++; desloc = 0; 
		}
	parte_declara_tipo
	parte_declara_vars
	parte_declara_subrotinas
		{ 	
			if (nivel_lexico == 0 && print_r0 == 0 && func_proc == 0){
			char instrucao[50];
			sprintf(instrucao, "R00");
			geraCodigo(instrucao, "NADA");
			print_r0++;
		} 
		}
	comando_composto
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
	;

//regra6
tipo:
	identificador
		{ 
			//ALTERAÇÂO PEDIDA PELO PROFESSOR
			if (rel == 0){
				if (strcmp("integer", token) != 0)
					imprimeErro("Identificador com tipo invalido");
			} else {
				int aux = 0;
				for (int i = 0; i < rel; i++){
					if (strcmp(lista_relacao[i].identificador, token) == 0)
						aux = 1;
				}
				if (aux == 0 && strcmp("integer", token) != 0){
					imprimeErro("Identificador personalizado com tipo invalido");
				} else {
					if (strcmp("integer", token) != 0)
						altera_tipo( token, &fila_simbolos, var_decs);
				}
			}

			if (dec_type == 1){
				strcpy(lista_relacao[rel].tipo, token);
				rel++;

			}

			var_decs=0;
		}
	;

//ALTERAÇÂO PEDIDA PELO PROFESSOR
parte_declara_tipo:
	TYPE
		{
			dec_type = 1;
		}
	declara_tipo
		{
			dec_type = 0;
		}
	|
	;

//ALTERAÇÂO PEDIDA PELO PROFESSOR
declara_tipo:
	declara_tipo
	identificador
		{
			strcpy(lista_relacao[rel].identificador,token);
		}
	T_IGUAL
	tipo
	PONTO_E_VIRGULA
	|
	identificador
		{
			strcpy(lista_relacao[rel].identificador,token);
		}
	T_IGUAL
	tipo
	PONTO_E_VIRGULA
	;

//regra8
parte_declara_vars:
	VAR
			{
			limpa_lista(&fila_simbolos); dec_var = 1;
			}
	declara_vars 
		{ 
			num_vars_temp = lista_para_pilha(&fila_simbolos, &tabela_simbolos);
			char instrucao[30];
			sprintf(instrucao, "AMEM %d", num_vars_temp);
			geraCodigo(NULL, instrucao);
			num_vars_temp = 0;
			limpa_lista(&fila_simbolos);
			dec_var = 0;
		}
	|
	;
	

//regra9
declara_vars:
	declara_vars
	lista_ident
	DOIS_PONTOS
	tipo 
	PONTO_E_VIRGULA
	|
	lista_ident
	DOIS_PONTOS
	tipo
	PONTO_E_VIRGULA
	;


//regra10
lista_ident:
	lista_ident
	VIRGULA
	identificador 
	{tipo_t s = create_var_s(); in(&fila_simbolos, s); desloc++; var_decs++; }
	|
	identificador
	{tipo_t s = create_var_s(); in(&fila_simbolos, s); desloc++; var_decs++;}
	;

//regra11
parte_declara_subrotinas:
	parte_declara_subrotinas procedimento_funcao |
	procedimento_funcao |
	;

procedimento_funcao:
	declara_procedimento | declara_funcao ;

//regra12
declara_procedimento:
	PROCEDURE
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
	identificador_subrotina
	parametros_formais
	PONTO_E_VIRGULA
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
	bloco
	PONTO_E_VIRGULA
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
	;

//regra13
declara_funcao:
	FUNCTION
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
	identificador_func
	parametros_formais
	DOIS_PONTOS
	tipo
	PONTO_E_VIRGULA
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
	bloco
	PONTO_E_VIRGULA
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
	;

identificador_subrotina:
	IDENT
		{ 
			tipo_t p = create_proc();
			in(&fila_simbolos, p);
		}
	;

identificador_func:
	IDENT
		{ 
			tipo_t p = create_func();
			in(&fila_simbolos, p);
		}
	;

//regra14
parametros_formais:
	ABRE_PARENTESES
	{desloc = -4;}
	sec_parametros_formais
	{//print_pilha(&pilha_par);
	}
	FECHA_PARENTESES
	|
	;

//regra15
sec_parametros_formais:
	sec_parametros_formais
	PONTO_E_VIRGULA
	VAR
	lista_ident_par_r
	DOIS_PONTOS
	tipo
	|
	VAR
	lista_ident_par_r
	DOIS_PONTOS
	tipo
	|
	sec_parametros_formais
	PONTO_E_VIRGULA
	lista_ident_par_f
	DOIS_PONTOS
	tipo
	|
	lista_ident_par_f
	DOIS_PONTOS
	tipo
	;

lista_ident_par_r:
	lista_ident_par_r
	VIRGULA
	identificador
	{num_vars++; num_vars_temp++; tipo_t s = create_var_r(); pull(&pilha_par, s); desloc--;}
	|
	identificador
	{num_vars++; num_vars_temp++; tipo_t s = create_var_r(); pull(&pilha_par, s); desloc--;}
	;

lista_ident_par_f:
	lista_ident_par_f
	VIRGULA
	identificador
	{num_vars++; num_vars_temp++; tipo_t s = create_var_f(); pull(&pilha_par, s); desloc--;}
	|
	identificador
	{num_vars++; num_vars_temp++; tipo_t s = create_var_f(); pull(&pilha_par, s); desloc--;}
	;

//regra16
comando_composto:
	T_BEGIN
	comando
	T_END
	;

//regra17
comando:
	comando
	PONTO_E_VIRGULA
	comando_s_rotulo
	|
	comando_s_rotulo
	;

//regra18
comando_s_rotulo:
	variavel_ident
	|
	comando_composto
	|
	comando_condicional
	|
	comando_repetitivo
	;

//regra19
variavel_ident:
	IDENT
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

			tipo_t temp = busca_ident_char(&tabela_simbolos, print_list);
			get_tipo(temp, tipo_atr);
		}
		print_wait = 1;
	}
	funcao_atr
	{
		strcpy(name_func,"");
	}
	;

funcao_atr:
	ATRIBUICAO
	expressao_simples
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
	|
	chamada_proced
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
	;


//regra20
chamada_proced:
	ABRE_PARENTESES
		{
			num_vars_temp = 0;
			par_subrt = 1;
		}
	lista_de_expressao 
	FECHA_PARENTESES {leit_wait = 0; print_wait = 0; par_subrt = 0;}|
	;

//regra22
comando_condicional:
	T_IF
		{
			strcpy(erro_char,"Expressão não booleana");
		}
	expressao_bool
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
	T_THEN
	comando_s_rotulo
	else_condicional
	;

else_condicional:
	T_ELSE 
		{
			rotulo r = top_r(&desvios);
			char instrucao[50];
			sprintf(instrucao, "DSVS R%02d", r.enter);
			geraCodigo(NULL, instrucao);

			sprintf(instrucao, "R%02d", r.exit);
			geraCodigo(instrucao, "NADA");
		}
	comando_s_rotulo 
		{
			rotulo r = push_r(&desvios);
			char instrucao[50];
			sprintf(instrucao, "R%02d", r.enter);
			geraCodigo(instrucao, "NADA");
		}
	| 
		{
			rotulo r = push_r(&desvios);
			char instrucao[50];
			sprintf(instrucao, "R%02d", r.exit);
			geraCodigo(instrucao, "NADA");
		}
	;

//regra23
comando_repetitivo:
	T_WHILE
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
	expressao_bool
		{
			strcpy(erro_char, "Erro de sintaxe");
		}

	T_DO
		{
			rotulo r = top_r(&desvios);
			char instrucao[50];
        	sprintf(instrucao, "DSVF R%02d", r.exit);
        	geraCodigo(NULL, instrucao);
		}
	comando_s_rotulo
		{
			rotulo r = push_r(&desvios);
			char instrucao[50];
			sprintf(instrucao, "DSVS R%02d", r.enter);
			geraCodigo(NULL, instrucao);

			sprintf(instrucao, "R%02d", r.exit);
			geraCodigo(instrucao, "NADA");
		}
	;

//regra24
lista_de_expressao:
	lista_de_expressao
	VIRGULA
	expressao_simples 
		{
			if(par_subrt == 1){
				num_vars_temp++;
			}
		}
	|
	expressao_simples
		{
			if(par_subrt == 1){
				num_vars_temp++;
			}
		}
	;

//regra25
expressao_bool:
	expressao_simples
	relacao
	expressao_simples
		{
			geraCodigo(NULL, print_list);
		}
	|
	ABRE_PARENTESES
	expressao_simples
	relacao
	expressao_simples
		{
			geraCodigo(NULL, print_list);
		}
	FECHA_PARENTESES
	;


//regra26
relacao:
	T_IGUAL {char instrucao[30]; sprintf(instrucao, "CMIG"); strcpy(print_list, instrucao);}|
	T_DIFERENTE {char instrucao[30]; sprintf(instrucao, "CMDG"); strcpy(print_list, instrucao);}|
	T_MENOR {char instrucao[30]; sprintf(instrucao, "CMME"); strcpy(print_list, instrucao);}|
	T_MENOR_IGUAL {char instrucao[30]; sprintf(instrucao, "CMEG"); strcpy(print_list, instrucao);}|
	T_MAIOR {char instrucao[30]; sprintf(instrucao, "CMMA"); strcpy(print_list, instrucao);}|
	T_MAIOR_IGUAL {char instrucao[30]; sprintf(instrucao, "CMAG"); strcpy(print_list, instrucao);}
	;

//regra27
expressao_simples:
	termo
	|
	termo 
	T_MAIS
	expressao_simples
		{ 	char instrucao[30];
			sprintf(instrucao, "SOMA");
			geraCodigo(NULL, instrucao); 
		}
	|
	termo
	T_MENOS
	expressao_simples
		{ 
			char instrucao[30];
			sprintf(instrucao, "SUBT");
			geraCodigo(NULL, instrucao); 
		}
	;

//regra28
termo:
	fator
	|
	fator
	T_MULT
	fator
		{ 	char instrucao[30];
			sprintf(instrucao, "MULT");
			geraCodigo(NULL, instrucao); 
		}
	|
	fator
	T_DIV
	fator
		{ 	char instrucao[30];
			sprintf(instrucao, "DIVI");
			geraCodigo(NULL, instrucao); 
		}
	;

//regra29
fator:
	identificador
	|
	chamada_func
	|
	ABRE_PARENTESES
	expressao_simples
	FECHA_PARENTESES
	|
	NUMERO
		{
			char instrucao[30];
			sprintf(instrucao, "CRCT %s", token);
			geraCodigo(NULL, instrucao);
		}
	;

//regra31
chamada_func:
	identificador
		{
			print_wait = 1;
			num_vars_temp = 0;
			par_subrt = 1;
		}
	par_func
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
	;

par_func:
	ABRE_PARENTESES
	lista_de_expressao
	FECHA_PARENTESES
	;

//regra34
identificador:
   IDENT
   {
		
		if (strcmp("write", token) != 0 && strcmp("read", token) != 0){
			//ALTERACAO DO PROFESSOR, VERIFICAR COMPATIBILIDADE ENTRE OS SIMBOLOS
			tipo_t temp = busca_ident(&tabela_simbolos);
			char aux[TAM_TOKEN];
			get_tipo(temp, aux);
			if ((strcmp("integer", tipo_atr) != 0 || strcmp("integer", aux) != 0 ) && strcmp("", tipo_atr) != 0 && strcmp(tipo_atr, aux) != 0){
				for (int i = 0; i < rel; i++){
					if (strcmp(lista_relacao[i].identificador, tipo_atr) == 0)
						if(strcmp(lista_relacao[i].tipo, aux) != 0)
							imprimeErro("Atribuição entre tipos incompativeis");
				}
			}
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
   ;


%%

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
