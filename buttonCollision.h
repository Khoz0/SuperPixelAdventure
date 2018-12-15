#pragma once
#include "constants.h"

/***********************************************************************************
This funtion fill a table with values to make the buttons collide with the character
0 = empty (everything is empty by default)
2 = full
***********************************************************************************/

int** buttonCollision(Button* button1, Button* button2, Button* button3);
