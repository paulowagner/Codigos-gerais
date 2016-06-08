#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif
#include <cstdlib>

#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include "tinyxml.h"
#include "Canon.h"
#include "Rectangle.h" 
#include "Circle.h"
#include "Tanque.h"
#include "Bala.h"
#define vel 0.7
using namespace std;
int destino, origem, vertices = 0;
int custo, *custos; 
int xTanque,yTanque;
unsigned char matrix[774][727],matrixArena[774][727];
vector<Rectangle *> retangulos;
vector<Circle *> circulos;
map< int, int> valores;
vector< GLfloat *> matriztanques;
vector<Tanque *>  inimigos;
// Tamanho da arena - a ser definido pelo arquivo pgm
int arenaWidth = 600, arenaHeight = 600;
// Nome do arquivo pgm - a ser lido pelo arquivo config.xml
string pgmFileName;
//Nome do arquivo svg - a ser lido pelo arquivo config.xml
string svgFileName;
// Lista de objetos a serem lidos do arquivo svg e desenhados na tela
vector<Object*> objects;

bool MatrizColisaoBala[774][727],MatrizColisaoCanhao[774][727];

string s = "vazio";

GLfloat	 Matriz[4][4],MatrizAux[4][4],MatrizMapa[4][4];
Tanque* t = new Tanque(0,0,107,142,35);

float angle1=0;

GLuint list_teste,list_bala,list_bala_ini;
// Dicionario para lidar com a leitura do teclado
int keyStatus[256];

// Inicializa posicoes do mouse com zeero
int xMouse=0, yMouse=0;

// Inicializa teclas com zero
void inicializaTeclas()
{
	for (size_t i = 0; i < 255; i++)
		keyStatus[i] = 0;
}

float angle(int i, int a,int b){
	if(i>=0){
		if((matriztanques.at(i)[13]*(arenaHeight/2)-(b))==0){
			if((matriztanques.at(i)[12]*(arenaWidth/2))>(a))
				return -90;
			else
				return 90;
		}
		float angle = atan((matriztanques.at(i)[12]*(arenaWidth/2)-(a))/(matriztanques.at(i)[13]*(arenaHeight/2)-(b)));
		angle = (angle*180)/3.1415926535898;
		if(b<0)
			angle+=180;
		if(b>=0&&matriztanques.at(i)[13]>0&&(matriztanques.at(i)[13]*(arenaHeight/2))>b)
			angle+=180;
		if(b<0&&(matriztanques.at(i)[13]*(arenaHeight/2))<0&&(matriztanques.at(i)[13]*(arenaHeight/2))<b)
			angle+=180;
		return angle;
	}else{
		if((Matriz[3][1]*(arenaHeight/2)-(b))==0){
			if((Matriz[3][0]*(arenaWidth/2))>(a))
				return -90;
			else
				return 90;
		}
		float angle = atan((Matriz[3][0]*(arenaWidth/2)-(a))/(Matriz[3][1]*(arenaHeight/2)-(b)));
		angle = (angle*180)/3.1415926535898;
		if(b<0)
			angle+=180;
		if(b>=0&&Matriz[3][1]>0&&(Matriz[3][1]*(arenaHeight/2))>b)
			angle+=180;
		if(b<0&&(Matriz[3][1]*(arenaHeight/2))<0&&(Matriz[3][1]*(arenaHeight/2))<b)
			angle+=180;
		return angle;
	}
}

