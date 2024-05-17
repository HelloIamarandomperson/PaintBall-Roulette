//Including the other file
#include "Headers.h"

int Button() {




    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_draw_rectangle(0, 600, 200, 800, al_map_rgb(200, 200, 0), 10);
    // first 2 is coords for the top vertices's's, next 2 is for the bottom one.
    al_flip_display();

    while (RunEvent) {
        ALLEGRO_EVENT ButtonEvent;
        al_wait_for_event(event_queue, & ButtonEvent);
        if (ButtonEvent.mouse.x >= 0 && ButtonEvent.mouse.y >= 600 && ButtonEvent.mouse.x <= 200 && ButtonEvent.mouse.y <= 800 && ButtonEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            RunEvent = false;
        }
    }
    return 0;
}
