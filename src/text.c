#include "text.h"

float orthoFontSize = 1.0f;

void setOrthoFontSize(float size)
{
	orthoFontSize = size;
}

GLvoid glPrint(GLint x, GLint y, const char *string, ...)	// Where The Printing Happens
{
	char		text[256];				// Holds Our String
	va_list		ap;					// Pointer To List Of Arguments
	if (string == NULL)					// If There's No Text
		return;						// Do Nothing

	va_start(ap, string);					// Parses The String For Variables
	    vsprintf(text, string, ap);				// And Converts Symbols To Actual Numbers
	va_end(ap);						// Results Are Stored In Text

	glBindTexture(GL_TEXTURE_2D, texttex.texID);			// Select Our Font Texture
	glPushMatrix();						// Store The Modelview Matrix
	glLoadIdentity();					// Reset The Modelview Matrix
	glTranslated(x,y,1);					// Position The Text (0,0 - Bottom Left)
	glListBase(base-32);					// Choose The Font Set
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
	glPopMatrix();						// Restore The Old Projection Matrix
}

GLvoid glPrintOrtho(GLint x, GLint y, const char *string, ...)
{
	char		text[256];				// Holds Our String
	va_list		ap;					// Pointer To List Of Arguments
	if (string == NULL)					// If There's No Text
		return;						// Do Nothing

	va_start(ap, string);					// Parses The String For Variables
	vsprintf(text, string, ap);				// And Converts Symbols To Actual Numbers
	va_end(ap);						// Results Are Stored In Text

	glBindTexture(GL_TEXTURE_2D, texttex.texID);			// Select Our Font Texture
	glPushMatrix();						// Store The Modelview Matrix
	glLoadIdentity();					// Reset The Modelview Matrix
	glTranslated(x,y,1);					// Position The Text (0,0 - Bottom Left)
	glScalef(0.125f * orthoFontSize, 0.17f *orthoFontSize, 1.0);
	glListBase(base-32);					// Choose The Font Set
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
	glPopMatrix();
}

GLvoid BuildFont()				// Build Our Font Display List
{
	base=glGenLists(95);					// Creating 95 Display Lists
	glBindTexture(GL_TEXTURE_2D,texttex.texID);	// Bind Our Font Texture
	int loop;
	for (loop=0; loop<95; loop++)			// Loop Through All 95 Lists
	{
		float cx=(float)(loop%16)/16.0f;			// X Position Of Current Character
		float cy=(float)(loop/16)/8.0f;			// Y Position Of Current Character

		glNewList(base+loop,GL_COMPILE);		// Start Building A List
		{
			glBegin(GL_QUADS);			// Use A Quad For Each Character
			{
				glTexCoord2f(cx,         1.0f-cy-0.120f); glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
				glTexCoord2f(cx+0.0625f, 1.0f-cy-0.120f); glVertex2i(12,0);	// Texutre / Vertex Coord (Bottom Right)
				glTexCoord2f(cx+0.0625f, 1.0f-cy);		  glVertex2i(12,12);// Texture / Vertex Coord (Top Right)
				glTexCoord2f(cx,         1.0f-cy);		  glVertex2i(0,12);	// Texture / Vertex Coord (Top Left)
			}
			glEnd();				// Done Building Our Quad (Character)
			glTranslated(7,0,0);			// Move To The Right Of The Character
		}
		glEndList();					// Done Building The Display List
	}							// Loop Until All 256 Are Built
	Minimap();
}

void Deinitialize (void)				// Any User DeInitialization Goes Here
{
// 	int nCo/*nt;*/
	
	glDeleteLists(base,95);				// Delete All 95 Font Display Lists
	glDeleteLists(miniMAp,2);
	
	free(texttex.imageData);
	free(minimap.imageData);
}

void Minimap()
{
	miniMAp=glGenLists(2);
	glBindTexture(GL_TEXTURE_2D,minimap.texID);
	glNewList(miniMAp,GL_COMPILE);
	{
			glBegin(GL_QUADS);			// Use A Quad For Each Character
			{
				glTexCoord2i(0, 0); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
				glTexCoord2i(1, 0); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
				glTexCoord2i(1, 1);	  glVertex2i(128,128);	// Texture / Vertex Coord (Top Right)
				glTexCoord2i(0, 1);	  glVertex2i(0,128);	// Texture / Vertex Coord (Top Left)
			}
			glEnd();
	}
	glEndList();
	
	miniMe = miniMAp+1;
	
	glNewList(miniMe,GL_COMPILE);
	{
			glBegin(GL_TRIANGLES);			// Use A Quad For Each Character
			{
				glTexCoord2f(0, 0.1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
				glTexCoord2f(0.1, 0); 	  glVertex2i(8,2);	// Texutre / Vertex Coord (Bottom Right)
				glTexCoord2f(0, 0);	  glVertex2i(0,4);	// Texture / Vertex Coord (Top Right)
			}
			glEnd();
	}
	glEndList();
}

void MinimapShow(int x, int y)
{
	glDisable(GL_BLEND);
	glBindTexture(GL_TEXTURE_2D,minimap.texID);
	glPushMatrix();						// Store The Modelview Matrix
	glLoadIdentity();					// Reset The Modelview Matrix
	glTranslated(x,y,0);					// Position The Text (0,0 - Bottom Left)
	glCallList(miniMAp);
	
	glTranslatef(-128.0*(zpos - 5.0)/30.0 ,-128*(xpos - 14)/26,0.01);
	glRotatef(yrot,0,0,1);
	glCallList(miniMe);
	glPopMatrix();
}

void CrossShow(int x, int y)
{
	glPushMatrix();						// Store The Modelview Matrix
	glLoadIdentity();					// Reset The Modelview Matrix
	glTranslated(x-8,y-8,0);					// Position The Text (0,0 - Bottom Left)

	glBindTexture(GL_TEXTURE_2D,cross.texID);
	glBegin(GL_QUADS);			// Use A Quad For Each Character
	{
		glTexCoord2i(0, 0); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 0); 	  glVertex2i(16,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 1);	  glVertex2i(16,16);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 1);	  glVertex2i(0,16);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	glPopMatrix();
}

