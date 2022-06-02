#include "Battle.h"

Battle::Battle(ALLEGRO_BITMAP* P1, ALLEGRO_BITMAP* T1, ALLEGRO_BITMAP* P2, ALLEGRO_BITMAP* T2){




	Pokemon1 = P1;
	Pokemon2 = P2;
	Trainer1 = T1;
	Trainer2 = T2;
	Map::Map();
	Background = al_load_bitmap("imagenes/BattleBack.jpg");

	



}

void Battle::StartBattle(int liveP1, int LiveP2)
{







}



void Battle::DrawBattle()
{



	Map::DrawMap(1, 1);








}
