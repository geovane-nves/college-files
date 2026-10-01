#include <stdio.h>

// unsigned long long fatorial(unsigned n) {
//     if (n <= 1) {
//         return 1;
//     }
//
//     printf("fat: %lld\n", (n * fatorial(n - 1)));
//     return n * fatorial(n - 1);
// }


/*
Erro, mesmo dentro de um Print, os parametros ainda sao modificados, 
o código executa "n * fatorial(n - 1)" duas vezes;
Para corrigir basta armazenar o valor em uma variável 
*/

unsigned long long fatorial(unsigned n) {
    if (n <= 1) {
        return 1;
    }
    
    unsigned long long resultado =  n * fatorial(n - 1);

    printf("fat: %lld\n", resultado);
    return resultado;
}

// Resolvendo o erro anterior

int main(){
    int entrada;

    printf("Entrada :");
    scanf("%d", entrada);

    printf("Saida: %lld\n", fatorial(entrada));

    return 0;
}