void Inteface(int x, int y)
{
     glPushMatrix();						// Store The Modelview Matrix
     glLoadIdentity();					// Reset The Modelview Matrix
     glTranslated(x,y + 7,-0.2);					// Position The Text (0,0 - Bottom Left)
     
     
     
     glColor3f(1,1,1);
     
     glBindTexture(GL_TEXTURE_2D,Btn[Bar].texID);
     glBegin(GL_QUADS);			// Use A Quad For Each Character
     {
	   glTexCoord2i(0, 0); 	  
	   glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	   
	   glTexCoord2i(1, 0); 	  
	   glVertex2i(200,0);	// Texutre / Vertex Coord (Bottom Right)
	   
	   glTexCoord2i(1, 1);	  
	   glVertex2i(200,12);	// Texture / Vertex Coord (Top Right)
	   
	   glTexCoord2i(0, 1);	  
	   glVertex2i(0,12);	// Texture / Vertex Coord (Top Left)
     }
     glEnd();
     
     
     glTranslated(0,0,0.1);
     
     
     glColor3f(0.9,0.1,0.0);
     //health Bar
     glBindTexture(GL_TEXTURE_2D,Btn[Bar].texID);
    
     
     glBegin(GL_QUADS);			// Use A Quad For Each Character
     {
	   glTexCoord2i(0, 0); 	 
	   glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	   
	   glTexCoord2i(1, 0); 
	   glVertex2i((float)you[0].HP/you[0].HPM*200.0,0);	// Texutre / Vertex Coord (Bottom Right)
	   
	   glTexCoord2i(1, 1);
	   glVertex2i((float)you[0].HP/you[0].HPM*200.0,12);	// Texture / Vertex Coord (Top Right)
	   
	   glTexCoord2i(0, 1);
	   glVertex2i(0,12);	// Texture / Vertex Coord (Top Left)
     }
     glEnd();
     
     glTranslated(0,-15,0);					// Position The Text (0,0 - Bottom Left)
  
     glColor3f(1,1,1);
     
     glBindTexture(GL_TEXTURE_2D,Btn[Bar].texID);
     glBegin(GL_QUADS);			// Use A Quad For Each Character
     {
	   glTexCoord2i(0, 0); 	  
	   glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	   
	   glTexCoord2i(1, 0); 	  
	   glVertex2i(200,0);	// Texutre / Vertex Coord (Bottom Right)
	   
	   glTexCoord2i(1, 1);	  
	   glVertex2i(200,12);	// Texture / Vertex Coord (Top Right)
	   
	   glTexCoord2i(0, 1);	  
	   glVertex2i(0,12);	// Texture / Vertex Coord (Top Left)
     }
     glEnd();
     
     glTranslated(0,0,0.1);
     
     glColor3f(0.3,0.3,0.9);
     //mana Bar
     glBindTexture(GL_TEXTURE_2D,Btn[Bar].texID);
     glBegin(GL_QUADS);			// Use A Quad For Each Character
     {
	   glTexCoord2i(0, 0); 	  
	   glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	   
	   glTexCoord2i(1, 0); 	  
	   glVertex2i((float)you[0].MP/you[0].MPM*200,0);	// Texutre / Vertex Coord (Bottom Right)
	   
	   glTexCoord2i(1, 1);	  
	   glVertex2i((float)you[0].MP/you[0].MPM*200,12);	// Texture / Vertex Coord (Top Right)
	   
	   glTexCoord2i(0, 1);	  
	   glVertex2i(0,12);	// Texture / Vertex Coord (Top Left)
     }
     glEnd();
     
     glColor3f(1,1,1);
     
     
     glPopMatrix(); 
}
	
void Text()
{
	//======================================================
	// Here lives our text
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glMatrixMode(GL_PROJECTION);					// Select The Projection Matrix
	glPushMatrix();							// Store The Projection Matrix
	glLoadIdentity();						// Reset The Projection Matrix
	glOrtho(0,800,0,600,-1,1);					// Set Up An Ortho Screen
	glMatrixMode(GL_MODELVIEW);					// Select The Modelview Matrix

	Inteface(5,475);
	
	glPrint(10,530,"Class: %s", you[plClass].class);	
	glPrint(10,510,"Level: %d", you[plClass].level);

	glPrint(10,481,"Hitpoints:  %d/%d", you[plClass].HP, you[plClass].HPM);
	glPrint(10,467,"Mana:  %d/%d", you[plClass].MP,you[plClass].MPM );
	glPrint(10,400,"Gold: %d", you[plClass].Gold );
	
	if(tmp_text){glPrint(50,70,tmpC); tmp_text--;}
	CrossShow(400,300);
	if(L1map)MinimapShow(600, 60);
	glTranslated(400,300,0);



	glMatrixMode(GL_PROJECTION);				// Select The Projection Matrix
	glPopMatrix();						// Restore The Old Projection Matrix
	glMatrixMode(GL_MODELVIEW);				// Select The Modelview Matrix

	glFlush();	
	glDisable(GL_BLEND);
	glBlendFunc(GL_DST_COLOR, GL_ZERO);
	//======================================================
}

