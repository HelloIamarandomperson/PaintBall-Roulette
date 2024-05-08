#include <stdio.h> // Standard input/output functions
#include <stdlib.h> // General utilities
#include <string.h> // String manipulation functions
//#include <math.h> // Mathematical functions
//#include <ctype.h> // Character classification functions
//#include <stdbool.h> // Boolean type definitions
//#include <limits.h> // Minimum and maximum values for data types
#include <time.h>
//#include <chrono>
//#include <thread>
// Additional common includes based on functionality
//#include <fstream> // File stream operations (for C++)
//#include <memory.h> // Additional memory management functions

// Platform-specific headers

#include <windows.h>


#include "functions_separated.cpp"

char Shot(int slots, char cylinder[]);
char OpponentOrYou();
void checkMag(int slots, char cylinder[]);
void LoadRandomBullets(int &bullets, int &slots, char cylinder[], int &reload);
bool Playerturn(int &yourHealth, int &OpponentHealth, char cylinder[], int &chamber, bool &nextTurnIsPlayer);
int main() {
    // Declarations
    int slots = 6;
    int yourHealth = 5;
    int OpponentHealth = 5;
    srand(time(NULL));
    int bullets = rand() % (slots);
    int blanks = slots - bullets;
    char cylinder[slots];
    int reload;
    char choice;
    char PlayersChoice;
    int Money;
    // Initialize the cylinder with blanks
    for (int i = 0; i < slots; i++) {
        cylinder[i] = '\0';
    }

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
                if (Playerturn(yourHealth, OpponentHealth, cylinder, chamber, nextTurnIsPlayer) == false){
                    break;

                }
            }
            while (yourTurn == false) {
                int whoTheyShootin = rand() % (2); //1 is player, 2 is opponent
                if (whoTheyShootin == 1) {
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
                printf("You killed the poor innocent other person. Hooray for you.");
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
