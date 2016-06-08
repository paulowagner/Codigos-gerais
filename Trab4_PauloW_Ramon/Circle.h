#pragma once
#include "Object.h" 
#include <string>
// Classe Circulo, herdado de Objeto
class Circle :
	public Object
{
public:
	int x, y, Radius;
	int R,G,B;
	Circle();
	Circle(int x, int y, int pRadius,int R,int G,int B);
	Circle(int x, int y, int pRadius);
	void Set(int x, int y, int pRadius,int R,int G,int B);
	~Circle();
	void Draw(); // a ser implementado
};

