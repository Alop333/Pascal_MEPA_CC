#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tabela_simbolos.h"

tipo_t create_var_s(){
    tipo_t s;

    strcpy(s.identificador,token);
    s.atributos.var_s.nivel_lexico = nivel_lexico;
    s.atributos.var_s.deslocamento = desloc;
    s.tipo = VARIAVEL_SIMPLES;

    return s;
}

tipo_t create_var_f(){
    tipo_t s;

    strcpy(s.identificador,token);
    s.atributos.var_f.nivel_lexico = nivel_lexico+1;
    s.atributos.var_f.deslocamento = desloc;
    s.tipo = PARAMETRO_FORMAL;

    return s;
}

tipo_t create_var_r(){
    tipo_t s;

    strcpy(s.identificador,token);
    s.atributos.var_r.nivel_lexico = nivel_lexico+1;
    s.atributos.var_r.deslocamento = desloc;
    s.tipo = PARAMETRO_REAL;

    return s;
}

tipo_t create_proc(){
    tipo_t s;
    char temp[30];

    strcpy(s.identificador,token);
    s.atributos.proc.nivel_lexico = nivel_lexico+1;

    s.atributos.proc.rotulo = last_rotulo;
    last_rotulo++;
    s.atributos.proc.num_vars = 0;

    s.tipo = PROCEDIMENTO;

    return s;

}

tipo_t create_func(){
    tipo_t s;
    char temp[30];

    strcpy(s.identificador,token);
    s.atributos.func.nivel_lexico = nivel_lexico+1;
    s.atributos.func.deslocamento = desloc;

    s.atributos.func.rotulo = last_rotulo;
    last_rotulo++;
    s.atributos.func.num_vars = 0;

    s.tipo = FUNCAO;

    return s;
}

pilha_tipos start_stack(){
    pilha_tipos p;
    p.topo = -1;
    return p;
}

tipo_t push(pilha_tipos* p){

    tipo_t aux = p->pilha[p->topo];
    p->topo--;
    return aux;
}

void pull(pilha_tipos* p, tipo_t item){
    p->topo++;
    p->pilha[p->topo] = item;
}

tipo_t top(pilha_tipos* p){
    return p->pilha[p->topo];
}

fila_tipos start_queue(){
    fila_tipos f;

    f.start = 0;
    f.end = -1;
    f.tam = 0;

    return f;
}

tipo_t out(fila_tipos* f){
    tipo_t aux;
    aux = f->fila[f->start];
    f->start++;

    if (f->start >= 50)
        f->start = 0;

    f->tam--;

    return aux;
}

void in(fila_tipos* f, tipo_t item){
    f->end++;

    if (f->end >= 50)
        f->end = 0;

    f->fila[f->end] = item;
    f->tam++;
}

int lista_para_pilha(fila_tipos* f, pilha_tipos* p){
    int n_vars = 0;
    tipo_t temp;

    while (f->tam > 0){
        pull(p, out(f));
        n_vars++;
    }

    return n_vars;
}

int get_n_lex(tipo_t s){
    switch (s.tipo){
        case VARIAVEL_SIMPLES: return s.atributos.var_s.nivel_lexico;
        case PARAMETRO_FORMAL: return s.atributos.var_f.nivel_lexico;
        case PARAMETRO_REAL: return s.atributos.var_r.nivel_lexico;
        case PROCEDIMENTO: return s.atributos.proc.nivel_lexico;
        case FUNCAO: return s.atributos.func.nivel_lexico;
    }
    return -1;
}

int get_n_desloc(tipo_t s){
    switch (s.tipo){
        case VARIAVEL_SIMPLES: return s.atributos.var_s.deslocamento;
        case PARAMETRO_FORMAL: return s.atributos.var_f.deslocamento;
        case PARAMETRO_REAL: return s.atributos.var_r.deslocamento;
        case FUNCAO: return s.atributos.func.deslocamento;
    }
    return -1;
}

void set_desloc(tipo_t* s, int n){
    switch (s->tipo){
        case PARAMETRO_FORMAL: s->atributos.var_f.deslocamento = n;
        case PARAMETRO_REAL: s->atributos.var_r.deslocamento = n;
    }
}


