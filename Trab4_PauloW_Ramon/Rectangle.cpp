#include "Rectangle.h" 
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


// Criar um retangulo dado x, y, height e width
Rectangle::Rectangle(int x, int y, float pHeight, float pWidth,int R,int G,int B)
{
	
	this->x = x;
	this->y = y;
	this->Height = pHeight;
	this->Width = pWidth;
	this->R = R;
	this->G = G;
	this->B = B;
}
void Rectangle::Set(int x, int y, float pHeight, float pWidth,int R,int G,int B)
{
	this->x = x;
	this->y = y;
	this->Height = pHeight;
	this->Width = pWidth;
	this->R = R;
	this->G = G;
	this->B = B;
}

// Destrutor
Rectangle::~Rectangle()
{
}

// Desenhar um retangulo - a ser implementado
void Rectangle::Draw()
{
	glLineWidth(2.0);
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
	glVertex2i(x-(Width/2),y-(Height/2));
	glVertex2i(x+(Width/2),y-(Height/2));
	glEnd();
	glLineWidth(2.0);
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
	glVertex2i(x+(Width/2),y-(Height/2));
	glVertex2i(x+(Width/2),y+(Height/2));
	glEnd();
	glLineWidth(2.0);
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
	glVertex2i(x+(Width/2),y+(Height/2));
	glVertex2i(x-(Width/2),y+(Height/2));
	glEnd();
	glLineWidth(2.0);
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
	glVertex2i(x-(Width/2),y+(Height/2));
	glVertex2i(x-(Width/2),y-(Height/2));
	glEnd();
	glColor3ub(R,G,B);
	glBegin(GL_POLYGON);
    glBegin(GL_LINE_STRIP);
	glVertex3f(x-(Width/2),y-(Height/2), 0);
	glVertex3f(x+(Width/2),y-(Height/2), 0);
	glVertex3f(x+(Width/2),y+(Height/2), 0);
	glVertex3f(x-(Width/2),y+(Height/2), 0);
	glEnd();
}
