/* Leia nnúmeros inteiros em um vetor alocado dinamicamente. Inverta a ordem dos elementos no próprio vetor, 
sem criar um segundo vetor, e apresente o resultado.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;

    printf("Digite quantos numeros você quer armazenar: ");
    scanf("%d", &n);

    int *vetor = malloc(n * (sizeof(int)));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        printf("Digite um número: ");
        scanf("%d", vetor[i]);
    }

    printf("Os numeros em ordem inversa: ");
    for (int i = 0; i < n; i++) {
        printf("Número %d, posição %d do vetor", vetor[i], i);
    }

    free(vetor);
    return 0;
}