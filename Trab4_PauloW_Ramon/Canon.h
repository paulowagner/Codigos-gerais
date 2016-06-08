#pragma once
#include "Object.h"
#include "Rectangle.h"
#include "Circle.h"
#include <math.h>
#include <vector>
#include "Bala.h"
#include <iostream>
using namespace std;
// Classe Canon devera ser implementada - Funcoes abaixo sao apenas sugestoes
class Canon :
	public Object
{
public:
	int rodaesq,rodadir,ciclo;
	float angleac,angle;
	Rectangle canon;
	GLfloat	 MatrizCanhao[4][4];
	vector<Bala *> balas;
	Canon();
	~Canon();
	void Draw();
	void NewBala();
	void moveUp(GLfloat rate);
	bool colisao(int x,int y);
	void moveDown(GLfloat rate);
	void turnRight(GLfloat rate,bool up,bool down);
	void turnLeft(GLfloat rate,bool up,bool down);
	void Set(int x,int y);
	void moveCanon(int x, int y);
	void Fire(int tempo,GLuint list_bala,unsigned char matrix[][727]);
};

