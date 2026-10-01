/* Leia n números inteiros em um vetor dinâmico. Em seguida, conte a quantidade de valores pares e ímpares e aloque
dois novos vetores com os tamanhos exatos necessários. Copie os valores para os vetores correspondentes e exiba os 
números pares e ímpares separadamente */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    int *vetor = malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    int quantidadePares = 0;
    int quantidadeImpares = 0;

    for (int i = 0; i < n; i++) {

        if (vetor[i] % 2 == 0) {
            quantidadePares++;
        } 
        else {
            quantidadeImpares++;
        }
    }

    int *pares = malloc(quantidadePares * sizeof(int));
    int *impares = malloc(quantidadeImpares * sizeof(int));

    if (pares == NULL || impares == NULL) {
        printf("Erro ao alocar memoria.\n");

        free(vetor);
        free(pares);
        free(impares);

        return 1;
    }

    int indicePar = 0;
    int indiceImpar = 0;

    for (int i = 0; i < n; i++) {

        if (vetor[i] % 2 == 0) {
            pares[indicePar] = vetor[i];
            indicePar++;
        } 
        else {
            impares[indiceImpar] = vetor[i];
            indiceImpar++;
        }
    }

    printf("\nNumeros pares: ");

    for (int i = 0; i < quantidadePares; i++) {
        printf("%d ", pares[i]);
    }

    
    printf("\nNumeros impares: ");

    for (int i = 0; i < quantidadeImpares; i++) {
        printf("%d ", impares[i]);
    }

    printf("\n");

    
    free(vetor);
    free(pares);
    free(impares);

    return 0;
}