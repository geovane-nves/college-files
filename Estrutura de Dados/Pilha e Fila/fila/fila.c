#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void fila_inicializar(Fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

int fila_vazia(Fila *f)
{
    return f->inicio == NULL;
}

// Insere uma nova palavra no FIM da fila (regra FIFO de entrada).
int fila_inserir(Fila *f, const char *palavra)
{
    NoFila *novo = (NoFila *) malloc(sizeof(NoFila));
    if (novo == NULL)
    {
        fprintf(stderr, "Erro: falha ao alocar memoria para a fila.\n");
        return EXIT_FAILURE;
    }

    strncpy(novo->palavra, palavra, TAM_PALAVRA - 1);
    novo->palavra[TAM_PALAVRA - 1] = '\0';
    novo->prox = NULL;

    if (fila_vazia(f))
    {
        // Fila estava vazia: o novo nó é início e fim ao mesmo tempo.
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }

    return EXIT_SUCCESS;
}

// Remove do INÍCIO da fila (regra FIFO de saída padrão).
int fila_remover(Fila *f, char *palavra_removida)
{
    if (fila_vazia(f))
    {
        fprintf(stderr, "Erro: fila vazia, nao ha nada para remover.\n");
        return EXIT_FAILURE;
    }

    NoFila *removido = f->inicio;

    if (palavra_removida != NULL)
    {
        strncpy(palavra_removida, removido->palavra, TAM_PALAVRA - 1);
        palavra_removida[TAM_PALAVRA - 1] = '\0';
    }

    f->inicio = removido->prox;
    if (f->inicio == NULL)
    {
        // Era o único elemento: início e fim voltam a ser NULL.
        f->fim = NULL;
    }
    free(removido);

    return EXIT_SUCCESS;
}

// Consulta a frente da fila sem remover nem alterar a ordem.
int fila_consultar_frente(Fila *f, char *palavra_frente)
{
    if (fila_vazia(f))
    {
        fprintf(stderr, "Erro: fila vazia, nao ha frente para consultar.\n");
        return EXIT_FAILURE;
    }

    strncpy(palavra_frente, f->inicio->palavra, TAM_PALAVRA - 1);
    palavra_frente[TAM_PALAVRA - 1] = '\0';

    return EXIT_SUCCESS;
}

// Libera todos os nós restantes ao encerrar o programa.
void fila_limpar(Fila *f)
{
    char descartada[TAM_PALAVRA];
    while (!fila_vazia(f))
    {
        fila_remover(f, descartada);
    }
}