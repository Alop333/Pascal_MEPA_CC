#include "compilador.h"

typedef enum {
    VARIAVEL_SIMPLES,
    PARAMETRO_FORMAL,
    PARAMETRO_REAL,
    PROCEDIMENTO,
    FUNCAO
} tipo_simbolos;

typedef struct {
    int nivel_lexico;
    int deslocamento;
} variavel_simples;

typedef struct {
    int nivel_lexico;
    int deslocamento;
} variavel_formal;

typedef struct {
    int nivel_lexico;
    int deslocamento;
} variavel_real;

typedef struct {
    int rotulo;
    int nivel_lexico;
    int num_vars;
    tipo_simbolos par[10];
} procedure;

typedef struct {
    int rotulo;
    int nivel_lexico;
    int deslocamento;
    int num_vars;
    tipo_simbolos par[10];
} function;

typedef struct {
    tipo_simbolos tipo;
    char identificador[TAM_TOKEN];
    union {
        variavel_simples var_s;
        variavel_formal var_f;
        variavel_real var_r;
        procedure proc; 
        function func;
    } atributos;
} tipo_t;

tipo_t create_var_s();
tipo_t create_var_f();
tipo_t create_var_r();
tipo_t create_proc();
tipo_t create_func();

typedef struct {
    tipo_t pilha[50];
    int topo;
} pilha_tipos;
pilha_tipos start_stack();
tipo_t push(pilha_tipos* p);
void pull(pilha_tipos* p, tipo_t item);
tipo_t top(pilha_tipos* p);
void print_pilha(pilha_tipos* p);

typedef struct {
    int enter;
    int exit;
} rotulo;

typedef struct {
    rotulo pilha[50];
    int topo;
} pilha_rotulos;
pilha_rotulos start_r_stack();
rotulo push_r(pilha_rotulos* p);
void pull_r(pilha_rotulos* p, rotulo r);
rotulo top_r(pilha_rotulos* p);

typedef struct {
    tipo_t fila[50];
    int start;
    int end;
    int tam;
} fila_tipos;
fila_tipos start_queue();
tipo_t out(fila_tipos* f);
void in(fila_tipos* f, tipo_t item);
void print_lista(fila_tipos* f);
void limpa_lista(fila_tipos* f);

int get_n_lex(tipo_t s);
int get_n_desloc(tipo_t s);
void set_desloc(tipo_t* s, int n);
void print_item(tipo_t s);
int lista_para_pilha(fila_tipos* f, pilha_tipos* p);
int pilha_para_lista(fila_tipos* f, pilha_tipos* p);

tipo_t busca_ident(pilha_tipos* p);
tipo_t busca_ident_char(pilha_tipos* p, char* string);
tipo_simbolos extrai_index(tipo_t t, int n);
int get_n_var(tipo_t s);