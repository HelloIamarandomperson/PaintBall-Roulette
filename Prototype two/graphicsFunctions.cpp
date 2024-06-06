//Including the other file
#include "Headers.h"
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_BITMAP *Table;
extern ALLEGRO_BITMAP *Dummy;
extern ALLEGRO_BITMAP *Player;
extern ALLEGRO_BITMAP *Dummyfires;
extern ALLEGRO_BITMAP *Dummyflash;
extern ALLEGRO_BITMAP *Playerfires;
extern ALLEGRO_BITMAP *Playerflash;
extern ALLEGRO_BITMAP *Buttons;
extern ALLEGRO_BITMAP *PlayerSelf1;
extern ALLEGRO_BITMAP *PlayerSelf2;
extern ALLEGRO_BITMAP *PlayerSelf3;
extern ALLEGRO_BITMAP *Shop;
extern ALLEGRO_BITMAP *BlankBulletCounter;
extern ALLEGRO_BITMAP *FullBulletCounter;
extern ALLEGRO_BITMAP *IndividualBulletForCounter;
extern ALLEGRO_BITMAP *InventoryButton;
extern ALLEGRO_BITMAP *ShopButton;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_EVENT eventOrder;
extern ALLEGRO_BITMAP *HealthBar1;
extern ALLEGRO_BITMAP *HealthBar2;
extern ALLEGRO_BITMAP *HealthBar3;
extern ALLEGRO_BITMAP *HealthBar4;
extern ALLEGRO_BITMAP *HealthBar5;
extern ALLEGRO_BITMAP *Zero;
extern ALLEGRO_BITMAP *One;
extern ALLEGRO_BITMAP *Two;
extern ALLEGRO_BITMAP *Three;
extern ALLEGRO_BITMAP *Four;
extern ALLEGRO_BITMAP *Five;
extern ALLEGRO_BITMAP *Six;
extern ALLEGRO_BITMAP *Seven;
extern ALLEGRO_BITMAP *Eight;
extern ALLEGRO_BITMAP *Nine;
extern ALLEGRO_BITMAP *Ball;
extern ALLEGRO_BITMAP *BallEmpty;



extern int yourHealth;
extern char Allegro[50]; // Declaration of the global variable
extern bool RunEvent;
extern int OpponentHealth;
extern bool nextTurnIsPlayer; //who's turn it is next (0 is the player, 1 is next person, etc...)
extern int chamber;
extern char cylinder[];
extern char response;
extern ALLEGRO_EVENT ButtonEvent;
extern int OpX;
extern int OpY;
extern int currentOp;
extern int slots;

ALLEGRO_MOUSE_STATE state;

void SwitchOp(){
    currentOp++;
    if (currentOp == 1){
        Dummy = al_load_bitmap("ImageFile\\GhostlyCharacter.png");
        OpX = 175;
        OpY = 75;
    }
}

void NormalScreenDraws(int ScreenDrawSpecial) {
    // Draw background elements InventoryButton ShopButton
    if (ScreenDrawSpecial != 1){
        al_draw_bitmap(Dummy, OpX, OpY, 0);
    }

    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Buttons, 0, 600, 0);
    al_draw_bitmap(InventoryButton, 600, 690, 0);
    al_draw_bitmap(ShopButton, 450, 690, 0);
    al_draw_bitmap(BlankBulletCounter, 0, 630, 0);

    // Draw bullets in the counter based on the number of available slots using switch case
    switch (chamber) {
        case 0:
            al_draw_bitmap(IndividualBulletForCounter, -33, 585, 0);
        case 1:
            al_draw_bitmap(IndividualBulletForCounter, 6, 585, 0);
        case 2:
            al_draw_bitmap(IndividualBulletForCounter, 45, 585, 0);
        case 3:
            al_draw_bitmap(IndividualBulletForCounter, 84, 585, 0);
        case 4:
            al_draw_bitmap(IndividualBulletForCounter, 123, 585, 0);
        case 5:
            al_draw_bitmap(IndividualBulletForCounter, 162, 585, 0);
            break;
    }
    switch (yourHealth) {
        case 5:
            al_draw_bitmap(HealthBar1, 450, 600, 0);
            break;
        case 4:
            if (ScreenDrawSpecial > 0 && cylinder[chamber-1] == 'B'){
                al_draw_bitmap(HealthBar1, 450, 600, 0);
            }else{
                al_draw_bitmap(HealthBar2, 450, 600, 0);
            }
            break;
        case 3:
            if (ScreenDrawSpecial > 0 && cylinder[chamber-1] == 'B'){
                al_draw_bitmap(HealthBar2, 450, 600, 0);
            }else{
                al_draw_bitmap(HealthBar3, 450, 600, 0);
            }

            break;
        case 2:
            if (ScreenDrawSpecial > 0 && cylinder[chamber-1] == 'B'){
                al_draw_bitmap(HealthBar3, 450, 600, 0);
            }else{
                al_draw_bitmap(HealthBar4, 450, 600, 0);
            }
            break;
        case 1:
            if (ScreenDrawSpecial > 0 && cylinder[chamber-1] == 'B'){
                al_draw_bitmap(HealthBar4, 450, 600, 0);
            }else{
                al_draw_bitmap(HealthBar5, 450, 600, 0);
            }

            break;
    }
}



