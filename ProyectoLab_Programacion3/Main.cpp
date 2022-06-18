#include <iostream>
#include "Menu.h"
#include "Npc.h"
#include "MessageBox.h"
#include "Map.h"
#include "Movie.h"
#include "Trivia.h"
#include "PathFinder.h"
#include "PokemonNames.h"
#include "MesaDesc.h"
//Para reparar el dialogo solo se requiere de colocar un false en el lugar correcto
int ScreenWidht = 1024;
int ScreenHeight = 768;
int frames = 0;
int x = -1, y = -1;
Player* ColisionObj;
bool MouseClicked = false;

int MouseX = 0, MouseY = 0;
void ChangeMusic(ALLEGRO_SAMPLE_INSTANCE* Instance, ALLEGRO_SAMPLE_INSTANCE* stop, bool* playing);

enum Mapas {
    LOBBY = 1, UNITEC = 2, CASA = 3, LABORATORY = 4, MOVIE = 5, VALLE = 6, TRIVIA = 7, SALON = 8, FINDER = 9, MESADESC = 10
};

void MapLoad() {
}
//ready
struct fader {
    int time;
    int speed;
    int count;
    bool fading;
    ALLEGRO_BITMAP* fadeImage;
    ALLEGRO_TIMER* timer;

    fader(ALLEGRO_BITMAP* _fader, int _time, int _speed) {
        fadeImage = _fader;
        count = 0;
        time = _time;
        speed = _speed;
        timer = al_create_timer(1.0 / 60);
        fading = false;
    }

    void fade() {
        if (!fading) {
            al_start_timer(timer);
        }
        fading = true;
        //MODUFIFICAR PARA CONVERTIR ESTO EN STRUCT O FUNCIION
        if (count >= 250 && al_get_timer_count(timer) >= time) {
            fading = false;
        }
        else {
            if (count <= 250) {
                count = count + speed;
            }
        }
        al_draw_tinted_scaled_bitmap(fadeImage, al_map_rgba(0, 0, 0, count),0, 0, 100, 100, 10, 0, 500 * 7, 300 * 7, 0);
    }
};

