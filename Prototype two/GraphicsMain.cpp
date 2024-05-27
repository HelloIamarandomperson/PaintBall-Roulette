//Including the other files
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
ALLEGRO_EVENT ButtonEvent;
int AllegroMain() {
	// Initialize Allegro

	// Initialize display
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
 	al_set_window_title(display, "PaintBall Roulette");

	// Initialize image add on
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	// Declare the bitmaps setting it's initial value to nullptr


    // Create a display
    // Load the background image
    Table = al_load_bitmap("Table.png");
    Dummy = al_load_bitmap("Dummy.png");
    Player = al_load_bitmap("Player.png");
    Dummyfires = al_load_bitmap("Dummyshoot.png");
    Dummyflash = al_load_bitmap("DummyFlash.png");
    Playerfires = al_load_bitmap("PlayerGun.png");
    Playerflash = al_load_bitmap("PlayerFlash.png");
    Buttons = al_load_bitmap("buttons.png");

    //check if images are missing
    if (!Table  || !Dummy || !Player || !Dummyfires || !Dummyflash || !Playerflash || !Playerfires || !Buttons) {
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                    nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }
    //Start up phase.
    al_rest(1.0);
    al_draw_bitmap(Table, 0, 0, 0);
    al_flip_display();
    al_rest(.2);
    al_draw_bitmap(Dummy, 0, 0, 0);
    al_flip_display();
    al_rest(.2);
    al_draw_bitmap(Player, 0, 0, 0);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_rest(.2);
    al_draw_bitmap(Buttons, 0, 600, 0);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));


    frameOfGame();



    return 0;
}

