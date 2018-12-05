#pragma once
#include "constants.h"
#include "mapBuilder.h"
#include "mapBoolean.h"
#include "destroyTab.h"

typedef struct Tables {

  Uint16** map_builder;
  Uint16** map_boolean;

} Tables;

Tables* createTables();
void updateTables(Tables* tables, int index_map);
Uint16** getTable(Tables* tables, int index);
void destroyTables();
