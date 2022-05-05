#include "Body.h"

Body::Body()
{

	x = 0;
	y = 0;
	speed = 0;
	Sprite = NULL;

}

Body::Body(ALLEGRO_BITMAP*_Sprite, Player _ColisionObj, int _width, int _height, int _x, int _y, int _speed)
{

	Sprite = _Sprite;
	ColsionObj = _ColisionObj;
	width = _width;
	height = _height;
	x = _x;
	y = _y;
	speed = _speed;


}



Body::Body(ALLEGRO_BITMAP*sprite, Player _ColisionObj, int _x, int _y)

{


	speed = 1;
	width = al_get_bitmap_width(sprite);
	height = al_get_bitmap_height(Sprite);
	x = _x;
	y = _y;
	ColsionObj = _ColisionObj;






}






void Body::ClearBackGround(ALLEGRO_COLOR color)
{
	al_convert_mask_to_alpha(Sprite,color);
}

void Body::setX(int n)
{

	x = n;
}

void Body::setY(int n)
{

	y = n;
}

void Body::Colision()
{
	if (ColsionObj.getDirY() == 3) {




	};
}
