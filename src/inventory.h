#ifndef Inventory
#define Inventory

#include "items.h"
#include "vars.h"
#include "text.h"
#include "player.h"

void DrawItem(int ID, int x, int y);
void DrawItemInfo();
void DrawInventory();
void TakeItem(int x, int y, int button);
void GetItem(int item);

#endif
