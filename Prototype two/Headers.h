#include <stdio.h> // Standard input/output functions
#include <stdlib.h> // General utilities
#include <string.h> // String manipulation functions
#include <time.h>
#include <ctype.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

struct inventory {
    //struct inventory is used to store the inventory of the player and the opponent.
    int Money = 0;
    int DoubleBullet = 0;
};







const float FPS = 60;
const int SCREEN_W = 800;       // screen width
const int SCREEN_H = 800 ;       // screen height
void checkMag(int & slots, char cylinder[]);
char PlayerChoice();
void LoadRandomBullets(int & bullets, int & slots, char cylinder[], int & reload);
bool OpponentDummyTurn(bool & nextTurnIsPlayer, int & chamber, char cylinder[], int & OpponentHealth, int & slots, int & yourHealth, int & bullets, int & reload);
bool checkIfGameCont(int & OpponentHealth, int & yourHealth);
void PlayerShootsOpponent(bool &nextTurnIsPlayer, int &chamber, char cylinder[], int &OpponentHealth);
bool Playerturn(int &yourHealth, int &OpponentHealth, char cylinder[], int &chamber, bool &nextTurnIsPlayer, inventory &PlayerInventory);
int AllegroMain();
int Button(char cylinder[], int &chamber);
void DummyShootsPlayer(ALLEGRO_BITMAP *Table, ALLEGRO_BITMAP *Dummyfires, ALLEGRO_BITMAP *Player, ALLEGRO_BITMAP *Dummyflash);
void PlayerShootsDummy(ALLEGRO_BITMAP *Table, ALLEGRO_BITMAP *Dummy, ALLEGRO_BITMAP *Player, ALLEGRO_BITMAP *Playerfires, ALLEGRO_BITMAP *Playerflash);
bool frameOfGame();
