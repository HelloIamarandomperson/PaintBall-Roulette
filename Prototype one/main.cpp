#include <stdio.h> // Standard input/output functions
#include <stdlib.h> // General utilities
#include <string.h> // String manipulation functions
#include <windows.h>
#include <time.h>

#include "functions.cpp"

char OpponentOrYou();
void checkMag(int &slots, char cylinder[]);
void LoadRandomBullets(int &bullets, int &slots, char cylinder[], int &reload);
bool Playerturn(int &yourHealth, int &OpponentHealth, char cylinder[], int &chamber, bool &nextTurnIsPlayer, int &money);

int main() {
    // Declarations
    int slots = 6;
    int yourHealth = 5;
    int OpponentHealth = 5;
    srand(time(NULL));
    int bullets;
    char cylinder[slots] = {'\0'};
    int reload;
    char choice;
    int Money = 0;


    // Load the bullets randomly into the cylinder
    LoadRandomBullets(bullets, slots, cylinder, reload);
    // Print initial game state

    checkMag(slots, cylinder); // Print the updated cylinder (for dev purposes)
    bool nextTurnIsPlayer = true; //whos turn it is next (0 is the player, 1 is next person, etc...)
    bool yourTurn;  //whos turn it is next (0 is the player, 1 is next person, etc...)
    // round 1
    while (true) {
        for (int chamber = 0; chamber < slots; chamber++) {
            fflush(stdin);
            if (nextTurnIsPlayer == true){
                yourTurn = true;
            }
            else{
                yourTurn = false;
            }
            while (yourTurn == true) {
                if (Playerturn(yourHealth, OpponentHealth, cylinder, chamber, nextTurnIsPlayer, Money) == false){
                    break;
                }
            }
            while (yourTurn == false) {
                int whoTheyShootin = 1;//rand() % (2); //1 is player, 2 is opponent
                if (whoTheyShootin == 1) {
                    nextTurnIsPlayer = true;
                    printf("\nThey raise the gun...");
                    Sleep(1000);
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
                    nextTurnIsPlayer = true;
                    break;
                //} else {
                //}
                }
            }
            if (yourHealth <= 0) {
                printf("You are dead. Should'nt have shot yourself probably. L+ratio+skill-issue");
                return 0;
            } else if(OpponentHealth <= 0) {
                printf("\nYou killed the poor innocent other person. Hooray for you.");
                return 0;
            }
        }
        fflush(stdin);
        LoadRandomBullets(bullets, slots, cylinder, reload);
        checkMag(slots, cylinder);
        //printf("for the this test game i have it so you can leave at any time so it doesn't go on forever, just type l to leave here to leave");
        //if (OpponentOrYou() == 'l') {
        //    break;
        //}
    }
}
