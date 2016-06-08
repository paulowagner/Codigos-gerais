/*
55
89 e5
68 00 00 00 01
68 00 00 00 03
e8 xx xx xx xx
83 c4 08
5d
c3

06 05 03 02

85
137 229
104 0 0 0 1
104 0 0 0 3
232 x x x x
131 196 8
93
195
*/

#include <stdio.h>
#include <stdlib.h>

void separa(unsigned int aux, char resp[]){
	resp[0] = aux;
	aux>>=8;
	resp[1] = aux;
	aux>>=8;
	resp[2] = aux;
	aux>>=8;
	resp[3] = aux;
	
}

int* create(void* f){
	void* func;
	int* funcAux;
	unsigned int end;	
	char auxvetor[4];

	funcAux = malloc(1024); // 1024 bytes
	end = (unsigned int)f - ((unsigned int)funcAux+18);
	funcAux[0] = 0x68e58955; //PUSH EBP

	funcAux[1] = 1;	
	funcAux[2] = 0X00000368;

	
	funcAux[3] = 0X90909000;
	
	separa(end, auxvetor);
	funcAux[4] = 0xC4819090;
	funcAux[5] = 0Xc35d08;


	return funcAux;

}

int soma(int a, int b){
	return a+b;
}


int main(){
	typedef int (*fptr) ();
	fptr hue = (fptr) create (soma);
	printf("sdhkasjhdlsa\n");
	printf ("%d\n", hue());
	return 0;
}
