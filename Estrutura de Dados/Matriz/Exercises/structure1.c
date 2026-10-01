#include <stdio.h>

int main () {
    int num[10];
    int bigger, small;

    printf ("Enter the numbers: \n");
    for (int i = 0; i < 10; i++) {
        scanf ("%d", &num[i]);

        if (i == 0) {
            bigger = num[i];
            small = num[i];
        }
    }

    for (int i = 1; i < 10; i++) {
        if (num[i] > bigger) {
            bigger = num[i];
        }
        if (num[i] < small) {
            small = num[i];
        }
    }

    printf ("\n The difference between the two is: %d", bigger - small);
    return 0;
}