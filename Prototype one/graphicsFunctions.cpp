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
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_EVENT eventOrder;

extern char Allegro[50]; // Declaration of the global variable
extern bool RunEvent;
extern int OpponentHealth;
extern bool nextTurnIsPlayer; //whos turn it is next (0 is the player, 1 is next person, etc...)
extern int chamber;
extern char cylinder[];
extern char response;

int Button(char cylinder[], int &chamber) {
    printf("t");
    // first 2 is coords for the top vertices's's, next 2 is for the bottom one.
    al_wait_for_event(event_queue, &eventOrder);
    if (eventOrder.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
        printf("AAAAAAAAAAAAAAAAA");
    }

    if (eventOrder.mouse.x >= 0 && eventOrder.mouse.y >= 600 && eventOrder.mouse.x <= 200 && eventOrder.mouse.y <= 800 && eventOrder.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

        PlayerShootsOpponent(nextTurnIsPlayer, chamber, cylinder, OpponentHealth);
        response = 'o';
        strcpy(Allegro, "Button Pressed");
    }
    return 0;
}



void DummyShootsPlayer(ALLEGRO_BITMAP *Table, ALLEGRO_BITMAP *Dummyfires, ALLEGRO_BITMAP *Player, ALLEGRO_BITMAP *Dummyflash){
    memset(Allegro, '\0', sizeof(Allegro));
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Dummyfires, 0, 0, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    al_flip_display();
    al_rest(.9);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Dummyfires, 0, 0, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    al_draw_bitmap(Dummyflash, 0, 0, 0);
    al_flip_display();
    al_rest(.3);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Dummyfires, 0, 0, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    al_flip_display();
    al_rest(.4);

}
void PlayerShootsDummy(ALLEGRO_BITMAP *Table, ALLEGRO_BITMAP *Dummy, ALLEGRO_BITMAP *Player, ALLEGRO_BITMAP *Playerfires, ALLEGRO_BITMAP *Playerflash){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Dummy, 0, 0, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    al_draw_bitmap(Playerfires, 0, 0, 0);
    al_flip_display();
    al_rest(.9);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Dummy, 0, 0, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    al_draw_bitmap(Playerfires, 0, 0, 0);
    al_draw_bitmap(Playerflash, 0, 0, 0);
    al_flip_display();
    al_rest(.3);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(Table, 0, 0, 0);
    al_draw_bitmap(Dummy, 0, 0, 0);
    al_draw_bitmap(Player, 0, 0, 0);
    al_draw_bitmap(Playerfires, 0, 0, 0);
    al_flip_display();
    al_rest(.4);
}

bool frameOfGame(){
    if (Allegro[0] != '\0'){

            if (strcmp(Allegro, "Player Is Choosing") == 0){
                al_wait_for_event(event_queue, &eventOrder);
                Button(cylinder, chamber);
                return true;

            }
            else if (strcmp(Allegro, "Dummy Fires") == 0){
                memset(Allegro, '\0', sizeof(Allegro));
                DummyShootsPlayer(Table, Dummyfires, Player, Dummyflash);
                return true;
            }
            else if (strcmp(Allegro, "Player Fires") == 0){
                memset(Allegro, '\0', sizeof(Allegro));
                PlayerShootsDummy(Table, Dummy, Player, Playerfires, Playerflash);
                return true;
            }
            else if (strcmp(Allegro, "Game Ends") == 0){
                RunEvent = false;
                al_destroy_bitmap(Table);
                al_destroy_display(display);
                return true;

            }
        }
        else{
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(Table, 0, 0, 0);
        al_draw_bitmap(Dummy, 0, 0, 0);
        al_draw_bitmap(Player, 0, 0, 0);
        al_draw_bitmap(Buttons, 0, 600, 0);
        al_flip_display();
        //Button(cylinder, chamber);
        // Clean up
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(Table, 0, 0, 0);
        al_draw_bitmap(Dummy, 0, 0, 0);
        al_draw_bitmap(Player, 0, 0, 0);
        al_draw_bitmap(Buttons, 0, 600, 0);
        al_flip_display();
        //Button(cylinder, chamber);
        }
    return true;
}
