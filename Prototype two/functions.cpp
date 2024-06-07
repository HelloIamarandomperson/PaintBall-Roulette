#include "Headers.h"
//Including header.h

extern char EventHandler[50];
extern char response;
extern int chamber;
extern char cylinder[6];
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_BITMAP *Table;
extern ALLEGRO_BITMAP *Dummy;
extern ALLEGRO_BITMAP *Player;
extern ALLEGRO_BITMAP *Dummyfires;
extern ALLEGRO_BITMAP *Dummyflash;
extern ALLEGRO_BITMAP *Playerfires;
extern ALLEGRO_BITMAP *Playerflash;
extern ALLEGRO_BITMAP *Buttons;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_EVENT eventOrder;
extern ALLEGRO_EVENT ButtonEvent;
extern int slots;
extern int bullets;

void checkMag(int &slots) {
    //This is a dev function to check the Mag inside
    printf("\n");
    for (int i = 0; i < slots; i++) {
        if (cylinder[i] == '\0') {
            printf("0 ");
        } else {
            printf("%c ", cylinder[i]);
        }
    }
    printf("\n");
}

char PlayerChoice() {
    //PlayerChoice is a function that checks if player has asked to do something tells the game the proper response
    strcpy(EventHandler, "Player Is Choosing");
    al_wait_for_event(event_queue, &ButtonEvent);
    Button(cylinder, chamber);
    if (strcmp(EventHandler, "Shoot the Opponent") == 0){
        memset(EventHandler, '\0', sizeof(EventHandler));
        response = 'o';
    } else if (strcmp(EventHandler, "Shoot Yourself") == 0){
        memset(EventHandler, '\0', sizeof(EventHandler));
        response = 's';
    } else if (strcmp(EventHandler, "Go To Shop") == 0){
        memset(EventHandler, '\0', sizeof(EventHandler));
        //Since shop doesn't have items due to lack of assets, it is useless and so for now dosn't do anything.
        //response = 'p';
        response = '\0';
    }
    else{
        response = '\0';
    }
    return response;
}

void LoadRandomBullets(int &bullets, int &slots, int &reload) {
    //Load Random Bullets is designed to load the bullets randomly
    bullets = rand() % (slots);
    //randomizes bullet count.
    memset(cylinder, '\0', slots);
    //Sets cylinder to only NULLs. This clears the bullets in the last chamber
    for (int i = 0; i < bullets; i++) {
        //randomizes the Mag.
        reload = rand() % slots;
        if (cylinder[reload] == '\0') {
            cylinder[reload] = 'B';
        } else {
            i--;
        }
    }
    chamber = 0;
}

void LoadInventoryBullet(int &reload) {
    //Load Random Bullets is designed to load the bullets randomly
    bullets = rand() % (slots);
    //randomizes bullet count.
    memset(cylinder, '\0', slots);
    //Sets cylinder to only NULLs. This clears the bullets in the last chamber
    for (int i = 0; i < bullets; i++) {
        //randomizes the Mag.
        reload = rand() % slots;
        if (cylinder[reload] == '\0') {
            cylinder[reload] = 'B';
        } else {
            i--;
        }
    }
    chamber = 0;
}

bool OpponentDummyTurn(bool &nextTurnIsPlayer, int &OpponentHealth, int &yourHealth, int &reload) {
    int whoTheyShootin = 1; //rand() % (2); //1 is player, 2 is opponent
    if (whoTheyShootin == 1) {
        nextTurnIsPlayer = true;
        strcpy(EventHandler, "Dummy Fires");
        if (cylinder[chamber] == 'B') {
            //If chamber contains bullet.
            bullets--;
            yourHealth--;
        }
    }
    chamber++;
    nextTurnIsPlayer = true;
    return false;
}

bool checkIfGameCont(int &OpponentHealth, int &yourHealth) {
    //checks if both are alive, else returns false.
    if (yourHealth <= 0) {
        return false;
    } else if (OpponentHealth <= 0) {
        return false;
    }
    return true;
}

void PlayerShootsOpponent(bool &nextTurnIsPlayer, int &chamber, int &OpponentHealth){
    //Makes it so the screen shows the player shooting.
    //if the player shoots the opponent
    nextTurnIsPlayer = false;
    //make it so the Opponents turn is next.

    if (cylinder[chamber] == 'B') {
        //If chamber contains bullet opponent loses health.
        bullets--;
        OpponentHealth--;
    }
    chamber++;
    strcpy(EventHandler, "Player Fires");
}

void PlayerShootsThemselves(bool &nextTurnIsPlayer, int &chamber, int &yourHealth, inventory PlayerInventory){
    strcpy(EventHandler, "Shoot Yourself");
        //if player choose to shoot themselves
        nextTurnIsPlayer = true;
        //Makes it so the next turn is still the player
        if (cylinder[chamber] == 'B') {
            //if chamber contains bullet.
            bullets--;
            yourHealth--;
            //lowers health by one
            PlayerInventory.Money += 15;
            //Adds money.
        } else {
            //Adds money.
            PlayerInventory.Money += 5;
        }
    chamber++;
}

void PlayerGoesShop(inventory PlayerInventory){
//if player goes to shop
        char PlayersChoice = PlayerChoice();
        if (PlayersChoice == 'y') {
            if (PlayerInventory.Money < 5) {

            } else {
                PlayerInventory.Money -= 5;
                PlayerInventory.DoubleBullet += 1;
                }
        } else {

        }
    strcpy(EventHandler, "Shop Screen");
}

bool Playerturn(int &yourHealth, int &OpponentHealth, int &chamber, bool &nextTurnIsPlayer, inventory &PlayerInventory) {
    if (!EventHandler[0] == '\0'){
        if (strcmp(EventHandler, "Shop Screen") == 0){
        PlayerGoesShop(PlayerInventory);
        return false;
        }
    }
    char PlayersChoice = PlayerChoice();
    //Self explanatory.
    if (PlayersChoice == 's') {
        PlayerShootsThemselves(nextTurnIsPlayer, chamber, yourHealth, PlayerInventory);
        return true;
    } else if (PlayersChoice == 'o') {
        PlayerShootsOpponent(nextTurnIsPlayer, chamber, OpponentHealth);
        return false;
    } else if (PlayersChoice == 'p') {
        PlayerGoesShop(PlayerInventory);
    }
    return false;
}
