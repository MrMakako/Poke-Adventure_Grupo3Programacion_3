#pragma once
#include<allegro5/allegro5.h>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "Player.h"

#ifndef BODY_H
#define BODY_H
class Body
{
protected:
	int x;
	int y;
	int Rx;
	int Ry;
	int width;
	int height;
	int speed;
	bool reg;





	ALLEGRO_BITMAP* Sprite;

	ALLEGRO_BITMAP* getSprite();

	Player *ColisionObj;



public:

	Body();

	Body(ALLEGRO_BITMAP*, Player*, int, int, int, int, int, int, int);
	Body(ALLEGRO_BITMAP*, Player*, int, int, int, int, int);

	Body(ALLEGRO_BITMAP*, Player*, int, int);




	void ClearBackGround(ALLEGRO_COLOR  color);

	void setX(int n);

	void setSpeed(int _speed);

	void setY(int n);

	void  Colision();

	void Draw();
	void Collide(float x, float y, float ex, float ey, int width, int  height);






};

#endif // !BODY_H


