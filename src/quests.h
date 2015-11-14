#ifndef Quests
#define Quests

#include "vars.h"
#include "player.h"
#include "text.h"

void InitQList();
void DrawQuestInfo();
void DrawQuests();
void SelectQuest(int x, int y, int active);

#endif
