#include "Player.h"



Player::Player() {

    dirX = 0;
    dirY = 0;
}


Player::~Player() {





}


int Player::getHeight() {
    return height;
    
}
int Player::getWidth() {
    return width;


}
int Player::getY() {
    return y;

}

int Player::getDirY()
{
    return dirY;
}

int Player::getSpeed()
{
    return speed;
}

void Player::setX(int n)
{

    x = n;
}

void Player::setY(int n){

   y = n;

}

int Player::getX() {
    return x;

}

Player::Player(ALLEGRO_BITMAP* _Sprite) {

	Sprite = _Sprite;

    dirX = 0;
    dirY = 0;
    speed = 3;


    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    al_init_image_addon();



}
void Player:: setWidht(int n) {
	
	width = n;


}
void Player::setHeight(int n) {

	height = n;


}
void Player::Mover(ALLEGRO_KEYBOARD_STATE KeyState, int *FrameRate) {

    bool anmation = false;
    
    int maxFrameRate = 4;

    if (al_key_down(&KeyState, ALLEGRO_KEY_W)) {
        y -= speed;

        dirY = 3;


        anmation = true;

    };
    if (al_key_down(&KeyState, ALLEGRO_KEY_S)) {

        y += speed;

        dirY = 0;
        anmation = true;
        
    }
    if (al_key_down(&KeyState, ALLEGRO_KEY_D) && (!al_key_down(&KeyState, ALLEGRO_KEY_W)) && (!al_key_down(&KeyState, ALLEGRO_KEY_S))) {

        x += speed;

        dirY = 2;

        anmation = true;
    }
    if (al_key_down(&KeyState, ALLEGRO_KEY_A) && (!al_key_down(&KeyState, ALLEGRO_KEY_W)) &&(!al_key_down(&KeyState, ALLEGRO_KEY_S))) {

        x -= speed;
        dirY = 1;
        anmation = true;
    }

    if (dirX < 3) {
        if (anmation) {
            if (*FrameRate ==maxFrameRate) {
                dirX++;


               

            }
          
        }
  
    }
    else {
    
        dirX = 0;

        *FrameRate = 0;

    
    }
    //Modificando frames con punteros

   if (*FrameRate > maxFrameRate) {
       *FrameRate = 0;
    }

    *FrameRate += 1;
    



}
void Player::Dibujar() {

	al_draw_bitmap_region(Sprite, width * dirX , height * dirY, width, height,x,y, NULL);
   

	



}