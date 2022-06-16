#include "Boton.h"

Boton::Boton()
{
}

Boton::Boton(int _x, int _y, int _width, int _height, ALLEGRO_FONT* _Font, ALLEGRO_COLOR col, const char* Name)
{

	x = _x;
	y = _y;
	width = _width;
	height = _height;
	Font = _Font;
	color = col;
	Sprite = NULL;
	Name_btn = Name;
	//ready




}

Boton::Boton(int _x, int _y, int _width, int _height, ALLEGRO_FONT* _font, ALLEGRO_COLOR _color, ALLEGRO_BITMAP* IMG, const char* NombreBtn)
{


	Boton::Boton(_x,_y,_width,_height,_font,_color,NombreBtn);
}

void Boton::setFont(ALLEGRO_FONT* f)
{

	Font = f;
}

void Boton::resetPress()
{


	pressed = false;


}

void Boton::Draw()
{
	//	if (color.r-opaque  >= 0 && color.r+opaque<= 250) {
	color = al_map_rgb(255, 140 + opaque, 255);


	//


	al_draw_rectangle(x, y, width, height, color, 10);
	if (Sprite == nullptr) {
		al_draw_text(Font, color, x + 10, y + 10, 0, Name_btn.c_str());
	
	}
	else {
		al_draw_text(Font, color, x + 10, y + 10, 0, Name_btn.c_str());
		al_draw_tinted_scaled_bitmap(Sprite, color, 0, 0, width, height, x, y, width * Rx, height * Ry, 0);
	
	}



	opaque = 0;
}

void Boton::Pressed()
{

	pressed = true;
}

void Boton::ColorChange(ALLEGRO_COLOR* Color)
{

	color = *Color;

}

void Boton::Opaque()
{

	opaque = 100;

}

bool Boton::isPressed()
{
	return pressed;
}

void Boton::movimiento()
{




}

Boton::~Boton()
{

	al_destroy_bitmap(Sprite);



}
