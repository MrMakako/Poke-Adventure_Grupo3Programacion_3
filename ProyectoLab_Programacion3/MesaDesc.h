#pragma once
#include "Map.h"
#include"PokemonBtn.h"
#include "string"
#include<vector>
#include "Dialog.h"


class MesaDesc:public Map
{



private:
	
	
	int *MouseX;
	int *MouseY;
	bool *MouseClicked;

	std::vector<std::string>Preguntas;
	ALLEGRO_FONT* Font;

	int preguntaActual = 0;

	PokemonBtn Left;
	PokemonBtn Right;
	std::vector<PokemonBtn> Bottons;
	Dialog DescPreguntas;
	Dialog Respuestas;

	



public:
	using Map::Map;
	
	void AddInput(int*, int*, bool*);

	void CargarPreguntas();

	void DrawPreguntas();
	void CambiarPregunas();

	void AddButton(ALLEGRO_BITMAP*_Sprite,int h,int w);
	void LoadButtons();
	
		void DrawTable();



		bool collision(float x, float y, float ex, float ey, int width, int  height);






};

