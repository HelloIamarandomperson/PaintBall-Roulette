//Including standard libraries

//Including the other files
#include "Headers.h"
extern char Allegro[50];
extern char response;
extern int chamber;
extern char cylinder[6];
//initializes player inventory.
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
    //PlayerChoice is a scanf function that lowers all responses to their lower form for convenience.
    //printf("\n%s", Allegro);
    strcpy(Allegro, "Player Is Choosing");
    //scanf("%c", &response);
    al_wait_for_event(event_queue, &eventOrder);
    if (strcmp(Allegro, "Button Pressed") == 0){
        printf("\n%s", Allegro);
        memset(Allegro, '\0', sizeof(Allegro));
        response = 'o';
        response = tolower(response);

    }


    return response;
}

void LoadRandomBullets(int &bullets, int &slots, int &reload) {
    //Load Random Bullets is designed to load the bullets randomly
    bullets = rand() % (slots);
    //randomizes bullet count.
    memset(cylinder, '\0', slots);
    //Sets cylinder to only NULLs. This clears the bullets in the last chamber
    printf("\nThe gun is being loaded");
    for (int i = 0; i < bullets; i++) {
        //randomizes the Mag.
        reload = rand() % slots;
        if (cylinder[reload] == '\0') {
            cylinder[reload] = 'B';
        } else {
            i--;
        }
    }
    int blanks = slots - bullets;
    chamber = 0;
    printf("\nThere are %i bullets and %i blanks in the gun.\n", bullets, blanks);
    printf("The gun has been loaded randomly, and has a total of %i slots.\n", slots);
}

bool OpponentDummyTurn(bool &nextTurnIsPlayer, int &OpponentHealth, int &slots, int &yourHealth, int &bullets, int &reload) {
    int whoTheyShootin = 1; //rand() % (2); //1 is player, 2 is opponent
    if (whoTheyShootin == 1) {
        nextTurnIsPlayer = true;
        printf("\nThey raise the gun...");
        strcpy(Allegro, "Dummy Fires");
        printf("\ntowards you...");
        if (cylinder[chamber] == 'B') {
            //If chamber contains bullet.
            fflush(stdin);
            printf("Click... \nBang! ...That probably hurt... you should like, not get shot... or something...");
            yourHealth--;
        } else {
            printf("Click.... It was a blank... This time...");
        }
    }
    chamber++;
    printf("\n next chamber is %i", chamber);
    nextTurnIsPlayer = true;
    return false;
}

bool checkIfGameCont(int & OpponentHealth, int & yourHealth) {
    //checks if both are alive, else returns false.
    if (yourHealth <= 0) {
        printf("You are dead. Shouldn't have shot yourself probably. L+ratio+skill-issue");
        return false;
    } else if (OpponentHealth <= 0) {
        printf("\nYou killed the poor innocent other person. Hooray for you.");
        return false;
    }
    return true;
}

void PlayerShootsOpponent(bool &nextTurnIsPlayer, int &chamber, char cylinder[], int &OpponentHealth){
    //Makes it so the screen shows the player shooting.
    //if the player shoots the opponent
    nextTurnIsPlayer = false;
    //make it so the Opponents turn is next.

    if (cylinder[chamber] == 'B') {
        //If chamber contains bullet
        fflush(stdin);
        //fflush here to fix bug
        printf("Click.... Bang! It was a live round!");
        //opponent loses health.
        OpponentHealth--;
    } else {
        printf("Click.... It was a blank...");
            //if miss thats it.
    }
    chamber++;
    printf("\n next chamber is %i", chamber);
}

bool Playerturn(int &yourHealth, int &OpponentHealth, char cylinder[], int &chamber, bool &nextTurnIsPlayer, inventory &PlayerInventory) {
    fflush(stdin);
    //fflush to fix bug.
    if (Allegro[0] == '\0'){
        printf("\nYou have %i health.", yourHealth);
        printf("\nYour opponent has %i health.", OpponentHealth);
        printf("\nYou have %i coins and %i DoubleBullets", PlayerInventory.Money, PlayerInventory.DoubleBullet);
        printf("\nIf you choose to shoot yourself (s), you get to shoot again. \nIf you choose to shoot your opponent (o), it is no longer your turn. If you choose to go to shop press (p)\n\n");
    }
    char PlayersChoice = PlayerChoice();
    al_wait_for_event(event_queue, &eventOrder);
    //Self explanatory.
    if (strcmp(Allegro, "Button Pressed") == 0){
        printf("\ntest");
        if (PlayersChoice == 's') {
            //if player choose to shoot themselves
            nextTurnIsPlayer = true;
            //Makes it so the next turn is still the player
            if (cylinder[chamber] == 'B') {
                //if chamber contains bullet.
                printf("Click... Bang! ...That probably hurt... you should like, not shoot yourself... or something...");
                yourHealth--;
                //lowers health by one
                PlayerInventory.Money += 15;
                //Adds money.
                return false;
            } else {
                printf("Click.... It was a blank... Bit of a gambler, are you?\n");
                //Adds money.
                PlayerInventory.Money += 5;

                return false;
            }
        } else if (PlayersChoice == 'o') {
            PlayerShootsOpponent(nextTurnIsPlayer, chamber, cylinder, OpponentHealth);
            strcpy(Allegro, "Player Fires");
            return false;
        } else if (PlayersChoice == 'p') {
            //if player goes to shop
            fflush(stdin);
            //fflush to fix bug.
            printf("shop in beta testing right now");
            printf("\nwould you like to buy a double bullet? Cost 5 coins!\n");
            char PlayersChoice = PlayerChoice();
            if (PlayersChoice == 'y') {
                if (PlayerInventory.Money < 5) {
                    printf("\nHaha poor");
                } else {
                    printf("\n Here you go");
                    PlayerInventory.Money -= 5;
                    PlayerInventory.DoubleBullet += 1;
                    }
            } else {
            printf("\nok, thanks for visiting the shop!");
            }

        } else {
            printf("Invalid Option, s or o or p");

        }
    }
    return true;
}



