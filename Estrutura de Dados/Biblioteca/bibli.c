#include <stdio.h>
#include "bibli.h"

// Método de imprimir genérico, validando o TIPO
void imprima(char tipo, void *valor){
    if(tipo == 'i'){ printf("%d\n", *(int *)valor); }
    if(tipo == 'c'){ printf("%c\n", *(char *)valor); }
    if(tipo == 'f'){ printf("%f\n", *(float *)valor); }
    if(tipo == 's'){ printf("%s\n", (char*)valor); }
}

// Método de ler genérico, validando TIPO
void leia(char tipo, void *valor){
    if (tipo == 'i'){ scanf("%d", (int *)valor); }
    if (tipo == 'c'){ scanf(" %c", (char *)valor); }
    if (tipo == 'f'){ scanf("%f", (float *)valor); }
    if (tipo == 's'){ getchar(); fgets((char *)valor, 100, stdin);}
}