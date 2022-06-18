#pragma once
#include "Map.h"
#include"PokemonBtn.h"
#include "string"
#include<vector>

class MesaDesc:public Map
{



private:
	
	
	int *MouseX;
	int *MouseY;
	bool *MouseClicked;

	std::vector<std::string>Preguntas;




	std::vector<PokemonBtn> Bottons;



public:
	using Map::Map;
	
	void AddInput(int*, int*, bool*);

	void CargarPreguntas();

	

	void AddButton(ALLEGRO_BITMAP*_Sprite,int h,int w);
	void LoadButtons();
	
		void DrawTable();



		bool collision(float x, float y, float ex, float ey, int width, int  height);






};

