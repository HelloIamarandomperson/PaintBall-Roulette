

// You must include the allegro header files
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
const int SCREEN_W = 800;       // screen width
const int SCREEN_H = 600 ;       // screen height

DWORD WINAPI BitmapTest(LPVOID lpParam) {
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

	// Declare a BITMAP called image, setting it's initial value to nullptr
	ALLEGRO_BITMAP *image = nullptr;

	// Initialize Allegro

    // Create a display
    // Load the background image
    image = al_load_bitmap("backgroundTable.png");
    if (!image) {
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
    al_rest(3.0);

    while (true){
        al_rest(1.0); // Wait for 5 seconds
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(image, 0, 5, 0);
        al_flip_display();
    // Clean up
        al_rest(1.0); // Wait for 5 seconds
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(image, 0, 0, 0);
        al_flip_display();

    }
    al_destroy_bitmap(image);
    al_destroy_display(display);

    return 0;
}
