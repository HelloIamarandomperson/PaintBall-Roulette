void checkMag(char cylinder[]) {
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

