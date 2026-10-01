/* Utilize malloc() para criar um vetor de n números reais. Leia os valores, calcule a média dos elementos 
e exiba somente os valores que estiverem acima da média.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    float soma = 0, media = 0;

    printf("Digite quantos numeros você quer armazenar: ");
    scanf("%d", &n);

    float *vetor = malloc(n * (sizeof(float)));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%f", &vetor[i]);
        soma += vetor[i];
    }

    media = soma / n;

    printf("Os numeros maiores ou iguais a media são: ");

    for (int i = 0; i < n; i++) {
        if(media <= vetor[i]){
            printf("%f", vetor[i]);
        }
    }

    free(vetor);
    return 0;
}