bool mexeu = false;
bool first= true;
void ciclo1()
{
	if(t->c.ciclo==0)
		t->c.ciclo=1;
	else
		t->c.ciclo=0;
}
int apaga = false,apagaPrincipal=true;
bool colisaotanques(int k,int x,int y)
{	
	int yt,xt;
	if(k!=-1){
		yt = Matriz[3][1]*(774/2);
		xt = Matriz[3][0]*(727/2);
		yt=-yt+(774/2);
		xt=xt+(727/2);
		apaga= t->c.colisao(x,y);
		if (apaga)
 			return false;
		if(sqrt((x-xt)*(x-xt)+(y-yt)*(y-yt))<40)
			return false;
	}
	for (int i = 0; i < inimigos.size(); i++)
	{
		if(k==-1){
			
			apagaPrincipal=inimigos.at(i)->c.colisao(x,y);
			if(apagaPrincipal)
				return false;
		}
		if(i!=k){
			yt = matriztanques.at(i)[13]*(774/2);
			xt = matriztanques.at(i)[12]*(727/2);
			yt=-yt+(774/2);
			xt=xt+(727/2);
			if(sqrt((x-xt)*(x-xt)+(y-yt)*(y-yt))<40)
				return false;
		}
	}
	return true;
}

void moveinimigo(int k,float rate,int i)
{
    double d;
    
    if(k==8||k==1||k==2){
		glTranslatef(0,rate,0);
		inimigos.at(i)->c.rodaesq++;
		inimigos.at(i)->c.rodadir++;
		if(inimigos.at(i)->c.rodadir==7)
			inimigos.at(i)->c.rodadir=0;
		if(inimigos.at(i)->c.rodaesq==7)
			inimigos.at(i)->c.rodaesq=0;
	}
	if(k==6||k==5||k==4)
	{
		glTranslatef(0,-rate,0);
		inimigos.at(i)->c.rodaesq--;
		inimigos.at(i)->c.rodadir--;
		if(inimigos.at(i)->c.rodadir==-1)
			inimigos.at(i)->c.rodadir=6;
		if(inimigos.at(i)->c.rodaesq==-1)
			inimigos.at(i)->c.rodaesq=6;
	}
}
void moveinimigorot(int k,int i,int timeDiference){
	float rate = timeDiference;
	inimigos.at(i)->c.ciclo = t->c.ciclo;
	if(k==2||k==3||k==4)
	{ 
		if(k==2)
		{
			if(inimigos.at(i)->c.ciclo)
				inimigos.at(i)->c.rodadir--;
			if(inimigos.at(i)->c.rodadir==-1)
				inimigos.at(i)->c.rodadir=6;
			glRotatef(-rate,0, 0, 1);
			inimigos.at(i)->c.angleac+=rate;
		}else if(k==4){
			if(inimigos.at(i)->c.ciclo)
				inimigos.at(i)->c.rodadir++;
			if(inimigos.at(i)->c.rodadir==7)
				inimigos.at(i)->c.rodadir=0;
			glRotatef(rate,0, 0, 1);
			inimigos.at(i)->c.angleac-=rate;
		}else{
			inimigos.at(i)->c.rodaesq--;
			inimigos.at(i)->c.rodadir++;
			if(inimigos.at(i)->c.rodadir==7)
				inimigos.at(i)->c.rodadir=0;
			if(inimigos.at(i)->c.rodaesq==-1)
				inimigos.at(i)->c.rodaesq=6;
			glRotatef(-rate,0, 0, 1);
			inimigos.at(i)->c.angleac+=rate;
		}
	}

	if(k==7||k==8||k==6)
	{ 
		if(k==8)
		{
			if(inimigos.at(i)->c.ciclo)
				inimigos.at(i)->c.rodaesq--;
			if(inimigos.at(i)->c.rodaesq==-1)
				inimigos.at(i)->c.rodaesq=6;
			glRotatef(rate,0, 0, 1);
			inimigos.at(i)->c.angleac-=rate;
		}else if(k==6){
			if(inimigos.at(i)->c.ciclo)
				inimigos.at(i)->c.rodaesq++;
			if(inimigos.at(i)->c.rodaesq==7)
				inimigos.at(i)->c.rodaesq=0;
			glRotatef(-rate,0, 0, 1);
			inimigos.at(i)->c.angleac+=rate;
		}else{
			inimigos.at(i)->c.rodaesq++;
			inimigos.at(i)->c.rodadir--;
			if(inimigos.at(i)->c.rodadir==-1)
				inimigos.at(i)->c.rodadir=6;
			if(inimigos.at(i)->c.rodaesq==7)
				inimigos.at(i)->c.rodaesq=0;
			glRotatef(rate,0, 0, 1);
			inimigos.at(i)->c.angleac-=rate;
		}
	}
}
// Funcao a ser chamada a todo momento durante o loop de renderizacao
int k=1,muda=0,v[4];
int tempo;
float novoTiro=0;
bool nitro=false;
void idle()
{
	
    double d,rate;
	ciclo1();
	if(first){
		glGetFloatv(GL_MODELVIEW_MATRIX, &MatrizMapa[0][0]);
		Tanque* aux;
		GLfloat* auxmatrix;
		for (int i = 0; i < circulos.size(); i++)
		{
			if(i<4)
				v[i]=k;
			if(circulos.at(i)->R==200){
				glTranslatef(circulos.at(i)->x,circulos.at(i)->y,0);
				glRotatef(-90,0, 0, 1);
				t->c.angleac+=90;
			}else{
				glPushMatrix();
				glLoadIdentity();
				glMultMatrixf(&MatrizMapa[0][0]);
				glTranslatef(circulos.at(i)->x,circulos.at(i)->y,0);
				glRotatef(-90,0, 0, 1);
				aux = new Tanque(0,0,207,181,59);
				aux->c.angleac+=90;
				auxmatrix = new GLfloat[16];
				glGetFloatv(GL_MODELVIEW_MATRIX, auxmatrix);
				matriztanques.push_back(auxmatrix);
				inimigos.push_back(aux);
				glPopMatrix();
			}
		}
		
	}
	    // Faz o calculo do delta time
	static GLdouble previousTime = 0;
	GLdouble currentTime, timeDiference;
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	timeDiference = currentTime - previousTime;
	previousTime = currentTime;
	tempo=timeDiference;
	novoTiro+=0.0005*timeDiference;
	glGetFloatv(GL_MODELVIEW_MATRIX, &MatrizAux[0][0]);
    // Atualiza o canhao dependendo das opcoes do teclado
    bool down = false,up=false;
	if (keyStatus['n']||keyStatus['N'])
		nitro=!nitro;
	if (keyStatus['w'] || keyStatus['W'])
	{

		if (nitro)
			t->c.moveUp(0.8*timeDiference*vel);
		else
			t->c.moveUp(0.2*timeDiference*vel);
		up=true;
	}
	if (keyStatus['s'] || keyStatus['S'])
	{
		if (nitro)
			t->c.moveDown(-0.8*timeDiference*vel);
		else
			t->c.moveDown(-0.2*timeDiference*vel);
		down = true;
	}
	glGetFloatv(GL_MODELVIEW_MATRIX, &Matriz[0][0]);
	int yt = Matriz[3][1]*(774/2);
	int xt = Matriz[3][0]*(727/2);
	yt=-yt+(774/2);
	xt=xt+(727/2);
	if(!colisaotanques(-1,xt,yt)||matrix[774-yt-1][xt]<20)
	{
		if (apagaPrincipal)
		{
			cout<<"Perdeu"<<endl;
			exit(0);
		}	
		glLoadIdentity();
		glMultMatrixf(&MatrizAux[0][0]);
	}
	GLfloat aux[4][4];

	if (keyStatus['d'] || keyStatus['D'])
	{
		t->c.turnRight(0.2*timeDiference*vel,up,down);
	}
	if (keyStatus['a'] || keyStatus['A'])
	{
		t->c.turnLeft(0.2*timeDiference*vel,up,down);
	}
	muda++;
	for (int i = 0; i < inimigos.size(); i++)
	{
		if(inimigos.at(i)->draw)
		{
			if(muda==50)
			{
				d = (double) rand( ) / ((double) RAND_MAX + 1);
				k = d*8;
				k = 1 + k;
				v[i]=k;
			}
			glPushMatrix(); 
			glLoadIdentity ();
			glMultMatrixf(matriztanques.at(i));
			glGetFloatv(GL_MODELVIEW_MATRIX, &aux[0][0]);
			rate = timeDiference*0.2*vel;
			moveinimigo(v[i],rate,i);
			glGetFloatv(GL_MODELVIEW_MATRIX, matriztanques.at(i));
			int yt = matriztanques.at(i)[13]*(774/2);
			int xt = matriztanques.at(i)[12]*(727/2);
			yt=-yt+(774/2);
			xt=xt+(727/2);
			bool colide = colisaotanques(i,xt,yt);
			if(matrix[774-yt-1][xt]<20||!colide){
				if (apaga)
				{
					apaga=false;
					inimigos.at(i)->draw = false;
					glPopMatrix();
					continue;
				}
				glLoadIdentity();
				glMultMatrixf(&aux[0][0]);
			}
			moveinimigorot(v[i],i,rate);
			glGetFloatv(GL_MODELVIEW_MATRIX, matriztanques.at(i));
			glPopMatrix();
		}
	}
	if (inimigos.size()==0)
	{
		cout<<"Ganhou"<<endl;
		exit(0);
	}
	if (novoTiro>1.0)
	{
		for (int i = 0; i < inimigos.size(); i++)
		{	
			if(inimigos.at(i)->draw)
			{
				inimigos.at(i)->c.NewBala();
			}
		}
		novoTiro-=1;
	}
	if(muda==50)
		muda=0;
	first=false;
	glGetFloatv(GL_MODELVIEW_MATRIX, &Matriz[0][0]);
	yTanque = Matriz[3][1]*(arenaHeight/2);
	xTanque = Matriz[3][0]*(arenaWidth/2); 
	for(int i=0;i<inimigos.size();i++){
		inimigos.at(i)->c.angle = angle(i,xTanque,yTanque);
	}

	if(xMouse != 0 || yMouse !=0)
	{
		mexeu = true;
		int y=-(yMouse-(arenaHeight/2));
		int x=xMouse-(arenaWidth/2);
		angle1 = angle(-1,x,y);
		
	}
    
	glutPostRedisplay();

}

