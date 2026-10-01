#include <stdio.h>
#include <stdlib.h>

/* Escreva um programa que leia a quantidade n de números inteiros. Utilize malloc() para alocar um vetor com n posições,
 leia os elementos e exiba-os na mesma ordem em que foram digitados. */

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

    printf("\nNumeros digitados:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    free(vetor);

    return 0;
}