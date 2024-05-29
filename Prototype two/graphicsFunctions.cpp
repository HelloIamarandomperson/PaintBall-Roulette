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

extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_EVENT eventOrder;

extern char Allegro[50]; // Declaration of the global variable
extern bool RunEvent;
extern int OpponentHealth;
extern bool nextTurnIsPlayer; //whos turn it is next (0 is the player, 1 is next person, etc...)
extern int chamber;
extern char cylinder[];
extern char response;
extern ALLEGRO_EVENT ButtonEvent;
extern int OpX;
extern int OpY;
extern int currentOp;


ALLEGRO_MOUSE_STATE state;

void SwitchOp(){
    currentOp++;
    if (currentOp == 1){
        Dummy = al_load_bitmap("ImageFile\\GhostlyCharacter.png");
        OpX = 175;
        OpY = 75;
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
    al_draw_bitmap(PlayerSelf1, 0, 0, 0);
    al_draw_bitmap(Dummy, OpX, OpY, 0);
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    al_draw_bitmap(Buttons, 0, 600, 0);
    al_flip_display();
    al_rest(.8);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Dummy, OpX, OpY, 0);
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(PlayerSelf2, 0, 0, 0);
    al_draw_bitmap(Buttons, 0, 600, 0);
    al_flip_display();
    al_rest(.9);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Dummy, OpX, OpY, 0);
    al_draw_bitmap(Table, 0, 0, 0);
    if (cylinder[chamber-1] == 'B') {
        al_draw_bitmap(PlayerSelf3, 0, 0, 0);
    } else{
        al_draw_bitmap(PlayerSelf2, 0, 0, 0);
    }

    al_draw_bitmap(Buttons, 0, 600, 0);
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
    al_draw_bitmap(Dummyfires, OpX, OpY, 0);
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    al_draw_bitmap(Buttons, 0, 600, 0);
    al_flip_display();
    al_rest(.9);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Dummyfires, OpX, OpY, 0);
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    if (cylinder[chamber-1] == 'B') {
        al_draw_bitmap(Dummyflash, 0, 0, 0);
    }
    al_draw_bitmap(Buttons, 0, 600, 0);
    al_flip_display();
    al_rest(.3);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Dummyfires, OpX, OpY, 0);
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    al_draw_bitmap(Buttons, 0, 600, 0);
    al_flip_display();
    al_rest(.4);

}
void PlayerShootsDummy(ALLEGRO_BITMAP *Table, ALLEGRO_BITMAP *Dummy, ALLEGRO_BITMAP *Player, ALLEGRO_BITMAP *Playerfires, ALLEGRO_BITMAP *Playerflash){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Dummy, OpX, OpY, 0);
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Playerfires, 0, 0, 0);
    al_draw_bitmap(Buttons, 0, 600, 0);
    al_flip_display();
    al_rest(.9);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Dummy, OpX, OpY, 0);
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Playerfires, 0, 0, 0);
    if (cylinder[chamber-1] == 'B') {
        al_draw_bitmap(Playerflash, 0, 0, 0);
    }
    al_draw_bitmap(Buttons, 0, 600, 0);
    al_flip_display();
    al_rest(.3);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Dummy, OpX, OpY, 0);
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Playerfires, 0, 0, 0);
    al_draw_bitmap(Buttons, 0, 600, 0);
    al_flip_display();
    al_rest(.4);
}

bool frameOfGame(){
    if (Allegro[0] != '\0'){
            if (strcmp(Allegro, "Player Is Choosing") == 0){
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_draw_bitmap(Dummy, OpX, OpY, 0);
                al_draw_bitmap(Table, 0, 0, 0);
                al_draw_bitmap(Player, 0, 0, 0);
                al_draw_bitmap(Buttons, 0, 600, 0);
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
        al_draw_bitmap(Dummy, OpX, OpY, 0);
        al_draw_bitmap(Table, 0, 0, 0);
        al_draw_bitmap(Player, 0, 0, 0);
        al_draw_bitmap(Buttons, 0, 600, 0);
        al_flip_display();
        //Button(cylinder, chamber);
        // Clean up
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(Dummy, OpX, OpY, 0);
        al_draw_bitmap(Table, 0, 0, 0);
        al_draw_bitmap(Player, 0, 0, 0);
        al_draw_bitmap(Buttons, 0, 600, 0);
        al_flip_display();
        //Button(cylinder, chamber);
        }
    return true;
}