// Funcao movimento do mouse
void mouseMove(int x, int y)
{
    // Atualiza posicoes do mouse - altera posicao da arma do canhao
	xMouse = x;
	yMouse = y;
}

// Funcao click do mouse
void mouse(int button, int state, int x, int y)
{
	if (button == 0 && state ==1)
		t->c.NewBala();
}

// Funcao de inicializacao
void init()
{
	
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-(arenaWidth/2), (arenaWidth/2), -(arenaHeight/2), (arenaHeight/2), -1, 1);
    inicializaTeclas();
}

// Funcao display
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	float tt = Matriz[3][0];
	int x = (Matriz[3][0]*(arenaWidth/2));
	int y = (Matriz[3][1]*(arenaHeight/2));
	
	if(x<-280&&y<48&&y>-43){
		Matriz[3][0] = tt*278/x;
		glLoadIdentity ();
		glMultMatrixf(&Matriz[0][0]);
	}
	if(x>280&&y<48&&y>-43){
		Matriz[3][0] = tt*(-278)/x;
		glLoadIdentity ();
		glMultMatrixf(&Matriz[0][0]);
	}
	
	for(int i=0;i<inimigos.size();i++)
	{
		glPushMatrix(); 
		glLoadIdentity ();
		glMultMatrixf(matriztanques.at(i));
		tt = matriztanques.at(i)[12];
		int yt = matriztanques.at(i)[13]*(774/2);
		int xt = matriztanques.at(i)[12]*(727/2);
		if(xt<-280&&yt<48&&yt>-43){
			matriztanques.at(i)[12] = tt*278/xt;
			glLoadIdentity ();
			glMultMatrixf(matriztanques.at(i));
		}
		if(xt>280&&yt<48&&yt>-43){
			matriztanques.at(i)[12] = tt*(-278)/xt;
			glLoadIdentity ();
			glMultMatrixf(matriztanques.at(i));
		}
		glGetFloatv(GL_MODELVIEW_MATRIX, matriztanques.at(i));
		glPopMatrix();
	}
	t->c.Fire(tempo,list_bala,matrix);
	for (int i = 0; i < inimigos.size(); ++i)
	{
		inimigos.at(i)->c.Fire(tempo,list_bala_ini,matrix);
		if(!inimigos.at(i)->draw&&inimigos.at(i)->c.balas.size()==0)
		{
			inimigos.erase(inimigos.begin()+i);
			matriztanques.erase(matriztanques.begin()+i);
			i--;
		}
	}
	for (int i = 0; i < inimigos.size(); i++)
	{
		if(inimigos.at(i)->draw)
		{
			glPushMatrix(); 
			glLoadIdentity ();
			glMultMatrixf(matriztanques.at(i));
			inimigos.at(i)->Draw();
			glCallList(list_teste+1+inimigos.at(i)->c.rodaesq);
			glCallList(list_teste+8+inimigos.at(i)->c.rodadir);
			glRotatef(-inimigos.at(i)->c.angle+inimigos.at(i)->c.angleac,0, 0, 1);
			glGetFloatv(GL_MODELVIEW_MATRIX, &inimigos.at(i)->c.MatrizCanhao[0][0]);
			glCallList(list_teste+15);
			glPopMatrix();
		}
	}
	glCallList(list_teste);
	glCallList(list_teste+1+t->c.rodaesq);
	glCallList(list_teste+8+t->c.rodadir);
	if(mexeu){
		glPushMatrix(); 
		glLoadIdentity ();
		glMultMatrixf(&Matriz[0][0]);
		glRotatef(-angle1+t->c.angleac,0, 0, 1);
		glGetFloatv(GL_MODELVIEW_MATRIX, &t->c.MatrizCanhao[0][0]);
		glCallList(list_teste+15);
		glPopMatrix();
	}else{
		glPushMatrix(); 
		glLoadIdentity ();
		glMultMatrixf(&Matriz[0][0]);
		glGetFloatv(GL_MODELVIEW_MATRIX, &t->c.MatrizCanhao[0][0]);
		glPopMatrix();
		glCallList(list_teste+15);
	}	
	
	glPushMatrix();
	glLoadIdentity ();
	glMultMatrixf(&MatrizMapa[0][0]);
	for (int i = 0; i < retangulos.size(); ++i)
	{
		retangulos.at(i)->Draw();
	}
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

