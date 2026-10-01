#include <stdio.h>

int main(){
    int mat[3][3]; // [linha] e [coluna]
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            printf("digite um numero matri[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

        int maior = mat[0][0];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            if( mat[0][0] < mat[i][j] ){
                printf("Linha: %d", i);
                printf("Coluna: %d", j);
            }
        }
    }
    return 0;
}
