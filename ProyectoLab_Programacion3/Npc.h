#pragma once
#include "Body.h"
#include "MessageBox.h"
#include <vector>
#ifndef NPC_H
#define NPC_H

class Npc :public Body
{
private:


	std::vector<MessageBoxZ> Messages;

	



public:




	



	Npc(ALLEGRO_BITMAP* _sprite, int _x, int _y,int _height,int _width);

	void movimiento();


	

};


#endif // !NPC_H


