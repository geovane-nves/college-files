/* Aloque dinamicamente um vetor de nnúmeros inteiros. Solicite ao usuário uma posição a ser removida, desloque os elementos 
seguintes uma posição para a esquerda e reduza o tamanho do vetor utilizando realloc().*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    printf("Digite o tamanho do vetor: ");
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

    int posicao;

    printf("Digite a posicao que deseja remover: ");
    scanf("%d", &posicao);

    if (posicao < 0 || posicao >= n) {
        printf("Posicao invalida.\n");
        free(vetor);
        return 1;
    }

    for (int i = posicao; i < n - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    int novoTamanho = n - 1;

    int *temp = realloc(vetor, novoTamanho * sizeof(int));

    if (temp == NULL && novoTamanho > 0) {
        printf("Erro ao redimensionar memoria.\n");
        free(vetor);
        return 1;
    }

    vetor = temp;

    printf("\nVetor apos a remocao:\n");

    for (int i = 0; i < novoTamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    free(vetor);

    return 0;
}