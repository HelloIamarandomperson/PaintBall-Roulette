
//Including standard libraries
#include <stdio.h> // Standard input/output functions
#include <stdlib.h> // General utilities
#include <string.h> // String manipulation functions
#include <windows.h>
#include <time.h>


//Including the other files
#include "functions.cpp"
#include "GraphicsMain.cpp"
#include "Headers.h"

//Initializing the Functions
char OpponentOrYou();
void checkMag(int &slots, char cylinder[]);
void LoadRandomBullets(int &bullets, int &slots, char cylinder[], int &reload);
bool checkIfGameCont(int &OpponentHealth, int &yourHealth);
bool Playerturn(int &yourHealth, int &OpponentHealth, char cylinder[], int &chamber, bool &nextTurnIsPlayer, int &money);
bool OpponentDummyTurn(bool &nextTurnIsPlayer, int &chamber, char cylinder[], int &OpponentHealth, int &slots, int &yourHealth, int &bullets, int &reload);

//Creating the thread.
DWORD WINAPI AllegroMain(LPVOID lpParam);

int main() {
    // Initializing the variables
    int slots = 6;
    int yourHealth = 5;
    int OpponentHealth = 3;
    srand(time(NULL));
    int bullets;
    char cylinder[slots] = {'\0'};
    int reload;
    //making the variables needed for the thread
    HANDLE hThread;
    DWORD dwThreadId;
    //making the thread.
    hThread = CreateThread(NULL, 0, AllegroMain, NULL, 0, &dwThreadId);
    //If thread does not run make error message
    if (hThread == NULL) {
        printf("Error creating thread\n");
        return 1;
    }

    // Load the bullets randomly into the cylinder
    LoadRandomBullets(bullets, slots, cylinder, reload);

    checkMag(slots, cylinder); // Print the updated cylinder (for dev purposes)
    bool nextTurnIsPlayer = true; //whos turn it is next (0 is the player, 1 is next person, etc...)
    bool yourTurn;  //whos turn it is next (0 is the player, 1 is next person, etc...)
    // round 1
    while (true) {
        //While true for a convenient infinite loop that can only be broken with breaks.
        for (int chamber = 0; chamber < slots; chamber++) {
            //For loop for until chamber is empty.
            fflush(stdin);
            //fflush to stop a glitch from happening.
            if (nextTurnIsPlayer == true){
                //if next player is supposed to be the player it sets the variable to true.
                yourTurn = true;
            }
            else{
                //else it is the opponents turn
                yourTurn = false;
            }
            while (yourTurn == true) {
                //if it is the players turn.
                if (Playerturn(yourHealth, OpponentHealth, cylinder, chamber, nextTurnIsPlayer, PlayerInventory) == false){
                    //Function for player's turn.
                    break;
                }
            }
            while (yourTurn == false) {
                //If not player turn
                if (OpponentDummyTurn(nextTurnIsPlayer, chamber, cylinder, OpponentHealth, slots, yourHealth, bullets, reload) == false){
                    //run function for the opponents turn
                    nextTurnIsPlayer = true;
                    break;
                }
            }
            if (checkIfGameCont(OpponentHealth, yourHealth) == false){
                //if the game should have ended the game ends
                break;
            }
        }
        if (checkIfGameCont(OpponentHealth, yourHealth) == false){
            //if the game should have ended the game ends
            break;
        }
        fflush(stdin);
        //fflush to fix a bug.
        LoadRandomBullets(bullets, slots, cylinder, reload);
        //If the code gets here then the cylinder is empty so I reload here
        checkMag(slots, cylinder);
        //checkMag is for dev pourposes only and shows the inside of the maganzine
    }
    strcpy(Allegro, "Game Ends");
    //Runs command ending allegro
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);
    //ends thread.
}
