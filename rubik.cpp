#include <stdio.h>
#include <string.h>
int vet[50][50];
int passou[50][50];
int m,n;
int posy=0,posx=0;
int faceU[3][3];
int faceF[3][3];
int faceL[3][3];
int faceB[3][3];//L D R U
int faceR[3][3];//U B D F
int faceD[3][3];
void preencheFaceU()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			faceU[i][j] = 'u';
		}
	}
}
void preencheFaceR()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			faceR[i][j] = 'r';
		}
	}
}
void preencheFaceB()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			faceB[i][j] = 'b';
		}
	}
}
void preencheFaceL()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			faceL[i][j] = 'l';
		}
	}
}
void preencheFaceD()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			faceD[i][j] = 'd';

		}
	}
}
void preencheFaceF()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			faceF[i][j] = 'f';
		}
	}
}
int contaFaceU()
{
	int cont=0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{

			cont+=faceU[i][j];
		}
	}
	return cont;
}
int contaFaceR()
{
	int cont=0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{

			cont+=faceR[i][j];
		}
	}
	return cont;
}
int contaFaceB()
{
	int cont=0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{

			cont+=faceB[i][j];
		}
	}
	return cont;
}
int contaFaceL()
{
	int cont=0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cont += faceL[i][j];
		}
	}
	return cont;
}
int contaFaceD()
{
	int cont=0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cont += faceD[i][j];
		}
	}
	return cont;
}
int contaFaceF()
{
	int cont=0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cont += faceF[i][j];
		}
	}
	return cont;
}
void rotFaceU(int sentido)//R F L B
{
	int a=faceU[0][0],b=faceU[0][2],c=faceU[2][2],d=faceU[2][0];
	int c1=faceU[0][1],c2=faceU[1][2],c3=faceU[2][1],c4=faceU[1][0];
	if (sentido==1) //sentido horario
	{
		faceU[0][0] = d;
		faceU[0][2] = a;
		faceU[2][2] = b;
		faceU[2][0] = c;
		faceU[0][1] = c4;
		faceU[1][2] = c1;
		faceU[2][1] = c2;
		faceU[1][0] = c3;
		int aux = faceR[0][0],aux2 = faceR[0][1],aux3 = faceR[0][2];
		faceR[0][0] = faceB[0][0];
		faceR[0][1] = faceB[0][1];
		faceR[0][2] = faceB[0][2];
		faceB[0][0] = faceL[0][0];
		faceB[0][1] = faceL[0][1];
		faceB[0][2] = faceL[0][2];
		faceL[0][0] = faceF[0][0];
		faceL[0][1] = faceF[0][1];
		faceL[0][2] = faceF[0][2];
		faceF[0][0] = aux;
		faceF[0][1] = aux2;
		faceF[0][2] = aux3;
	}else{
		faceU[0][2] = c;
		faceU[0][0] = b;
		faceU[2][2] = d;
		faceU[2][0] = a;
		faceU[0][1] = c2;
		faceU[1][2] = c3;
		faceU[2][1] = c4;
		faceU[1][0] = c1;
		int aux = faceR[0][0],aux2 = faceR[0][1],aux3 = faceR[0][2];
		faceR[0][0] = faceF[0][0];
		faceR[0][1] = faceF[0][1];
		faceR[0][2] = faceF[0][2];
		faceF[0][0] = faceL[0][0];
		faceF[0][1] = faceL[0][1];
		faceF[0][2] = faceL[0][2];
		faceL[0][0] = faceB[0][0];
		faceL[0][1] = faceB[0][1];
		faceL[0][2] = faceB[0][2];
		faceB[0][0] = aux;
		faceB[0][1] = aux2;
		faceB[0][2] = aux3;
	}
}
void rotFaceR(int sentido)//U B D F
{
	int a=faceR[0][0],b=faceR[0][2],c=faceR[2][2],d=faceR[2][0];
	int c1=faceR[0][1],c2=faceR[1][2],c3=faceR[2][1],c4=faceR[1][0];
	if (sentido==1) //sentido horario
	{
		faceR[0][0] = d;
		faceR[0][2] = a;
		faceR[2][2] = b;
		faceR[2][0] = c;
		faceR[0][1] = c4;
		faceR[1][2] = c1;
		faceR[2][1] = c2;
		faceR[1][0] = c3;
		int aux = faceU[0][0],aux2 = faceU[0][1],aux3 = faceU[0][2];
		faceU[0][0] = faceF[0][2];
		faceU[0][1] = faceF[1][2];
		faceU[0][2] = faceF[2][2];
		faceF[0][2] = faceD[0][0];
		faceF[1][2] = faceD[0][1];
		faceF[2][2] = faceD[0][2];
		faceD[0][0] = faceB[2][0];
		faceD[0][1] = faceB[1][0];
		faceD[0][2] = faceB[0][0];
		faceB[2][0] = aux;
		faceB[1][0] = aux2;
		faceB[0][0] = aux3;
	}else{
		faceR[0][2] = c;
		faceR[0][0] = b;
		faceR[2][2] = d;
		faceR[2][0] = a;
		faceR[0][1] = c2;
		faceR[1][2] = c3;
		faceR[2][1] = c4;
		faceR[1][0] = c1;
		int aux = faceU[0][0],aux2 = faceU[0][1],aux3 = faceU[0][2];
		faceU[0][0] = faceB[2][0];
		faceU[0][1] = faceB[1][0];
		faceU[0][2] = faceB[0][0];
		faceB[2][0] = faceD[0][0];
		faceB[1][0] = faceD[0][1];
		faceB[0][0] = faceD[0][2];
		faceD[0][0] = faceF[0][2];
		faceD[0][1] = faceF[1][2];
		faceD[0][2] = faceF[2][2];
		faceF[0][2] = aux;
		faceF[1][2] = aux2;
		faceF[2][2] = aux3;
	}
}
void rotFaceB(int sentido)//L D R U
{
	int a=faceB[0][0],b=faceB[0][2],c=faceB[2][2],d=faceB[2][0];
	int c1=faceB[0][1],c2=faceB[1][2],c3=faceB[2][1],c4=faceB[1][0];
	if (sentido==1) //sentido horario
	{
		faceB[0][0] = d;
		faceB[0][2] = a;
		faceB[2][2] = b;
		faceB[2][0] = c;
		faceB[0][1] = c4;
		faceB[1][2] = c1;
		faceB[2][1] = c2;
		faceB[1][0] = c3;
		int aux = faceL[0][0],aux2 = faceL[1][0],aux3 = faceL[2][0];
		faceL[0][0] = faceU[0][0];
		faceL[1][0] = faceU[1][0];
		faceL[2][0] = faceU[2][0];
		//printf("----------------------------------- SH\n");
		//mostrafaceL();
		faceU[0][0] = faceR[2][2];
		faceU[1][0] = faceR[1][2];
		faceU[2][0] = faceR[0][2];
		//mostrafaceU();
		faceR[2][2] = faceD[2][2];
		faceR[1][2] = faceD[1][2];
		faceR[0][2] = faceD[0][2];
		//mostrafaceR();
		faceD[2][2] = aux;
		faceD[1][2] = aux2;
		faceD[0][2] = aux3;
		//mostrafaceD();
		//printf("-----------------------------------\n");
		//getchar();
	}else{
		faceB[0][2] = c;
		faceB[0][0] = b;
		faceB[2][2] = d;
		faceB[2][0] = a;
		faceB[0][1] = c2;
		faceB[1][2] = c3;
		faceB[2][1] = c4;
		faceB[1][0] = c1;
		int aux = faceL[0][0],aux2 = faceL[1][0],aux3 = faceL[2][0];
		faceL[0][0] = faceD[2][2];
		faceL[1][0] = faceD[1][2];
		faceL[2][0] = faceD[0][2];
		//printf("-----------------------------------SAH\n");
		faceD[2][2] = faceR[2][2];
		faceD[1][2] = faceR[1][2];
		faceD[0][2] = faceR[0][2];
		//mostrafaceD();
		faceR[2][2] = faceU[0][0];
		faceR[1][2] = faceU[1][0];
		faceR[0][2] = faceU[2][0];
		//mostrafaceR();
		faceU[0][0] = aux;
		faceU[1][0] = aux2;
		faceU[2][0] = aux3;
		//mostrafaceU();
		//printf("-----------------------------------\n");
		//getchar();
	}
}
void rotFaceL(int sentido)//F D B U
{
	int a=faceL[0][0],b=faceL[0][2],c=faceL[2][2],d=faceL[2][0];
	int c1=faceL[0][1],c2=faceL[1][2],c3=faceL[2][1],c4=faceL[1][0];
	if (sentido==1) //sentido horario
	{
		faceL[0][0] = d;
		faceL[0][2] = a;
		faceL[2][2] = b;
		faceL[2][0] = c;
		faceL[0][1] = c4;
		faceL[1][2] = c1;
		faceL[2][1] = c2;
		faceL[1][0] = c3;
		int aux = faceF[0][0],aux2 = faceF[1][0],aux3 = faceF[2][0];
		faceF[0][0] = faceU[2][0];
		faceF[1][0] = faceU[2][1];
		faceF[2][0] = faceU[2][2];
		faceU[2][0] = faceB[2][2];
		faceU[2][1] = faceB[1][2];
		faceU[2][2] = faceB[0][2];
		faceB[2][2] = faceD[2][0];
		faceB[1][2] = faceD[2][1];
		faceB[0][2] = faceD[2][2];
		faceD[2][0] = aux;
		faceD[2][1] = aux2;
		faceD[2][2] = aux3;
	}else{
		faceL[0][2] = c;
		faceL[0][0] = b;
		faceL[2][2] = d;
		faceL[2][0] = a;
		faceL[0][1] = c2;
		faceL[1][2] = c3;
		faceL[2][1] = c4;
		faceL[1][0] = c1;
		int aux = faceF[0][0],aux2 = faceF[1][0],aux3 = faceF[2][0];
		faceF[0][0] = faceD[2][0];
		faceF[1][0] = faceD[2][1];
		faceF[2][0] = faceD[2][2];
		faceD[2][0] = faceB[2][2];
		faceD[2][1] = faceB[1][2];
		faceD[2][2] = faceB[0][2];
		faceB[2][2] = faceU[2][0];
		faceB[1][2] = faceU[2][1];
		faceB[0][2] = faceU[2][2];
		faceU[2][0] = aux;
		faceU[2][1] = aux2;
		faceU[2][2] = aux3;
	}
}
void rotFaceD(int sentido)//F R B L
{
	int a=faceD[0][0],b=faceD[0][2],c=faceD[2][2],d=faceD[2][0];
	int c1=faceD[0][1],c2=faceD[1][2],c3=faceD[2][1],c4=faceD[1][0];
	if (sentido==1) //sentido horario
	{
		faceD[0][0] = d;
		faceD[0][2] = a;
		faceD[2][2] = b;
		faceD[2][0] = c;
		faceD[0][1] = c4;
		faceD[1][2] = c1;
		faceD[2][1] = c2;
		faceD[1][0] = c3;
		int aux = faceF[2][2],aux2 = faceF[2][1],aux3 = faceF[2][0];
		faceF[2][2] = faceL[2][2];
		faceF[2][1] = faceL[2][1];
		faceF[2][0] = faceL[2][0];
		faceL[2][2] = faceB[2][2];
		faceL[2][1] = faceB[2][1];
		faceL[2][0] = faceB[2][0];
		faceB[2][2] = faceR[2][2];
		faceB[2][1] = faceR[2][1];
		faceB[2][0] = faceR[2][0];
		faceR[2][2] = aux;
		faceR[2][1] = aux2;
		faceR[2][0] = aux3;
	}else{
		faceD[0][2] = c;
		faceD[0][0] = b;
		faceD[2][2] = d;
		faceD[2][0] = a;
		faceD[0][1] = c2;
		faceD[1][2] = c3;
		faceD[2][1] = c4;
		faceD[1][0] = c1;
		int aux = faceF[2][2],aux2 = faceF[2][1],aux3 = faceF[2][0];
		faceF[2][2] = faceR[2][2];
		faceF[2][1] = faceR[2][1];
		faceF[2][0] = faceR[2][0];
		faceR[2][2] = faceB[2][2];
		faceR[2][1] = faceB[2][1];
		faceR[2][0] = faceB[2][0];
		faceB[2][2] = faceL[2][2];
		faceB[2][1] = faceL[2][1];
		faceB[2][0] = faceL[2][0];
		faceL[2][2] = aux;
		faceL[2][1] = aux2;
		faceL[2][0] = aux3;
	}
}
void rotFaceF(int sentido)//R D L U
{
	int a=faceF[0][0],b=faceF[0][2],c=faceF[2][2],d=faceF[2][0];
	int c1=faceF[0][1],c2=faceF[1][2],c3=faceF[2][1],c4=faceF[1][0];
	if (sentido==1) //sentido horario
	{
		faceF[0][0] = d;
		faceF[0][2] = a;
		faceF[2][2] = b;
		faceF[2][0] = c;
		faceF[0][1] = c4;
		faceF[1][2] = c1;
		faceF[2][1] = c2;
		faceF[1][0] = c3;
		int aux = faceR[0][0],aux2 = faceR[1][0],aux3 = faceR[2][0];
		faceR[0][0] = faceU[2][2];
		faceR[1][0] = faceU[1][2];
		faceR[2][0] = faceU[0][2];
		faceU[2][2] = faceL[2][2];
		faceU[1][2] = faceL[1][2];
		faceU[0][2] = faceL[0][2];
		faceL[2][2] = faceD[0][0];
		faceL[1][2] = faceD[1][0];
		faceL[0][2] = faceD[2][0];
		faceD[0][0] = aux;
		faceD[1][0] = aux2;
		faceD[2][0] = aux3;
	}else{
		faceF[0][2] = c;
		faceF[0][0] = b;
		faceF[2][2] = d;
		faceF[2][0] = a;
		faceF[0][1] = c2;
		faceF[1][2] = c3;
		faceF[2][1] = c4;
		faceF[1][0] = c1;
		int aux = faceR[0][0],aux2 = faceR[1][0],aux3 = faceR[2][0];
		faceR[0][0] = faceD[0][0];
		faceR[1][0] = faceD[1][0];
		faceR[2][0] = faceD[2][0];
		faceD[0][0] = faceL[2][2];
		faceD[1][0] = faceL[1][2];
		faceD[2][0] = faceL[0][2];
		faceL[2][2] = faceU[2][2];
		faceL[1][2] = faceU[1][2];
		faceL[0][2] = faceU[0][2];
		faceU[2][2] = aux;
		faceU[1][2] = aux2;
		faceU[0][2] = aux3;
	}
}
bool diferente(){

	if (contaFaceF()!=('f'*9))
	{
		return true;
	}
	if (contaFaceB()!=('b'*9))
	{
		return true;
	}
	if (contaFaceL()!=('l'*9))
	{
		return true;
	}
	if (contaFaceR()!=('r'*9))
	{
		return true;
	}
	if (contaFaceU()!=('u'*9))
	{
		return true;
	}
	if (contaFaceD()!=('d'*9))
	{
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	char mov[80];
	while(scanf("%s",mov)!=EOF)
	{
		int cont = 0;
		preencheFaceF();
		preencheFaceR();
		preencheFaceU();
		preencheFaceB();
		preencheFaceL();
		preencheFaceD();
		do{
			cont++;
			
			for (int i = 0; i < strlen(mov); ++i)
			{
				if (mov[i]=='R')
	 				rotFaceR(1);
	 			else if (mov[i]=='r')
	 				rotFaceR(0);
	 			else if (mov[i]=='L')
	 				rotFaceL(1);
	 			else if (mov[i]=='l')
	 				rotFaceL(0);
	 			else if (mov[i]=='U')
	 				rotFaceU(1);
	 			else if (mov[i]=='u')
	 				rotFaceU(0);
	 			else if (mov[i]=='D')
	 				rotFaceD(1);
	 			else if (mov[i]=='d')
	 				rotFaceD(0);
	 			else if (mov[i]=='F')
	 				rotFaceF(1);
	 			else if (mov[i]=='f')
	 				rotFaceF(0);
	 			else if (mov[i]=='B')
	 				rotFaceB(1);
	 			else 
	 				rotFaceB(0);
			}
		}while(diferente());
		printf("%d\n",cont);
	}
	return 0;
}