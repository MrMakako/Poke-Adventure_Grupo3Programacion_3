#include <iostream>

#include "Menu.h"
#include "Npc.h"
#include "MessageBox.h";
#include "Map.h";
#include "Movie.h";

int ScreenWidht = 1024;
int ScreenHeight = 768;
int frames = 0;
int x = -1, y = -1;
Player* ColisionObj;


void ChangeMusic(ALLEGRO_SAMPLE_INSTANCE* Instance, ALLEGRO_SAMPLE_INSTANCE *stop, bool* playing);
enum Mapas {
    LOBBY = 1, UNITEC = 2, CASA = 3, LABORATORY = 4, MOVIE = 5

};


void MapLoad() {



}


bool collision(float x, float y, float ex, float ey, int width,int  height) {


    if (x + width<ex || x>ex + width || y>ey + height || y + height<ey) {
     

        return false;

  
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

        return true;
    }


}


bool inRange(float x, float y, float ex, float ey, int width, int  height) {
   


        if (x + width<ex || x>ex + width || y > ey + height || y + height < ey) {


            return false;


        }
        return true;


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

    std::cout << CameraPosition[0] << "   " << CameraPosition[1]<<"\n";


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
    al_reserve_samples(4);

    ALLEGRO_DISPLAY* display = al_create_display(ScreenWidht,ScreenHeight);

    ALLEGRO_FONT* font = NULL;
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_BITMAP* Character = al_load_bitmap("Pokemon/Player.png");
    ALLEGRO_BITMAP* mapa = al_load_bitmap("Pokemon/MapaVer2.jpg");
    ALLEGRO_BITMAP* LabMap = al_load_bitmap("imagenes/willowlab.png");
    ALLEGRO_BITMAP* Oak = al_load_bitmap("imagenes/Oak.png");
    ALLEGRO_BITMAP* fader = al_load_bitmap("imagenes/Fade1.png");
    ALLEGRO_BITMAP* pokemon = al_load_bitmap("Pokemon/Player.png");
    ALLEGRO_TRANSFORM camera;
    ALLEGRO_SAMPLE* Gym = al_load_sample("sonidos/Gym.mp3");
    ALLEGRO_SAMPLE* Narration= al_load_sample("sonidos/Narration.mp3");
    


    
    ALLEGRO_SAMPLE_INSTANCE* MusicInstance=al_create_sample_instance(Gym);
    ALLEGRO_SAMPLE_INSTANCE* NarrationInstance = al_create_sample_instance(Narration);

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
    //Music
    al_attach_sample_instance_to_mixer(MusicInstance, al_get_default_mixer());

    al_set_sample_instance_gain(MusicInstance, 0.1);

    al_play_sample_instance(MusicInstance);


   
    //Character position;
    int Px = 100;
    int Py = 100;

    //para que el event timer funcione hay que niciarlo
    al_start_timer(timer);
    assert(Character != NULL);

    //Frame Counter
    int frames = 1;
    al_clear_to_color(al_map_rgb(255, 255, 200));
    
    Steve.setX(928);
    Steve.setY(1909);



    bool  menu=true;

    Menu MainMenu;
    MainMenu.setShow(true);


    //Bodys
    Npc NewPokemon(pokemon1,200,300,64,64,&Steve);
    
    
  ///  MessageBoxZ mensaje(NULL, "HOLAAAAAAA", ScreenWidht / 2, ScreenHeight / 2);
    
    //0,0, 346, 250, 1360, 400, 346 * 4, 250* 4, 0
    Map Lab(LabMap, 1360, 400, 346, 250, &Steve);
    Map Lobby(mapa,0,0, 864, 1104, &Steve);

    Lobby.AddColision(1270, 1336, 30, 420);


    Lobby.AddNpc(NULL, 637, 1819, 30, 30,"Dialogs/Lobby/arboc.txt");

    


    Lab.AddColision(1995, 922, 100, 50);
    Lab.AddColision(2340, 915,220,80);
    Lab.AddColision(1701,1084,40, 80);

   Lab.AddNpc(pokemon1, 2463, 775, 64, 64,"Dialogs/Lab/Bulba1.txt");
   
    

    Lab.LoadMap(true);

    Mapas ActualMap = MOVIE;

    Movie StartMovie = Movie(timer,&Steve);
    

    bool PlayinMusic=false;




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
            //Mapa 1 Lobyy //
            if (ActualMap == LOBBY) {
                collision(Steve.getX(), Steve.getY(), 1528, -5, 20, 1891);

                collision(Steve.getX(), Steve.getY(), 1003, 1132, 200, 70);
                collision(Steve.getX(), Steve.getY(), 847, 1387, 200, 70);
                collision(Steve.getX(), Steve.getY(), 622, 1642, 200, 70);
                collision(Steve.getX(), Steve.getY(), 115, 1288, 30, 800);
                //cabana


                collision(Steve.getX(), Steve.getY(), 1528, -5, 20, 1891);

                collision(Steve.getX(), Steve.getY(), 1003, 1132, 200, 70);
                collision(Steve.getX(), Steve.getY(), 847, 1387, 200, 70);
                collision(Steve.getX(), Steve.getY(), 622, 1642, 200, 70);
                collision(Steve.getX(), Steve.getY(), 115, 1288, 30, 800);
                //cabana
                collision(Steve.getX(), Steve.getY(), 137, 440, 235, 240);
                //Arboles con verjas
                collision(Steve.getX(), Steve.getY(), 1507, 628, 160, 140);
                collision(Steve.getX(), Steve.getY(), 1507, 1564, 160, 170);

                collision(Steve.getX(), Steve.getY(), 1123, 394, 32, 32);
                collision(Steve.getX(), Steve.getY(), 277, 1336, 20, 400);
                //Entrada
                collision(Steve.getX(), Steve.getY(), 1315, 1906, 300, 20);
                collision(Steve.getX(), Steve.getY(), 442, 1891, 300, 20);


                collision(Steve.getX(), Steve.getY(), 1528, -5, 20, 1891);

                collision(Steve.getX(), Steve.getY(), 1003, 1132, 200, 70);
                collision(Steve.getX(), Steve.getY(), 847, 1387, 200, 70);
                collision(Steve.getX(), Steve.getY(), 622, 1642, 200, 70);
                collision(Steve.getX(), Steve.getY(), 115, 1288, 30, 800);
                //cabana
                collision(Steve.getX(), Steve.getY(), 137, 440, 235, 240);
                //Arboles con verjas
                collision(Steve.getX(), Steve.getY(), 1507, 628, 160, 140);
                collision(Steve.getX(), Steve.getY(), 1507, 1564, 160, 170);

                collision(Steve.getX(), Steve.getY(), 1123, 394, 32, 32);


            
            
            
            }
           
            

          
            if (!menu) {
                al_draw_rectangle(0, 0, 2000, 2000, al_map_rgb(0, 0, 0), 2000);
                if (ActualMap == LOBBY) {
                   // al_draw_tinted_scaled_bitmap(mapa, al_map_rgb(255, 255, 255), 0, 0, 864, 1104, 0, 0, 864 * 2, 1104 * 2, 0);
                    Lobby.LoadMap(true);
                    Lobby.DrawMap(2,2);
                    //aqui se dibuja a steve
                    //Aqui esta el....

                    Steve.Dibujar();

                 
            
                   

                    if (al_get_timer_count(timer) >30) {
                        al_draw_bitmap_region(Oak, 50 * 1, 70 * 1, 50, 70, 100, 100, 0);
                    
                    }
                    else {
                        al_draw_bitmap_region(Oak, 50 * 0, 70 * 0, 50, 70, 100, 100, 0);
                    
                    }


                    std::cout << "colisiones" << Steve.getX() << " --" << Steve.getY()<<std::endl;
                    cameraUpdate(CameraPosition, Steve.getX(), Steve.getY(), Steve.getWidth(), Steve.getHeight());

                   

                    
                
                
                }
                else if (ActualMap == LABORATORY) {
                
              
                    Lab.DrawMap(4,4);
                    if (collision(Steve.getX(), Steve.getY(), 1989, 571, 32, 32)) {
                      
                        ActualMap = LOBBY;
                        Steve.setX(1354);
                        Steve.setY(229);

                        al_clear_to_color(al_map_rgb(255,255,255));

                    
                    }


                    Steve.Dibujar();

                    cameraUpdate(CameraPosition, Steve.getX(), Steve.getY(), Steve.getWidth(), Steve.getHeight());

               
                
                }
                else if (ActualMap == MOVIE) {

                
        
                    ChangeMusic(NarrationInstance,MusicInstance, &PlayinMusic);
                
                    
                    
                    


                    StartMovie.StartAnimattion();
                    //al_draw_scaled_bitmap(fader,0,0,2500,2500,1024,1768,2500*-1,2500*-1,0);
                    //SDDDDDSSSDDDDSDSDSDSDSDSDSDSDSDSDSDSDPOLO
                    //al_draw_tinted_scaled_bitmap(fader, al_map_rgb(0,0,0), 0, 0, 2500, 2500, 0, 0, 2500, 2500, 0);
                
                    cameraUpdate(CameraPosition,0 ,0, Steve.getWidth(), Steve.getHeight());


                    if (!al_get_sample_instance_playing(NarrationInstance)||al_key_down(&KeyState,ALLEGRO_KEY_ESCAPE)) {
                    
                        ActualMap = LOBBY;

                        PlayinMusic = false;

                        ChangeMusic(MusicInstance, NarrationInstance, &PlayinMusic);
                    
                    }

                
                
                
                
                }


              
           
                Steve.Mover(KeyState, &frames);


               // std::cout << Steve.getX() << "   " << Steve.getY() << std::endl;
               




  
            }
 
            collision(Steve.getX(), Steve.getY(), NewPokemon.getX(), NewPokemon.getY(),NewPokemon.getWidth()/2,NewPokemon.getHeight()/2);
            


            if (al_get_timer_count(timer) == 60) {
                al_set_timer_count(timer, 0);
              

            
            }

            //Cambios de mapa
            if (collision(Steve.getX(), Steve.getY(), 1363, 166, 32, 32)) {

                ActualMap = LABORATORY;
                Steve.setX(1989);
                Steve.setY(700);




                al_clear_to_color(al_map_rgb(0, 0, 0));





            }

            
            Steve.setTalking(false);
   
            //Cambio de mapa si se choca con la puerta
         

         
            al_flip_display();

            
           
    
        


        }









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
    al_destroy_sample(Gym);
    al_destroy_sample(Narration);
    al_destroy_sample_instance(MusicInstance);




}


void ChangeMusic(ALLEGRO_SAMPLE_INSTANCE* Instance,ALLEGRO_SAMPLE_INSTANCE* stop,bool* playing) {



    if (!*playing) {

      
        al_stop_sample_instance(stop);

        al_attach_sample_instance_to_mixer(Instance, al_get_default_mixer());

        al_play_sample_instance(Instance);



        *playing = true;
        std::cout << "Playinggggggggg" << std::endl;
    
    
    
    
    }





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
