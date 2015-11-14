#ifndef Dungeon0
#define  Dungeon0

#include <GL/gl.h>
#include "../src/vars.h"

void Make0Segment();
void CreateDungeon0();
void InitMobs0();
void Init0Items();
int wallSeg0;
int wallESeg0;
int DungList0;

extern int Dun0MobC ;

extern int Dun0ItemC ;

extern float D0X;
extern float D0Y;
extern int Passmap0[];

extern monster Dun0Mobs[];

extern itmL Dun0Items[];


#endif
