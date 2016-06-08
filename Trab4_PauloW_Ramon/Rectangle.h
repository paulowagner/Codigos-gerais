#pragma once
#include "Object.h"
#include <string>
// Classe Retangulo, herdado de Objeto
class Rectangle :
	public Object
{
	public:
	    int x,y;
	    int R,G,B;
	    std::string style;
		float Height, Width;
		Rectangle();
		Rectangle(int x, int y, float pHeight, float pWidth,int R,int G,int B);
		void Set(int x, int y, float pHeight, float pWidth,int R,int G,int B);
		~Rectangle();
		void Draw(); // a ser implementado
};

