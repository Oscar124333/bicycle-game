#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_util.h"

#include "globals.h"
#include "game_logic.h"
#include "game_UI.h"
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
            screen = bike_manual();
            break;
        case SHOP:
        case SKILLS:
        case ITERATE:
            screen = OVERVIEW;
            break;
        default:
            screen = OVERVIEW;
            break;
        }
    } while (screen != EXIT);

    return RESET;
}