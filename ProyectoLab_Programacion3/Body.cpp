#include "Body.h"
#include <iostream>;
//updates
Body::Body()
{

	x = 0;
	y = 0;
	speed = 0;
	Sprite = NULL;

}

Body::Body(ALLEGRO_BITMAP* _Sprite, Player *_ColisionObj, int _width, int _height, int _x, int _y, int _speed, int _rx, int _ry) {

	reg = true;
	Sprite = _Sprite;
	ColisionObj = _ColisionObj;
	width = _width;
	height = _height;
	x = _x;
	y = _y;
	speed = _speed;
	Rx = _rx;
	Ry = _ry;

}

Body::Body(ALLEGRO_BITMAP*_Sprite, Player *_ColisionObj, int _width, int _height, int _x, int _y, int _speed)
{

	Sprite = _Sprite;
	ColisionObj = _ColisionObj;
	width = _width;
	height = _height;
	x = _x;
	y = _y;
	speed = _speed;


}



Body::Body(ALLEGRO_BITMAP*sprite, Player *_ColisionObj, int _x, int _y)

{


	speed = 1;
	width = al_get_bitmap_width(sprite);
	height = al_get_bitmap_height(Sprite);
	x = _x;
	y = _y;
	ColisionObj = _ColisionObj;






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

int Body::getHeight()
{
	return height;
}

int Body::getWidth()
{
	return width;
}
void Body::setHeight(int _height)
{
	height = _height;
}

void Body::setWidth(int _width)
{

	width = _width;

}

int Body::getX()
{
	return x;
}

int Body::getY()
{
	return y;
}


void Body::Colision()
{
	if (ColisionObj->getDirY() == 3) {
		//Up
		ColisionObj->setY(ColisionObj->getY() + ColisionObj->getSpeed());
		std::cout << ColisionObj->getDirY() << "\n";




	}
	else if (ColisionObj->getDirY()==0) {
		//Down
		ColisionObj->setY(ColisionObj->getY() - ColisionObj->getSpeed());
		std::cout << ColisionObj->getDirY() << "\n";


	}
	else if (ColisionObj->getDirY()==1) {
		//Left
		ColisionObj->setX(ColisionObj->getX() + ColisionObj->getSpeed());

		std::cout << ColisionObj->getDirY() << "\n";



		


	
	
	}
	else if(ColisionObj->getDirY()==2) {
		//right
		ColisionObj->setX(ColisionObj->getX() - ColisionObj->getSpeed());
		
		std::cout << ColisionObj->getDirY()<<"\n";

		
	}

	
}

void Body::Draw(int Rx,int Ry)
{

		
			al_draw_bitmap_region(Sprite, width * Rx, height * Ry, width, height, x, y, NULL);
			
			std::cout << "draw";


	



}

