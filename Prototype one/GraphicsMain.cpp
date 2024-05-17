//Including the other files
#include "graphicsFunctions.cpp"

DWORD WINAPI AllegroMain(LPVOID lpParam) {

	// Initialize Allegro
	al_init();
	al_init_primitives_addon();
    al_install_mouse();

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

    //check if images are missing
    if (!Table  || !Dummy || !Player || !Dummyfires || !Dummyflash || !Playerflash || !Playerfires) {
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                    nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }


    // Optionally wait for user input
    // al_wait_for_event(event_queue, &event);

    Button();

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

