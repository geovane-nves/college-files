#include <stdio.h>
#include <stdlib.h>
#include "./arquivos/arquivos.h"
#include "editor.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Erro: Número incorreto de argumentos.\n");
        fprintf(stderr, "Uso: %s <caminho_do_arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int opcao = 0;

    printf("=== Editor de Texto (Pilha e Fila) ===\n");
    printf("1 - Importar arquivo existente\n");
    printf("2 - Criar do zero\n");
    printf("Opcao: ");

    if (scanf("%d", &opcao) != 1)
    {
        fprintf(stderr, "Erro: opcao invalida.\n");
        return EXIT_FAILURE;
    }
    printf("\n");

    if (opcao == 1)
    {
        editor_importar_arquivo(argv[1]);
    }
    else if (opcao == 2)
    {
        if (carregar_arquivo(argv[1]) == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
        editor_criar_do_zero(argv[1]);
    }
    else
    {
        fprintf(stderr, "Erro: opcao invalida.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}