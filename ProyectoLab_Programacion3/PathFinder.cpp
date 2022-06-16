#include "PathFinder.h"








void PathFinder::DrawTable()
{


	int XPos=486;
	int Ypos=347;	
	int Line=0;

	for (int i= 0; i < FootPrints.size();i++) {
		if (FootPrints[i].isFound()) {
			if (FootPrints[i].collision(*MouseX, *MouseY, XPos+32, Ypos+32, 32, 32)) {
				FootPrints[i].DrawInTable(XPos, Ypos, true);
				if (*MouseClicked) {
					SelectedIndex = i;
					std::cout << "Has Seleccionado ::::" << i << "\n";
				}
				else {

				}

			}
			else {

				FootPrints[i].DrawInTable(XPos, Ypos, false);
			}
		
			XPos += 90;

		}

		
		else {
			
		
		
		}
		

	
	
	}






}

void PathFinder::DrawLobby()
{

	FootPrints[0].Draw(0, 0);
	FootPrints[1].Draw(0, 0);
	
	FootPrints[2].Draw(0, 0);



}

void PathFinder::AddMouseInput(int* _MouseX, int* _MouseY, bool* _Clicked)
{



	MouseX = _MouseX;
	MouseY = _MouseY;
	MouseClicked = _Clicked;
}

void PathFinder::Load_all_pokemon()
{
	
	PokemonSprites[0] = al_load_bitmap("FootPrints/pokemon/94.png");



	

	PokemonSprites[1] = al_load_bitmap("FootPrints/pokemon/495.png");
	PokemonSprites[2] = al_load_bitmap("FootPrints/pokemon/135.png");
	PokemonSprites[3] = al_load_bitmap("FootPrints/pokemon/172.png");
	PokemonSprites[4] = al_load_bitmap("FootPrints/pokemon/253.png");
	PokemonSprites[5] = al_load_bitmap("FootPrints/pokemon/376.png");

	PokemonSprites[6] = al_load_bitmap("FootPrints/pokemon/257.png");
	PokemonSprites[7] = al_load_bitmap("FootPrints/pokemon/277.png");
	PokemonSprites[8] = al_load_bitmap("FootPrints/pokemon/552.png");


	for (int i = 0; i < 9; i++) {
	
		PokemonBtn p(PokemonSprites[i], 0, 0, 96, 96, Snivy, MainPlayer);
		p.setRx(2);
		p.setRy(2);
		TablaBotones.push_back(p);

	}



}

void PathFinder::Encontrar(ALLEGRO_KEYBOARD_STATE  State)
{

	for (int i = 0; i < FootPrints.size();i++) {
		if (FootPrints[i].inRange()) {
			if (al_key_down(&State, ALLEGRO_KEY_SPACE) && (!SpacePressed)) {
				SpacePressed = true;
				std::cout << "Se ha encontradoun huella";
				FootPrints[i].setFound(true);
			}
		}
	
	}





	if (!al_key_down(&State, ALLEGRO_KEY_SPACE)) {
		SpacePressed = false;

	}




}

void PathFinder::DrawPokeTable()
{

	int XPos = 10;
	int Ypos = 120;
	int Line = 0;


	;
	for (int i = 0; i < TablaBotones.size(); i++) {


			if (i == 3) {
				Ypos += 150;
				XPos = 10;

			}
			else if (i== 6) {
				Ypos += 150;
				XPos = 10;
			}
			


			if (TablaBotones[i].collision(*MouseX, *MouseY, XPos + 96, Ypos + 96, 32, 32)) {
				TablaBotones[i].DrawInTable(XPos, Ypos, true);
				


				if (*MouseClicked) {
				
					std::cout << "Has Seleccionado ::::" << i << "\n";
				}
				else {

				}

			}
			else {

				TablaBotones[i].DrawInTable(XPos, Ypos, false);
			}



			XPos += 120;

		


	




	}


	


}

void PathFinder::addPath(PokemonNames Name, int _x, int _y)
{
	ALLEGRO_BITMAP* PathSprite;
	
	switch (Name)
	{
	case Snivy: {
		PathSprite = al_load_bitmap("FootPrints/495.png");

		break;
	
	
	}case Grovyle: {
	
		
	
		PathSprite = al_load_bitmap("FootPrints/253.png");

		break;
	
	}case Megatross:{
		PathSprite = al_load_bitmap("FootPrints/376.png");

		break;
	
	
	}case Pichu: {
		PathSprite = al_load_bitmap("FootPrints/172.png");

		break;
	
	
	}case Jolteon:{

		PathSprite = al_load_bitmap("FootPrints/135.png");

		break;
	
	
	}case Gengar: {
		PathSprite = al_load_bitmap("FootPrints/94.png");

		break;
	
	}


	default:

		PathSprite = nullptr;
		break;
	}


	
	Paths footprint(PathSprite, _x, _y, 16, 16, Name,MainPlayer);
	FootPrints.push_back(footprint);

}
