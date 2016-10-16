#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define BASE 2

int32_t size_base_2 (int32_t a) {
    if (a < 0) {
        a = fabs(a);
    } else if (a == 0) {
        return 0;
    }

    return (int32_t) ceil(log((double) a) / log((double) BASE));
}

int32_t karatsuba (int32_t a, int32_t b) {
    printf("a is %i  and a_length : %i AND b is %i b_length : %i\n", a, size_base_2(a), b, size_base_2(b));
    if ((a < 10) || (b < 10)) {
        return a * b;
    }

    int32_t m = max(size_base_2(a), size_base_2(b));

    int32_t m2 = floor(m / 2);

    int32_t high1 = a >> m2;
    int32_t low1 = a % high1;
    printf("low : %i high : %i\n", low1, high1);

    int32_t high2 = b >> m2;
    int32_t low2 = b % high2;
    printf("low : %i high : %i\n", low2, high2);

    int32_t z0 = karatsuba(low1, low2);
    int32_t z1 = karatsuba((low1 + high1), (low2 + high2));
    int32_t z2 = karatsuba(high1, high2);

    return (z2 * pow(BASE, (2 * m2))) + ((z1 - z2 - z0) * pow(BASE, m2)) + (z0);
}

int main () {
    printf("%i", karatsuba(23, 24));
}
