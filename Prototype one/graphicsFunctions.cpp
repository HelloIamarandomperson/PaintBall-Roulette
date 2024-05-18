//Including the other file
#include "Headers.h"

void PlayerShootsOpponent(bool &nextTurnIsPlayer, int &chamber, char cylinder[], int &OpponentHealth);
int Button(char cylinder[], int &chamber) {
    RunEvent = true;
    // first 2 is coords for the top vertices's's, next 2 is for the bottom one.
    while (RunEvent){
        ALLEGRO_EVENT ButtonEvent;
        al_wait_for_event(event_queue, &ButtonEvent);
        if (ButtonEvent.mouse.x >= 0 && ButtonEvent.mouse.y >= 600 && ButtonEvent.mouse.x <= 200 && ButtonEvent.mouse.y <= 800 && ButtonEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            PlayerShootsOpponent(nextTurnIsPlayer, chamber, cylinder, OpponentHealth);
            RunEvent = false;
            response = 'o';
        }
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
