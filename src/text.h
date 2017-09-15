#ifndef RPGtext
#define RPGtext

#include "vars.h"
#include "textures.h"
#include "player.h"

extern GLint fontSize;
GLvoid glPrint(GLint x, GLint y, const char *string, ...);
GLvoid glPrintOrtho(GLint x, GLint y, const char *string, ...);
GLvoid BuildFont();
void Deinitialize (void);
void Minimap();
void MinimapShow(int x, int y);
void CrossShow(int x, int y);
void Inteface(int x, int y);
void Text();
void setOrthoFontSize(float size);

#endif
