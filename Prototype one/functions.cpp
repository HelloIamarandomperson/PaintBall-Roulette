//Including standard libraries

//Including the other files
#include "GraphicsMain.cpp"

struct inventory {
    //struct inventory is used to store the inventory of the player and the opponent.
    int Money = 0;
    int DoubleBullet = 0;
};
//initializes player inventory.
inventory PlayerInventory;

void checkMag(int & slots, char cylinder[]) {
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
    char response;
    scanf("%c", & response);
    response = tolower(response);
    return response;
}

void LoadRandomBullets(int & bullets, int & slots, char cylinder[], int & reload) {
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
    Sleep(1000);
    printf("\nThere are %i bullets and %i blanks in the gun.\n", bullets, blanks);
    printf("The gun has been loaded randomly, and has a total of %i slots.\n", slots);
    Sleep(1000);
}

bool OpponentDummyTurn(bool & nextTurnIsPlayer, int & chamber, char cylinder[], int & OpponentHealth, int & slots, int & yourHealth, int & bullets, int & reload) {
    int whoTheyShootin = 1; //rand() % (2); //1 is player, 2 is opponent
    if (whoTheyShootin == 1) {
        nextTurnIsPlayer = true;
        printf("\nThey raise the gun...");
        Sleep(500);
        strcpy(Allegro, "Dummy Fires");
        Sleep(500);
        printf("\ntowards you...");
        Sleep(1000);
        if (cylinder[chamber] == 'B') {
            //If chamber contains bullet.
            fflush(stdin);
            printf("Click... \nBang! ...That probably hurt... you should like, not get shot... or something...");
            yourHealth--;
        } else {
            printf("Click.... It was a blank... This time...");
        }
    }
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

bool Playerturn(int & yourHealth, int & OpponentHealth, char cylinder[], int & chamber, bool & nextTurnIsPlayer, inventory & PlayerInventory) {
    fflush(stdin);
    //fflush to fix bug.
    printf("\nYou have %i health.", yourHealth);
    printf("\nYour opponent has %i health.", OpponentHealth);
    printf("\nYou have %i coins and %i DoubleBullets", PlayerInventory.Money, PlayerInventory.DoubleBullet);
    printf("\nIf you choose to shoot yourself (s), you get to shoot again. \nIf you choose to shoot your opponent (o), it is no longer your turn. If you choose to go to shop press (p)\n\n");
    char PlayersChoice = PlayerChoice();
    //Self explanatory.
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
        //if the player shoots the opponent
        nextTurnIsPlayer = false;
        //make it so the Opponents turn is next.
        strcpy(Allegro, "Player Fires");
        //Makes it so the screen shows the player shooting.
        Sleep(2000);
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
    return true;
}
