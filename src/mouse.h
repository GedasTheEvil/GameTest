#ifndef RPGmouse
#define RPGmouse

#include "vars.h"
#include "keyboard.h"
#include "events.h"
#include "shoot.h"
#include "conf.h"
#include "loading.h"
#include "sounds.h"
#include "building_inside.h"

void processMouse(int button, int state, int x, int y); 
void processMouseActiveMotion(int x, int y);
void processMousePassiveMotion(int x, int y);
void processMouseEntry(int state);

#endif