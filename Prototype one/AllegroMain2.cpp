

#include "Headers.h"

// You must include the allegro header files
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
const int SCREEN_W = 800;       // screen width
const int SCREEN_H = 600 ;       // screen height

char Allegro[50] = {'\0'};

DWORD WINAPI AllegroMain(LPVOID lpParam) {
    memset(Allegro, '\0', sizeof(Allegro));
    char* AllegroAction = reinterpret_cast<char*>(lpParam);
    //memset(AllegroAction, 't', sizeof(AllegroAction));
    //for (int i = 0; i < sizeof(AllegroAction); i++){
    //    printf("%c", AllegroAction[i]);
    //}

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

    // Create a display
    // Load the background image
    Table = al_load_bitmap("Table.png");
    Dummy = al_load_bitmap("Dummy.png");
    Player = al_load_bitmap("Player.png");
    Dummyfires = al_load_bitmap("Dummyshoot.png");
    Dummyflash = al_load_bitmap("DummyFlash.png");
    if (!Table  || !Dummy || !Player || !Dummyfires || !Dummyflash) {
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
            if (strcmp(Allegro, "Dummy fires")){
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
            else if (strcmp(Allegro, "Player fires")){

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
