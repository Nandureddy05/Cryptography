#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) {
        x1 += m0;
    }
    return x1;
}
void generateRSAKeys(int *e, int *d, int *n) {
    int p = 61;
    int q = 53;
    *n = p * q;
    int phi_n = (p - 1) * (q - 1);
    *e = 17;
    *d = modInverse(*e, phi_n);
}
int main() {
    int e, d, n;
    generateRSAKeys(&e, &d, &n);
    printf("Initial Public Key (e, n): (%d, %d)\n", e, n);
    printf("Initial Private Key (d, n): (%d, %d)\n", d, n);
    printf("\nSimulating leaking the private key...\n\n");
    generateRSAKeys(&e, &d, &n);
    printf("New Public Key (e, n): (%d, %d)\n", e, n);
    printf("New Private Key (d, n): (%d, %d)\n", d, n);

    return 0;
}
