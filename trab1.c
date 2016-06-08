#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {LIVRE, CONSTANTE, FUNCAO} Amarracao;
typedef enum {VOID, CHAR, INT, FLOAT, DOUBLE, POINTER} Tipo;

typedef union{
    char   vChar;
    int    vInt;
    float  vFloat;
    double vDouble;
    void  *vPointer;
}Valor;

typedef struct{
    Amarracao amarracao;
    Tipo tipo;
    Valor valor;
}Parametro;

void *create (void *f, Tipo ret, unsigned n, Parametro *params);
void destroy (void *f, int recursivo);

typedef double (*dfptr) (double);

double h (double a, double b);
int g(int a,int b);

int ultParam(Parametro *params,unsigned n);
void *descobrevalor(Parametro params);
void imprimi(char *v){
    int i,a;
    for (i = 0; i < 30; ++i)
    {
        a = v[i];
        a&=0xff;
        printf("%x\n",a );
    }
}

int callEnd( void *f, char *v, int k);
int inicia( int k, char *v);
int livreDouble( int k, char *v, int desl);
int livreNotDouble( int k, char *v, int desl);
int constDouble(int k, char *v, int desl, double vDouble);
void* create2(void *f, Tipo ret, unsigned n, Parametro *params);
int main () {
    //printf("%d\n",g(10,20));
    //printf("%f\n",h(3,2));

    Parametro params [2];
    params [0].amarracao = LIVRE;
    params [0].tipo = DOUBLE;
    params [1].amarracao = CONSTANTE;
    params [1].tipo = DOUBLE;
    params [1].valor.vDouble = 2;
    printf("satanas ta aki  %x\n",params[1].valor.vInt);
    typedef double (*fptr) (double);
    fptr quadrado = (fptr) create2 (pow, DOUBLE, 2, params);
    printf("\n");
    printf ("O valor de 5 elevado ao quadrado é %f\n", quadrado (5));

return 0;
}

int ultParam(Parametro *params,unsigned n){
    printf("ultParam\n");
    int i;
    int resul = 0;
    for(i=0;i<n;i++){
        if(params[i].amarracao !=1 ){
            if(params[i].tipo == 4) resul += 8;
            else resul+=4;
        }
    }
    return resul + 4;
}

 

void* create2(void *f, Tipo ret, unsigned n, Parametro *params){
    int i,j,k=0;
    char *v = (char*)malloc(1024);
    k = inicia(k,v);
    printf("k = %d\n",k);

    printf("ant for\n");
    int desl = ultParam(params,n);
    printf("desl = %d\n", desl);
    for(i=n-1;i>=0;i--){
        printf("dentro for\n");
        // AMARAÇÃO LIVRE
        if(params[i].amarracao == 0){
            printf("AMARAÇÃO LIVRE\n");
            //DOUBLE                            
            if(params[i].tipo == 4){
                printf("DOUBLE\n");
                printf("desl = %d\n", desl);
                // CHAMAR livreConstDouble();
                k = livreDouble(k,v,desl);
                desl-=4;                        

            }
            // VOID , INT , CHAR , FLOAT e POINTER
            else if((params[i].tipo>=0 && params[i].tipo<=3) || (params[i].tipo==5)){
                printf("NOT DOUBLE\n");
                printf("desl = %d\n", desl);
                // CHAMAR livreNotDouble(); 
                k = livreNotDouble(k,v,desl);   

                
            }
            else{
                printf("DEU PAU 1\n");
            }
        }
        // AMARAÇÃO CONSTANTE
        else if(params[i].amarracao == 1){ 
            printf("AMARAÇÃO CONSTANTE\n");                     
            //DOUBLE                            
            if(params[i].tipo == 4){
                printf("DOUBLE\n");
                printf("desl = %d\n", desl);
                // CHAMAR livreConstDouble();
                k = constDouble(k,v,desl,params[i].valor.vDouble);                                              

            }
            // VOID , INT , CHAR , FLOAT e POINTER
            else if((params[i].tipo>=0 && params[i].tipo<=3) || (params[i].tipo==5)){
                printf("NOT DOUBLE \n");
                printf("desl = %d\n", desl);
                // CHAMAR constNotDouble();
                //v[k] = descobrevalor(params[i]); // push valor    
                if(params[i].tipo == CHAR){
                    v[k] = params[i].valor.vChar;
                }
                else if(params[i].tipo == FLOAT){
                    v[k] = params[i].valor.vFloat;
                }
                else if(params[i].tipo == INT){
                    v[k] = params[i].valor.vInt;
                }
                else if(params[i].tipo == DOUBLE){
                    v[k] = params[i].valor.vDouble;
                }
                else if(params[i].tipo == POINTER){
                    //v[k] = params[i].valor.vPointer;
                }
                else printf("DEU PAU\n");
                //k++;
            }
            else printf("DEU PAU 2\n");
        }
        // AMARAÇÃO FUNÇÃO
        else if(params[i].amarracao == 2){                      
            //DOUBLE                            
            if(params[i].tipo == 4){                        
            //v[k]= ;//asdas
            //k++;
            }
            // VOID , INT , CHAR , FLOAT e POINTER
            else if((params[i].tipo>=0 && params[i].tipo<=3) || (params[i].tipo==5)){   

            }
            else printf("DEU PAU 3\n");
        }
        else printf("DEU PAU 4\n");
    
        if(params[i].amarracao != 1){
            desl-=4;
        }
    }

    k=callEnd(f,v,k);

    printf("FINAL create\n");
    return v;
}