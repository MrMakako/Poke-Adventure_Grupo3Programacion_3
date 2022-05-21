#include "Dialog.h"

Dialog::Dialog(const char*_dir, int _x, int _y, int size): StaticBody(_x,_y)
{
	dir = _dir;

	size = 23;


	load();

	
}

std::vector<std::string> Dialog::getMessages()
{


	return Messages;
}

void Dialog::load()
{

	

	std::fstream File;
	File.open(dir, std::ios::in);//read
	std::string line;
	while (File.is_open()) {
	
		if (std::getline(File, line)) {
			
			Messages.push_back(line);
		
		}
	
	
	}
}

Dialog::Dialog()
{



}
