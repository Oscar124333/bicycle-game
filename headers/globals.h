#ifndef constants_H
#define constants_H

// Constants
extern const int RESET;
extern const int EXIT;
#define CASE_EXIT 9

// Global Variables
extern int userInput;
extern int lineBreakLen;
extern int userSave;

// Gameplay Data (Structs)
typedef struct
{
    int type;
    int speed;
    int HP;
    float accidentRate;
} Bicycle;
extern Bicycle bike1;

typedef struct
{
    float dollars;  // Standard currency)
    int favors;       // Rare currency
    float dollarRate;
    float favorRate;
} PlayerStats;
extern PlayerStats p1;
extern PlayerStats global_change;

// Gameplay Data (Variables)
extern int dayCount;

#endif