int pilha_para_lista(fila_tipos* f, pilha_tipos* p){
    int n_vars = 0;
    int n_lex;

    tipo_t temp;

    temp = top(p);
    n_lex = nivel_lexico;


    while (get_n_lex(temp) >= n_lex && p->topo >= 0){
        in(f, push(p));
        if (temp.tipo == VARIAVEL_SIMPLES)
            n_vars++;
        temp = top(p);
    }

    return n_vars;
}

void print_pilha(pilha_tipos* p){
    tipo_t temp;
    for (int i = p->topo; i >= 0; i--){
        temp = p->pilha[i];
        print_item(temp);
        printf("\n");
    }
}

void print_lista(fila_tipos* f){
    tipo_t temp;
    for (int i = 0; i < f->tam; i++){
        temp = f->fila[f->start+i];
        print_item(temp);
    }
    printf("\n");
}

void limpa_lista(fila_tipos* f){
    f->start = 0;
    f->end = -1;
    f->tam = 0;
}

tipo_t busca_ident(pilha_tipos* p){
    tipo_t temp;

    for (int i = p->topo; i >= 0; i--){
        temp = p->pilha[i];
        
        if (strcmp(temp.identificador, token) == 0){
            error = 1;
            return temp;
        }
    }

    error = 0;
}

tipo_t busca_ident_char(pilha_tipos* p, char* string){
    tipo_t temp;

    for (int i = p->topo; i >= 0; i--){
        temp = p->pilha[i];
        
        if (strcmp(temp.identificador, string) == 0){
            error = 1;
            return temp;
        }
    }

    error = 0;
}

pilha_rotulos start_r_stack(){
    pilha_rotulos p;
    p.topo = -1;
    return p;
}

rotulo push_r(pilha_rotulos* p){
    rotulo aux = p->pilha[p->topo];
    p->topo--;
    return aux;
}

void pull_r(pilha_rotulos* p, rotulo r){
    p->topo++;
    p->pilha[p->topo] = r;
}

rotulo top_r(pilha_rotulos* p){
    return p->pilha[p->topo];
}

void print_item(tipo_t s){
    switch (s.tipo){
        case VARIAVEL_SIMPLES: { printf("VS %s, nl%02d d%02d |", s.identificador, get_n_lex(s), get_n_desloc(s)); break; }
        case PARAMETRO_FORMAL: { printf("PF %s, nl%02d d%02d |", s.identificador, get_n_lex(s), get_n_desloc(s)); break; }
        case PARAMETRO_REAL: { printf("PR %s, nl%02d d%02d |", s.identificador, get_n_lex(s), get_n_desloc(s)); break;}
        case PROCEDIMENTO: { printf("PC %s, nl%02d R%02d par%d ", s.identificador, get_n_lex(s), s.atributos.proc.rotulo, s.atributos.proc.num_vars);
            for(int i = 0; i < s.atributos.proc.num_vars; i++){
                switch(s.atributos.proc.par[i]){
                    case PARAMETRO_FORMAL:{printf("=PF"); break;}
                    case PARAMETRO_REAL: {printf("=PR"); break;}
                }
            }
            printf("|");
            break;}
        case FUNCAO: { printf("FN %s, nl%02d d%02d R%02d par%d ", s.identificador, get_n_lex(s), get_n_desloc(s), s.atributos.func.rotulo, s.atributos.func.num_vars);
            for(int i = 0; i < s.atributos.func.num_vars; i++){
                switch(s.atributos.func.par[i]){
                    case PARAMETRO_FORMAL:{printf("=PF"); break;}
                    case PARAMETRO_REAL: {printf("=PR"); break;}
                }
            }
            printf("|");
        break;}
    }
}

tipo_simbolos extrai_index(tipo_t t, int n){
    switch (t.tipo){
        case PROCEDIMENTO: return t.atributos.proc.par[n];
        case FUNCAO: return t.atributos.func.par[n];
    }
    return VARIAVEL_SIMPLES;
}

int get_n_var(tipo_t s){
    switch (s.tipo){
        case PROCEDIMENTO: return s.atributos.proc.num_vars;
        case FUNCAO: return s.atributos.func.num_vars;
    }
    return -1;
}
