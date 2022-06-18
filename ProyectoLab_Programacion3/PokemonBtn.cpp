#include "PokemonBtn.h"

void PokemonBtn::setFrase(const char* _frase)
{

	
	Frase =_frase;
	font = al_load_font("fuente/pokemon_pixel_font.ttf", 30, 0);


}

PokemonBtn::PokemonBtn()
{








}

void PokemonBtn::DrawInTable(int _x, int _y, bool op) {
	int grade = -20;

	if (op) {

		grade = 50;
	}




	if (ColisionObj != NULL) {
		if (Sprite != NULL) {

			//collision(ColisionObj->getX(), ColisionObj->getY(), x, y, width, height);//////
		/////// al_draw_bitmap_region(Sprite, width*0, height *0, width, height, _x, _y, 0);///
		///////////////////////////////////////////////////////////////////////////////////////
			al_draw_tinted_scaled_bitmap(Sprite, al_map_rgba(255,255,255, grade), 0, 0, width, height, _x, _y, width * Rx, height * Rx, 0);
			
			if (Frase != NULL) {
			
					al_draw_text(font,al_map_rgb(255,255,255), _x + 100, _y+90,0,Frase );
			
			}


		}
		else {



		}



	//	if (inRange()) {

	//		al_draw_bitmap(Sign, x, y - 20, 0);



	//	}





	}
}
