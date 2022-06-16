#pragma once
#include "Body.h"
#include <allegro5/allegro_primitives.h>
class Boton:public Body
{





private:




	ALLEGRO_FONT* Font;
	ALLEGRO_COLOR color;
	bool pressed = false;
	int opaque = 0;
	std::string Name_btn;
	ALLEGRO_BITMAP* Img;




public:

	Boton();


	Boton(int, int, int, int, ALLEGRO_FONT*, ALLEGRO_COLOR, const char*);
	Boton(int _x, int _y, int _width, int _height, ALLEGRO_FONT*, ALLEGRO_COLOR, ALLEGRO_BITMAP* IMG, const char* NombreBtn);
	void setFont(ALLEGRO_FONT* f);
	void resetPress();
	void Draw();
	void Pressed();
	void ColorChange(ALLEGRO_COLOR* Color);
	void Opaque();
	bool isPressed();

	virtual void movimiento();



	~Boton();










};

