#include "Paths.h"

Paths::Paths():Npc(NULL,0,0,0,0,nullptr)
{




}
void Paths::DrawInTable(int _x, int _y,bool op) {
	int grade = 100;

	if (op) {
		
		grade = 50;
	}
	



	if (ColisionObj != NULL) {
		if (Sprite != NULL) {

		//collision(ColisionObj->getX(), ColisionObj->getY(), x, y, width, height);//////
	/////// al_draw_bitmap_region(Sprite, width*0, height *0, width, height, _x, _y, 0);///
	///////////////////////////////////////////////////////////////////////////////////////
			al_draw_tinted_scaled_bitmap(Sprite, al_map_rgba(0,0,0,grade), 0, 0, width, height, _x, _y, width *Rx, height *Rx, 0);
		



		}
		else {
		

		
		}



		if (inRange()) {

			al_draw_bitmap(Sign, x, y - 20, 0);



		}





	}
}

void Paths::Draw(int Rx, int Ry)
{


	if (ColisionObj != NULL) {
		if (Sprite != NULL) {

			collision(ColisionObj->getX(), ColisionObj->getY(), x, y, width, height);
			al_draw_bitmap_region(Sprite, width * Rx, height * Ry, width, height, x + 32, y + 32, 0);





		}



		if (inRange()) {

			al_draw_bitmap(Sign, x, y - 20, 0);



		}





	}
}

bool Paths::isFound()
{
	return IsFound;
}










Paths::Paths(ALLEGRO_BITMAP* _Sprite, int x, int y, int h, int w, PokemonNames name,Player*Player) :Npc(_Sprite,x, y,h,w, Player)
{

	Name = name;
	Rx = 4;
	Ry = 4;

	//Tener cuidado con player











	
}

void Paths::setFound(bool _IdFound)
{

	IsFound = _IdFound;
}
