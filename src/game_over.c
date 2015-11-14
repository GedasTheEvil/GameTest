#include "game_over.h"

void ShowDead()
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
     
     glPrint(300,500,"You are now dead");
     
     glPrint(300,450,"Congratulations");
        
     glMatrixMode(GL_PROJECTION);				// Select The Projection Matrix
     glPopMatrix();						// Restore The Old Projection Matrix
     glMatrixMode(GL_MODELVIEW);				// Select The Modelview Matrix
     
     glFlush();	
     glDisable(GL_BLEND);
     glBlendFunc(GL_DST_COLOR, GL_ZERO);
     
     glutSwapBuffers();
     
}

int CheckDead()
{
     if(you[0].HP <= 0)return 1;
     
     return 0;
}
