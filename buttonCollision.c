#include "button.h"
#include "buttonCollision.h"

/***********************************************************************************
This funtion fill a table with values to make the buttons collide with the character
0 = empty (everything is empty my default)
2 = full
***********************************************************************************/


int** buttonCollision(Button* button1, Button* button2, Button* button3){
  int i, j;
  int** tab_collision = malloc(SCREEN_WIDTH*sizeof(int*));
  for(int j = 0 ; j < SCREEN_WIDTH; j++){
    tab_collision[j] = malloc(SCREEN_HEIGHT*sizeof(int));
  }

  for (i = 0; i < SCREEN_WIDTH-1; i++){
    for (j = 0; j < SCREEN_HEIGHT-1; j++){
       tab_collision[i][j] = 0;					// il n'y a pas de collision
    }
  }

  for (i = getButtonXLeft(button1) - 32; i <= getButtonXRight(button1); i++){
    for (j = getButtonYUp(button1) - 32; j <= getButtonYDown(button1); j++){
       tab_collision[i][j] = 2;					// il y a une collision
    }
  }

  for (i = getButtonXLeft(button2) - 32; i <= getButtonXRight(button2); i++){
    for (j = getButtonYUp(button2) - 32; j <= getButtonYDown(button2); j++){
       tab_collision[i][j] = 2;					// il y a une collision
    }
  }

  for (i = getButtonXLeft(button3) - 32; i <= getButtonXRight(button3); i++){
    for (j = getButtonYUp(button3) - 32; j <= getButtonYDown(button3); j++){
       tab_collision[i][j] = 2;					// il y a une collision
    }
  }

  return tab_collision;
}
