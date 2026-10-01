/* Leia a quantidade de linhas e colunas de uma matriz de números inteiros. Aloque a
matriz dinamicamente utilizando um vetor de ponteiros, leia seus elementos e realize as
seguintes operações:

•exibir a matriz completa;
•calcular a soma de todos os elementos;
•calcular e exibir a soma de cada linha;
•encontrar o maior elemento da matriz;
•liberar cada linha e, posteriormente, o vetor de ponteiros. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int linhas, colunas;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &linhas);

    printf("Digite a quantidade de colunas: ");
    scanf("%d", &colunas);

    int **matriz = malloc(linhas * sizeof(int *));

    if (matriz == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < linhas; i++) {

        matriz[i] = malloc(colunas * sizeof(int));

        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria.\n");

            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }

            free(matriz);

            return 1;
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz:\n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    int somaTotal = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            somaTotal += matriz[i][j];
        }
    }

    printf("\nSoma total: %d\n", somaTotal);

    for (int i = 0; i < linhas; i++) {

        int somaLinha = 0;

        for (int j = 0; j < colunas; j++) {
            somaLinha += matriz[i][j];
        }

        printf("Soma da linha %d: %d\n", i, somaLinha);
    }

    int maior = matriz[0][0];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }

    printf("Maior elemento: %d\n", maior);

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}