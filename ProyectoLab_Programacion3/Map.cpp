#include "Map.h"

Map::Map(ALLEGRO_BITMAP*MapSprite, int _x, int _y, int _width, int _height , int, Player*_Player)
{

	MainPlayer = _Player;
	Sprite = MapSprite;
	x = _x;
	y = _y;
	width = _width;
	height = _height;

	load = false;



}

void Map::AddColision(int _x, int _y, int _width, int _height)
{


	Colisions.push_back(collider(MainPlayer, _x, _y, _width, _height));


}





void Map::DrawMap() {


	if (load) {
	
		al_draw_tinted_scaled_bitmap(Sprite, al_map_rgb(255, 255, 255), x, y, width, height, x, y, width * 2, height * 2, NULL);
	
		
	
	
	}









}