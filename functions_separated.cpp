#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


void checkMag(int slots,char cylinder[]) {
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

char LoadRandomBullets(int bullets,int slots, char cylinder[], int reload){
    srand(time(NULL));
    for (int i = 0; i < bullets; i++) {
        reload = rand() % slots;
        if (cylinder[reload] == '\0') {
            cylinder[reload] = 'B';
        } else {
            i--;
        }
    }


}