// Funcao de leitura do teclado - tecla eh solta
void keyboardUp(unsigned char key, int x, int y)
{
	keyStatus[(int)key] = 0; 
}

// Funcao de leitura do teclado - tecla eh pressionada
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
        // Atualiza estado de cada tecla
		keyStatus[key] = 1;
		break;
	} 
}
void drawLinhaRodaEsquerda(int desloc,int x,int y)
{
	int j = 6;
	for (int i = 0; i < 4; ++i)
	{
		glLineWidth(1.0);
		glColor3ub(0,0,0);
		glBegin(GL_LINES);
		glVertex2i(x-16,j+y+desloc);
		glVertex2i(x-8,j+y+desloc);
		glEnd();
		j-=6;
	}
}
void drawLinhaRodaDireita(int desloc,int x,int y)
{
	int j = 6;
	for (int i = 0; i < 4; ++i)
	{
		glLineWidth(1.0);
		glColor3ub(0,0,0);
		glBegin(GL_LINES);
		glVertex2i(8,j+y+desloc);
		glVertex2i(16,j+y+desloc);
		glEnd();
		y-=6;
	}
}
void funcaoinicialist()
{
	
	//display
	list_teste = glGenLists (16);
	glNewList(list_teste, GL_COMPILE);
	t->Draw();
	glEndList();
	for(int i=0;i<7;i++){
		glNewList(list_teste+1+i, GL_COMPILE);
		drawLinhaRodaEsquerda(i,0,0);
		glEndList();
	}

	for(int i=0;i<7;i++){
		glNewList(list_teste+8+i, GL_COMPILE);
		drawLinhaRodaDireita(i,0,0);
		glEndList();
	}
	glNewList(list_teste+15, GL_COMPILE);
	t->c.Draw();
	glEndList();
	Circle bala,balaini;
	bala.Set(0,20,2,255,0,0);
	balaini.Set(0,20,2,200,50,0);
	list_bala = glGenLists (1);
	glNewList(list_bala, GL_COMPILE);
	bala.Draw();
	glEndList();
	list_bala_ini = glGenLists (1);
	glNewList(list_bala_ini, GL_COMPILE);
	balaini.Draw();
	glEndList();
}

