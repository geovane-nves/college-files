#include <stdio.h>
#include <stdlib.h>

int main() {

    size_t quantidade = 50000000;
    size_t bytes = quantidade * sizeof(int);

    printf("Tentando alocar %zu bytes.\n", bytes);

    int *vetor = malloc(bytes);

    if (vetor == NULL) {
        printf("Falha ao alocar memoria.\n");
        return EXIT_FAILURE;
    }

    printf("Memoria alocada com sucesso.\n");

    for (size_t i = 0; i < quantidade; i++) {
        vetor[i] = 0;
    }

    free(vetor);
    
    return EXIT_SUCCESS;
}

// bash
// gcc -Wall -Wextra ex11.c -o falha_alocacao   
// ulimit -v 100000 ./falha_alocacao

// Tentando alocar 200000000 bytes.
// Falha ao alocar memoria.



// 1. NULL indica que a função malloc() não conseguiu alocar a quantidade de memória solicitada. 
// Nesse caso, o ponteiro não aponta para uma área de memória válida que possa ser utilizada pelo programa.

// 2. Porque, quando malloc() retorna NULL, não existe uma área de memória válida associada ao ponteiro.

// 3. para tornar o programa seguro e previsível. A quantidade de memória disponível pode ser insuficiente 
// por diversos motivos. Se o programa ignorar a falha e utilizar o ponteiro mesmo assim, poderá ocorrer comportamento indefinido

// 4. EXIT_FAILURE indica ao sistema operacional que o programa terminou devido a uma falha/erro.