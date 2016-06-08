#pragma once
#include <vector>

#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif

// Classe Objeto devera ser implementada - Util p/ criar partes do canhao como geometrias mais simples

class Object
{
public:
	Object();
	~Object();
	virtual void Draw(); 
};

