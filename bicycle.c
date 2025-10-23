#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include "menu_ui.h"
#include "gen_util.h"
#include "game_util.h"

// Constants
//#define CASE_EXIT 9
const int RESET = 0;
const int EXIT = 9;

// Global Variables
int userInput = 0;
int userSave = 0;
int lineBreakLen = 20;

// Gameplay Data
/*  Distance is measured in miles * 10; 100 distance = 10 miles */
int dayCount = 0;

int main(void)
{
    int m_Screen = 0;

    enum MenuMain{
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
        switch (m_Screen)
        {
            case MAIN:
                do
                {
                    lineBreak(lineBreakLen);
                    
                    printf("Main Menu\n");
                    printf("1: Start\n2: Options\n3: Info & How-To\n4: Credits\n\n9: Exit\n\n");
                    printf("==> ");
                } while (inputHandler(&m_Screen) != 1);

                break;
            case START:
                printf("you started the game! wow!\n");
                if (user_saves())
                {
                    wait(0.5);
                    printf("Loading save #%d.\n", userSave);
                    wait(0.5);
                    m_Screen = game_overview();
                }
                break;
            case OPTIONS:
                m_Screen = main_options();
                break;
            case INFO_HOW:
                m_Screen = main_info();
                break;
            case CREDITS:
                m_Screen = main_credits();
                break;
            case 9:
                lineBreak(lineBreakLen);
                printf("Exiting game.\n");
                break;
            default:
                m_Screen = MAIN;
                break;
        }
    } while (m_Screen != EXIT);

return 0;
}