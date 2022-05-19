#include "Movie.h"
#include "allegro5//allegro_image.h"
void Movie::load()
{


	PokemonSprite = al_load_bitmap("Pokemon/Mega-Absol.png");
	al_convert_mask_to_alpha(PokemonSprite,al_get_pixel(PokemonSprite,0,0));
	Pokemon = new Npc(PokemonSprite,200,200,64,64,NULL);
	Font = al_load_font("fuente/pokemon_pixel_font.ttf", 34, NULL);







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


	Pokemon->DrawScaled(0, 0, 5);

	int Y = 0;
	int X = 0;



	
	X = (Pokemon->getX() < 700) ? 5 : 0;
	Pokemon->setX(Pokemon->getX() + X);
	

	Y=(al_get_timer_count(timer) == 30)?10:0;
	Pokemon->setY(Pokemon->getY() + Y);
	Y= (al_get_timer_count(timer) == 60) ? -10 : 0;
	Pokemon->setY(Pokemon->getY() +Y);


	Input->DrawMessageBox(300, 500, "HOlaaaaaa como estas la matiza de sharon wowwwwww", Font);









}
