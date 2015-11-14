#include "game_win.h"

void ShowWin()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
     glLoadIdentity();
     
     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
     glEnable(GL_BLEND);
     glMatrixMode(GL_PROJECTION);					// Select The Projection Matrix
     glPushMatrix();							// Store The Projection Matrix
     glLoadIdentity();						// Reset The Projection Matrix
     glOrtho(0,800,0,600,-1,1);					// Set Up An Ortho Screen
     glMatrixMode(GL_MODELVIEW);					// Select The Modelview Matrix
     
     glBindTexture(GL_TEXTURE_2D,Btn[0].texID);
     
     glBegin(GL_QUADS);// bg		
     {
	  glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	  glTexCoord2i(1, 1); 	  glVertex2i(800,0);	// Texutre / Vertex Coord (Bottom Right)
	  glTexCoord2i(1, 0);	  glVertex2i(800,600);	// Texture / Vertex Coord (Top Right)
	  glTexCoord2i(0, 0);	  glVertex2i(0,600);	// Texture / Vertex Coord (Top Left)
     }
     glEnd();
     
     glPrint(300,500,"You are completed the demo");
     
     glPrint(300,450,"Congratulations");
     
     glPrint(200,400,"After your training you are ready to go out for adventure");
     glPrint(200,380,"The Evil wizzard Gedas is proud of you");
     
     glPrint(200,300,"The full version was planned to contain the following features:");
     glPrint(200,280,"* Item shops where you can buy great new items");
     glPrint(200,260,"* Spells of destruction and of blessings");
     glPrint(200,240,"* Mage guild");
     glPrint(200,220,"* Unique player classes");
     glPrint(200,200,"* Player skills");
     glPrint(200,180,"* Many maps and monsters");
     glPrint(200,160,"And much much more");
     
        
     glMatrixMode(GL_PROJECTION);				// Select The Projection Matrix
     glPopMatrix();						// Restore The Old Projection Matrix
     glMatrixMode(GL_MODELVIEW);				// Select The Modelview Matrix
     
     glFlush();	
     glDisable(GL_BLEND);
     glBlendFunc(GL_DST_COLOR, GL_ZERO);
     
     glutSwapBuffers();
     
}

