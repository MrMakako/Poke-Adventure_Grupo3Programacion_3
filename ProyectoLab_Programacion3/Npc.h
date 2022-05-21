#pragma once
#include "Body.h"
#include "MessageBox.h"
#include "collider.h"
#include <vector>
#include "Player.h"
#ifndef NPC_H
#define NPC_H

class Npc :public Body
{
private:


	ALLEGRO_BITMAP* Sign;

	collider colision;
	




public:




	



	Npc(ALLEGRO_BITMAP* _sprite, int _x, int _y,int _height,int _width,Player*);

	void movimiento();

	bool inRange();

	void Draw(int Rx,int Ry);
	
	
};


#endif // !NPC_H


