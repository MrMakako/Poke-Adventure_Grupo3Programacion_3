#pragma once


#include "Npc.h";

#include "MessageBox.h";

#include <vector>

#include "Dialog.h"



class Movie
{



private:
	ALLEGRO_BITMAP* Background;

	ALLEGRO_BITMAP* PokemonSprite;

	Npc *Pokemon;
	ALLEGRO_TIMER* timer;


	Player* Input;

	ALLEGRO_FONT* Font;

	Dialog Npc_Dialogs;
	void load();
	

	






public :



	Movie();



	Movie(ALLEGRO_TIMER*,Player* _Input);






	void StartAnimattion();























};














