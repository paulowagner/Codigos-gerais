#pragma once
#include "Object.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Canon.h"


class Tanque:
	public Object
{
	public:
		Rectangle central;
		Rectangle rodadireita;
		Rectangle rodaesquerda;
		Circle ccentral;
		Canon c;
		bool draw;
		Tanque(int x,int y,int R,int G,int B);
		~Tanque();
		void Draw();
};