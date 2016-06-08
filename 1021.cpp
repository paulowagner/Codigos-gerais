#include <iostream>
#include <fstream>
#include <cmath>
#include <string.h>
#include <map>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
double N;
using namespace std;

int main () {
   
    int notas[6] = {10000, 5000, 2000, 1000, 500, 200};
    int moedas[6] = {100, 50, 25, 10, 5, 1};
    scanf("%lf", &N);
    int valor = (int)(N*100);
    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        printf ("%d nota(s) de R$ %d.00\n", valor/notas[i], notas[i]/100);
        valor-=	(valor/notas[i])*notas[i];
    }
    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++) {
        printf ("%d moeda(s) de R$ %.2f\n",valor/moedas[i], (float)moedas[i]/100.0);
        valor-=(valor/moedas[i])*moedas[i];
    }  
    return 0;
}
