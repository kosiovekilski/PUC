#include <stdio.h>

int main () {
    int sum = 0, a, b;
    scanf ("%d %d", &a, &b);
    if (a > b) {
        a += b;
        b = a - b;
        a -= b;
    } // swap a^=b^=a^=b;
    for (; ++ a < b;) {
        sum += a;
    }
    printf ("%d\n", sum);
    return 0;
}
