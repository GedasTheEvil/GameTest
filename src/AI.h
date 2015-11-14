#ifndef gameAI
#define gameAI

#include "vars.h"
// #include "scene.h"
// #include "sounds.h"
#include "passage.h"
#include "game_over.h"
#include "../Maps/Dungeon0.h"

void ShowMoveDir(monster m, float vx, float vz);
int Decide(monster m);
void Anim(monster m);
void L1Anim();
void Dung1Anim();
int DecideD(monster m);

#endif
