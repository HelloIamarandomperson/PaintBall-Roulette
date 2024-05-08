#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>



void checkMag(int slots, char cylinder[]) {
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


char OpponentOrYou() {
    char response;
    scanf("%c", &response);
    response = tolower(response);
    return response;
}

void LoadRandomBullets(int &bullets, int &slots, char cylinder[], int &reload){
    int blanks = slots-bullets;
    srand(time(NULL));
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

bool Playerturn(int &yourHealth, int &OpponentHealth, char cylinder[], int &chamber, bool &nextTurnIsPlayer){
    fflush(stdin);
    printf("\nYou have %d health.", yourHealth);
    printf("\nYour opponent has %d health.\n", OpponentHealth);
    printf("If you choose to shoot yourself (s), you get to shoot again. \nIf you choose to shoot your opponent (o), it is no longer your turn.\n\n");
    char PlayersChoice = OpponentOrYou();
    if (PlayersChoice == 's') {
        if (cylinder[chamber] == 'B') {
            printf("Click... Bang! ...That probably hurt... you should like, not shoot yourself... or something...");
            yourHealth--;
            nextTurnIsPlayer = true;
            return false;
        } else {
            printf("Click.... It was a blank... Bit of a gambler, are you?\n");
            nextTurnIsPlayer = true;
            return false;
        }
    } else {
        if (PlayersChoice == 'o') {
            nextTurnIsPlayer = false;
            if (cylinder[chamber] == 'B') {
                fflush(stdin);
                printf("Click.... Bang! It was a live round!");
                OpponentHealth--;
            } else {
                printf("Click.... It was a blank...");
            }
            return false;
        }
    }
    return true;
}
