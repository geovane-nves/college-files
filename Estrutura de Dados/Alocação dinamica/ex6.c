/* Aloque inicialmente um vetor para cinco números inteiros. Depois da leitura, pergunte quantos números o usuário 
deseja acrescentar. Redimensione o vetor utilizando realloc(), leia os novos elementos e exiba o vetor completo. O 
programa deverá preservar o endereço original caso o realloc() falhe, evitando a perda da área de memória 
anteriormente alocada. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *vetor = malloc(5 * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite 5 numeros:\n");

    for (int i = 0; i < 5; i++) {
        scanf("%d", &vetor[i]);
    }

    int quantidade;

    printf("Quantos numeros deseja acrescentar? ");
    scanf("%d", &quantidade);

    int novoTamanho = 5 + quantidade;

    int *temp = realloc(vetor, novoTamanho * sizeof(int));

    if (temp == NULL) {
        printf("Erro ao redimensionar memoria.\n");
        free(vetor);
        return 1;
    }

    vetor = temp;

    for (int i = 5; i < novoTamanho; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor completo:\n");

    for (int i = 0; i < novoTamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    free(vetor);
    return 0;
}