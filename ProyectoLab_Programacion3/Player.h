#pragma once


#include<allegro5/allegro5.h>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#ifndef PLAYER_H;


#endif // !PLAYER_H;

class Player
{
private:

	int x, y;
	ALLEGRO_BITMAP* Sprite;

	int width ;
	int height;
	int dirX, dirY;



public:

	enum { DER, IZQ, ARR, ABJ };

	Player();

	Player(ALLEGRO_BITMAP* _Sprite);

	void setWidht(int n);
	void setHeight(int n);


	void Mover(ALLEGRO_KEYBOARD_STATE keySate);

	void Dibujar();


	void correr();

	~Player();


	








};

