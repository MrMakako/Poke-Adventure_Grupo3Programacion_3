#pragma once


#include "StaticBody.h"

#include <fstream>

#include <string>

#include <vector>
#include <iostream>


class Dialog :public StaticBody
{

	std::string dir;
	

	int curDialog;

	std::vector<std::vector<std::string>>MessageList;


public:

	Dialog(const char *,int size);

	std::vector<std::vector<std::string>> getMessages();






	void load();


	Dialog();










};