bool collision(float x, float y, float ex, float ey, int width, int  height) {
    if (x + width<ex || x>ex + width || y > ey + height || y + height < ey) {
        return false;
    }
    else {
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
        }
        else if (ColisionObj->getDirY() == 2) {
            //right
            ColisionObj->setX(ColisionObj->getX() - ColisionObj->getSpeed());
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

void cameraUpdate(float* CameraPosition, float x, float y, int width, int height) {
    CameraPosition[0] = -(ScreenWidht / 2) + (x + width / 2);
    CameraPosition[1] = -(ScreenHeight / 2) + (y + height / 2);
    if (CameraPosition[0] < 0) {
        CameraPosition[0] = 0;
    }
    if (CameraPosition[1] < 0) {
        CameraPosition[1] = 0;
    }
}

int main() {
    //Punteros

    al_init();
    float CameraPosition[2] = { 0,0 };
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

    ALLEGRO_DISPLAY* display = al_create_display(ScreenWidht, ScreenHeight);
    ALLEGRO_FONT* font = NULL;
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_TIMER* timer = NULL;

    ALLEGRO_BITMAP* Character = al_load_bitmap("Pokemon/Player.png");
    ALLEGRO_BITMAP* mapa = al_load_bitmap("Pokemon/MapaVer2.jpg");
    ALLEGRO_BITMAP* LabMap = al_load_bitmap("imagenes/willowlab.png");
    ALLEGRO_BITMAP* faderIMG = al_load_bitmap("imagenes/Black.jpg");
    ALLEGRO_BITMAP* pokemon = al_load_bitmap("Pokemon/Player.png");
    ALLEGRO_BITMAP* Trainer1 = al_load_bitmap("imagenes/RedTrainer");
    ALLEGRO_BITMAP* Trainer2 = al_load_bitmap("imagenes/BlueTrainer");
    ALLEGRO_BITMAP* Mapa2 = al_load_bitmap("Pokemon/SecondMap.png");
    ALLEGRO_BITMAP* MapaSalon = al_load_bitmap("imagenes/Salon.png");
    ALLEGRO_BITMAP* PokeDex = al_load_bitmap("Pokemon/Pokedex.png");
    ALLEGRO_BITMAP* Violador = al_load_bitmap("Pokemon/97.png");
    ALLEGRO_BITMAP* pokemon1 = al_load_bitmap("Pokemon/Bulba.png");
    ALLEGRO_BITMAP* MenuPathFinder = al_load_bitmap("imagenes/PathFinderv2.png");
    ALLEGRO_BITMAP* DescTable = al_load_bitmap("Pokemon/MesaDescartes.png");
    ALLEGRO_TRANSFORM camera;


    ALLEGRO_SAMPLE* Gym = al_load_sample("sonidos/Gym.mp3");
    ALLEGRO_SAMPLE* Narration = al_load_sample("sonidos/Narration.mp3");
    ALLEGRO_SAMPLE_INSTANCE* MusicInstance = al_create_sample_instance(Gym);
    ALLEGRO_SAMPLE_INSTANCE* NarrationInstance = al_create_sample_instance(Narration);

    //esta funcion importa el quita el colro de fondo de la imagen
    al_convert_mask_to_alpha(pokemon1, al_get_pixel(pokemon1, 0, 0));
    timer = al_create_timer(1.0 / 60);
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

    bool  menu = true;
    bool ifpress = false;
    Menu MainMenu;
    MainMenu.setShow(true);

    //Bodys
    Npc NewPokemon(pokemon1, 200, 300, 64, 64, &Steve);

    //Trivia
    Trivia JuegoTrivia(display,&Steve);

    //MessageBoxZ mensaje(NULL, "HOLAAAAAAA", ScreenWidht / 2, ScreenHeight / 2);
    //0,0, 346, 250, 1360, 400, 346 * 4, 250* 4, 0
    Map Lab(LabMap, 1360, 400, 346, 250, &Steve);
    Map Lobby(mapa, 0, 0, 864, 1104, &Steve);
    Map Valle(Mapa2, 0, 0, 1600, 1600, &Steve);
    Map Salon(MapaSalon, 0, 0, 192, 176, &Steve);


    Lobby.AddColision(1270, 1336, 30, 420);
    Lobby.AddNpc(NULL, 637, 1819, 30, 30, "Dialogs/Lobby/arboc.txt");
    Lobby.AddNpc(NULL, 1039, 1567, 30, 30, "Dialogs/Lobby/bulba.txt");
    Lobby.AddNpc(NULL, 436, 688, 30, 30, "Dialogs/Lobby/PokebolaMapa.txt");
    Lobby.AddNpc(NULL, 481, 1408, 30, 30, "Dialogs/Lobby/P_Peleando.txt");
    Lobby.AddNpc(NULL, 481, 1480, 30, 30, "Dialogs/Lobby/P_Peleando2.txt");
    Lobby.AddNpc(NULL, 205, 1135, 30, 30, "Dialogs/Lobby/Licenciados.txt");
    Lobby.AddNpc(NULL, 205, 1189, 30, 30, "Dialogs/Lobby/Licenciados2.txt");
    Lobby.AddNpc(NULL, 205, 1189, 30, 30, "Dialogs/Lobby/Licenciados2.txt");
    Lobby.AddNpc(NULL, 205, 1189, 30, 30, "Dialogs/Lobby/Licenciados2.txt");
    Lobby.AddNpc(NULL, 1060, 688, 30, 30, "Dialogs/Lobby/PeleasPoke.txt");
    Lobby.AddNpc(NULL, 1033, 433, 30, 30, "Dialogs/Lobby/PeleasPoke2.txt");
    Lobby.AddNpc(NULL, 1156, 388, 30, 30, "Dialogs/Lobby/CamaraMan.txt");
    ALLEGRO_BITMAP* medallas[3];

    //Salon de clases
    Salon.LoadMap(true);
    ALLEGRO_BITMAP* MiniOak = al_load_bitmap("imagenes/MiniOak.png");
    Salon.AddNpc(MiniOak, 354, 159, 45, 64, "Dialogs/salon/oak.txt");

    //Laboratorio
    Lab.AddColision(1995, 922, 100, 50);
    Lab.AddColision(2340, 915, 220, 80);
    Lab.AddColision(1701, 1084, 40, 80);
    Lab.AddColision(1533, 892, 40, 400);
    Lab.AddNpc(pokemon1, 2463, 775, 64, 64, "Dialogs/Lab/Bulba1.txt");
    Lab.AddNpc(nullptr, 1995, 856, 32, 32, "");
    Lab.LoadMap(true);
    MesaDesc MesaDescartes(DescTable, 0, 0, 960, 960,&Steve);
    MesaDescartes.AddInput(&MouseX, &MouseY, &MouseClicked);
    MesaDescartes.LoadButtons();
    MesaDescartes.LoadMap(true);
;

    //Valle
    Valle.AddColision(2077, 2614, 1104, 30);
    Valle.AddColision(919, 1861, 30, 1664);
    Valle.AddNpc(NULL, 1402, 1555, 30, 30, "Dialogs/Lobby/Hipno.txt");
    Valle.AddColision(2077, 130, 1104, 30);
    Valle.AddColision(30115, 1603, 30, 800);

    Mapas ActualMap =MESADESC;
    Movie StartMovie = Movie(timer, &Steve);
    bool PlayinMusic = false;
    bool PathFinderOn;
    PathFinder PathGame(MenuPathFinder, 0, 0, 1024, 758, &Steve);
    

    //Path Game
    PathGame.LoadMap(true);
    PathGame.addPath(Gengar, 600, 700);
    PathGame.addPath(Jolteon, 2000, 400);
    PathGame.addPath(Megatross, 1054, 1812);
    PathGame.AddMouseInput(&MouseX, &MouseY, &MouseClicked);
    PathGame.Load_all_pokemon();
   


    fader faderSys(faderIMG,15, 3);

    bool press = false;
    Steve.setVida(8);

    while (running) {
        int vidas = ColisionObj->getVida();
        ALLEGRO_BITMAP** hearts = new ALLEGRO_BITMAP * [vidas];
        al_flip_display();

        ALLEGRO_KEYBOARD_STATE KeyState;
        ALLEGRO_EVENT event;

        al_get_keyboard_state(&KeyState);
        al_wait_for_event(queue, &event);

        //Seteando el evento 
        if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {

            MouseX = event.mouse.x;
            MouseY = event.mouse.y;




        }

        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

            std::cout << "presses---------------";


            if (event.mouse.button && 1) {



                MouseClicked = true;

            }
            else if (event.mouse.button & 2) {
                MouseClicked = true;

            }



        }
        

        MainMenu.setMouseEvent(event);




        if (menu) {
            menu = MainMenu.ShowMenu();
        }
        if (event.type == ALLEGRO_EVENT_TIMER) {
            if (al_key_down(&KeyState, ALLEGRO_KEY_TAB) && press == false) {
                if (press == false) {
                    press = true;
                }
            }
            else if (!al_key_down(&KeyState, ALLEGRO_KEY_TAB) && press == true) {
                press = false;
            }

      


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
                    Lobby.DrawMap(2, 2);

                    PathGame.DrawLobby();
                    PathGame.Encontrar(KeyState);
                    //aqui se dibuja a steve
                    Steve.Dibujar();
                    //Cambios de mapa
                    if (collision(Steve.getX(), Steve.getY(), 1363, 166, 32, 32)) {
                        ActualMap = SALON;
                        Steve.setX(351);
                        Steve.setY(621);
                        cameraUpdate(CameraPosition, Steve.getX(), Steve.getY(), Steve.getWidth(), Steve.getHeight());
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                    }

                    if (Steve.getX() <= -41) {
                        ActualMap = VALLE;
                        Steve.setX(3106);
                        Steve.setY(2347);
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                    }
                    cameraUpdate(CameraPosition, Steve.getX(), Steve.getY(), Steve.getWidth(), Steve.getHeight());
                }
                else if (ActualMap == LABORATORY) {
                    Lab.DrawMap(4, 4);
                    if (collision(Steve.getX(), Steve.getY(), 1989, 571, 32, 32)) {
                        ActualMap = VALLE;
                        Steve.setX(1219);
                        Steve.setY(700);
                        al_clear_to_color(al_map_rgb(255, 255, 255));
                    }

                    if (inRange(Steve.getX(), Steve.getY(), 1584, 886, 40, 150) && ActualMap == LABORATORY) {

                        std::cout << "Finder";
                        if (al_key_down(&KeyState, ALLEGRO_KEY_E)) {

                            ActualMap = FINDER;




                        }


                    }
                    Steve.Dibujar();
                    cameraUpdate(CameraPosition, Steve.getX(), Steve.getY(), Steve.getWidth(), Steve.getHeight());
                }
                else if(ActualMap==MESADESC) {
                    MesaDescartes.DrawMap(1, 1);
                    MesaDescartes.DrawTable();
                    

                  
                    
                
                }
                else if (ActualMap == MOVIE) {
                    ChangeMusic(NarrationInstance, MusicInstance, &PlayinMusic);
                    StartMovie.StartAnimattion();
                    //al_draw_scaled_bitmap(fader,0,0,2500,2500,1024,1768,2500*-1,2500*-1,0);
                    //SDDDDDSSSDDDDSDSDSDSDSDSDSDSDSDSDSDSDPOLO
                    //al_draw_tinted_scaled_bitmap(fader, al_map_rgb(0,0,0), 0, 0, 2500, 2500, 0, 0, 2500, 2500, 0);
                    cameraUpdate(CameraPosition, 0, 0, Steve.getWidth(), Steve.getHeight());
                    if (al_key_down(&KeyState, ALLEGRO_KEY_ESCAPE) || faderSys.fading == true) {
                        faderSys.fade();
                        if (faderSys.fading == false) {
                            ActualMap = LOBBY;
                            PlayinMusic = false;
                            ChangeMusic(MusicInstance, NarrationInstance, &PlayinMusic);
                        }
                    }
                }
                else if (ActualMap == VALLE) {
                    Valle.LoadMap(true);
                    if (Steve.getX() < 2620) {
                        cameraUpdate(CameraPosition, Steve.getX(), Steve.getY(), Steve.getWidth(), Steve.getHeight());
                    }

                    if (collision(Steve.getX(), Steve.getY(), 1216, 649, 30, 10)) {
                        ActualMap = LABORATORY;
                        Steve.setX(1989);
                        Steve.setY(700);
                        cameraUpdate(CameraPosition, Steve.getX(), Steve.getY(), Steve.getWidth(), Steve.getHeight());
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                    }

                    if (Steve.getX() > 3135) {
                        ActualMap = LOBBY;
                        //set steve
                        Steve.setX(200);
                        Steve.setY(180);
                    }
                    Valle.DrawMap(2, 2);
                    Steve.Dibujar();
                }
                else if (ActualMap == TRIVIA) {
                    JuegoTrivia.Ruleta();
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    ActualMap = SALON;
                    JuegoTrivia.reset();
                }
                else if (ActualMap == SALON) {
                    Salon.DrawMap(4, 4);
                    if (Salon.getNpcAt(0).inRange()) {
                        if (al_key_down(&KeyState, ALLEGRO_KEY_E)) {
                            ActualMap = TRIVIA;
                        }
                    }

                    if (collision(Steve.getX(), Steve.getY(), 357, 681, 40, 15)) {
                        ActualMap = LOBBY;
                        //setear posiciones de nuevo//
                        Steve.setX(1354);
                        Steve.setY(228);
                    }

                    Steve.Dibujar();
                    cameraUpdate(CameraPosition, Steve.getX(), Steve.getY(), Steve.getWidth(), Steve.getHeight());
                }
                else if (ActualMap == FINDER) {

                    PathGame.DrawMap(1, 1);
                    PathGame.DrawTable();
                    PathGame.DrawPokeTable();
                    cameraUpdate(CameraPosition, 0, 0, 64, 64);
               
                    if (al_key_down(&KeyState, ALLEGRO_KEY_ESCAPE)) {
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                        ActualMap = LABORATORY;




                    }







                }

                

                if (press == true) {
                    al_draw_bitmap_region(PokeDex, 0, 0, 1024, 768, (Steve.getX() - 486), (Steve.getY() - 384), 0);

                    medallas[0] = al_load_bitmap("imagenes/medalSun.png");
                    medallas[1] = al_load_bitmap("imagenes/battleMedal.png");
                    medallas[2] = al_load_bitmap("imagenes/filoMedal.png");
                    al_draw_bitmap_region(PokeDex, 0, 0, 1024, 768, (Steve.getX() - 486), (Steve.getY() - 384), 0);
                    for (int i = 0; i < vidas; i++) {
                        hearts[i] = al_load_bitmap("imagenes/pixelheart.png");
                        al_draw_bitmap(hearts[i], ((Steve.getX() + 200) + (i * 35)), (Steve.getY() - 40), 0);
                    }
                    if (Steve.getMedal() == 1) {
                        al_draw_bitmap(medallas[0], ((Steve.getX() + 55) + (0 * 80)), (Steve.getY() + 95), 0);
                    }
                    else if (Steve.getMedal() == 2) {
                        al_draw_bitmap(medallas[0], ((Steve.getX() + 55) + (0 * 80)), (Steve.getY() + 95), 0);
                        al_draw_bitmap(medallas[1], ((Steve.getX() + 65) + (1 * 80)), (Steve.getY() + 95), 0);
                    }
                    else if (Steve.getMedal() == 3) {
                        al_draw_bitmap(medallas[0], ((Steve.getX() + 55) + (0 * 80)), (Steve.getY() + 95), 0);
                        al_draw_bitmap(medallas[1], ((Steve.getX() + 65) + (1 * 80)), (Steve.getY() + 95), 0);
                        al_draw_bitmap(medallas[2], ((Steve.getX() + 80) + (2 * 80)), (Steve.getY() + 95), 0);
                      


                    }
                }


                MouseClicked = false;
            }
          //  std::cout << Steve.getX() << " --" << Steve.getY() << std::endl;
            Steve.Mover(KeyState, &frames);
            collision(Steve.getX(), Steve.getY(), NewPokemon.getX(), NewPokemon.getY(), NewPokemon.getWidth() / 2, NewPokemon.getHeight() / 2);



                 std::cout << MouseX << "  " << MouseY << "\n";

            if (al_get_timer_count(timer) == 60) {
                al_set_timer_count(timer, 0);
            }
           
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

void ChangeMusic(ALLEGRO_SAMPLE_INSTANCE* Instance, ALLEGRO_SAMPLE_INSTANCE* stop, bool* playing) {
    if (!*playing) {
        al_stop_sample_instance(stop);
        al_attach_sample_instance_to_mixer(Instance, al_get_default_mixer());
        al_play_sample_instance(Instance);

        *playing = true;
    }
}