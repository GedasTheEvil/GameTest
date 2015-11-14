#ifndef RPGscene
#define RPGscene

#include "vars.h"
#include "building_inside.h"
#include "menu_main.h"
#include "menu_conf.h"
#include "stats.h"
#include "credits.h"
#include "TextInput.h"
#include "menu_game.h"
#include "shoot.h"
#include "inventory.h"
#include "quests.h"
#include "sceneSetup.h"
#include "loading.h"
#include "game_over.h"
#include "game_win.h"

int LockFramesPerSecond(int framerate);
void Draw();
void Idle();

#endif
