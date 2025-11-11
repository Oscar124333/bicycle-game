#include <stdio.h>
#include <stdbool.h>
#include "menu_UI.h"

#include "globals.h"
#include "gen_util.h"
#include "menu_util.h"

int save_handler(void)
{
    screen = 0;
    
    while (true)
    {
        inputPrompt(&userInput, "Please choose your save.\n\n==> ");
        if (does_save_exist(userInput))
        {
            wait(0.5);
            printf("Loading save #%d.\n", userSave);
            wait(0.5);
            screen = game_overview();
            break;
        }
        else
        {
            printf("Save not found.\n");
        }
    }
    return RESET;
}