// Leitura do config.xml file
bool loadConfig()
{
	TiXmlDocument doc("config.xml");
	bool loaded = doc.LoadFile();
	if (loaded)
	{
        // Faz a leitura dos dados do arquivo xml
        TiXmlElement* inputFiles = doc.FirstChildElement("config")->FirstChildElement("inputFiles");
        
        // Le path para primeiro arquivo (pgm)
		TiXmlElement* arenaDescription = inputFiles->FirstChildElement("arenaDistanceMap");
		pgmFileName = arenaDescription->Attribute("path");
		pgmFileName.append(arenaDescription->Attribute("name"));
		pgmFileName.append(".").append(arenaDescription->Attribute("type"));

        // Le path para segundo arquivo (svg)
		TiXmlElement* arenaMobility = inputFiles->FirstChildElement("arenaDescription");
		svgFileName = arenaMobility->Attribute("path");
		svgFileName.append(arenaMobility->Attribute("name"));
		svgFileName.append(".").append(arenaMobility->Attribute("type"));
	}
	else
	{
		cout << "Arquivo 'config.xml' nao encontrado ou nao eh um xml valido." << endl;
	}
	return loaded;
}
bool loadArenaMobilityMatixArena()
{
	char line[100];
	FILE *arenaFile;
	char lixo[50];
	int altura,largura,e;
	arenaFile = fopen("arenaMobility.pgm", "r");
	bool result = false;
	if(arenaFile > 0)
	{
        fgets(lixo,50,arenaFile);
        fgets(lixo,50,arenaFile);
        fscanf(arenaFile,"%d %d",&largura,&altura);
        arenaHeight = altura;
        arenaWidth = largura;
        fscanf(arenaFile,"%d",&e);
        for (int i = altura-1; i >= 0; i--)
        {
        	
        	for (int j = 0; j < largura; j++)
        	{
        		fscanf(arenaFile,"%d",&e);
        		matrixArena[i][j]=e;
        	}
        }
        
		fclose(arenaFile);
		return true;
	}
	else
	{
		cout << "Arquivo '" << pgmFileName << "' nao encontrado." << endl;
		return false;
	}
}
// Leitura da arena.pgm
bool loadArenaMobilityMatix()
{
	char line[100];
	FILE *arenaFile;
	char lixo[50];
	int altura,largura,e;
	arenaFile = fopen(pgmFileName.c_str(), "r");
	bool result = false;
	if(arenaFile > 0)
	{
        fgets(lixo,50,arenaFile);
        fgets(lixo,50,arenaFile);
        fscanf(arenaFile,"%d %d",&largura,&altura);
        arenaHeight = altura;
        arenaWidth = largura;
        fscanf(arenaFile,"%d",&e);
        for (int i = altura-1; i >= 0; i--)
        {
        	
        	for (int j = 0; j < largura; j++)
        	{
        		fscanf(arenaFile,"%d",&e);
        		matrix[i][j]=e;
        	}
        }
        
		fclose(arenaFile);
		return true;
	}
	else
	{
		cout << "Arquivo '" << pgmFileName << "' nao encontrado." << endl;
		return false;
	}
}
char Valor[2];
int Resultado;
void htod(){
	string Hexa = "0123456789abcdef" ;
	Resultado = 0;    
	for (int i = 0; i < 2; i++)
	{
		Resultado+=pow(16,i)*Hexa.find(Valor[1-i]);
	}         
}
// Leitura do arquivo com o cenario svg
bool loadArenaScenario()
{
	TiXmlDocument doc(svgFileName.c_str());
	bool loaded = doc.LoadFile();
	if (loaded)
	{
        TiXmlElement* inputFiles = doc.FirstChildElement("svg")->FirstChildElement("g");
		TiXmlElement* rect = inputFiles->FirstChildElement("rect");
		Rectangle* aux;
		while(rect!=NULL){
			string s = rect->Attribute("style");
			Valor[0] = s.at(6);
			Valor[1] = s.at(7);
			htod();
			int rb = Resultado;
			Valor[0] = s.at(8);
			Valor[1] = s.at(9);
			htod();
			int gb = Resultado;
			Valor[0] = s.at(10);
			Valor[1] = s.at(11);
			htod();
			string w = rect->Attribute("width");
			string h = rect->Attribute("height");
			string x = rect->Attribute("x");
			string y = rect->Attribute("y");
			int xlido =(int)atof(x.c_str());
			int ylido =(int)atof(y.c_str());
			int ycerto=152-(ylido-(arenaHeight/2))-atof(h.c_str())/2;
			int xcerto=-8+xlido-(arenaWidth/2)+atof(w.c_str())/2;
			aux = new Rectangle(xcerto, ycerto, atof(h.c_str()), atof(w.c_str()), rb,gb,Resultado);
			retangulos.push_back(aux);
			rect = rect->NextSiblingElement("rect");
		};
		TiXmlElement* circle = inputFiles->FirstChildElement("circle");
		
		Circle* aux2;
		while(circle!=NULL){
			string x = circle->Attribute("cx");
			string y = circle->Attribute("cy");
			string r = circle->Attribute("r");
			string s = circle->Attribute("fill");
			Valor[0] = s.at(1);
			Valor[1] = s.at(2);
			htod();
			int rb = Resultado;
			Valor[0] = s.at(3);
			Valor[1] = s.at(4);
			htod();
			int gb = Resultado;
			Valor[0] = s.at(5);
			Valor[1] = s.at(6);
			htod();
			int xlido =(int)atof(x.c_str());
			int ylido =(int)atof(y.c_str());
			int ycerto=152-(ylido-(arenaHeight/2));
			int xcerto=-8+xlido-(arenaWidth/2);
			aux2 = new Circle(xcerto, ycerto, atoi(r.c_str()),rb,gb,Resultado);
			circulos.push_back(aux2);
			circle = circle->NextSiblingElement("circle");
		};
	}
	else
	{
		cout << "Arquivo '" << svgFileName << "' nao encontrado ou nao eh um xml valido." << endl;
	}
	return loaded;
}

bool loadData()
{
    // Leitura do config file
	if(loadConfig())
	{
        // Leitura da arena.pgm
		if(loadArenaMobilityMatix())
		{
            // Leitura do arquivo do cenario svg
			if(loadArenaScenario())
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else 
		return false;
}

int main(int argc, char** argv)
{
    // Faz leitura dos dados e os mostra na tela
	if(loadData())
	{	
		loadArenaMobilityMatixArena();
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(arenaWidth, arenaHeight);
		glutCreateWindow("Trab04");
		init();
		funcaoinicialist();
	    glutDisplayFunc(display);
		glutKeyboardFunc(keyboard);
		glutKeyboardUpFunc(keyboardUp);
		glutMouseFunc(mouse);
		glutPassiveMotionFunc(mouseMove);
		glutIdleFunc(idle);
		glutMainLoop();
	}
    
	return 0;
}