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
	int speed;
	bool Talkin;
	int TalkinPressed=0;


public:

	enum { DER, IZQ, ARR, ABJ };


	int getWidth();

	int getHeight();

	int getX();
	int getY();
	int getDirY();
	int getSpeed();
	void setX(int);

	int getTalkingPressed();
	void setTalking(bool);

	void setY(int);
	void resetButtons();
	Player();

	Player(ALLEGRO_BITMAP* _Sprite);

	void setWidht(int n);
	void setHeight(int n);


	void Mover(ALLEGRO_KEYBOARD_STATE keySate,int* );

	void Dibujar();


	void correr();
	bool Talk();
	bool isTalking();
	~Player();
	

	








};

