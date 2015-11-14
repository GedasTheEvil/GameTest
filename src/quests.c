#include "quests.h"

void InitQList()
{
     QList = (quest *) malloc(0x0f * sizeof(quest));
     
     int i;
     for(i = 0; i < 15; i++)
     {     
	   QList[i].accepted = 0;
	   QList[i].complete = 0;
	   QList[i].XPReward = 0;
	   QList[i].itemNeeded = 0x00;
	   QList[i].GoldReward = 0;
	   QList[i].itemReward = 0;
	   strcpy(QList[i].Name , "NULL item\0\n");
	   strcpy(QList[i].L1   , "NULL item\0\n");
	   strcpy(QList[i].L2   , "NULL item\0\n");
	   strcpy(QList[i].L3   , "NULL item\0\n");
	   strcpy(QList[i].L4   , "NULL item\0\n");
	   strcpy(QList[i].QComplete, "NULL item\0\n");
     }
     
     
     strcpy(QList[0x00].Name, "Leave this place\0");
     QList[0x00].XPReward = 9000;
     QList[0x00].itemNeeded = 0;
     QList[0x00].GoldReward = 0;
     strcpy(QList[0x00].L1, "You have been stranded in this land by the wizzard Gedas  \0");
     strcpy(QList[0x00].L2, "as part of your training to become an adventuring hero. \0");
     strcpy(QList[0x00].L3, "you will need to learn to fight, trade, and survive . \0");
     strcpy(QList[0x00].L4, "Good luck to you! .\0");
     strcpy(QList[0x00].QComplete, "Congratulations, demo complete.\0");
     QList[0x00].accepted =1;
     
     strcpy(QList[0x01].Name, "Missing beer mug\0");
     QList[0x01].XPReward = 3000;
     QList[0x01].itemNeeded = 129;
     QList[0x01].GoldReward = 250;
     strcpy(QList[0x01].L1, "Long time ago our tavern received a beer mug from Xelsor. \0");
     strcpy(QList[0x01].L2, "We have been showing it with pride to all visitors but .  \0");
     strcpy(QList[0x01].L3, "a creature came, called itself anubis, and took the mug . \0");
     strcpy(QList[0x01].L4, "If you can get the mug from him, we'll be very gratefull .\0");
     strcpy(QList[0x01].QComplete, "Ah, the mug! Here is a hefty reward of 250 gold coins for it.\0");
     
     strcpy(QList[0x02].Name, "Missing Captain\0");
     QList[0x02].XPReward = 5000;
     QList[0x02].itemNeeded = 130;
     QList[0x02].GoldReward = 2500;
     strcpy(QList[0x02].L1, "The only way to leave this land is by sea. \0");
     strcpy(QList[0x02].L2, "However the captain of the only ship is missing.  \0");
     strcpy(QList[0x02].L3, "The people should know what happened to him. \0");
     strcpy(QList[0x02].L4, "Time to investigate.\0");
     strcpy(QList[0x02].QComplete, "Hah, thank you for saving me. I'll be you captain from now.\0");
     
}
     
void DrawQuestInfo()
{
     infoQShow--;
     
     glPushMatrix();
     glTranslatef(150,250,0.4);
     
     glBindTexture(GL_TEXTURE_2D,Btn[BtnInfBG].texID);
     glBegin(GL_QUADS);// bg		
     {
	   glTexCoord2i(0, 1);   glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	   glTexCoord2i(1, 1);   glVertex2i(520,0);	// Texutre / Vertex Coord (Bottom Right)
	   glTexCoord2i(1, 0);	  glVertex2i(520,300);	// Texture / Vertex Coord (Top Right)
	   glTexCoord2i(0, 0);	  glVertex2i(0,300);	// Texture / Vertex Coord (Top Left)
     }
     glEnd();
     glPrint(350,510,"%s", QList[infoQuest].Name);
     glPrint(210,468,"%s", QList[infoQuest].L1);
     glPrint(210,456,"%s", QList[infoQuest].L2);
     glPrint(210,444,"%s", QList[infoQuest].L3);
     glPrint(210,432,"%s", QList[infoQuest].L4);
     glPrint(210,414,"Status: %d", QList[infoQuest].complete);
     if(QList[infoQuest].itemNeeded)
	   glPrint(200,400,"Item needed (No.%d): %s ",QList[infoQuest].itemNeeded, List[QList[infoQuest].itemNeeded].Name);
     glPopMatrix();
}

void DrawQuests()
{
     glColor3f(1,1,1);
     glDisable(GL_LIGHTING);
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
     
     if(infoQShow)DrawQuestInfo();
     
//	text is here
     int kkk; // kuklusklanas :D
     for(kkk = 0; kkk < 15; kkk++)
     if( QList[kkk].accepted)
     {
	   if(HQ[kkk])glColor3f(0,1,0);
	   else if(QList[kkk].complete)glColor3f(0.5,0.4,0.8);
	   else glColor3f(1,1,1);
	   glPrint(50,550 -(kkk*25),"%d: %s",kkk+1, QList[kkk].Name);
     }
     
     glColor3f(1,1,1);
//	!text is here
     
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
     
     
     glMatrixMode(GL_PROJECTION);				// Select The Projection Matrix
     glPopMatrix();						// Restore The Old Projection Matrix
     glMatrixMode(GL_MODELVIEW);				// Select The Modelview Matrix
     
     glFlush();	
     glDisable(GL_BLEND);
     glBlendFunc(GL_DST_COLOR, GL_ZERO);
     
     glutSwapBuffers();
     glEnable(GL_LIGHTING);
}

void SelectQuest(int x, int y, int active)
{
     //WTF, why bugging???
     int j =0;
     int i;
     
     quest tmpQ;

     if(x > (int)(resX*0.069) && x < (int)(resX*0.81))
     {
	   for(i = 0; i < 15 ; i++)
	   {
		 if(    (y >  (int)(resY * 0.057 + i*resY*0.041 + (i-1)*0.001)) 
		    &&  (y <  (int)(resY * 0.091 + i*resY*0.041)) 
		    && QList[i].accepted) 
		      
		 {
		      if(active)
		      {
			    infoQuest = i;
			    infoQShow = 120;
		      }
		      else
		      {
			    for(j = 0; j < 15; j++)
				  HQ[j] = 0;
			    HQ[i] = 1;
			    
			    tmpQ = QList[sellectedQuest];
			    QList[sellectedQuest] = QList[i];
			    QList[i] = tmpQ;
			    
			    sellectedQuest = i;
		      }
		 }
	   }
     }     
}

