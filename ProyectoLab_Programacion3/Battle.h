#pragma once


#include "Map.h"


#include "Pokemon.h";



class Battle :public Map
{


private:

	int LifeBar;
	int LifeBar2;

	
	ALLEGRO_BITMAP* Pokemon1;
	ALLEGRO_BITMAP* Trainer1;

	ALLEGRO_BITMAP* Pokemon2;
	ALLEGRO_BITMAP* Trainer2;

	

	ALLEGRO_BITMAP* Background;
	ALLEGRO_BITMAP* P1LiveBar;
	ALLEGRO_BITMAP* P2LiveBar;


public:
	Battle();

	Battle(ALLEGRO_BITMAP*P1, ALLEGRO_BITMAP* T1, ALLEGRO_BITMAP* P2, ALLEGRO_BITMAP* T2);




	void StartBattle(int liveP1, int LiveP2);



	void DrawBattle();

	





	




};

