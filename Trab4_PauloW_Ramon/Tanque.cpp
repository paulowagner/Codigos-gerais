#include "Tanque.h" 


Tanque::Tanque(int x,int y,int R,int G,int B){
	this->central.Set(x,y,20,16,R,G,B);
	this->rodadireita.Set(x+12,y,24,8,R,G,B);
	this->rodaesquerda.Set(x-12,y,24,8,R,G,B);
	this->ccentral.Set(x,y,5,35,142,104);
	this->c.Set(x,y);
	this->draw = true;
}
Tanque::~Tanque(){

}

void Tanque::Draw(){
	this->central.Draw();
	this->rodaesquerda.Draw();
	this->rodadireita.Draw();
	this->ccentral.Draw();
}
