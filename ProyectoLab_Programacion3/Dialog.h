#pragma once


#include "StaticBody.h"

#include <fstream>

#include <string>

#include <vector>
#include <iostream>


class Dialog :public StaticBody
{

	std::string dir;
	std::vector <std::string> Messages;

public:

	Dialog(const char *,int _x,int _y,int size);

	std::vector<std::string> getMessages();
	void load();


	Dialog();










};

