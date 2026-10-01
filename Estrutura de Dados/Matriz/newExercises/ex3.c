#include <stdio.h>

int main(){
    int mat[3][3]; // [linha] e [coluna]
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            printf("digite um numero matri[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            if( i != j){
                printf("%d", mat[i][j]);
            }
        }
    }
    return 0;
}
