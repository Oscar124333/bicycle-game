#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_util.h"

#include "globals.h"
#include "gen_util.h"
#include "game_UI.h"

int bike_manual(void)
{
    lineBreak(lineBreakLen);

    srand(time(NULL));
    float dEarned = (int)((rand() % (300 - 100)) + 100) / 100.0f;
    p1.dBal += dEarned;

    wait(0.5);
    printf("biking...\n"); // will make a automagical function that does dot dot dot for me
    wait(0.5);
    printf("earned %.2f dollars!\n", dEarned);
    wait(0.5);

    dayCount += 1;

    return 0;
}