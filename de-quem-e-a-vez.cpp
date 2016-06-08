#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int QT;
unsigned long long n,m;
char teste1[200];
char teste2[200];
char teste3[200];
char teste4[200];
int d;


int main(){

    cin >> QT;
    for(int i=0;i<QT;i++){
        scanf("%s %s %s %s",teste1,teste2,teste3,teste4);
        scanf("%d %d",&n,&m);

        if(strcmp(teste2,"PAR") == 0){
            d =0;
        }else d =1;
        if((m+n)%2 == 0){
            if(d == 0) printf("%s\n",teste1);
            else printf("%s\n",teste3);
        }else{
            if(d == 0) printf("%s\n",teste3);
            else printf("%s\n",teste1);
        }
    }
    return 0;
}
