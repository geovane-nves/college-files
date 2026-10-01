#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0)return a;
    return mdc(b, a % b);
}

int main() {
    int resultado = mdc(9, 2);

    printf("MDC = %d\n", resultado);

    return 0;
}

/*
1   mdc(8, 4)
2   mdc(4, 8 % 4)
3   mdc(4, 0)
4   4

Explicação:

(Linha 8) Em ordem de execussão, o programa ainda não sabe o resultado da variavel "resultado", então entramos na função;
(Linha 4) Na função encontramos um caso base, "if (b == 0) return a;" (b recebe o valor de 4), como essa logica está errada, pulamos a linha;
(Linha 5) Dentro do return estamos chamando a função novamente (return mdc(b, a % b)) a = 8 % 4 == 0;

(Linha 4) Na segunda execussão da função, "b" agora é igual a 0, então retornamos "a";

Já que descobrimos o resultado que torna o caso base verdadeiro significa que ao voltarmos uma etapa descobrimos que (8,4) é a mesma coisa de (4,0);



E se o programa tivesse que executar no minimo 3 vezes ou mais?
Se a = 9, b = 2;

Na primeira execussão = falso                   9 != 0
Na segunda execussão = falso                    ((9 % 2) == 1) != 0;
Na terceira execussão = verdadeiro              ((2 % 1) == 0) == 0

mdc(9, 2)
    ↓
mdc(2, 1)
    ↓
mdc(1, 0)
    ↓
return 1

Agora o programa começa a voltar:

Se mdc(1,0) == 1, então significa que mdc(2,1) == 1 também;
E se mdc(2,1) == 1, então significa que mdc(9,2) == 1 também;

*/