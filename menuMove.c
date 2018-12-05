#include "menuMove.h"

void MenuMove(SDL_Event event, SDL_Rect positionChar, int goalPurpose, int tab_collide, int speed, int movement, int orientation,
   Button* button_play, Button* button_goal, Button* button_quit, Button* tab_button, int endMenu, int gameOver){
     switch(event.type)
       {
       case SDL_MOUSEBUTTONUP:
       goalPurpose = 0;
       if (event.button.button == SDL_BUTTON_LEFT){
          if ((positionChar.x != event.button.x) && authorizedX){
            if (tab_collide[positionChar.x + 1][positionChar.y] == 0 ){
              if (abs(event.button.x - (positionChar.x + 1)) < abs(event.button.x - (positionChar.x - 1))){
                orientation = 2;
                if (movement < 2){
                  movement += 1;
                }else{
                  movement = 0;
                }
                speed = 1;
                positionChar.x += speed;

              }
            }
            if (tab_collide[positionChar.x - 1][positionChar.y] == 0 ){
              if (abs(event.button.x - (positionChar.x - 1)) < abs(event.button.x - (positionChar.x + 1))){
                orientation = 1;
                if (movement < 2){
                  movement += 1;
                }else{
                  movement = 0;
                }
                speed = 1;
                positionChar.x -= speed;
              }
            }
            if ((tab_collide[positionChar.x + 1][positionChar.y] != 0 ) || (tab_collide[positionChar.x - 1][positionChar.y] != 0)){
              speed = 0;
            }
            if (speed < 1){
             authorizedY = 0;
             speed = 1;
             if (event.button.y < (getButtonYUp(tab_button[1]) + (getButtonYDown(tab_button[1]) - getButtonYUp(tab_button[1]))/2)){
               if (event.button.y > (getButtonYUp(tab_button[0]) + (getButtonYDown(tab_button[0]) - getButtonYUp(tab_button[0]))/2)){
                 if (positionChar.x <= (getButtonYUp(tab_button[0]) + (getButtonYDown(tab_button[0]) - getButtonYUp(tab_button[0]))/2)){
                   speed = 1;
                   orientation = 0;
                 }else{
                   speed = -1;
                   orientation = 3;
                 }
               }else{
                 if (positionChar.x > (getButtonYUp(tab_button[0]) + (getButtonYDown(tab_button[0]) - getButtonYUp(tab_button[0]))/2)){
                   speed = -1;
                   orientation = 3;
                 }else{
                   speed = 1;
                   orientation = 0;
                 }
               }
             }else{
               if (event.button.y < (getButtonYUp(tab_button[2]) + (getButtonYDown(tab_button[2]) - getButtonYUp(tab_button[2]))/2)){
                 if (positionChar.x >= (getButtonYUp(tab_button[0]) + (getButtonYDown(tab_button[0]) - getButtonYUp(tab_button[0]))/2)){
                   speed = -1;
                   orientation = 3;
                 }else{
                   speed = 1;
                   orientation = 0;
                 }
               }else{
                 if (positionChar.x > (getButtonYUp(tab_button[0]) + (getButtonYDown(tab_button[0]) - getButtonYUp(tab_button[0]))/2)){
                   speed = 1;
                   orientation = 0;
                 }else{
                   speed = -1;
                   orientation = 3;
                 }
               }
             }
             if (movement < 2){
               movement += 1;
             }else{
               movement = 0;
             }
           positionChar.y += speed;
           }
          }
          authorizedX = 1;


          if ((positionChar.y != event.button.y) && (authorizedY)){
            if (tab_collide[positionChar.x][positionChar.y + 1] == 0 ){
              if (abs(event.button.y - (positionChar.y + 1)) < abs(event.button.y - (positionChar.y - 1))){
                orientation = 0;
                if (movement < 2){
                  movement += 1;
                }else{
                  movement = 0;
                }
                speed = 1;
                positionChar.y += speed;
              }
            }
            if (tab_collide[positionChar.x][positionChar.y - 1] == 0 ){
              if (abs(event.button.y - (positionChar.y - 1)) < abs(event.button.y - (positionChar.y + 1))){
                orientation = 3;
                if (movement < 2){
                  movement += 1;
                }else{
                  movement = 0;
                }
                speed = 1;
                positionChar.y -= speed;
              }
            }
            if (tab_collide[positionChar.x][positionChar.y + 1] != 0 ){
              speed = 0;
            }
            if (tab_collide[positionChar.x][positionChar.y - 1] != 0 ){
              speed = 0;
            }
            if (speed < 1){
             authorizedX = 0;
             speed = 1;
             if (event.button.x < (getButtonXLeft(tab_button[1]) + (getButtonXRight(tab_button[1]) - getButtonXLeft(tab_button[1]))/2)){
               speed = -1;
               orientation = 1;
             }
             if (event.button.x >= (getButtonXLeft(tab_button[1]) + (getButtonXRight(tab_button[1]) - getButtonXLeft(tab_button[1]))/2)){
               speed = 1;
               orientation = 2;
             }
             if (movement < 2){
               movement += 1;
             }else{
               movement = 0;
             }
           positionChar.x += speed;
           }
          }
          authorizedY = 1;
          if (event.button.x > getButtonXLeft(button_play) && event.button.x < getButtonXRight(button_play) &&
              event.button.y > getButtonYUp(button_play) - 32 && event.button.y < getButtonYDown(button_play)){
            if (positionChar.x >= getButtonXLeft(button_play) - 32 && positionChar.x <= getButtonXRight(button_play) + 1 &&
              positionChar.y >= getButtonYUp(button_play) - 32 && positionChar.y <= getButtonYDown(button_play) + 1){
                endMenu = 0;
                }
            }

         if (event.button.x > getButtonXLeft(button_goal) && event.button.x < getButtonXRight(button_goal) &&
             event.button.y > getButtonYUp(button_goal) - 32 && event.button.y < getButtonYDown(button_goal)){
           if (positionChar.x >= getButtonXLeft(button_goal) - 32 && positionChar.x <= getButtonXRight(button_goal) + 1 &&
             positionChar.y >= getButtonYUp(button_goal) - 32 && positionChar.y <= getButtonYDown(button_goal) + 1){
               goalPurpose = 1;
               authorizedX = 0;
               authorizedY = 0;
           }
         }
         if (event.button.x > getButtonXLeft(button_quit) && event.button.x < getButtonXRight(button_quit) &&
             event.button.y > getButtonYUp(button_quit) - 32 && event.button.y < getButtonYDown(button_quit)){
           if (positionChar.x >= getButtonXLeft(button_quit) - 32 && positionChar.x <= getButtonXRight(button_quit) + 1 &&
             positionChar.y >= getButtonYUp(button_quit) - 32 && positionChar.y <= getButtonYDown(button_quit) + 1){
               *gameOver = 1;
               endMenu = 0;
           }
        }
      }
      break;
    }
}
