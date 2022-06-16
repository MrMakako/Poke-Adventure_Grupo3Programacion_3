#include "Paths.h"

Paths::Paths():Npc(NULL,0,0,0,0,nullptr)
{




}
void 

Paths::Draw(int Rx, int Ry) {







	if (ColisionObj != NULL) {
		if (Sprite != NULL) {

			collision(ColisionObj->getX(), ColisionObj->getY(), x, y, width, height);
			al_draw_bitmap_region(Sprite, width * Rx, height * Ry, width, height, x+32, y+32, 0);

		



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
	

	//Tener cuidado con player











	
}

void Paths::setFound(bool _IdFound)
{

	IsFound = _IdFound;
}
