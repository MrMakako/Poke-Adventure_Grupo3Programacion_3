#pragma once



#include "Map.h"
#include "Paths.h"

#include <vector>

class PathFinder:public Map
{


	bool active = false;
	bool SpacePressed=false;







private:
	bool Found[6]{ false,false,false,false,false,false};
	std::vector<Paths>FootPrints;





	
public:
	void DrawTable();

	void DrawLobby();



	void Encontrar(ALLEGRO_KEYBOARD_STATE State);
	void DrawValle();


	using Map::Map;


	void addPath(PokemonNames Name, int x, int y);























};

