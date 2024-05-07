#include <stdio.h> // Standard input/output functions
#include <stdlib.h> // General utilities
#include <string.h> // String manipulation functions
#include <math.h> // Mathematical functions
#include <ctype.h> // Character classification functions
#include <stdbool.h> // Boolean type definitions
#include <limits.h> // Minimum and maximum values for data types
#include <time.h>
#include <chrono>
#include <thread>
// Additional common includes based on functionality
#include <fstream> // File stream operations (for C++)
#include <memory.h> // Additional memory management functions

// Platform-specific headers
#ifdef _WIN32
#include <windows.h>

#endif

#include "functions_separated.cpp"

char Shot(int slots, char cylinder[]);
char OpponentOrYou();
int slots = 6;
void checkMag(int slots, char cylinder[]);
char LoadRandomBullets(int bullets,int slots, char cylinder[], int reload);
int main() {
    // Declarations
    int yourHealth = 3;
    int OpponentHealth = 3;
    srand(time(NULL));
    int bullets = rand() % (slots);
    int blanks = slots - bullets;
    char cylinder[slots];
    int reload;
    char choice;
    char PlayersChoice;
    // Initialize the cylinder with blanks
    for (int i = 0; i < slots; i++) {
        cylinder[i] = '\0';
    }

    // Load the bullets randomly into the cylinder
    LoadRandomBullets(bullets, slots, cylinder, reload);
    // Print initial game state
    printf("There are %d bullets and %d blanks in the gun.\n", bullets, blanks);
    printf("The gun has been loaded randomly, and has a total of %d slots.\n", slots);

    checkMag(slots, cylinder); // Print the updated cylinder (for dev purposes)
    bool nextTurn = true; //whos turn it is next (0 is the player, 1 is next person, etc...)
    bool yourTurn;  //whos turn it is next (0 is the player, 1 is next person, etc...)
    // round 1
    while (true) {
        for (int chamber = 0; chamber < slots; chamber++) {
            if (nextTurn == true){
                yourTurn = true;
            }
            else{
                yourTurn = false;
            }

            while (yourTurn == true) {
                if (yourHealth > 0 && OpponentHealth > 0) {
                    fflush(stdin);
                    printf("\nYou have %d health.\n", yourHealth);
                    printf("Your opponent has %d health.\n", OpponentHealth);
                    printf("If you choose to shoot yourself (s), you get to shoot again. \nIf you choose to shoot your opponent (o), it is no longer your turn.\n\n");
                    char PlayersChoice = OpponentOrYou();
                    if (PlayersChoice == 's') {
                        if (cylinder[chamber] == 'B') {
                            printf("Click... Bang! ...That probably hurt... you should like, not shoot yourself... or something...");
                            yourHealth--;
                            break;
                        } else {
                            printf("Click.... It was a blank... Bit of a gambler, are you?\n");
                            break;
                        }
                    } else {
                        if (PlayersChoice == 'o') {
                            if (cylinder[chamber] == 'B') {
                                fflush(stdin);
                                printf("Click.... Bang! It was a live round!");
                                OpponentHealth--;
                            } else {
                                printf("Click.... It was a blank...");
                            }
                            nextTurn = false;
                            break;
                        }
                    }
                } else {
                    if (yourHealth < 0) {
                        printf("You are dead. Should'nt have shot yourself probably. L+ratio+skill-issue");
                        break;
                    } else {
                        printf("You killed the poor innocent other person. Hooray for you.");
                        break;
                    }
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
                        printf("Click... Bang! ...That probably hurt... you should like, not get shot... or something...");
                        yourHealth--;
                    } else {
                        printf("Click.... It was a blank... This time...");
                    }
                    nextTurn = true;
                    break;
                } else {
                }
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
