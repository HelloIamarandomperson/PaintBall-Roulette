
// Including standard libraries

// Including the other files
#include "functions.cpp"

// Creating the thread.

int main() {
    // Initializing the variables
    al_init();
    al_init_primitives_addon();
    al_install_mouse();

    event_queue = al_create_event_queue();

    timer = al_create_timer(1 / FPS);
    if (!timer) {
        al_show_native_message_box(display, "Error", "Error","Failed to create timer!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    al_get_mouse_event_source();
    char cylinder[slots];
    srand(time(NULL));

    // making the variables needed for the thread
    // making the thread.
    AllegroMain();
    // If thread does not run make error message


    // Load the bullets randomly into the cylinder
    LoadRandomBullets(bullets, slots, cylinder, reload);

    checkMag(slots, cylinder);  // Print the updated cylinder (for dev purposes)
                                // whos turn it is next (0 is the player, 1 is
                                // next person, etc...)
    // round 1
    int chamber = 0;
    while (Gamerun == true) {
        ALLEGRO_EVENT eventOrder;
        al_wait_for_event(event_queue, &eventOrder);
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
                    if (Playerturn(yourHealth, OpponentHealth, cylinder, chamber, nextTurnIsPlayer, PlayerInventory) == false) {
                        // Function for player's turn.
                    }
                }
                if (yourTurn == false) {
                    // If not player turn
                    if (OpponentDummyTurn(nextTurnIsPlayer, chamber, cylinder, OpponentHealth, slots, yourHealth, bullets, reload) == false) {
                        // run function for the opponents turn
                        nextTurnIsPlayer = true;
                    }
            }
            if (checkIfGameCont(OpponentHealth, yourHealth) == false) {
                // if the game should have ended the game ends
                break;
            }

            frameOfGame();

            fflush(stdin);
            // fflush to fix a bug.

            if (chamber == slots){
                LoadRandomBullets(bullets, slots, cylinder, reload);
                // If the code gets here then the cylinder is empty so I reload here
                checkMag(slots, cylinder);
                // checkMag is for dev pourposes only and shows the inside of the
                // maganzine
            }
            chamber++;

    }
    strcpy(Allegro, "Game Ends");
    // Runs command ending allegro
    // ends thread.
}
