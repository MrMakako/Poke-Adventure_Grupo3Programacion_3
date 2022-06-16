#include "PathFinder.h"

void PathFinder::DrawTable()
{

	for (Paths p : FootPrints) {
		if (p.isFound()) {
			p.Draw(20, 20);
		
		
		
		}
	
	
	}



}

void PathFinder::DrawLobby()
{

	FootPrints[0].Draw(0, 0);
	FootPrints[1].Draw(0, 0);
	
	FootPrints[2].Draw(0, 0);



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
