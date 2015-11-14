#ifndef RPGtext
#define RPGtext

#include "vars.h"
#include "textures.h"
#include "player.h"

GLvoid glPrint(GLint x, GLint y, const char *string, ...);
GLvoid BuildFont();
void Deinitialize (void);
void Minimap();
void MinimapShow(int x, int y);
void CrossShow(int x, int y);
void Inteface(int x, int y);
void Text();

#endif
