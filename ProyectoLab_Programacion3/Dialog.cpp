#include "Dialog.h"

ALLEGRO_FONT* Dialog::getFont()
{
	return font;
}

Dialog::Dialog(const char*_dir, int size): StaticBody(0,0)
{
	dir = _dir;

	size = 23;


	load();
	curDialog = -1;
   font = al_load_font("fuente/pokemon_pixel_font.ttf",24,0);

	





	
}

std::vector<std::vector<std::string>> Dialog::getMessages()
{


	return MessageList;


	
}

void Dialog::load()
{

	

	std::fstream File;
	File.open(dir, std::ios::in);//read
	std::string line;
	std::vector <std::string> Messages;
	while (File.is_open()) {
	
		if (std::getline(File, line)) {
			

		

			
			
				Messages.push_back(line);
				std::cout << line<<std::endl;
				
			
			
			if(line.c_str() == "END") {

				//Extrano gliythc con push bakc solo se pushe dos veces funciona
				MessageList.push_back(Messages);
				Messages.clear();
			}


			
		
		}
		else {
		
			File.close();
		}
	
	
	}

	std::cout << MessageList.size();
}

Dialog::Dialog()
{



}

Dialog::~Dialog()
{

	//al_destroy_font(font);
}
