#include "Movie.h"
#include "allegro5//allegro_image.h"
void Movie::load()
{


	PokemonSprite = al_load_bitmap("Pokemon/Mega-Absol.png");
	al_convert_mask_to_alpha(PokemonSprite,al_get_pixel(PokemonSprite,0,0));
	Pokemon = new Npc(PokemonSprite,200,200,64,64,NULL);
	Npc_Dialogs = Dialog("Dialogs/Intro/1.txt",12);
	Font = al_load_font("fuente/pokemon_pixel_font.ttf", 24, NULL);
	Background = al_load_bitmap("imagenes/Library.jpg");

	//Npc_Dialogs = Dialog("Dialogs/Intro/1.txt",0,0,23);




}

Movie::Movie()
{



	timer = NULL;

	Background = NULL;

	PokemonSprite = NULL;
}

Movie::Movie(ALLEGRO_TIMER*_timer, Player*_Input)
{
	timer = _timer;
	Input = _Input;

	load();



}

void Movie::StartAnimattion()
{

	al_draw_bitmap(Background, 0, 0, 0);
	Pokemon->DrawScaled(0, 0, 5);

	int Y = 0;
	int X = 0;




	X = (Pokemon->getX() < 700) ? 5 : 0;
	Pokemon->setX(Pokemon->getX() + X);
	Y=(al_get_timer_count(timer) == 30)?10:0; 
	Pokemon->setY(Pokemon->getY() + Y);
	
	Y= (al_get_timer_count(timer) == 60) ? -10 : 0;
	
	Pokemon->setY(Pokemon->getY() +Y);

	if (Input->getDialogNum()>=0 && Input->getDialogNum()<Npc_Dialogs.getMessages().size()) {
		int num = Input->getDialogNum();

		

			Input->DrawMessageBox(300 , 500, Npc_Dialogs.getMessages().at(num), Font);

		
		
		
	
	
	}
	else {
		Input->resetDialogNum();
	
	}
	
	
	











}
