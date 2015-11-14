#include "shoot.h"
#include "../Models/arrow.h"

void SetProj(/*float x, float y*/)
{
	int i;
	for(i = 0; i < arrow.VC*3; i++)
		arrow.Vert[i] = ArrowVertex[i];

	arrow.visible = 0;
	arrow.life = 36;
	arrow.beg.x = xpos;
	if(display == LAND1)
	     arrow.beg.z = zpos +9.5;
	if(display == DUNG1)
	     arrow.beg.z = zpos;
	arrow.beg.y = -ytrans -0.1;
	Translate(arrow.Vert, arrow.VC, arrow.beg.x,arrow.beg.y, arrow.beg.z);
	arrow.end.x = -(float)sin(yrot*DegRad) * 18.0f;
	arrow.end.z = -(float)cos(yrot*DegRad) * 18.0f;
	arrow.end.y = -(float)sin(lookupdown*DegRad) * 18.0f;
	arrow.visible = 1;
	ShotDelay = 60 - you[0].Spd;
	if(ShotDelay <= 8)ShotDelay = 10;
	Selection();
}


void UpdProj()
{
	if(arrow.life)
	{
		arrow.life--;
		Translate(arrow.Vert, arrow.VC, arrow.end.x/36.0,arrow.end.y/36.0 ,arrow.end.z/36.0);
	}
	else arrow.visible = 0;

}


void Selection(void)			// This Is Where Selection Is Done
{
     GLuint	buffer[512];		// Set Up A Selection Buffer
     GLint	hits;			// The Number Of Objects That We Selected


	  // The Size Of The Viewport. [0] Is <x>, [1] Is <y>, [2] Is <length>, [3] Is <width>
	  GLint	viewport[4];

	  // This Sets The Array <viewport> To The Size And Location Of The Screen Relative To The Window
	  glGetIntegerv(GL_VIEWPORT, viewport);
	  glSelectBuffer(512, buffer);								// Tell OpenGL To Use Our Array For Selection

	  // Puts OpenGL In Selection Mode. Nothing Will Be Drawn.  Object ID's and Extents Are Stored In The Buffer.
	  (void) glRenderMode(GL_SELECT);

	  glInitNames();	// Initializes The Name Stack
	  glPushName(0);	// Push 0 (At Least One Entry) Onto The Stack

	  glMatrixMode(GL_PROJECTION);	// Selects The Projection Matrix
	  glPushMatrix();		// Push The Projection Matrix
	  glLoadIdentity();		// Resets The Matrix

	  // This Creates A Matrix That Will Zoom Up To A Small Portion Of The Screen, Where The Mouse Is.
	  gluPickMatrix((GLdouble) resX/2.0, (GLdouble) resY/2.0, 2.0f, 2.0f, viewport);

	  // Apply The Perspective Matrix
	  gluPerspective(45.0f, (GLfloat) (viewport[2]-viewport[0])/(GLfloat) (viewport[3]-viewport[1]), 0.1f, 100.0f);
	  glMatrixMode(GL_MODELVIEW);			// Select The Modelview Matrix
// 	  DrawTargets();				// Render The Targets To The Selection Buffer

	  if(display == LAND1)dLand1(0);
	  if(display == DUNG1)dDungeon(1);

	  glMatrixMode(GL_PROJECTION);			// Select The Projection Matrix
	  glPopMatrix();				// Pop The Projection Matrix
	  glMatrixMode(GL_MODELVIEW);			// Select The Modelview Matrix
	  hits=glRenderMode(GL_RENDER);			// Switch To Render Mode, Find Out How Many
	  // Objects Were Drawn Where The Mouse Was

	 //test
	 int dmg = you[0].dmg + you[0].dmgB;




	 if (hits > 0)		// If There Were More Than 0 Hits
	  {
	       int choose = buffer[3];	// Make Our Selection The First Object
	       int depth = buffer[1];		// Store How Far Away It Is
	       int loop;

	       for (loop = 1; loop < hits; loop++)		// Loop Through All The Detected Hits
	       {
		    // If This Object Is Closer To Us Than The One We Have Selected
		    if (buffer[loop*4+1] < depth  && buffer[loop*4+3] != 6 && buffer[loop*4+3] != 5)
		    {
			 choose = buffer[loop*4+3];		// Select The Closer Object
			 depth = buffer[loop*4+1];		// Store How Far Away It Is
		    }
	       }
	       if(display == LAND1)
		{
		      if (choose == 1)//anubis
		      {
			    anb[0].Hp -= (you[0].dmg + you[0].dmgB);
			    sprintf(tmppp,"You hit Anubis%d for %d damage\n",1,dmg);
			    tmpC=tmppp; tmp_text = 90;

			    if(anb[0].Hp <= 0)
			    {
				  you[0].XP += anb[0].XP;
				  anb[0].alive = 0;
				  Mix_PlayChannel(-1, AnbDie, 0);
				  GetItem(QList[1].itemNeeded);
				  tmpC = "You killed Anubis, gained 1 item";
			    }
		      }
		      if (choose == 2)//Spider #1
		      {
			    spd[0].Hp -= (you[0].dmg + you[0].dmgB);
			    sprintf(tmppp,"You hit Spider%d for %d damage\n",1,dmg);
			    tmpC=tmppp; tmp_text = 90;

			    if(spd[0].Hp <= 0)
			    {
				  you[0].XP += spd[0].XP;
				  spd[0].alive = 0;
				  Mix_PlayChannel(-1, SpdDie, 0);
				  tmpC = "You killed Giant Spider";
			    }
		      }

	       }
	       if(display == DUNG1)
		{
		     if (choose > 2)
		     {
			   Dun0Mobs[choose-3].Hp -= (you[0].dmg + you[0].dmgB);
			   sprintf(tmppp,"You hit Spider%d for %d damage\n",choose-3,dmg);
			   tmpC=tmppp; tmp_text = 90;

			   if(Dun0Mobs[choose-3].Hp <= 0)
			   {
				 you[0].XP += spd[0].XP;
				 Dun0Mobs[choose-3].alive = 0;
				 Mix_PlayChannel(-1, SpdDie, 0);
				 sprintf(tmppp,"You killed Spider%d \n",choose-3);
				 tmpC=tmppp; tmp_text = 90;
// 				 tmpC = "You killed Giant Spider";
			   }
		     }
// 		     printf("Debug::Hit%d\n",choose);
		}

	       checkLevel();
	  }

}