int Button(char cylinder[], int &chamber) {
    // first 2 is coords for the top vertices's's, next 2 is for the bottom one.
    al_get_mouse_state(&state);
    if (ButtonEvent.mouse.x >= 0 && ButtonEvent.mouse.y >= 600 && ButtonEvent.mouse.x <= 200 && ButtonEvent.mouse.y <= 800 && state.buttons & 1) {
        response = 'o';
        strcpy(Allegro, "Shoot Yourself");

        //printf("\n%s", Allegro);
    }
    if (ButtonEvent.mouse.x >= 200 && ButtonEvent.mouse.y >= 600 && ButtonEvent.mouse.x <= 400 && ButtonEvent.mouse.y <= 800 && state.buttons & 1) {
        response = 'o';
        strcpy(Allegro, "Shoot the Opponent");
        //printf("\n%s", Allegro);
    }
    if (ButtonEvent.mouse.x >= 400 && ButtonEvent.mouse.y >= 600 && ButtonEvent.mouse.x <= 600 && ButtonEvent.mouse.y <= 800 && state.buttons & 1) {
        response = 'o';
        strcpy(Allegro, "Go To Shop");
        //printf("\n%s", Allegro);
    }
    if (ButtonEvent.mouse.x >= 600 && ButtonEvent.mouse.y >= 600 && ButtonEvent.mouse.x <= 800 && ButtonEvent.mouse.y <= 800 && state.buttons & 1) {
        response = 'o';
        strcpy(Allegro, "Open Inventory");
        //printf("\n%s", Allegro);
    }
    return 0;
}

void PlayerShootsPlayer(){
    memset(Allegro, '\0', sizeof(Allegro));
    al_clear_to_color(al_map_rgb(0, 0, 0));
    NormalScreenDraws(2);
    al_draw_bitmap(Playerfires, 0, 0, 0);
    al_flip_display();
    al_rest(.8);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    NormalScreenDraws(2);
    al_draw_bitmap(PlayerSelf2, 0, 0, 0);
    al_flip_display();
    al_rest(.9);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    NormalScreenDraws(2);
    if (cylinder[chamber-1] == 'B') {
        al_draw_bitmap(PlayerSelf3, 0, 0, 0);
    } else{
        al_draw_bitmap(PlayerSelf2, 0, 0, 0);
    }
    al_flip_display();
    al_rest(.4);
}

void ShopScreen(){
    al_draw_bitmap(Shop, 0, 0, 0);
    al_flip_display();
    al_rest(.4);
}

void DummyShootsPlayer(ALLEGRO_BITMAP *Table, ALLEGRO_BITMAP *Dummyfires, ALLEGRO_BITMAP *Player, ALLEGRO_BITMAP *Dummyflash){
    memset(Allegro, '\0', sizeof(Allegro));
    al_clear_to_color(al_map_rgb(0, 0, 0));
    NormalScreenDraws(1);
    al_draw_bitmap(Dummyfires, OpX, OpY, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    al_flip_display();
    al_rest(.9);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    NormalScreenDraws(1);
    al_draw_bitmap(Dummyfires, OpX, OpY, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    if (cylinder[chamber-1] == 'B') {
        al_draw_bitmap(Dummyflash, 0, 0, 0);
    }
    al_flip_display();
    al_rest(.3);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Dummyfires, OpX, OpY, 0);
    NormalScreenDraws(1);
    al_draw_bitmap(Player, 0, 0, 0);
    al_flip_display();
    al_rest(.4);
}
void PlayerShootsDummy(ALLEGRO_BITMAP *Table, ALLEGRO_BITMAP *Dummy, ALLEGRO_BITMAP *Player, ALLEGRO_BITMAP *Playerfires, ALLEGRO_BITMAP *Playerflash){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    NormalScreenDraws(0);
    al_draw_bitmap(Playerfires, 0, 0, 0);
    al_flip_display();
    al_rest(.9);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    NormalScreenDraws(0);
    al_draw_bitmap(Playerfires, 0, 0, 0);
    if (cylinder[chamber-1] == 'B') {
        al_draw_bitmap(Playerflash, 0, 0, 0);
    }
    al_flip_display();
    al_rest(.3);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    NormalScreenDraws(0);
    al_draw_bitmap(Playerfires, 0, 0, 0);
    al_flip_display();
    al_rest(.4);
}

bool frameOfGame(){
    if (Allegro[0] != '\0'){
            if (strcmp(Allegro, "Player Is Choosing") == 0){
                al_clear_to_color(al_map_rgb(0, 0, 0));
                NormalScreenDraws(0);
                al_draw_bitmap(Player, 0, 0, 0);
                al_flip_display();
                return true;

            }
            else if (strcmp(Allegro, "Player Fires") == 0){

                memset(Allegro, '\0', sizeof(Allegro));
                PlayerShootsDummy(Table, Dummy, Player, Playerfires, Playerflash);
                return true;
            } else if (strcmp(Allegro, "Shoot Yourself") == 0){

                memset(Allegro, '\0', sizeof(Allegro));
                PlayerShootsPlayer();
                return true;
            }
            else if (strcmp(Allegro, "Dummy Fires") == 0){
                memset(Allegro, '\0', sizeof(Allegro));
                DummyShootsPlayer(Table, Dummyfires, Player, Dummyflash);
                return true;
            }
            else if (strcmp(Allegro, "Game Ends") == 0){
                RunEvent = false;
                al_destroy_bitmap(Table);
                al_destroy_display(display);
                return true;
            }
            else if (strcmp(Allegro, "Shop Screen") == 0){
                ShopScreen();
                return true;
            }
        }
        else{
        al_clear_to_color(al_map_rgb(0, 0, 0));
        NormalScreenDraws(0);
        al_draw_bitmap(Player, 0, 0, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        NormalScreenDraws(0);
        al_draw_bitmap(Player, 0, 0, 0);
        al_flip_display();
        }
    return true;
}
