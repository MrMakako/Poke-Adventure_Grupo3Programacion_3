#pragma once
#include <string>;
#include "Body.h"
#include <allegro5/allegro_primitives.h>
#include "vector"
#ifndef MESSAGEBOX_H

#define MESSAGEBOX_H


class MessageBoxZ :public Body
{
private:


	std::string Message;



	ALLEGRO_FONT* font;


public:

	MessageBoxZ(ALLEGRO_BITMAP*, std::string, int, int);
	MessageBoxZ();
	void movimiento();




	void DisplayMessage(int,int);
	void DisplayMessage(const char*,int, int);



























};
#endif // !MESSAGEBOX_H





