#pragma once

#include "Paths.h"

class PokemonBtn:public Paths
{



private:
	bool btn_pressed=false;
	const char* Frase=NULL;
	ALLEGRO_FONT* font;
public:
	void setFrase(const char* _frase);

	using Paths::Paths;
	PokemonBtn();

	

	







	void DrawInTable(int _x, int _y, bool op);

};

