#ifndef SceneSetup
#define SceneSetup

#include "vars.h"
#include "textures.h"
#include "AI.h"
#include "passage.h"
#include "shoot.h"
#include "text.h"
#include "../Maps/Dungeon0.h"

void Translate(float *a, int b,float x, float y, float z);
void Scale(float *a, int b, float m);
void RotateZ(building house);
void DrawProj(proj ar);
void DrawHouse(building house);
void DrawMon(monster m);
void NormalizeZ(float *A, int b);
void setupBuilding(building a);
void setupLand1();
float getZ();
void Dungeon1();
void compL1();
void dLand1(int selection);
void dDungeon(int selection);
void DrawMapItems();

#endif
