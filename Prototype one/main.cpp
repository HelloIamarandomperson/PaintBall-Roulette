#include <stdio.h> // Standard input/output functions
#include <stdlib.h> // General utilities
#include <string.h> // String manipulation functions
#include <windows.h>
#include <time.h>



#include "functions.cpp"
#include "GraphicsMain.cpp"
#include "Headers.h"


char OpponentOrYou();
void checkMag(int &slots, char cylinder[]);
void LoadRandomBullets(int &bullets, int &slots, char cylinder[], int &reload);
bool checkIfGameCont(int &OpponentHealth, int &yourHealth);
bool Playerturn(int &yourHealth, int &OpponentHealth, char cylinder[], int &chamber, bool &nextTurnIsPlayer, int &money);
bool OpponentDummyTurn(bool &nextTurnIsPlayer, int &chamber, char cylinder[], int &OpponentHealth, int &slots, int &yourHealth, int &bullets, int &reload);


DWORD WINAPI AllegroMain(LPVOID lpParam);
int main() {
    // Declarations
    int slots = 6;
    int yourHealth = 5;
    int OpponentHealth = 3;
    srand(time(NULL));
    int bullets;
    char cylinder[slots] = {'\0'};
    int reload;
    char AllegroAction[50] = {'t'};
    Allegro[0] = 'm';


    HANDLE hThread;
    DWORD dwThreadId;

    //hThread = CreateThread(NULL, 0, AllegroMain, NULL, 0, &dwThreadId);
    hThread = CreateThread(NULL, 0, AllegroMain, AllegroAction, 0, &dwThreadId);
    if (hThread == NULL) {
        printf("Error creating thread\n");
        return 1;
    }
    //sets up thread for bitmapstest

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
                if (Playerturn(yourHealth, OpponentHealth, cylinder, chamber, nextTurnIsPlayer, PlayerInventory) == false){
                    break;
                }
            }
            while (yourTurn == false) {
                if (OpponentDummyTurn(nextTurnIsPlayer, chamber, cylinder, OpponentHealth, slots, yourHealth, bullets, reload) == false){
                    nextTurnIsPlayer = true;
                    break;
                }
            }
            if (checkIfGameCont(OpponentHealth, yourHealth) == false){
                break;
            }
        }
        if (checkIfGameCont(OpponentHealth, yourHealth) == false){
            break;
        }
        fflush(stdin);
        LoadRandomBullets(bullets, slots, cylinder, reload);
        checkMag(slots, cylinder);
    }
    strcpy(Allegro, "Game Ends");
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);
}
