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
	int count;
	ALLEGRO_FONT* Font;

	bool Found[3]{ false,false,false};




	


	int SlectedPokemon=-1;
	int SelectedFoorPrint=-1;

	std::vector<Paths>FootPrints;
	




	int* MouseX;
	int* MouseY;
	bool* MouseClicked;
	
	int SelectedIndex;


	std::vector<PokemonBtn> TablaBotones;


	
public:
	void DrawTable();

	void DrawLobby();
	void DrawSelcetedOnes();
	void AddMouseInput(int*, int*, bool*);
	bool checkMatch();

	void Load_all_pokemon();
	void Encontrar(ALLEGRO_KEYBOARD_STATE State);
	void DrawValle();
	int getProgress();
	void DrawPokeTable();
	using Map::Map;
	bool collision(float x, float y, float ex, float ey, int width, int height);
	

	void addPath(PokemonNames Name, int x, int y);























};

