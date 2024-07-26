#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include "src/headers/colors.h"

/*
Comments are debug methods or things I learned while making this.
So when I come back someday to check the code again, I can remember all of this again.
*/

#define ntfBuilder "src\\ntfbuilder.py"
#define cleancommand "cls"
#define startpath "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\app.exe"

void buildNotification(char *msg1, char *msg2) {
    system(cleancommand);
    size_t commandLen = snprintf(NULL, 0, "python src/ntfbuilder.py \"%s\" \"%s\"", msg1, msg2) + 1;
    char *commandString = (char *)malloc(commandLen);
    snprintf(commandString, commandLen, "python src/ntfbuilder.py \"%s\" \"%s\"", msg1, msg2);
    system(commandString); // compiled ntf builder call or src call
    free(commandString);
}

void addToStart() {
    if (CopyFile("app.exe", startpath, FALSE)) {
        printf(green "+ " white "File added to start menu.\n");
        Sleep(3000);
    } else {
        printf(red "- " white "Couldn't add file to start menu, please check the app permissions!\n"); // ask user for admin
        Sleep(3000);
    }
}

int main() {
    int time;
    char addStart;

    system("title BetterPosture by kshv");
    system(cleancommand);

    printf(cyan "> " white "Sleep Time: ");
    scanf("%d", &time);
    getchar(); // scanf leaves a newline

    printf(cyan "> " white "{REQUIRES ADMIN} Add Script to Start? (y/n): ");
    scanf("%c", &addStart);

    system(cleancommand);

    switch (tolower(addStart)) {
        case 'y':
            addToStart();
            break;
        case 'n':
            printf("Add to start denied. You will have to relaunch it every time you sign in.\n");
            break;
        default:
            printf("Invalid input. Please enter 'y' or 'n'.\n");
            break;
    }

    while (time != 0) {
        buildNotification("BetterPosture", "Are You Sitting Properly?");
        Sleep(time * 1000);
    }

    printf("Time cannot be 0\n");
    Sleep(3000);

    return 0;
}
