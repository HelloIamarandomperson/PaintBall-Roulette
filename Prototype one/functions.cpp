#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>

#include "Headers.h"


void checkMag(int &slots, char cylinder[]) {
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
    char response;
    scanf("%c", &response);
    response = tolower(response);
    return response;
}

void LoadRandomBullets(int &bullets, int &slots, char cylinder[], int &reload){
    bullets = rand() % (slots);
    memset(cylinder, '\0', slots);
    printf("\nThe gun is being loaded");
    int blanks = slots-bullets;
    //srand(time(NULL));
    for (int i = 0; i < bullets; i++) {
        reload = rand() % slots;
        if (cylinder[reload] == '\0') {
            cylinder[reload] = 'B';
        } else {
            i--;
        }
    }
    Sleep(2000);
    printf("\nThere are %d bullets and %d blanks in the gun.\n", bullets, blanks);
    printf("The gun has been loaded randomly, and has a total of %d slots.\n", slots);
    Sleep(2000);
}

bool OpponentDummyTurn(bool &nextTurnIsPlayer, int &chamber, char cylinder[], int &OpponentHealth, int &slots, int &yourHealth, int &bullets, int &reload){
    int whoTheyShootin = 1;//rand() % (2); //1 is player, 2 is opponent
    if (whoTheyShootin == 1) {
        nextTurnIsPlayer = true;
        printf("\nThey raise the gun...");
        Sleep(500);
        strcpy(Allegro, "Dummy Fires");
        Sleep(500);
        printf("\ntowards you...");
        Sleep(1000);
        if (cylinder[chamber] == 'B') {
            fflush(stdin);
            printf("Click... \nBang! ...That probably hurt... you should like, not get shot... or something...");
            yourHealth--;
            if (chamber == slots){
                fflush(stdin); //placeholder solution
                LoadRandomBullets(bullets, slots, cylinder, reload);
                checkMag(slots, cylinder);
            }
        } else {
            printf("Click.... It was a blank... This time...");
        }
    }
    nextTurnIsPlayer = true;
    return false;
}

bool checkIfGameCont(int &OpponentHealth, int &yourHealth){
    if (yourHealth <= 0) {
        printf("You are dead. Shouldn't have shot yourself probably. L+ratio+skill-issue");
        return false;
    } else if(OpponentHealth <= 0) {
        printf("\nYou killed the poor innocent other person. Hooray for you.");
        return false;
    }
    return true;
}

bool Playerturn(int &yourHealth, int &OpponentHealth, char cylinder[], int &chamber, bool &nextTurnIsPlayer, int &Money){
    fflush(stdin);
    printf("\nYou have %d health.", yourHealth);
    printf("\nYour opponent has %d health.", OpponentHealth);
    printf("\nYou have %d coins.", Money);
    printf("\nIf you choose to shoot yourself (s), you get to shoot again. \nIf you choose to shoot your opponent (o), it is no longer your turn. If you choose to go to shop press (p)\n\n");
    char PlayersChoice = PlayerChoice();
    if (PlayersChoice == 's') {
        if (cylinder[chamber] == 'B') {
            printf("Click... Bang! ...That probably hurt... you should like, not shoot yourself... or something...");
            yourHealth--;
            Money += 15;
            nextTurnIsPlayer = true;
            return false;
        } else {
            printf("Click.... It was a blank... Bit of a gambler, are you?\n");
            Money += 5;
            nextTurnIsPlayer = true;
            return false;
        }
    } else if (PlayersChoice == 'o') {
        nextTurnIsPlayer = false;

        if (cylinder[chamber] == 'B') {
            fflush(stdin);
            strcpy(Allegro, "Player Fires");
            printf("Click.... Bang! It was a live round!");
            OpponentHealth--;
        } else {
            printf("Click.... It was a blank...");
        }
        return false;
    }
    else if (PlayersChoice == 'p') {
        fflush(stdin);
        printf("shop in beta testing right now");
        printf("\nwould you like to buy a double bullet? Cost 5 coins!\n");
        char PlayersChoice = PlayerChoice();
        if (PlayersChoice == 'y'){
            if (Money < 5){
                printf("\nHaha poor");
            }
            else{
                printf("\n Here you go");
                Money =- 5;
            }
        }
        else{
            printf("\nok, thanks for visiting the shop!");
        }

        }
    else{
        printf("Invalid Option, s or o or p");

    }
    return true;
}
