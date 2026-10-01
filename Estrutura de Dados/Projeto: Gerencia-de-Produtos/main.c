#include <stdio.h>
#include "simples.h"
#include "menu_simples.h"

int main()
{
    No *lista = NULL;
    int opcao;

    do {
        printf("\n===== ESTOQUE DA LOJA =====\n");
        printf("1. Gerenciar Pereciveis (Simples)\n");
        printf("2. Gerenciar Nao Pereciveis (Dupla)\n");
        printf("3. Gerenciar Promocoes (Circular)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                menu_simples(&lista);
                break;

            case 2:
                printf("Menu da lista dupla ainda nao implementado.\n");
                break;

            case 3:
                printf("Menu da lista circular ainda nao implementado.\n");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    esvaziar(&lista);

    return 0;
}