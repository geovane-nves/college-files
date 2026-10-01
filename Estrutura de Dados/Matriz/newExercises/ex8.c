#include <stdio.h>

int main(){
    int mat[10][10]; // [linha] e [coluna]
    int prod = 0;
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            printf("digite um numero matri[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            if( i + j < 10 - 1 ){
                printf("%d", mat[i][j]);
            }
        }
    }
    return 0;
}
