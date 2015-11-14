#ifndef RPGKeyboard
#define RPGKeyboard

#include "vars.h"
#include "textures.h"

#include "passage.h"
#include "player.h"
#include "TextInput.h"
#include "Exit.h"
#include "../Maps/Dungeon0.h"

#define ESCAPE 27

void keyPressed(unsigned char key, int x, int y);
void specialKeyPressed(int key, int x, int y);

#endif
