#include "stats.h"
 
void ShowStats()
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
	
	glPushMatrix();
	glTranslated(30,50,1);
	glBindTexture(GL_TEXTURE_2D,Btn[BtnStats].texID);
	glBegin(GL_QUADS);		
	{
	     glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	     glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
	     glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
	     glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glTranslated(150,0,0);
	glBindTexture(GL_TEXTURE_2D,Btn[BtnSkill].texID);
	glBegin(GL_QUADS);		
	{
	     glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	     glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
	     glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
	     glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glTranslated(150,0,0);
	glBindTexture(GL_TEXTURE_2D,Btn[BtnInvent].texID);
	glBegin(GL_QUADS);		
	{
	     glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	     glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
	     glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
	     glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glTranslated(150,0,0);
	glBindTexture(GL_TEXTURE_2D,Btn[BtnQuest].texID);
	glBegin(GL_QUADS);		
	{
	     glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	     glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
	     glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
	     glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glTranslated(150,0,0);
	glBindTexture(GL_TEXTURE_2D,Btn[BtnLeave].texID);
	glBegin(GL_QUADS);		
	{
	     glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	     glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
	     glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
	     glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glPopMatrix();
	
	
	glPrint(50,550,"Level %d %s", you[0].level,you[0].class);
	glPrint(50,520,"Expirience %d.", you[0].XP);
	glPrint(50,490,"Level %d at %d XP",you[0].level + 1, 
	((you[0].level + 2)/2)* (you[0].level) * 1000);
	
	if(you[0].Str > you[0].StrM)glColor3f(0,1,0);
	else glColor3f(1,1,1);
	glPrint(50,450,"Strength %d/%d",you[0].Str,you[0].StrM);
	
	if(you[0].End > you[0].EndM)glColor3f(0,1,0);
	else glColor3f(1,1,1);
	glPrint(50,420,"Endurance %d/%d",you[0].End,you[0].EndM);
	
	if(you[0].Spd > you[0].SpdM)glColor3f(0,1,0);
	else glColor3f(1,1,1);
	glPrint(50,390,"Speed %d/%d",you[0].Spd,you[0].SpdM);
	
	if(you[0].Wsd > you[0].WsdM)glColor3f(0,1,0);
	else glColor3f(1,1,1);
	glPrint(50,360,"Wisdom %d/%d",you[0].Wsd,you[0].WsdM);
	
	glPrint(50,300,"Attack Damage %d",you[0].dmg);
	glPrint(50,270,"Bonus Attack Damage %d",you[0].dmgB);
	
	glPrint(50, 240,"Armor: %d", you[0].armor);
	
	glMatrixMode(GL_PROJECTION);				// Select The Projection Matrix
	glPopMatrix();						// Restore The Old Projection Matrix
	glMatrixMode(GL_MODELVIEW);				// Select The Modelview Matrix
	
	
	

	glFlush();	
	glDisable(GL_BLEND);
	glBlendFunc(GL_DST_COLOR, GL_ZERO);
	
	glutSwapBuffers();


}

