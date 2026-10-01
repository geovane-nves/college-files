#ifndef PILHA_H
#define PILHA_H

#ifndef TAM_PALAVRA
#define TAM_PALAVRA 100
#endif

// Nó da pilha: guarda uma palavra e aponta para o nó empilhado antes dela.
typedef struct NoPilha
{
    char palavra[TAM_PALAVRA];
    struct NoPilha *prox;
} NoPilha;

// A pilha só precisa saber quem está no topo.
typedef struct
{
    NoPilha *topo;
} Pilha;

void pilha_inicializar(Pilha *p);
int pilha_vazia(Pilha *p);
int pilha_empilhar(Pilha *p, const char *palavra);
int pilha_desempilhar(Pilha *p, char *palavra_removida);
int pilha_consultar_topo(Pilha *p, char *palavra_topo);
void pilha_limpar(Pilha *p);

#endif