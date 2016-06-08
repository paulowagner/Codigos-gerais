#include "Canon.h" 

using namespace std;

// Classe Canon devera ser implementada - Funcoes abaixo sao apenas sugestoes

Canon::Canon()
{
	this->canon.Set(0,10,20,4,35,142,104);
	this->rodaesq=0;
	this->rodadir=0;
	this->angle=0;
	this->angleac=0;
}

Canon::~Canon()
{
	
}

void Canon::NewBala(){
	Bala* aux=new Bala(this->MatrizCanhao);
 	this->balas.push_back(aux);
}
void Canon::Set(int x,int y){
	this->canon.Set(x,y+10,20,4,35,142,104);
	
}
bool Canon::colisao(int x,int y)
{
	for (int i = 0; i < balas.size(); i++)
	{
		int xb = balas.at(i)->MatrizBala[3][0]*(727/2);
		int yb = balas.at(i)->MatrizBala[3][1]*(774/2);
		yb=-yb+(774/2);
		xb=xb+(727/2);
		if(sqrt((x-xb)*(x-xb)+(y-yb)*(y-yb))<22){
			balas.erase(balas.begin()+i);
			return true;
		}
	}
	return false;
}
void Canon::Fire(int tempo,GLuint list_bala,unsigned char matrix[][727])
{
	//cout<<"Size -> "<<balas.size()<<endl;
	for (int i = 0; i < balas.size(); i++)
	{ 
		for(int j=0;j<tempo;j++){
			if(balas.at(i)->pode(matrix))
			{
				glPushMatrix(); 
				glLoadIdentity ();
				glMultMatrixf(&balas.at(i)->MatrizBala[0][0]);
				if(j==tempo-1)
					glCallList(list_bala);
				glTranslatef(0,0.2,0);
		    	glGetFloatv(GL_MODELVIEW_MATRIX, &balas.at(i)->MatrizBala[0][0]); 
		 		glPopMatrix();	
			}
			else{
				
				balas.erase(balas.begin()+i);
				i--;
				break;
			}
		}
	}
}

void Canon::moveCanon(int x, int y)
{ 
}

void Canon::moveUp(GLfloat rate)
{ 
	glTranslatef(0,rate,0);
	this->rodaesq++;
	this->rodadir++;
	if(this->rodadir==7)
		this->rodadir=0;
	if(this->rodaesq==7)
		this->rodaesq=0;
}

void Canon::moveDown(GLfloat rate)
{ 
	glTranslatef(0,rate,0);
	this->rodaesq--;
	this->rodadir--;
	if(rodadir==-1)
		rodadir=6;
	if(rodaesq==-1)
		rodaesq=6;
}

void Canon::turnRight(GLfloat rate,bool up,bool down)
{ 
	if(up)
	{
		if(ciclo)
			this->rodadir--;
		if(this->rodadir==-1)
			this->rodadir=6;
		glRotatef(-rate,0, 0, 1);
		this->angleac+=rate;
	}else if(down){
		if(ciclo)
			this->rodadir++;
		if(rodadir==7)
			this->rodadir=0;
		glRotatef(rate,0, 0, 1);
		this->angleac-=rate;
	}else{
		this->rodaesq--;
		this->rodadir++;
		if(this->rodadir==7)
			this->rodadir=0;
		if(this->rodaesq==-1)
			this->rodaesq=6;
		glRotatef(-rate,0, 0, 1);
		this->angleac+=rate;
	}
}

void Canon::turnLeft(GLfloat rate,bool up,bool down)
{ 
	if(up)
	{
		if(ciclo)
			this->rodaesq--;
		if(this->rodaesq==-1)
			this->rodaesq=6;
		glRotatef(rate,0, 0, 1);
		this->angleac-=rate;
	}else if(down){
		if(ciclo)
			this->rodaesq++;
		if(this->rodaesq==7)
			this->rodaesq=0;
		glRotatef(-rate,0, 0, 1);
		this->angleac+=rate;
	}else{
		this->rodaesq++;
		this->rodadir--;
		if(this->rodadir==-1)
			this->rodadir=6;
		if(this->rodaesq==7)
			this->rodaesq=0;
		glRotatef(rate,0, 0, 1);
		this->angleac-=rate;
	}
}

void Canon::Draw()
{ 
	this->canon.Draw();
}
 
