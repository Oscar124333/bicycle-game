## Overview
Bicycle incremental with random elements and interactive gameplay.
Setting is a small town, route will be between two places. Capability to unlock better bikes, better routes, and better upgrades.


### Plan
+ Start with a storyline; you have to get to school on time everyday
+ Add at least one function every time I have freetime

### Gameplay (free-play)
+ No minimum requirement to proceed
+ Requires random world generation (seed-based) 

Progression is player-paced, upgrades are 100% incremental and maps/routes can be randomly generated. 

## Misc Ideas
+ Progression based on upgrades attained, calculated by averaging the "power" of the bike.
+ Shrimp chips currency
+ Weight Management for speed
    + Certain days have different modifiers and events that require items
    + Random holidays, set cooldown before random occurances start
+ Choose type of character you are playing; evolution as the game goes on
+ Weekends are when upgrades are done (mini motorways inspo)
+ Random minigame events
+ Grow a garden

## Feedback
example:
``` C
switch (mainoptions)
case MAIN:
case START:
	switch (gameoptions)
	what option ? 5
	option[5].run()
	case: Bike
	case: Shop
		case: check item
			what iem ? 3
				item[3].showInfo()
	case: Info
		mainoptions = INFO
case INFO:
	case: EXIT
		mainoptions = START
case EXIT:
```
get rid of nested loops and force the loop with the outermost loop.
every switch (button) will have its own screen states; the outermost loop will continue to loop and go through each screen state variable until it reaches the one you are on.
issue: requires global variables or a pointer to the previous screenstate to get passed on.


### Things Learned
+ I need to wrap code within my switch cases if it involves variable declarations (see lines 50-67 in game_util.c). this keeps variables local and does not confuse the compiler.