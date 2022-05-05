#pragma once
#include<allegro5/allegro5.h>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "Player.h"


class Body
{
protected:
	int x;
	int y;
	int width;
	int height;
	int speed;
    




	ALLEGRO_BITMAP* Sprite;

	ALLEGRO_BITMAP* getSprite();

	Player ColsionObj;



public:

	Body();


	Body(ALLEGRO_BITMAP*, Player, int, int,int,int,int);
	Body(ALLEGRO_BITMAP*, Player, int, int,int,int);
	Body(ALLEGRO_BITMAP*, Player,int, int);



	virtual void movimeinto()=0;



	void ClearBackGround(ALLEGRO_COLOR  color);

	void setX(int n);

	void setSpeed(int _speed);

	void setY(int n);

	void  Colision();






	
};

