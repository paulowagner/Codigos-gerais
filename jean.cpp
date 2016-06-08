#include <cstdio>

int triangulo[41][41];

int main () {
    long long R, soma = 0;
    triangulo[0][20] = 1;
    for (int i = 1; i < 41; i++)
        for (int j = 0; j < 41; j++)
            triangulo[i][j] = triangulo[i-1][j-1] + triangulo[i-1][j] + triangulo[i-1][j+1];
    scanf("%lld", &R);
    for (int j = 0; j < 41; j++)
        soma += triangulo[R][j];
    printf("%lld\n", soma);
    return 0;
}