#ifndef gameUTIL_H
#define gameUTIL_H

#include "gen_util.h"
#include "game_ui.h"

// Constants

// Globals
extern int lineBreakLen;
extern const int RESET;
extern const int EXIT;
extern int dayCount;

typedef struct {
    int type;
    int speed; 
    int HP;
    float accidentRate;
} Bicycle;
Bicycle bike1 = {0, 100, 10, 0.3f};

typedef struct {
    float dBal; // Dollars (standard currency)
    int fBal;   // Favors (premium currency)
    float dollarRate;
    float favorRate;
} PlayerStats;
PlayerStats p1 = {0.0f, 0, 1.0f, 0.11f};

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

#endif