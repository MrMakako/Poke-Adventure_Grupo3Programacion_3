#include <iostream>

#include "Menu.h"
#include "Npc.h"
int ScreenWidht = 1024;
int ScreenHeight = 768;
int frames = 0;
int x = -1, y = -1;
Player* ColisionObj;



void MapLoad() {



}

bool collision(float x, float y, float ex, float ey, int width,int  height) {


    if (x + width<ex || x>ex + width || y>ey + height || y + height<ey) {
     

        return true;

  
    }
    else {
        std::cout << "collision detected\n";
        if (ColisionObj->getDirY() == 3) {
            //Up
            ColisionObj->setY(ColisionObj->getY() + ColisionObj->getSpeed());
         




        }
        else if (ColisionObj->getDirY() == 0) {
            //Down
            ColisionObj->setY(ColisionObj->getY() - ColisionObj->getSpeed());
          

        }
        else if (ColisionObj->getDirY() == 1) {
            //Left
            ColisionObj->setX(ColisionObj->getX() + ColisionObj->getSpeed());

         //   std::cout << ColisionObj->getDirY() << "\n";








        }
        else if (ColisionObj->getDirY() == 2) {
            //right
            ColisionObj->setX(ColisionObj->getX() - ColisionObj->getSpeed());

        //    std::cout << ColisionObj->getDirY() << "\n";


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

    al_install_audio();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_install_mouse();
    al_init_image_addon();
    al_reserve_samples(2);

    ALLEGRO_DISPLAY* display = al_create_display(ScreenWidht,ScreenHeight);

    ALLEGRO_FONT* font = NULL;
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_BITMAP* Character = al_load_bitmap("Pokemon/Player.png");
    ALLEGRO_BITMAP* mapa = al_load_bitmap("Pokemon/MapaVer2.jpeg");
    ALLEGRO_BITMAP* pokemon = al_load_bitmap("Pokemon/Player.png");
    ALLEGRO_TRANSFORM camera;
    //esta funcion importa el //
    ALLEGRO_BITMAP* pokemon1= al_load_bitmap("Pokemon/Bulba.png");
    //quita el colro de fondo de la imagen
    al_convert_mask_to_alpha(pokemon1,al_get_pixel(pokemon1,0,0));



    timer = al_create_timer(1.0 /60 );



    al_convert_mask_to_alpha(Character, al_map_rgb(106, 78, 46));
    al_set_target_bitmap(al_get_backbuffer(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());


    //LOAD CHARACTER
    Player Steve(Character);
    Steve.setHeight(64);
    Steve.setWidht(64);
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



    bool  menu=true;

    Menu MainMenu;
    MainMenu.setShow(true);


    //Bodys
    Npc NewPokemon(pokemon1,200,300,64,64);

    while (running) {




        
        al_flip_display();

     
      
        ALLEGRO_KEYBOARD_STATE KeyState;
        ALLEGRO_EVENT event;
   
        al_get_keyboard_state(&KeyState);
        al_wait_for_event(queue, &event);
        
        //Seteando el evento 

        MainMenu.setMouseEvent(event);
        if (menu) {
            menu = MainMenu.ShowMenu();
        }

        
 
        
        if (event.type == ALLEGRO_EVENT_TIMER) {

            //Le pasamos los frames  steve cada 4 el caminara;
    
            //colisiones 

            collision(Steve.getX(),Steve.getY(),1528,-5,20,1891);

           collision(Steve.getX(), Steve.getY(), 1003,1132,200,70);
           collision(Steve.getX(), Steve.getY(), 847, 1387, 200, 70);
           collision(Steve.getX(), Steve.getY(), 622, 1642, 200, 70);
           collision(Steve.getX(), Steve.getY(), 115, 1288,30, 800);
           //cabana
           collision(Steve.getX(), Steve.getY(), 137, 440, 235,240);
           //Arboles con verjas
           collision(Steve.getX(), Steve.getY(), 1507, 628,160, 140);
           collision(Steve.getX(), Steve.getY(), 1507, 1564, 160, 170);

           collision(Steve.getX(), Steve.getY(), 1123, 394, 32, 32);

            if (!menu) {
                al_draw_bitmap(mapa, 0, 0, NULL);

                NewPokemon.Draw(0, 0);
                Steve.Mover(KeyState, &frames);
                //  std::cout << NewPokemon.getWidth()<<std::endl;

                Steve.Dibujar();
            
                
                    
               //Aqui se hace el dibujado
            }
 
            collision(Steve.getX(), Steve.getY(), NewPokemon.getX(), NewPokemon.getY(),NewPokemon.getWidth()/2,NewPokemon.getHeight()/2);
        
            

         
            al_flip_display();
           
    
        


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
