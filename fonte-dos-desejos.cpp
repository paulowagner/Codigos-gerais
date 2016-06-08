#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int CX,CY;
int R1,R2;
int N;
int X,Y;
char vez;// 'p' ou 'c'

int cf,cb;
int pf,pb;

float distTemp;

void troca(){
    if (vez == 'p') vez = 'c';
    else vez = 'p';
}

float distCentro(){
    return sqrt( pow (X - CX, 2) + pow (Y - CY, 2));
}

int main(){
    cin >> N;
    while(N != 0){
        vez = 'c';
        cf=0,cb=0,pf=0,pb=0;
        scanf("%d %d %d %d",&CX,&CY,&R1,&R2);
        float ERRE1 = R1;
        float ERRE2 = R2;
        for(int i=0;i < 2*N; i++){
            scanf("%d %d",&X,&Y);
            distTemp = distCentro();
            if(distTemp < ERRE1){
                if(vez == 'c') cf++;
                else pf++;
            }else if(distTemp <= ERRE2){
                if(vez == 'c') cb++;
                else pb++;
            }
            troca();
        };
        if((cf > pf) || ((pf==cf) && (cb>pb)) )printf("C > P\n");
        else if ((pf > cf) || ((pf==cf) && (pb>cb)) )printf("P > C\n");
        else printf("C = P\n");
        cin >> N;


    }
    return 0;

}
