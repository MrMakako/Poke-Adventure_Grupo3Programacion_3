#include "Player.h"



Player::Player() {

    dirX = 0;
    dirY = 0;
}


Player::~Player() {





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
void Player::Mover(ALLEGRO_KEYBOARD_STATE KeyState) {


    if (al_key_down(&KeyState, ALLEGRO_KEY_W)) {
        y -= 3;
        dirX = 0;
        dirY = 3;



    };
    if (al_key_down(&KeyState, ALLEGRO_KEY_S)) {

        y += 3;
        dirX = 0;
        dirY = 0;


    }
    if (al_key_down(&KeyState, ALLEGRO_KEY_D)) {

        x += 3;
        dirX = 0;
        dirY = 2;


    }
    if (al_key_down(&KeyState, ALLEGRO_KEY_A)) {

        x -= 3;
        dirX = 0;
        dirY = 1;

    }


}
void Player::Dibujar() {

	al_draw_bitmap_region(Sprite, width * dirX , height * dirY, width, height,x,y, NULL);

	



}