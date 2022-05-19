#include "Npc.h"



Npc::Npc(ALLEGRO_BITMAP* _sprite, int _x, int _y, int _width, int _height,Player* _p)
{
	width = _width;
	height = _height;
	x = _x;
	y = _y;
	Sprite = _sprite;
	ColisionObj = _p;
	collider col(_p,_x,_y,_width,_height);

	Sign = al_load_bitmap("imagenes/Interrogation.png");

	//Clase con herencia 
	 ///////////////
	//Complicado //
   ///////////////

	//






	



}


bool Npc::inRange() {


	if (ColisionObj->getX() + width+20<x  || ColisionObj->getX()>x + width + 20 || ColisionObj->getY() > y + height + 20 || ColisionObj->getY() +height + 20 <y) {


		return false;


	}
	return true;



}
void Npc::Draw(int Rx,int Ry) {

	Body::Draw(Rx, Ry);
	if (ColisionObj != NULL) {

		if (inRange()) {
			al_draw_bitmap(Sign, x, y - 20, 0);



		}
	
	
	}
	
	





	






}
void Npc::movimiento() {
	





}


