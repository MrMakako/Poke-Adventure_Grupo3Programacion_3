#include "MessageBox.h"



MessageBoxZ::MessageBoxZ(ALLEGRO_BITMAP*_sprite, std::string _message,int _x,int _y)
{


	Sprite = _sprite;
	Message = _message;
	x = _x;
	y = _y;
	width = 100;
	height = 400;
	font = al_load_ttf_font("fuente/pokemon_pixel_font.ttf", 37, NULL);







}

MessageBoxZ::MessageBoxZ()
{
}
void MessageBoxZ::movimiento() {



}

void MessageBoxZ::DisplayMessage(int _x,int _y)
{
	//draw message Box


	//se puede generarun glitcth dad que si estas muy abajo la extbox no se mostraria
	
	al_draw_filled_rectangle(_x, _y, _x+500, _y+200, al_map_rgb(0, 0, 0));

	al_draw_text(font, al_map_rgb(255, 255, 255), _x,_y, NULL, Message.c_str());
	


}

void MessageBoxZ::DisplayMessage(const char*ms, int _x, int _y)
{
	Message = ms;
	DisplayMessage(_x, _y);


}
