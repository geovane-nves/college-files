/* Desenvolva duas versões de um programa que aloque um vetor grande, por exemplo,
com 100 000 000 de números inteiros:

•Versão A: utilize malloc() e preencha todas as posições com zero;
•Versão B: utilize calloc(), aproveitando a inicialização automática das posições
com zero.

Em ambas as versões, percorra o vetor e calcule a soma dos elementos. Exiba a soma
para garantir que a memória alocada foi realmente acessada.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    long long n = 100000000;

    int *vetor = calloc(n, sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    long long soma = 0;

    for (long long i = 0; i < n; i++) {
        soma += vetor[i];
    }

    printf("Soma: %lld\n", soma);

    free(vetor);

    return 0;
}

// gcc -O0 -Wall -Wextra ex9Calloc.c -o calloc_teste
// /usr/bin/time -v ./calloc_teste

// Tempo Real: 0.17
// Tempo de Usuário: 0.12
// Tempo do Sistema: 0.05
// Memória Máxima: 1508