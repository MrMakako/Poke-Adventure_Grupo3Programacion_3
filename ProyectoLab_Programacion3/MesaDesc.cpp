#include "MesaDesc.h"

void MesaDesc::AddInput(int*_Mx, int*_My, bool* _MouseClicked)
{
	MouseX = _Mx;
	MouseY = _My;
	MouseClicked = _MouseClicked;
}

void MesaDesc::AddButton(ALLEGRO_BITMAP* _Sprite, int w, int h)
{
	if (MainPlayer == nullptr) {
		std::cout << "------------------------------------------------------------------------------------------ERROr";
	
	}
	Bottons.push_back(PokemonBtn(_Sprite, 0, 0, w, h, Snivy, MainPlayer));


}

void MesaDesc::LoadButtons()
{
	AddButton(al_load_bitmap("Pokemon/A.png"), 96, 96);
	AddButton(al_load_bitmap("Pokemon/B.png"), 96, 96);
	AddButton(al_load_bitmap("Pokemon/C.png"), 96, 96);
	AddButton(al_load_bitmap("Pokemon/D.png"), 96, 96);





}



void MesaDesc::DrawTable()
{

	int _xPos=100;
	int _yPos=200;
	Map::Draw(1,1);
	for (int i = 0; i < Bottons.size();i++) {
		
		
		if (collision(*MouseX, *MouseY, _xPos+192, _yPos+192, 32,32)) {
			
			Bottons[i].DrawInTable(_xPos, _yPos, true);
			std::cout << "Cambiando";

		}
		else {
		
			Bottons[i].DrawInTable(_xPos, _yPos, false);
		}
	


		_xPos += 120;
	}










}

bool MesaDesc::collision(float x, float y, float ex, float ey, int width, int height)
{

	if (x + width<ex || x>ex + width || y > ey + height || y + height < ey) {
		return false;
	}
	return true;
}
