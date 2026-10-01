#ifndef SIMPLES_H
#define SIMPLES_H

#include "produto.h"

typedef struct No{
    Produto produto;
    struct No* prox;
} No;


void inserirNoFinal(Produto produto, No** lista);
void inserirNoInicio(Produto produto, No** lista);

void remover_inicio(No **lista);
void remover_fim(No **lista);
void remover_por_id(No **lista, int id);


void listar(No* lista);
void buscar_nome(No *lista, char *nome);

void atualizar_quantidade(No *lista, int id, int nova_quantidade);

int contar(No *lista);

void esvaziar(No **lista);
#endif