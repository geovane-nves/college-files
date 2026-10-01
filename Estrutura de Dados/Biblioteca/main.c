#include "bibli.h"

int main() {
    int idade;
    float nota;
    char letra;
    char nome[100];

    leia('i', &idade);
    leia('f', &nota);
    leia('c', &letra);
    leia('s', nome);

    imprima('c', " ");

    imprima('i', &idade);
    imprima('f', &nota);
    imprima('c', &letra);
    imprima('s', nome);

    imprima('s', "Olá mundo!");

    return 0;
}