#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>


void primeFactors(int n, int* f) {
    int k = 0;
    while (n%2 == 0) {
        f[k++] = 2;
        n /= 2;
        printf ("%d ", f[k-1]);
        printf (" - at %d\n", k-1);
    }

    for (int i = 3; i <= sqrt(n); i = i+2) {
        while (n%i == 0) {
            f[k++] = i;
            n = n/i;
        }
    }

    if (n > 2)
        f[k++] = n;
    printf(" loop end \n");
}

int main ( int argc, char *argv[] ) {
    if (argc != 3) {
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }

    int st1 = (int)strtol(argv[1], (char **)NULL, 10);
    int st2 = (int)strtol(argv[2], (char **)NULL, 10);

    int s = (st1 < st2) ? st1 : st2;
    int l = (st2 >= st1) ? st2 : st1;

    if ( l % s == 0 ) {
        printf("GCF Found: %d\n", s);
        return 0;
    }

    int s_factors[1000] = { 0 }, l_factors[1000] = { 0 };

    primeFactors(s, s_factors);
    for (int i = 0; s_factors[i] > 0; i++) {
        printf ("%d ", s_factors[i]);
    }
    printf(" sf end \n");

    primeFactors(l, l_factors);
    for (int i = 0; l_factors[i] > 0; i++) {
        printf ("%d ", l_factors[i]);
    }
    printf(" lf end \n");

    int gcf = 1, j = 0;
    for (int i = 0; s_factors[i] > 0; i++) {
        while (s_factors[i] != l_factors[j] && l_factors[j+1] > 0 && s_factors[i] >= l_factors[j]) {
            j++;
        }
        if (s_factors[i] == l_factors[j]) {
            gcf *= s_factors[i];
            j++;
        }
    }
    printf("GCF Found: %d\n", gcf);

    return 0;

}

