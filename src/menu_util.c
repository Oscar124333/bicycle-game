#include <stdio.h>
#include <stdbool.h>
#include "menu_util.h"

#include "globals.h"
#include "gen_util.h"
#include "game_util.h"
#include "main_options.h"

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
            inputPrompt(&screen, "Options\n1: Linebreak Length\n2: Placeholder\n\n9: Exit\n\n==> ");
            break;
        case LINEBREAKLEN:
            inputPrompt(&userInput, "Default Linebreak Length: 20\nPlease enter your desired length\n\n==> ");
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
            inputPrompt(&screen, "Information\n1: How to Play\n2: Lore\n\n9: Exit\n\n==> ");
            break;
        case H2P:
            do
            {
                lineBreak(lineBreakLen);

                printf("How to Play WIP\n");
                printf("\n9: Exit\n\n");
                printf("==> ");
            } while (inputHandler(&screen) != 1);

            break;
        case LORE:
            do
            {
                lineBreak(lineBreakLen);
                printf("Lore WIP\n");
                printf("\n9: Exit\n\n");
                printf("==> ");
            } while (inputHandler(&screen) != 1);

            break;
        default:
            break;
            screen = INFO;
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
            do
            {
                lineBreak(lineBreakLen);

                printf("Credits WIP\n");
                printf("\n9: Exit\n\n");
                printf("==> ");
            } while (inputHandler(&screen) != 1);
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

void displayStats(PlayerStats player)
{
    printf("Balance: $%.2lf\n", player.dBal);
    printf("Favors:  %d\n", player.fBal);
    printf("$ Mult:  %.2fx\n", player.dollarRate);
    printf("F Mult:  %.2fx\n\n", player.favorRate);
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