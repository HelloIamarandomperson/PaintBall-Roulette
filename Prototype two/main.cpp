// Including standard libraries

// Including the other files
#include "Headers.h"

inventory PlayerInventory;
char Allegro[50]; // Declaration of the global variable
bool RunEvent = true;
int yourHealth = 5;
int OpponentHealth = 3;
bool nextTurnIsPlayer = true; //whos turn it is next (0 is the player, 1 is next person, etc...)
bool yourTurn;
int slots = 6;
int bullets;
int reload;
char cylinder[6];
char response;
bool Gamerun = true;
int chamber;
int currentOp;
int OpX = 0;
int OpY = 0;


// Creating the thread.
ALLEGRO_TIMER * timer = nullptr;
ALLEGRO_DISPLAY * display = nullptr;
ALLEGRO_BITMAP * Table = nullptr;
ALLEGRO_BITMAP * Dummy = nullptr;
ALLEGRO_BITMAP * Player = nullptr;
ALLEGRO_BITMAP * Dummyfires = nullptr;
ALLEGRO_BITMAP * Dummyflash = nullptr;
ALLEGRO_BITMAP * Playerfires = nullptr;
ALLEGRO_BITMAP * Playerflash = nullptr;
ALLEGRO_BITMAP * Buttons = nullptr;
ALLEGRO_BITMAP *PlayerSelf1 = nullptr;
ALLEGRO_BITMAP *PlayerSelf2 = nullptr;
ALLEGRO_BITMAP *PlayerSelf3 = nullptr;
ALLEGRO_BITMAP *Shop = nullptr;

ALLEGRO_EVENT_QUEUE * event_queue = nullptr;
ALLEGRO_EVENT eventOrder;
int main() {
    chamber = 0;
    // Initializing the variables
    al_init();
    al_init_primitives_addon();
    al_install_mouse();

    event_queue = al_create_event_queue();

    timer = al_create_timer(1 / FPS);

    al_start_timer(timer);
    if (!timer) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create timer!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    //al_get_mouse_event_source();
    char cylinder[slots];
    srand(time(NULL));

    AllegroMain();

    // Load the bullets randomly into the cylinder
    LoadRandomBullets(bullets, slots, reload);

    checkMag(slots); // Print the updated cylinder (for dev purposes)
    // whos turn it is next (0 is the player, 1 is
    // next person, etc...)
    // round 1

    while (Gamerun == true) {
        // While true for a convenient infinite loop that can only be broken
        // with breaks.
        // For loop for until chamber is empty.
        if (nextTurnIsPlayer == true) {
            // if next player is supposed to be the player it sets the
            // variable to true.
            yourTurn = true;
        } else {
            // else it is the opponents turn
            yourTurn = false;
        }
        if (yourTurn == true) {
            // if it is the players turn.
            if (Playerturn(yourHealth, OpponentHealth, chamber, nextTurnIsPlayer, PlayerInventory) == true) {
                // Function for player's turn.
            }
        } else {
            // If not player turn
            if (OpponentDummyTurn(nextTurnIsPlayer, OpponentHealth, slots, yourHealth, bullets, reload) == false) {
                // run function for the opponents turn
                nextTurnIsPlayer = true;
            }
        }
        frameOfGame();

        if (checkIfGameCont(OpponentHealth, yourHealth) == false) {
            // if the game should have ended the game ends
            break;
        }

        fflush(stdin);
        // fflush to fix a bug.

        if (chamber == slots) {
            LoadRandomBullets(bullets, slots, reload);
            // If the code gets here then the cylinder is empty so I reload here
            checkMag(slots);
            // checkMag is for dev pourposes only and shows the inside of the
            // maganzine
        }

    }
    strcpy(Allegro, "Game Ends");
    // Runs command ending allegro
    // ends thread.
}
