#ifndef menuUTIL_H
#define menuUTIL_H

#include "globals.h"

bool does_save_exist(int inSave);

int main_options(void);

int main_info(void);

int main_credits(void);

void displayStats(PlayerStats player);

int game_overview(void);

#endif