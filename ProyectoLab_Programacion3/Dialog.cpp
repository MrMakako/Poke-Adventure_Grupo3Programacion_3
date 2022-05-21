#include "Dialog.h"

Dialog::Dialog(const char*_dir, int size): StaticBody(0,0)
{
	dir = _dir;

	size = 23;


	load();
	curDialog = -1;






	
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
			

			if (line != "END") {
			
				Messages.push_back(line);
				std::cout << line;
				
			
			}
			else {
				//Extrano gliythc con push bakc solo se pushe dos veces funciona
				MessageList.push_back(Messages);
				MessageList.push_back(Messages);
				
				Messages =std::vector<std::string>();
			
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
