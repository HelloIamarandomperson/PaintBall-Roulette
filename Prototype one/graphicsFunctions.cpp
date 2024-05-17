
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

char Allegro[50] = {'\0'};


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
