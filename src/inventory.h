#ifndef Inventory
#define Inventory

#include "items.h"
#include "vars.h"
#include "text.h"
#include "player.h"

#define INVENTORY_GRID_START_X 4
#define INVENTORY_GRID_START_Y 4
#define INVENTORY_GRID_END_X 62
#define INVENTORY_GRID_END_Y 67
#define INVENTORY_GRID_ITEM_W 10
#define INVENTORY_GRID_ITEM_H 13
#define INVENTORY_GRID_ITEM_ROW_LENGTH 6

void DrawItem(int ID, int x, int y);
void DrawItemInfo();
void DrawInventory();
void TakeItem(int x, int y, int button);
void GetItem(int item);

#endif
