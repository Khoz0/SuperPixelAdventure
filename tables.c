#include "tables.h"

Tables* createTables() {

  Tables* tables = malloc(sizeof(Tables));

  tables->map_builder = mapBuilder(MAP_WATER);
  tables->map_boolean = mapBoolean(tables->map_builder);

  return tables;

}

void updateTables(Tables* tables, int index_map) {

  tables->map_builder = mapBuilder(index_map);
  tables->map_boolean = mapBoolean(tables->map_builder);

}

Uint16** getTable(Tables* tables, int index) {

  if(!index) return tables->map_builder;
  if (index) return tables->map_boolean;

}

void destroyTables(Tables* tables) {

  destroyTab(tables->map_builder);
  destroyTab(tables->map_boolean);
  free(tables);
  tables = NULL;

}
