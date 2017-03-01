#include <stdio.h>

void mult (int n, int m) {
    int i, res, j;
    int arr [10] = {0};
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            res = i * j;
            while (res) {
                arr [res % 10] ++;
                res /= 10;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        printf ("%d->%d\n",i, arr [i]);
    }
}

int main () {
    mult (12, 4);
    return 0;
}
