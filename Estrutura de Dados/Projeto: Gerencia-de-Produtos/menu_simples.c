#include <stdio.h>
#include <stdlib.h>
#include "menu_simples.h"
#include "produto.h"
#include "simples.h"

void menu_simples(No **lista)
{
    int opcao;
    int id;
    int nova_quantidade;

    char nome[50];
    char validade[20];

    int quantidade;
    float preco;

    Produto *produto;

    do
    {
        printf("\n===== PERECIVEIS =====\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do fim\n");
        printf("5. Remover por ID\n");
        printf("6. Listar produtos\n");
        printf("7. Buscar por nome\n");
        printf("8. Atualizar quantidade\n");
        printf("9. Contar produtos\n");
        printf("10. Esvaziar lista\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:

                printf("Nome: ");
                scanf(" %49[^\n]", nome);

                printf("Quantidade: ");
                scanf("%d", &quantidade);

                printf("Preco: ");
                scanf("%f", &preco);

                printf("Validade: ");
                scanf(" %19[^\n]", validade);

                produto = criarProduto(nome, quantidade, preco, validade);

                if (produto != NULL)
                {
                    inserirNoInicio(*produto, lista);
                    free(produto);
                }

                break;

            case 2:

                printf("Nome: ");
                scanf(" %49[^\n]", nome);

                printf("Quantidade: ");
                scanf("%d", &quantidade);

                printf("Preco: ");
                scanf("%f", &preco);

                printf("Validade: ");
                scanf(" %19[^\n]", validade);

                produto = criarProduto(nome, quantidade, preco, validade);

                if (produto != NULL)
                {
                    inserirNoFinal(*produto, lista);
                    free(produto);
                }

                break;

            case 3:

                remover_inicio(lista);

                break;

            case 4:

                remover_fim(lista);

                break;

            case 5:

                printf("Digite o ID: ");
                scanf("%d", &id);

                remover_por_id(lista, id);

                break;

            case 6:

                listar(*lista);

                break;

            case 7:

                printf("Digite o nome para buscar: ");
                scanf(" %49[^\n]", nome);

                buscar_nome(*lista, nome);

                break;

            case 8:

                printf("Digite o ID: ");
                scanf("%d", &id);

                printf("Digite a nova quantidade: ");
                scanf("%d", &nova_quantidade);

                atualizar_quantidade(*lista, id, nova_quantidade);

                break;

            case 9:

                printf("Quantidade de produtos: %d\n", contar(*lista));

                break;

            case 10:

                esvaziar(lista);

                break;

            case 0:

                printf("Voltando ao menu principal...\n");

                break;

            default:

                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);
}