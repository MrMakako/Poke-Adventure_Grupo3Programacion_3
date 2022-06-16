#pragma once

#include "Paths.h"

class PokemonBtn:public Paths
{



private:
	bool btn_pressed=false;


public:


	using Paths::Paths;

	

	







	void DrawInTable(int _x, int _y, bool op);

};

