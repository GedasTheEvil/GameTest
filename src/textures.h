#ifndef TEXTUROS
#define TEXTUROS

#include "vars.h"

short LoadTGA(TextureImage *texture, char *filename);
int ImageLoad(char *filename, Image *image);
int ImageLoad32(char *filename, Image *image);
void LoadGLTexturesLow();
void LoadGLTexturesHigh();
void LoadIntefaceTex();
void LoadItems();

#endif
