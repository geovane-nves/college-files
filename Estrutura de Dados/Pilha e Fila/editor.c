#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"
#include "./pilha/pilha.h"
#include "./fila/fila.h"
#include "./arquivos/arquivos.h"

#define TAM_TEXTO_FINAL 4096

// Faz o loop de digitar/apagar/fim a partir do que ja estiver em "pilha"
// (vazio no caso de criar do zero, ou ja carregado com as palavras de um
// arquivo importado). No final monta o texto e pergunta se deve salvar.
static void editar_e_salvar(Pilha *pilha, const char *caminho_arquivo)
{
    char palavra[TAM_PALAVRA];

    printf("Digite as palavras. \"apagar\" remove a ultima, \"fim\" encerra.\n\n");

    while (1)
    {
        printf("> ");
        if (scanf("%99s", palavra) != 1)
        {
            break;
        }

        if (strcmp(palavra, "fim") == 0)
        {
            break;
        }
        else if (strcmp(palavra, "apagar") == 0)
        {
            pilha_desempilhar(pilha, NULL); // se vazia, so ignora
        }
        else
        {
            pilha_empilhar(pilha, palavra);
        }
    }

    // Inverte a pilha usando uma segunda pilha (so empilhar/desempilhar,
    // sem percorrer nada) para recuperar a ordem original.
    Pilha pilha_invertida;
    pilha_inicializar(&pilha_invertida);

    char atual[TAM_PALAVRA];
    while (!pilha_vazia(pilha))
    {
        pilha_desempilhar(pilha, atual);
        pilha_empilhar(&pilha_invertida, atual);
    }

    // Passa para a fila, ja na ordem certa (a primeira palavra digitada
    // entra primeiro).
    Fila fila;
    fila_inicializar(&fila);

    while (!pilha_vazia(&pilha_invertida))
    {
        pilha_desempilhar(&pilha_invertida, atual);
        fila_inserir(&fila, atual);
    }

    // Le a fila do inicio ao fim (FIFO) para montar o texto final.
    char texto_final[TAM_TEXTO_FINAL] = "";
    while (!fila_vazia(&fila))
    {
        fila_remover(&fila, atual);
        strncat(texto_final, atual, TAM_TEXTO_FINAL - strlen(texto_final) - 2);
        strcat(texto_final, " ");
    }

    printf("\nTexto: %s\n\n", texto_final);

    char resposta = 'n';
    printf("Salvar arquivo? (s/n): ");
    scanf(" %c", &resposta);

    if (resposta == 's' || resposta == 'S')
    {
        salvar_arquivo(caminho_arquivo, texto_final);
        printf("Salvo em \"%s\".\n", caminho_arquivo);
    }

    pilha_limpar(pilha);
    pilha_limpar(&pilha_invertida);
    fila_limpar(&fila);
}

void editor_criar_do_zero(const char *caminho_arquivo)
{
    Pilha pilha;
    pilha_inicializar(&pilha);

    editar_e_salvar(&pilha, caminho_arquivo);
}

void editor_importar_arquivo(const char *caminho_arquivo)
{
    Pilha pilha;
    pilha_inicializar(&pilha);

    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL)
    {
        fprintf(stderr, "Aviso: nao foi possivel ler o arquivo, comecando vazio.\n");
    }
    else
    {
        char palavra[TAM_PALAVRA];
        // Le palavra por palavra e empilha na mesma ordem do arquivo,
        // como se a pessoa tivesse acabado de digitar cada uma.
        while (fscanf(arquivo, "%99s", palavra) == 1)
        {
            pilha_empilhar(&pilha, palavra);
        }
        fclose(arquivo);

        printf("Arquivo importado. Continue digitando ou use \"apagar\"/\"fim\".\n\n");
    }

    editar_e_salvar(&pilha, caminho_arquivo);
}