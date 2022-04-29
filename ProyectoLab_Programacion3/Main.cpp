#include <iostream>
#include <allegro5/allegro.h>


#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
int main()
{       //Punteros//
    al_init();

    int width = 64;
    int height = 64;
    int ScreenWidht=900;
    int ScreenHeight = 600;


    int dirX=0;
    int dirY=0;

    int paso = 0;

    




    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    al_init_image_addon();

    ALLEGRO_DISPLAY* display = al_create_display(900, 600);
    ALLEGRO_FONT* font = NULL;
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_BITMAP* Character = al_load_bitmap("Pokemon/Player.png");
    ALLEGRO_BITMAP* mapa = al_load_bitmap("Pokemon/mapa.jpeg");



    timer = al_create_timer(1.0 / 60);



    al_convert_mask_to_alpha(Character, al_map_rgb(106, 78, 46));


    al_set_target_bitmap(al_get_backbuffer(display));



    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));


    //LOAD CHARACTER

    bool running = true;
    //Character position;
    int Px = 100;
    int Py = 100;

    //para que el event timer funcione hay que niciarlo
    al_start_timer(timer);
    assert(Character != NULL);


    int frames = 1;
    al_clear_to_color(al_map_rgb(255, 255, 200));
    while (running) {

        al_flip_display();

        

        ALLEGRO_KEYBOARD_STATE KeyState;

        al_get_keyboard_state(&KeyState);
        

        ALLEGRO_EVENT event;
        //Setting the event


        al_wait_for_event(queue, &event);

        if (al_key_down(&KeyState, ALLEGRO_KEY_W)) {
            Py -= 3;
            dirX = 0;
            dirY = 3;



        };
        if (al_key_down(&KeyState, ALLEGRO_KEY_S)) {

            Py += 3;
            dirX = 0;
            dirY = 0;


        }
        if (al_key_down(&KeyState, ALLEGRO_KEY_D)) {

            Px += 3;
            dirX = 0;
            dirY = 2;


        }
        if (al_key_down(&KeyState, ALLEGRO_KEY_A)) {

            Px -= 3;
            dirX = 0;
            dirY = 1;

        }
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }





        if (event.type == ALLEGRO_EVENT_TIMER) {




            //Aqui se hace el dibujado
            
            std::cout << Px << " " << Py << "\n";
            al_draw_bitmap(mapa,0,0,NULL);
            al_draw_bitmap_region(Character, width * dirX, height * dirY, width, height, Px, Py, NULL);
            al_flip_display();
            //Actualizacion del codigo

        }











    }



    

    al_destroy_bitmap(Character);

 
    al_destroy_display(display);
    al_uninstall_keyboard();
    al_destroy_timer(timer);



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
