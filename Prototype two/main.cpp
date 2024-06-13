#include "Headers.h"

// Global variables
inventory PlayerInventory;
char EventHandler[50];
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
int chamber = 0;
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
ALLEGRO_BITMAP *Zero = nullptr;
ALLEGRO_BITMAP *One = nullptr;
ALLEGRO_BITMAP *Two = nullptr;
ALLEGRO_BITMAP *Three = nullptr;
ALLEGRO_BITMAP *Four = nullptr;
ALLEGRO_BITMAP *Five = nullptr;
ALLEGRO_BITMAP *Six = nullptr;
ALLEGRO_BITMAP *Seven = nullptr;
ALLEGRO_BITMAP *Eight = nullptr;
ALLEGRO_BITMAP *Nine = nullptr;
ALLEGRO_BITMAP *Ball = nullptr;
ALLEGRO_BITMAP *BallEmpty = nullptr;
ALLEGRO_BITMAP *OpHeart = nullptr;
ALLEGRO_BITMAP *ShootSelfButton = nullptr;
ALLEGRO_BITMAP *ShootOpButton = nullptr;


//Allegro event related pointers
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_EVENT eventOrder;

int main() {
    //run installs for Allegro
    al_init();
    al_init_primitives_addon();
    al_install_mouse();
    //Makes a event event_queue and a timer then sets its fps to the FPS set in header.h
    event_queue = al_create_event_queue();
    timer = al_create_timer(1 / FPS);
    //starts the timer
    al_start_timer(timer);
    if (!timer) {
        //if timer breaks, then send message
        al_show_native_message_box(display, "Error", "Error", "Failed to create timer!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    //Registers the event source such as the timer and the mouse.
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    //Initalizes randomness
    srand(time(NULL));
    //Runs AllegroMain
    AllegroMain();

    // Load the bullets randomly into the cylinder
    LoadRandomBullets(bullets, slots, reload);
    //checkMag(slots); // For development purposes, basically it tells command prompt what the chambers contain.

    while (Gamerun) {
        //main gameloop and the single while loop allowed by event handlers, everything in the gameplay happens in here.
        if (nextTurnIsPlayer) {
            //Checks if the next turn is supposed to be the players turn, if so their turn will be played, else make it so the opponent gets played
            yourTurn = true;
        } else {
            yourTurn = false;
        }
        if (yourTurn) {
            if (Playerturn(yourHealth, OpponentHealth, chamber, nextTurnIsPlayer, PlayerInventory)) {
                //Player's turn logic
            }
        } else {
            if (!OpponentDummyTurn(nextTurnIsPlayer, OpponentHealth, yourHealth, reload)) {
                //Opponent's turn logic
                nextTurnIsPlayer = true;
            }
        }
        //Runs frame of game, this is the function that contains the visual things that happen on screen
        frameOfGame();

        if (!checkIfGameCont(OpponentHealth, yourHealth)) {
            //This checks if the game should continue, else end the main gameloop.
            break;
        }
        if (chamber == slots) {
            //if chamber hits the end of the slots, reload the chamber which resets the chamber to zero.
            LoadRandomBullets(bullets, slots, reload);
            //checkMag(slots); // For development purposes, basically it tells command prompt what the chambers contain.
        }
    }

    strcpy(EventHandler, "Game Ends");
}
