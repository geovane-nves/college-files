#include <stdio.h>
#include <stdlib.h>

int main() {

    long long n = 100000000;

    int *vetor = malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    long long soma = 0;

    for (long long i = 0; i < n; i++) {
        vetor[i] = i;
        soma += vetor[i];
    }

    printf("Soma: %lld\n", soma);

    free(vetor);

    return 0;
}


/* 1. Não. Como todas as posições do vetor são posteriormente sobrescritas pelos valores de 0 até n-1, os zeros fornecidos pelo calloc() 
não são aproveitados. Assim, a inicialização automática não traz benefício para o programa. */

// 2. Em geral, a versão com malloc() apresente o menor tempo médio, embora a diferença possa ser pequena e variar.

// 3. não houve uma diferença significativa no consumo de memória residente entre as duas versões.

/* 4. Porque o calloc() tem como característica garantir que a memória alocada esteja inicialmente preenchida com zero. Isso representa 
uma inicialização que pode envolver trabalho de memória. No programa, porém, logo depois fazemos:

vetor[i] = i;
para todas as posições. Portanto, os zeros produzidos pelo calloc() são imediatamente substituídos.

Com malloc(), a memória não precisa ser inicialmente preenchida com zero. O programa simplesmente escreve diretamente os valores necessários. */ 