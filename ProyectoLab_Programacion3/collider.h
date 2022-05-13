#pragma once
#include"Player.h"

class collider
{
private:

	Player* ColisionObj;

	int x;
	int y;
	int ex;
	int ey;
	

public :

	collider();

	collider(Player *,int,int,int,int);


	void Colision();


};

