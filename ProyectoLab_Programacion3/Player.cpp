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

int Player::getX() {
    return x;

}

Player::Player(ALLEGRO_BITMAP* _Sprite) {

	Sprite = _Sprite;

    dirX = 0;
    dirY = 0;



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
        y -= 3;

        dirY = 3;

        anmation = true;

    };
    if (al_key_down(&KeyState, ALLEGRO_KEY_S)) {

        y += 3;

        dirY = 0;
        anmation = true;

    }
    if (al_key_down(&KeyState, ALLEGRO_KEY_D)) {

        x += 3;

        dirY = 2;

        anmation = true;
    }
    if (al_key_down(&KeyState, ALLEGRO_KEY_A)) {

        x -= 3;
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