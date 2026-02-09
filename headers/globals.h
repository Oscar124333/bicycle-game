#ifndef constants_H
#define constants_H

// Constants
extern const int RESET;
extern const int EXIT;
extern const int NULLTERMSPACE;
#define CASE_EXIT 9

// Global Variables
extern int userInput;
extern int lineBreakLen;
extern int userSave;

// Gameplay Data (Structs)
typedef struct
{
    float mult;
    float base;
} BasicOperands;

typedef struct
{
    BasicOperands dollars;
    BasicOperands favors;
    BasicOperands accidents;
} StatsType;

typedef struct
{
    int type;
    int HP;
    int speed;
    int weight;
} Bicycle;

typedef struct
{
    float dollars;  // Standard currency
    int favors;     // Rare currency
    Bicycle bike;
    StatsType arithValues;
} PlayerStats;
extern PlayerStats p1;

// Gameplay Data (Variables)
extern int dayCount;

#endif