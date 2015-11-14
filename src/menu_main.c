#include "menu_main.h"

void DMMenu()
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
	
	glBindTexture(GL_TEXTURE_2D,Btn[BtnBG].texID);
	
	glBegin(GL_QUADS);// bg		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(800,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(800,600);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,600);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();

	glTranslated(336,400,0);
	
	glBindTexture(GL_TEXTURE_2D,Btn[BtnNewGame].texID);
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glTranslated(0,-52,0);
	glBindTexture(GL_TEXTURE_2D,Btn[BtnLoad].texID);
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();

	glTranslated(0,-52,0);
	glBindTexture(GL_TEXTURE_2D,Btn[BtnConf].texID);
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();

	glTranslated(0,-52,0);
	glBindTexture(GL_TEXTURE_2D,Btn[BtnCredits].texID);
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();

	glTranslated(0,-52,0);
	glBindTexture(GL_TEXTURE_2D,Btn[BtnExit].texID);
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	
	glMatrixMode(GL_PROJECTION);				// Select The Projection Matrix
	glPopMatrix();						// Restore The Old Projection Matrix
	glMatrixMode(GL_MODELVIEW);				// Select The Modelview Matrix

	glFlush();	
	glDisable(GL_BLEND);
	glBlendFunc(GL_DST_COLOR, GL_ZERO);
	
	glutSwapBuffers();
	
}

