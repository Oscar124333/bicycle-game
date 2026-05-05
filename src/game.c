#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "globals.h"
#include "game_logic.h"
#include "game_UI.h"
#include "game_shop.h"
#include "gen_util.h"

int game_overview(void)
{
    int screen = 0;

    enum game_options
    {
        OVERVIEW,
        GO2SCHOOL,
        SHOP,
        SKILLS,
        HOME,
        ITERATE
    };

    lineBreak(lineBreakLen);

    printf("You wake up. It's day %d.\n", dayCount);

    do
    {
        switch (screen)
        {
        case OVERVIEW:
        {
            char displayStats[40] = {'\0'};
            formatStatsToString(displayStats, sizeof(displayStats), &p1);
            
            unsigned int promptTotalSize = sizeof(displayStats) + strlen(promptGameMenu) + promptDayCountSize + NULLTERMSPACE;
            char *promptGameMenuFormatted = malloc(promptTotalSize);
            if (promptGameMenuFormatted == NULL)
            {
                perror("Error encountered while printing the screen.");
                screen = EXIT;
                break;
            }

            snprintf(promptGameMenuFormatted, promptTotalSize, "%sDay %d.\n%s", displayStats, dayCount, promptGameMenu);
            inputPrompt(&screen, promptGameMenuFormatted);
            free(promptGameMenuFormatted);
        }
            break;
        case GO2SCHOOL:
            screen = go_to_school(false, &p1);
            break;
        case SHOP:
            screen = shop_overview();
            break;    
        case SKILLS:
            screen = OVERVIEW;
            break;    
        case HOME:
            screen = OVERVIEW;
            break;    
        case ITERATE:
            screen = go_to_school(true, &p1);
            break;
        default:
            screen = OVERVIEW;
            break;
        }
    } while (screen != EXIT);

    return RESET;
}