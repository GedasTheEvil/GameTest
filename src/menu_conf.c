#include "menu_conf.h"

void DCMenu()
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
	
	glPrint(320,570,"Configuration");

	glPrint(70,515,"Music");
	glTranslated(150,500,0);
	
	if(music)glBindTexture(GL_TEXTURE_2D,Btn[BtnCh1].texID);
	else glBindTexture(GL_TEXTURE_2D,Btn[BtnCh0].texID);
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(32,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(32,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glPrint(70,440,"Sound");
	glTranslated(0,-60,0);
	if(sound)glBindTexture(GL_TEXTURE_2D,Btn[BtnCh1].texID);
	else glBindTexture(GL_TEXTURE_2D,Btn[BtnCh0].texID);
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(32,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(32,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glPrint(70,380,"Texture Quality");
	glPrint(100,340,"Low");
	glPrint(100,300,"High");
	glTranslated(30,-100,0);
	if(texres)glBindTexture(GL_TEXTURE_2D,Btn[BtnCh0].texID);
	else glBindTexture(GL_TEXTURE_2D,Btn[BtnCh1].texID);
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(32,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(32,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	glTranslated(0,-40,0);
	if(texres)glBindTexture(GL_TEXTURE_2D,Btn[BtnCh1].texID);
	else glBindTexture(GL_TEXTURE_2D,Btn[BtnCh0].texID);
		glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(32,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(32,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	
	glPrint(400,515,"Resolution");
	
	glPrint(400,475,"%d x %d",resX,resY);
	glPrint(400,415,"Full Screen");
	
	glTranslated(360,110,0);
	if(fs)glBindTexture(GL_TEXTURE_2D,Btn[BtnCh1].texID);
	else glBindTexture(GL_TEXTURE_2D,Btn[BtnCh0].texID);
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(32,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(32,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glTranslated(-50,-390,0);
	
	glBindTexture(GL_TEXTURE_2D,Btn[BtnSave].texID);
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glTranslated(140,0,0);
	
	glBindTexture(GL_TEXTURE_2D,Btn[BtnLeave].texID);
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

