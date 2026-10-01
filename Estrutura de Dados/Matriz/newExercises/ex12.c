#include <stdio.h>

int main(){
    int mat[4][5]; // [linha] e [coluna]
    int sum = 0;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            printf("digite um numero matri[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            
            sum += mat[i][j];
            
        }
    }
    return 0;
}
