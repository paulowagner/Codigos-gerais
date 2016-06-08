#include "Bala.h" 

using namespace std;
Bala::Bala(GLfloat aux[][4]){
	this->dist=0;
	primeiravez=true;
	glPushMatrix(); 
	glLoadIdentity ();
	glMultMatrixf(&aux[0][0]);
	glGetFloatv(GL_MODELVIEW_MATRIX, &this->MatrizBala[0][0]); 
		glPopMatrix();	
}
Bala::~Bala(){

}
bool Bala::pode(unsigned char matrix[][727])
{
	int y = this->MatrizBala[3][1]*(774/2);
	int x = this->MatrizBala[3][0]*(727/2);
	y=-y+(774/2);
	x=x+(727/2);
	if(matrix[774-y-1][x]<2)
		return false;
	else 
		true;
}