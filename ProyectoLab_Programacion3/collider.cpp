#include "collider.h"



collider::collider()
{
}

collider::collider(Player*p, int _x, int _y, int _width, int _height)
{
	ColisionObj = p;


	x = _x;
	y = _y;
	width = width;
	height = _height;


}



bool collider::collide()
{




	if ((ColisionObj->getX() >= x && ColisionObj->getX() <= width) && (ColisionObj->getY() >= y && ColisionObj->getY() <= height)) {
	
		return true;
	
	}

	return false;


}

