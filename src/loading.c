#include "loading.h"

void DrawLoad()
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
     
     glTranslated(150,300-16,0);
     
     glBindTexture(GL_TEXTURE_2D,Btn[BtnEmpty].texID);
     glBegin(GL_QUADS);		
     {
	  glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	  glTexCoord2i(1, 1); 	  glVertex2i(504,0);	// Texutre / Vertex Coord (Bottom Right)
	  glTexCoord2i(1, 0);	  glVertex2i(504,34);	// Texture / Vertex Coord (Top Right)
	  glTexCoord2i(0, 0);	  glVertex2i(0,34);	// Texture / Vertex Coord (Top Left)
     }
     glEnd();
     
     glTranslated(2,1,1);
     glBindTexture(GL_TEXTURE_2D,Btn[LoadBar].texID);
     glBegin(GL_QUADS);		
     {
	  glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	  glTexCoord2i(1, 1); 	  glVertex2i(5*loaded,0);	// Texutre / Vertex Coord (Bottom Right)
	  glTexCoord2i(1, 0);	  glVertex2i(5*loaded,32);	// Texture / Vertex Coord (Top Right)
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

void LoadAll()
{
     lastframe=SDL_GetTicks();
     DrawLoad();
//      if(texres)LoadGLTexturesHigh();                           // load the textures.
// 	  else LoadGLTexturesLow();
     loaded = 10;  
     DrawLoad();
     SetPlayerVars();
     loaded = 20;
     DrawLoad();
     
     InitItemList();
     LoadItems();
     loaded = 30;
     DrawLoad();
     
//      xx();//debug
     
     InitQList();
     loaded = 40;
     DrawLoad();
     
     
     quadratic=gluNewQuadric();                  // Create A Pointer To The Quadric Object ( NEW )
     //     set up lights.
     glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
     glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
     glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
     glEnable(GL_LIGHT1);
     glEnable(GL_LIGHTING);
     glEnable(GL_COLOR_MATERIAL);	
     loaded = 50;
     DrawLoad();
     
     //fog
     glFogi(GL_FOG_MODE, fogMode[fogFilter]);
     glFogfv(GL_FOG_COLOR, fogColor);
     glFogf(GL_FOG_DENSITY, 0.55f);
     glHint(GL_FOG_HINT, GL_DONT_CARE);
     glFogf(GL_FOG_START, -0.4f);
     glFogf(GL_FOG_END, -15.0f);
     loaded = 60;
     DrawLoad();
     
     
     if(sound)InitSounds();
     loaded = 70;
     DrawLoad();
     
     setupLand1();
     loaded = 100;
     DrawLoad();

     display = LAND1;

}
