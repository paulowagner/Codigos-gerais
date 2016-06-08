#pragma once
#include "Object.h"
#include "Rectangle.h"
#include "Circle.h"
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

class Bala {
   public:
   	GLfloat MatrizBala[4][4]; 
   	int dist;
   	bool primeiravez;
   	Bala(GLfloat aux[][4]);
   	~Bala();
	bool pode(unsigned char matrix[][727]);
};