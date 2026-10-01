/* Aloque dinamicamente um vetor de n números inteiros. Depois da leitura, encontre e exiba o maior e o menor elemento, 
juntamente com suas respectivas posições no vetor. */

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
    
    for (int i = 0; i < n; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    int maior = vetor[0];
    int menor = vetor[0];
    int posicaoDoMaior = 0, posicaoDoMenor = 0;

    for (int i = 1; i < n; i++) {
        
        if(maior < vetor[i]){
            maior = vetor[i];
            posicaoDoMaior = i;
        }

        if(menor > vetor[i]){
            menor = vetor[i];
            posicaoDoMenor = i;
        }
    }

    printf("O maior numero do vetor é: %d, e sua posição se encontra em %d.", maior, posicaoDoMaior);
    printf("O menor numero do vetor é: %d, e sua posição se encontra em %d.", menor, posicaoDoMenor);

    free(vetor);
    return 0;
}