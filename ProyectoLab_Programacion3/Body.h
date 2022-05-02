#pragma once
#include<allegro5/allegro5.h>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>



class Body
{
protected:
	int x;
	int y;




	ALLEGRO_BITMAP* Sprite;




public:

	virtual void movimeinto()=0;

	

	ALLEGRO_BITMAP* getSprite();


	void setX(int n);


	void setY(int n);






	
};

