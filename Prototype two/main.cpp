#include "Headers.h"

// Global variables
inventory PlayerInventory;
char Allegro[50];
bool RunEvent = true;
int yourHealth = 5;
int OpponentHealth = 3;
bool nextTurnIsPlayer = true;
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

// Allegro related pointers
ALLEGRO_TIMER *timer = nullptr;
ALLEGRO_DISPLAY *display = nullptr;
ALLEGRO_BITMAP *Table = nullptr;
ALLEGRO_BITMAP *Dummy = nullptr;
ALLEGRO_BITMAP *Player = nullptr;
ALLEGRO_BITMAP *Dummyfires = nullptr;
ALLEGRO_BITMAP *Dummyflash = nullptr;
ALLEGRO_BITMAP *Playerfires = nullptr;
ALLEGRO_BITMAP *Playerflash = nullptr;
ALLEGRO_BITMAP *Buttons = nullptr;
ALLEGRO_BITMAP *PlayerSelf1 = nullptr;
ALLEGRO_BITMAP *PlayerSelf2 = nullptr;
ALLEGRO_BITMAP *PlayerSelf3 = nullptr;
ALLEGRO_BITMAP *Shop = nullptr;
ALLEGRO_BITMAP *BlankBulletCounter = nullptr;
ALLEGRO_BITMAP *FullBulletCounter = nullptr;
ALLEGRO_BITMAP *IndividualBulletForCounter = nullptr;
ALLEGRO_BITMAP *InventoryButton = nullptr;
ALLEGRO_BITMAP *ShopButton = nullptr;


ALLEGRO_BITMAP *HealthBar1 = nullptr;
ALLEGRO_BITMAP *HealthBar2 = nullptr;
ALLEGRO_BITMAP *HealthBar3 = nullptr;
ALLEGRO_BITMAP *HealthBar4 = nullptr;
ALLEGRO_BITMAP *HealthBar5 = nullptr;





ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_EVENT eventOrder;

int main() {
    chamber = 0;
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

    srand(time(NULL));
    AllegroMain();

    // Load the bullets randomly into the cylinder
    LoadRandomBullets(bullets, slots, reload);
    checkMag(slots); // For development purposes

    while (Gamerun) {
        if (nextTurnIsPlayer) {
            yourTurn = true;
        } else {
            yourTurn = false;
        }

        if (yourTurn) {
            if (Playerturn(yourHealth, OpponentHealth, chamber, nextTurnIsPlayer, PlayerInventory)) {
                // Player's turn logic
            }
        } else {
            if (!OpponentDummyTurn(nextTurnIsPlayer, OpponentHealth, slots, yourHealth, bullets, reload)) {
                nextTurnIsPlayer = true;
            }
        }

        frameOfGame();

        if (!checkIfGameCont(OpponentHealth, yourHealth)) {
            break;
        }

        fflush(stdin);

        if (chamber == slots) {
            LoadRandomBullets(bullets, slots, reload);
            checkMag(slots);
        }
    }

    strcpy(Allegro, "Game Ends");
}
