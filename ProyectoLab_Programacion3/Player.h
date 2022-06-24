#pragma once
#include <string>

#include<allegro5/allegro5.h>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include <vector>
#ifndef PLAYER_H;


#endif // !PLAYER_H;

class Player
{
private:


	int vidas;

	int x, y;
	ALLEGRO_BITMAP* Sprite;

	int width ;
	int height;
	int dirX, dirY;
	int speed;
	bool Talkin;
	bool InRange=false;
	int TalkinPressed=0;
	int dialogNum=-1;
	int medallas = 0;
	int vida = 0;
	ALLEGRO_BITMAP* MessageBox;


public:

	enum { DER, IZQ, ARR, ABJ };


	int getWidth();

	int getHeight();
	int getDialogNum();
	int getVida();
	void setInrange(bool Range);
	int getX();
	int getY();
	int getDirY();
	int getSpeed();
	void setX(int);

	int getTalkingPressed();
	void setTalking(bool);
	void DrawMessageBox(int, int, const char*,ALLEGRO_FONT*);

	void DrawMessageBox(int _x, int _y, std::vector<std::string>, ALLEGRO_FONT* font);

	void setY(int);
	void resetButtons();
	void resetDialogNum();
	void setVida(int );

	int getVidas();
	Player();

	Player(ALLEGRO_BITMAP* _Sprite);
	//bool EnterPressed();
	//bool EscapePressed();

	void setWidht(int n);
	void setHeight(int n);


	void Mover(ALLEGRO_KEYBOARD_STATE keySate,int* );

	void Dibujar();
	int getMedal();
	void setMedal(int _medal);


	void correr();
	bool Talk();
	bool isTalking();
	~Player();
	

	








};

