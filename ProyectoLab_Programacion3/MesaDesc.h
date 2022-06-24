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
	std::string Answers[5][4];

	int CorrectAnswers[5]{3,2,1,0,0};
	int GivenAnswers[5]{ -1,-1,-1, -1,-1 };
	int Progress=0;
	bool win=false;
	Dialog Respuestas;

	bool Victory=false;
	


public:
	using Map::Map;
	
	void AddInput(int*, int*, bool*);

	void CargarPreguntas();
	void Avanzar();
	bool checkSelected(int);
	void DrawPreguntas();
	void CambiarPregunas();
	bool CheckAnswers();
	//La funcion Check answers nos dira si las respuestas son correctas;
	
	void AddButton(ALLEGRO_BITMAP*_Sprite,int h,int w);
	void LoadButtons();
	
    void DrawTable();
    bool isCompleted();


		bool collision(float x, float y, float ex, float ey, int width, int  height);






};

