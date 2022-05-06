#include <iostream>
#include <allegro5/allegro.h>


#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "Player.h"
#include "Body.h"
#include "string"


int ScreenWidht = 900;
int ScreenHeight = 600;
int frames = 0;

Player* ColisionObj;


bool collision(float x, float y, float ex, float ey, int width,int  height) {


    if (x + width<ex || x>ex + width || y>ey + height || y + height<ey) {
     

        return true;

  
    }
    else {
        std::cout << "collision detected\n";
        if (ColisionObj->getDirY() == 3) {
            //Up
            ColisionObj->setY(ColisionObj->getY() + ColisionObj->getSpeed());
            std::cout << ColisionObj->getDirY() << "\n";




        }
        else if (ColisionObj->getDirY() == 0) {
            //Down
            ColisionObj->setY(ColisionObj->getY() - ColisionObj->getSpeed());
            std::cout << ColisionObj->getDirY() << "\n";


        }
        else if (ColisionObj->getDirY() == 1) {
            //Left
            ColisionObj->setX(ColisionObj->getX() + ColisionObj->getSpeed());

            std::cout << ColisionObj->getDirY() << "\n";








        }
        else if (ColisionObj->getDirY() == 2) {
            //right
            ColisionObj->setX(ColisionObj->getX() - ColisionObj->getSpeed());

            std::cout << ColisionObj->getDirY() << "\n";


        }

        return false;
    }


}

void cameraUpdate(float * CameraPosition,float x,float y,int width,int height) {

    CameraPosition[0] = -(ScreenWidht / 2)+(x+width/2);
    CameraPosition[1] = -(ScreenHeight / 2)+(y+height/2);

    if (CameraPosition[0] < 0) {
        CameraPosition[0] = 0;
    }
    if (CameraPosition[1] < 0) {
        CameraPosition[1] = 0;
        
    }




}
int main()
{       //Punteros//
    al_init();

    
    
   
    float CameraPosition [2] = {0,0};

    bool running = true;
    




    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    al_init_image_addon();

    ALLEGRO_DISPLAY* display = al_create_display(900, 600);
    ALLEGRO_FONT* font = NULL;
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_BITMAP* Character = al_load_bitmap("Pokemon/Player2.png");
    ALLEGRO_BITMAP* mapa = al_load_bitmap("Pokemon/mapa.jpeg");
    ALLEGRO_BITMAP* pokemon = al_load_bitmap("Pokemon/Player.png");


    ALLEGRO_TRANSFORM camera;

  



    timer = al_create_timer(1.0 /60 );



    al_convert_mask_to_alpha(Character, al_map_rgb(106, 78, 46));
    al_set_target_bitmap(al_get_backbuffer(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));


    //LOAD CHARACTER
    Player Steve(Character);
    Steve.setHeight(32);
    Steve.setWidht(32);
    ColisionObj = &Steve;
    


   
    //Character position;
    int Px = 100;
    int Py = 100;

    //para que el event timer funcione hay que niciarlo
    al_start_timer(timer);
    assert(Character != NULL);

    //Frame Counter
    int frames = 1;
    al_clear_to_color(al_map_rgb(255, 255, 200));
    
    Steve.setX(250);
    Steve.setY(250);

    while (running) {


        
        al_flip_display();

        

        ALLEGRO_KEYBOARD_STATE KeyState;
        ALLEGRO_EVENT event;

        al_get_keyboard_state(&KeyState);
        al_wait_for_event(queue, &event);

        //Seteando el evento 


  
  

        

        if (event.type == ALLEGRO_EVENT_TIMER) {

            //Le pasamos los frames  steve cada 4 el caminara;
            Steve.Mover(KeyState, &frames);
          
            //Aqui se hace el dibujado

            

            
            al_draw_bitmap(mapa,0,0,NULL);

            //colisiones 
        
            collision(Steve.getX(), Steve.getY(), 0, 0, 50, 1000);
            collision(Steve.getX(), Steve.getY(), 790, 0, 10, 1000);
            collision(Steve.getX(), Steve.getY(), 0, 0, 110, 80);
            collision(Steve.getX(), Steve.getY(), 600, 80, 100,100);
            //modficiar esta funcionn par saber con lo que colisiona player //
            collision(Steve.getX(), Steve.getY(), 600, 80, 100, 100);
            collision(Steve.getX(), Steve.getY(), 0, 960, 2000, 5);
            //Choza
            collision(Steve.getX(), Steve.getY(), 0, 260, 190, 110);

            Steve.Dibujar();

         
            al_flip_display();
           
            //Actualizacion del codigo
        
        


        }

        cameraUpdate(CameraPosition,Steve.getX(), Steve.getY(), Steve.getWidth(), Steve.getHeight());
        al_identity_transform(&camera);
        al_translate_transform(&camera, -CameraPosition[0], -CameraPosition[1]);
        al_use_transform(&camera);












    }



    

    al_destroy_bitmap(Character);
    al_destroy_bitmap(mapa);
    al_destroy_event_queue(queue);
    al_destroy_font(font);
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
