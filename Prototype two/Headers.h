#include <stdio.h> // Standard input/output functions
#include <stdlib.h> // General utilities
#include <string.h> // String manipulation functions
#include <time.h>
#include <ctype.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h> //for card
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h> //images
#include <stdlib.h>
struct inventory {
    //struct inventory is used to store the inventory of the player and the opponent.
    int Money = 0;
    int DoubleBullet = 0;
};

const float FPS = 120;
const int SCREEN_W = 800;       // screen width
const int SCREEN_H = 800 ;       // screen height
void checkMag(int &slots);
char PlayerChoice();
void LoadRandomBullets(int &bullets, int &slots, int &reload);
bool OpponentDummyTurn(bool &nextTurnIsPlayer, int &OpponentHealth, int &yourHealth, int &reload);
bool checkIfGameCont(int & OpponentHealth, int & yourHealth);
void PlayerShootsOpponent(bool &nextTurnIsPlayer, int &chamber, int &OpponentHealth);
void PlayerShootsThemselves(bool &nextTurnIsPlayer, int &chamber, int &yourHealth, inventory PlayerInventory);


bool Playerturn(int &yourHealth, int &OpponentHealth, int &chamber, bool &nextTurnIsPlayer, inventory &PlayerInventory);
int AllegroMain();
int Button(char cylinder[], int &chamber);
void DummyShootsPlayer(ALLEGRO_BITMAP *Table, ALLEGRO_BITMAP *Dummyfires, ALLEGRO_BITMAP *Player, ALLEGRO_BITMAP *Dummyflash);
void PlayerShootsDummy(ALLEGRO_BITMAP *Table, ALLEGRO_BITMAP *Dummy, ALLEGRO_BITMAP *Player, ALLEGRO_BITMAP *Playerfires, ALLEGRO_BITMAP *Playerflash);
bool frameOfGame();
