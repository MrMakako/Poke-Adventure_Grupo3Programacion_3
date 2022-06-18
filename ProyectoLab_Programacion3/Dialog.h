#pragma once


#include "StaticBody.h"

#include <fstream>

#include <string>

#include <vector>
#include <iostream>

#include <allegro5/allegro_font.h>

class Dialog :public StaticBody
{

	std::string dir;
	

	int curDialog;

	std::vector<std::vector<std::string>>MessageList;

	ALLEGRO_FONT* font;
		


public:


	ALLEGRO_FONT* getFont();
	Dialog();
	
	Dialog(const char *,int size);

	std::vector<std::vector<std::string>>& getMessages();
	std::vector<std::string> getMessage(int);
	void setFont(const char*, int size);


	int getSize();

	void load();
	void addDiaog(std::vector<std::string>vec);



	~Dialog();








};

