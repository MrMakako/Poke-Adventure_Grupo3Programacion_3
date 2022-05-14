#include "Npc.h"



Npc::Npc(ALLEGRO_BITMAP* _sprite, int _x, int _y, int _width, int _height,Player* _p)
{
	width = _width;
	height = _height;
	x = _x;
	y = _y;
	Sprite = _sprite;

	collider col(_p,_x,_y,_width,_height);


	//Clase con herencia 
	//Complicado //





	



}


bool Npc::inRange() {


	if (ColisionObj->getX() + width<x  || ColisionObj->getX()>x + width || ColisionObj->getY() > y + height || ColisionObj->getY() +height <y) {


		return false;


	}
	return true;



}
void Npc::movimiento() {






}


