#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include "globals.h"
#include "mainMenu_util.h"
#include "mainMenu_UI.h"
#include "gen_util.h"

int main(void)
{
    int screen = 0;

    enum MenuMain
    {
        MAIN,
        START,
        OPTIONS,
        INFO_HOW,
        CREDITS
    };

    lineBreak(lineBreakLen);

    printf("Welcome to Oscar's Bicycle Game!\n");
    printf("Please use numbers to indicate your choices.\n");

    do
    {
        switch (screen)
        {
        case MAIN:
            inputPrompt(&screen, "Main Menu\n1: Start\n2: Options\n3: Info & How-To\n4: Credits\n\n9: Exit\n");
            break;
        case START:
            printf("you started the game! wow!\n");
            screen = save_handler();
            break;
        case OPTIONS:
            screen = main_options();
            break;
        case INFO_HOW:
            screen = main_info();
            break;
        case CREDITS:
            screen = main_credits();
            break;
        case CASE_EXIT:
            lineBreak(lineBreakLen);
            printf("Exiting game.\n");
            break;
        default:
            screen = MAIN;
            break;
        }
    } while (screen != EXIT);

    return 0;
}