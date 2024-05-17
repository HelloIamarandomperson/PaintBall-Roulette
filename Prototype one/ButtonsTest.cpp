
#include "Headers.h"
//This code checks whether the mouse is within the bounds of the yellow square that has been drawn and checks whether it has been clicked
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

int Button() {


  ALLEGRO_EVENT_QUEUE * event_queue = nullptr;
  bool select = false;

  event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_mouse_event_source());

  al_clear_to_color(al_map_rgb(0, 0, 0));\
  al_draw_rectangle(500, 500, 800, 800, al_map_rgb(200, 200, 0), 10);
  // first 2 is coords for the top vertices's's, next 2 is for the bottom one.
  al_flip_display();

  while (!select) {
    ALLEGRO_EVENT ButtonEvent;
    al_wait_for_event(event_queue, & ButtonEvent);
    if (ButtonEvent.mouse.x >= 500 && ButtonEvent.mouse.y >= 500 && ButtonEvent.mouse.x <= 800 && ButtonEvent.mouse.y <= 800 && ButtonEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
      printf("Hooray!(%d, %d)", ButtonEvent.mouse.x, ButtonEvent.mouse.y);
      select = true;
    } else if (ButtonEvent.mouse.x >= 500 && ButtonEvent.mouse.y >= 500 && ButtonEvent.mouse.x <= 800 && ButtonEvent.mouse.y <= 800)
      printf("(%d, %d)", ButtonEvent.mouse.x, ButtonEvent.mouse.y);
  }

  return 0;
}
