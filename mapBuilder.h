#pragma once
#include "constants.h"
#include "isEmpty.h"

/*********************************************************************
This funtion fill a table with sprites values comming from a .txt file
*********************************************************************/
Uint16** mapBuilder();
/**************************************************************************************************
mapBoolean fill a table with boolean values ; 0 = empty (everything is empty my default) ; 1 = full
***************************************************************************************************/
Uint16** mapBoolean(Uint16** map_builder);
void destroyTab(Uint16** tab);
