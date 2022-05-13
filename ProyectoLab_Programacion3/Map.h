#pragma once
#include "Player.h"
#include <vector>
#include "Body.h"
#include "Npc.h"
#include "collider.h"

#ifndef MAP_H
#define MAP_H

class Map :public Body
{

	std::vector<collider>Colisions;

	std::vector<Npc> Npcs;


	Player* MainPlayer;
	bool load;
private:









public:


	Map(ALLEGRO_BITMAP*,int,int,int,int,int,Player *);



	void AddColision(int ,int ,int,int);

	void DrawMap();



	





	



};



#endif // !MAP_H

