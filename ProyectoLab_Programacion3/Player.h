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

	int x, y;
	ALLEGRO_BITMAP* Sprite;

	int width ;
	int height;
	int dirX, dirY;
	int speed;
	bool Talkin;
	int TalkinPressed=0;
	int dialogNum=0;

	ALLEGRO_BITMAP* MessageBox;


public:

	enum { DER, IZQ, ARR, ABJ };


	int getWidth();

	int getHeight();

	int getX();
	int getY();
	int getDirY();
	int getSpeed();
	void setX(int);

	int getTalkingPressed();
	void setTalking(bool);
	void DrawMessageBox(int, int, const char*,ALLEGRO_FONT*);

	void DrawMessageBox(int _x, int _y, std::vector<std::string> vector, ALLEGRO_FONT* font);

	void setY(int);
	void resetButtons();
	Player();

	Player(ALLEGRO_BITMAP* _Sprite);

	void setWidht(int n);
	void setHeight(int n);


	void Mover(ALLEGRO_KEYBOARD_STATE keySate,int* );

	void Dibujar();


	void correr();
	bool Talk();
	bool isTalking();
	~Player();
	

	








};

