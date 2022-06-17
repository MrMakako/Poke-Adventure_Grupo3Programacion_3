#pragma once



#include "Map.h"
#include "Paths.h"
#include "PokemonBtn.h"
#include <vector>

class PathFinder :public Map
{

private:
	bool active = false;
	bool SpacePressed = false;


	ALLEGRO_BITMAP* PokemonSprites[10];



	bool Found[6]{ false,false,false,false,false,false};


	std::vector<Paths>FootPrints;
	




	int* MouseX;
	int* MouseY;
	bool* MouseClicked;
	
	int SelectedIndex;


	std::vector<PokemonBtn> TablaBotones;


	
public:
	void DrawTable();

	void DrawLobby();

	void AddMouseInput(int*, int*, bool*);
	void Load_all_pokemon();
	void Encontrar(ALLEGRO_KEYBOARD_STATE State);
	void DrawValle();

	void DrawPokeTable();
	using Map::Map;
	bool collision(float x, float y, float ex, float ey, int width, int height);
	

	void addPath(PokemonNames Name, int x, int y);























};

