#include "constants.h"

typedef struct Boutons boutons;
struct Boutons{
  int xGauche;
  int xDroite;
  int yHaut;
  int yBas;
};

// void Collide(&i, &j, button_play, button_goal, button_quit);

void mainMenu(int* gameOver);
