#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;
int QT;
int N;
int A1,B1;
int A2,B2;
int C1,D1;
int C2,D2;
char S;

int HHT,MMT;
int banco;

void dfs(){
    int hora = 60;
    if(banco < 0) {
        S = '-';
        banco = banco*(-1);
    }
    else S = '+';

    HHT = banco/hora;
    MMT = banco%hora;
    return;
}


int main(){
    int difTemp = 0;
    cin >> QT;
    while(QT--){
        cin >> N;
        banco = 0;
        while(N--){
            scanf("%d:%d %d:%d | %d:%d %d:%d",&A1,&B1,&A2,&B2,&C1,&D1,&C2,&D2);
            difTemp = 8*60  - (A1*60 + B1);
            if(!(difTemp >= -5 && difTemp <= 5)){
                banco = banco + difTemp;
            }
            difTemp = (A2*60 + B2) - 12*60;
            if(!(difTemp >= -5 && difTemp <= 5)){
                banco = banco + difTemp;
            }

            difTemp = 14*60  - (C1*60 + D1);
            if(!(difTemp >= -5 && difTemp <= 5)){
                banco = banco + difTemp;
            }

            difTemp = (C2*60 + D2) - 18*60;
            if(!(difTemp >= -5 && difTemp <= 5)){
                banco = banco + difTemp;
            }
        }
        dfs();
        printf("%c %.2d:%.2d\n",S,HHT,MMT);
    }
    return 0;
}
