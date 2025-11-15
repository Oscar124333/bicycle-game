#ifndef menuUTIL_H
#define menuUTIL_H

#include <stdbool.h>

#include "globals.h"

// Saves
bool does_save_exist(int inSave);

int save_handler(void);

// Main Funcs
int main_options(void);

int main_info(void);

int main_credits(void);

#endif