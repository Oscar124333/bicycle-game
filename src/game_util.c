#include "game_util.h"
#include <stdio.h>
#include <stdbool.h>

#include "globals.h"
#include "game_logic.h"
#include "game_UI.h"
#include "gen_util.h"

int go_to_school(bool iterationState, PlayerStats *player)
{
    int iterations = 1;
    if (iterationState)
    {
        inputPrompt(&iterations, "How many times would you like to iterate?\n");
    }
    
    PlayerStats statsSummands = biking_RNG(iterations);
    change_stats_additive(player, statsSummands);
    display_biking_RNG(statsSummands);

    ++dayCount;

    return RESET;
}

int game_overview(void)
{
    int screen = 0;

    enum game_options
    {
        OVERVIEW,
        GO2SCHOOL,
        SHOP,
        SKILLS,
        ITERATE
    };

    lineBreak(lineBreakLen);

    printf("You wake up. It's day %d.\n", dayCount);

    do
    {
        switch (screen)
        {
        case OVERVIEW:
            do
            {
                lineBreak(lineBreakLen);

                if (true)
                {
                    displayStats(p1);
                }

                printf("Day %d.\n", dayCount);
                printf("1: Bike to School\n2: Shop\n3: Skills\n4: Iterate\n\n9: Exit\n\n");
                printf("==> ");
            } while (inputHandler(&screen) != 1);
            break;
        case GO2SCHOOL:
            screen = go_to_school(false, &p1);
            break;
        case SHOP:
            screen = OVERVIEW;
            break;    
        case SKILLS:
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