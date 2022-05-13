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

void Npc::movimiento() {






}


