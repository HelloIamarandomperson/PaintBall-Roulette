
#include <windows.h>
#include "Headers.h"
#include "graphicsFunctions.cpp"

// You must include the allegro header files

const int SCREEN_W = 800;       // screen width
const int SCREEN_H = 600 ;       // screen height


void DummyShootsPlayer(ALLEGRO_BITMAP *Table, ALLEGRO_BITMAP *Dummyfires, ALLEGRO_BITMAP *Player, ALLEGRO_BITMAP *Dummyflash);
DWORD WINAPI AllegroMain(LPVOID lpParam) {

	ALLEGRO_DISPLAY *display = nullptr;
	// Initialize Allegro
	al_init();

	// Initialize display
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
 	al_set_window_title(display, "Allegro gamescreen");

	// Initialize image add on
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	// Declare the bitmaps setting it's initial value to nullptr
	ALLEGRO_BITMAP *Table = nullptr;
    ALLEGRO_BITMAP *Dummy = nullptr;
    ALLEGRO_BITMAP *Player = nullptr;
    ALLEGRO_BITMAP *Dummyfires = nullptr;
    ALLEGRO_BITMAP *Dummyflash = nullptr;
    ALLEGRO_BITMAP *Playerfires = nullptr;
    ALLEGRO_BITMAP *Playerflash = nullptr;

    // Create a display
    // Load the background image
    Table = al_load_bitmap("Table.png");
    Dummy = al_load_bitmap("Dummy.png");
    Player = al_load_bitmap("Player.png");
    Dummyfires = al_load_bitmap("Dummyshoot.png");
    Dummyflash = al_load_bitmap("DummyFlash.png");
    Playerfires = al_load_bitmap("PlayerGun.png");
    Playerflash = al_load_bitmap("PlayerFlash.png");


    if (!Table  || !Dummy || !Player || !Dummyfires || !Dummyflash || !Playerflash || !Playerfires) {
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                    nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }

    // Optionally clear the display
    //al_clear_to_color(al_map_rgb(0, 0, 0));

    // Draw the background image
    //al_draw_bitmap(image, 0, 0, 0); // Draw at top-left corner with no rotation

    // Optionally wait for user input
    // al_wait_for_event(event_queue, &event);

    // Update the display
    //al_flip_display();

    // Wait for aq short time (adjust as needed)
    //al_rest(3.0); // Wait for 5 seconds
    //al_clear_to_color(al_map_rgb(0, 0, 0));
    //al_draw_bitmap(image, 50, 0, 0);
    //al_flip_display();
    // Clean up



    //al_draw_bitmap(Dummyfires, 0, 0, 0);
    //al_draw_bitmap(Dummyflash, 0, 0, 0);


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
    while (true){
        if (Allegro[0] != '\0'){
            if (strcmp(Allegro, "Dummy Fires") == 0){
                DummyShootsPlayer(Table, Dummyfires, Player, Dummyflash);
            }
            else if (strcmp(Allegro, "Player Fires") == 0){
                memset(Allegro, '\0', sizeof(Allegro));
                PlayerShootsDummy(Table, Dummy, Player, Playerfires, Playerflash);
            }
            else if (strcmp(Allegro, "Game Ends") == 0){
                break;
            }
        }
        else{
        al_rest(0); // Wait for 1 second
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(Table, 0, 0, 0);
        al_draw_bitmap(Dummy, 0, 0, 0);
        al_draw_bitmap(Player, 0, 0, 0);
        al_flip_display();
    // Clean up
        al_rest(.1); // Wait for 1 second
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(Table, 0, 0, 0);
        al_draw_bitmap(Dummy, 0, 0, 0);
        al_draw_bitmap(Player, 0, 0, 0);
        al_flip_display();

        }
    }
    al_destroy_bitmap(Table);
    al_destroy_display(display);

    return 0;
}

