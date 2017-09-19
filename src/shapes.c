//
// Created by gedas on 9/19/17.
//

#include "shapes.h"

void drawRectangle(int w, int h)
{
    glBegin(GL_QUADS);
    glTexCoord2i(0, 1);
    glVertex2i(0, 0);
    glTexCoord2i(1, 1);
    glVertex2i(w, 0);
    glTexCoord2i(1, 0);
    glVertex2i(w, h);
    glTexCoord2i(0, 0);
    glVertex2i(0, h);
    glEnd();
}
