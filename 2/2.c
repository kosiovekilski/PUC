#include <stdio.h>

void raz (int number) {
    int a = 1, b = number, i, j;
    for (i = 0; i < number/2; i++) {
        for (j = i; j < number/2; j++) {
            if (i * j == number) {
                if ((j - i) < (b - a)) {
                    b = j;
                    a = i;
                }
            }
        }
    }
    printf ("NUMBERS: %d\t%d\n", a, b);
}

int main () {
    raz (48);
    return 0;
}
