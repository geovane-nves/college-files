#include <stdio.h>

int main () {
    int p[3][3] = {
        {2,1,1},
        {4,0,2},
        {3,2,0}
    };

    int bah = 0, vit = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (i <= 1 && j > 0 && i != j) {

                if (p[i][j] > p[j][i]) { vit += 3; }
                if (p[i][j] < p[j][i]) { bah += 3; }
                else {
                    bah += 1;
                    vit += 1;
                }
            }
        }
    }

    printf ("Bahia score: %d,Vitoria score: %d\n", bah,vit);
}