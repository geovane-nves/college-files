#ifndef FILA_H
#define FILA_H

#ifndef TAM_PALAVRA
#define TAM_PALAVRA 100
#endif

// Nó da fila: guarda uma palavra e aponta para a próxima da sequência.
typedef struct NoFila
{
    char palavra[TAM_PALAVRA];
    struct NoFila *prox;
} NoFila;

// A fila guarda quem é o início (primeira palavra digitada) e o fim
// (última palavra digitada), para inserir e remover em O(1).
typedef struct
{
    NoFila *inicio;
    NoFila *fim;
} Fila;

void fila_inicializar(Fila *f);
int fila_vazia(Fila *f);
int fila_inserir(Fila *f, const char *palavra);
int fila_remover(Fila *f, char *palavra_removida);
int fila_consultar_frente(Fila *f, char *palavra_frente);
void fila_limpar(Fila *f);

#endif