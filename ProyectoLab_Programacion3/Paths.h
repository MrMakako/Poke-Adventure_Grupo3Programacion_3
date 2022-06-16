#pragma once

#include"Npc.h"

#include "PokemonNames.h"
class Paths :public Npc

{


protected:
	PokemonNames Name;
	bool IsFound=false;




public:



	Paths();

	void DrawInTable(int _x, int _y, bool op);



	Paths(ALLEGRO_BITMAP* _Sprite, int x, int y, int h, int w,PokemonNames name,  Player * Player);
	void setFound(bool _IdFound);

	bool pressed(int, int ,bool);
	void Draw(int, int);
	bool isFound();
	Paths* getDir();







};

