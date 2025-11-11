#include "menu_util.h"
#include <stdio.h>
#include <stdbool.h>

#include "globals.h"
#include "menu_UI.h"
#include "main_options.h" // Settings functionality
#include "gen_util.h"
#include "game_util.h"

/************
*   Saves
*************/
bool does_save_exist(int inSave) // Currently, '1' is the only correct choice.
{
    if (inSave == 1)
    {
        printf("Successfully selected save #%d.\n", inSave);
        return true;
    }
    else
    {
        return false;
    }
    wait(0.5);
}

int save_handler(void)
{
    int screen = 0;
    
    while (true)
    {
        inputPrompt(&userInput, "Please choose your save.\n");
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
    return screen;
}

/********************
*   Main Functions
*********************/
int main_options(void)
{
    int screen = 0;

    enum Options
    {
        OPTIONS,
        LINEBREAKLEN,
        PLACEHOLDER
    };

    do
    {
        switch (screen)
        {
        case OPTIONS:
            inputPrompt(&screen, promptOptions);
            break;
        case LINEBREAKLEN:
            inputPrompt(&userInput, promptLineBreakSetting);
            change_lineBreak(userInput);
            screen = OPTIONS;
            break;
        case PLACEHOLDER:
            screen = OPTIONS;
            break;
        case CASE_EXIT:
            break;
        default:
            screen = OPTIONS;
            break;
        }
    } while (screen != EXIT);

    return RESET;
}

int main_info(void)
{
    int screen = 0;

    enum Info
    {
        INFO,
        H2P,
        LORE
    };

    do
    {
        switch (screen)
        {
        case INFO:
            inputPrompt(&screen, promptInfo);
            break;
        case H2P:
            inputPrompt(&screen, promptH2P);
            screen = INFO;
            break;
        case LORE:
            inputPrompt(&screen, promptLore);
            screen = INFO;
            break;
        case CASE_EXIT:
            break;
        default:
            screen = INFO;
            break;
        }
    } while (screen != EXIT);

    return RESET;
}

int main_credits(void)
{
    int screen = 0;

    enum Credits
    {
        CREDITS,
        PLACEHOLDER
    };

    do
    {
        switch (screen)
        {
        case CREDITS:
            inputPrompt(&screen, promptCredits);
            break;
        case PLACEHOLDER:
            screen = CREDITS;
            break;
        case CASE_EXIT:
            break;
        default:
            screen = CREDITS;
            break;
        }
    } while (screen != EXIT);

    return RESET;
}
