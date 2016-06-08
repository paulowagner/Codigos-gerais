#include "Circle.h"
#define PI 3.1415926535898
#define MAX 1000
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
// Criar um circulo dado o centro e raio
Circle::Circle(int x, int y, int pRadius,int R,int G,int B)
{
	this->x = x;
	
	this->y = y;
	this->Radius = pRadius;
	this->R = R;
	this->G = G;
	this->B = B;
}
Circle::Circle(){

}
void Circle::Set(int x, int y, int pRadius,int R,int G,int B){
	this->x = x;
	this->y = y;
	this->Radius = pRadius;
	this->R = R;
	this->G = G;
	this->B = B;
}


// Destrutor
Circle::~Circle()
{
}

// Desenhar um circulo - a ser implementado
void Circle::Draw()
{
	float angle;
	
	for (int i = 0; i < MAX-1; i++) {
		glLineWidth(1.0);
		glColor3ub(0,0,0);
		glBegin(GL_LINES);
		angle = 2*PI*i/MAX;
		glVertex2i(x+(cos(angle)*(Radius)),y+ (sin(angle)*Radius));
		angle = 2*PI*(i+1)/MAX;
		glVertex2i(x+(cos(angle)*(Radius)),y+ (sin(angle)*Radius));
		glEnd();
	}
	glLineWidth(1.0);
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
	angle = 2*PI*0/MAX;
	glVertex2i(x+(cos(angle)*(Radius)),y+ (sin(angle)*Radius));
	angle = 2*PI*(MAX-1)/MAX;
	glVertex2i(x+(cos(angle)*(Radius)),y+ (sin(angle)*Radius));
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(R, G, B);
	for (int i = 0; i < MAX; i++) {
		angle = 2*PI*i/MAX;
		glVertex2f(x+(cos(angle)*(Radius)),y+ (sin(angle)*Radius));
	}
	glEnd(); 
}
