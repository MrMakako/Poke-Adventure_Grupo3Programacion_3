#include<iostream>

#include<allegro5/allegro.h>;
#include <iostream>
#include <allegro5/allegro.h>


#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
int main() {
	

	//cuandot utilzen headers que los vamos a utilzar mucho hay que incluirlos aqui
	// el main casi que no lo vamos a tocar si no que se incluira headers con las funciones luego se deben de implementar 
	// si mas de uno trbaja en el kain pueden arreglarse para crear uno solo .
	//Inicializadores

	al_init();

	//Variables
	
	bool  running;


	//ALLEGROS
	ALLEGRO_DISPLAY* Window;
	ALLEGRO_EVENT_QUEUE* Queue;
	

	
	//Init
	Window = al_create_display(900 ,600);
	
	running = true;

	while (running) {
		

		Queue = al_create_event_queue();
	
		al_clear_to_color(al_map_rgb(100, 103, 10));



		al_flip_display();
	
	
	
	}












}

	

;