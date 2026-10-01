#include <stdio.h>

int main () {
    int num[5][5], bigger, small, count = 0, sum = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf ("%d", &num[i][j]);

            if (i > j) { count++; }
            if (count == 1) {
                small = num[i][j];
                bigger = num[i][j];
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (i > j) {
                if (num[i][j] < small) {
                    small = num[i][j];
                }

                else if (num[i][j] > bigger) {
                    bigger = num[i][j];
                }

                sum += num[i][j];
            }

        }
    }

    printf ("The largest number is: %d\nThe smallest number is: %d\nTheir average is: %.2f\n", bigger, small, (float)sum/count);

    return 0;
}