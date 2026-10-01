#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void pilha_inicializar(Pilha *p)
{
    p->topo = NULL;
}

int pilha_vazia(Pilha *p)
{
    return p->topo == NULL;
}

// Empilha uma nova palavra no topo. Retorna EXIT_FAILURE se o malloc falhar.
int pilha_empilhar(Pilha *p, const char *palavra)
{
    NoPilha *novo = (NoPilha *) malloc(sizeof(NoPilha));
    if (novo == NULL)
    {
        fprintf(stderr, "Erro: falha ao alocar memoria para a pilha.\n");
        return EXIT_FAILURE;
    }

    strncpy(novo->palavra, palavra, TAM_PALAVRA - 1);
    novo->palavra[TAM_PALAVRA - 1] = '\0';

    // O novo nó aponta para o antigo topo, e vira o novo topo.
    novo->prox = p->topo;
    p->topo = novo;

    return EXIT_SUCCESS;
}

// Remove o elemento do topo (LIFO). Se palavra_removida != NULL, copia o
// conteúdo removido nele antes de liberar o nó.
int pilha_desempilhar(Pilha *p, char *palavra_removida)
{
    if (pilha_vazia(p))
    {
        fprintf(stderr, "Erro: pilha vazia, nao ha nada para desempilhar.\n");
        return EXIT_FAILURE;
    }

    NoPilha *removido = p->topo;

    if (palavra_removida != NULL)
    {
        strncpy(palavra_removida, removido->palavra, TAM_PALAVRA - 1);
        palavra_removida[TAM_PALAVRA - 1] = '\0';
    }

    // O topo passa a ser o próximo nó (ou NULL, se a pilha ficar vazia).
    p->topo = removido->prox;
    free(removido);

    return EXIT_SUCCESS;
}

// Consulta o topo sem remover nem alterar a pilha.
int pilha_consultar_topo(Pilha *p, char *palavra_topo)
{
    if (pilha_vazia(p))
    {
        fprintf(stderr, "Erro: pilha vazia, nao ha topo para consultar.\n");
        return EXIT_FAILURE;
    }

    strncpy(palavra_topo, p->topo->palavra, TAM_PALAVRA - 1);
    palavra_topo[TAM_PALAVRA - 1] = '\0';

    return EXIT_SUCCESS;
}

// Libera todos os nós restantes ao encerrar o programa.
void pilha_limpar(Pilha *p)
{
    char descartada[TAM_PALAVRA];
    while (!pilha_vazia(p))
    {
        pilha_desempilhar(p, descartada);
    }
}