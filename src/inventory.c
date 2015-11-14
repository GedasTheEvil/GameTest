#include "inventory.h"

void DrawItem(int ID, int x, int y)
{
     glPushMatrix();
	   glBindTexture(GL_TEXTURE_2D,Itm[ID].texID);
	   glTranslatef(x,y,0.1);
	   glBegin(GL_QUADS);// bg		
	   {
		 glTexCoord2i(0, 1);   glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		 glTexCoord2i(1, 1);   glVertex2i(64,0);	// Texutre / Vertex Coord (Bottom Right)
		 glTexCoord2i(1, 0);	  glVertex2i(64,64);	// Texture / Vertex Coord (Top Right)
		 glTexCoord2i(0, 0);	  glVertex2i(0,64);	// Texture / Vertex Coord (Top Left)
	   }
	   glEnd();
     glPopMatrix();
}


void DrawItemInfo()
{
     if(infoItem == 0 )
     {
	   infoShow = 0;
	   return;
     }
     infoShow--;
     
     glPushMatrix();
	   glTranslatef(150,250,0.2);
	   
	   glBindTexture(GL_TEXTURE_2D,Btn[BtnInfBG].texID);
	   glBegin(GL_QUADS);// bg		
	   {
		 glTexCoord2i(0, 1);   glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		 glTexCoord2i(1, 1);   glVertex2i(520,0);	// Texutre / Vertex Coord (Bottom Right)
		 glTexCoord2i(1, 0);	  glVertex2i(520,300);	// Texture / Vertex Coord (Top Right)
		 glTexCoord2i(0, 0);	  glVertex2i(0,300);	// Texture / Vertex Coord (Top Left)
	   }
	   glEnd();
	   DrawItem(infoItem,20,200);
	   glPrint(350,510,"%s", List[infoItem].Name);
	   
	   glPrint(250,470,"%s", List[infoItem].L1);
	   glPrint(250,460,"%s", List[infoItem].L2);
	   glPrint(250,440,"%s", List[infoItem].L3);
	   glPrint(250,430,"%s", List[infoItem].L4);
	   if(List[infoItem].Armor)glPrint(250,420,"Armor: %d", List[infoItem].Armor);
	   if(List[infoItem].Damage)glPrint(250,410,"Damage: %d", List[infoItem].Damage);
	   glPrint(250,400,"Value: %d gold", List[infoItem].Value);
     glPopMatrix();
}

void DrawInventory()
{
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
     
     glBindTexture(GL_TEXTURE_2D,Itm[0].texID);
     
     glBegin(GL_QUADS);// bg		
     {
	   glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
	   glTexCoord2i(1, 1); 	  glVertex2i(800,0);	// Texutre / Vertex Coord (Bottom Right)
	   glTexCoord2i(1, 0);	  glVertex2i(800,600);	// Texture / Vertex Coord (Top Right)
	   glTexCoord2i(0, 0);	  glVertex2i(0,600);	// Texture / Vertex Coord (Top Left)
     }
     glEnd();
     
     // Main inventory
     int kkk;
     int iii = 0;
     int jjj = 0;
     
     if(infoShow)DrawItemInfo(infoItem);
     
     for(kkk = 0x00; kkk < 30; kkk++)	   
     {
	   if(InvGrid[kkk])
		 DrawItem(InvGrid[kkk],40 + 78*iii, 505 - 75*jjj);
	   
	   iii++;   
	   if(iii >= 6)
	   {
		 iii = 0; 
		 jjj++;
	   }
     }
     // !Main inventory
     
     if(selectedItem)
     {
	   DrawItem(selectedItem,mouseX*((float)resY/(float)resX)*1.4,500-MouseY);
     }
     
     if(Helm)DrawItem(Helm,625, 505);
     if(Boots)DrawItem(Boots,625, 350);
     if(RHand)DrawItem(RHand,700, 428);
     if(LHand)DrawItem(LHand,545, 428);
     if(Armor)DrawItem(Armor,625, 428);
     
     //text goes here
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

void TakeItem(int x, int y, int button)
{
     int temp = 0x00;
     
//      printf("Called with x=%d y=%d button =%d\n",x,y,button);
     
//      if(button == LMB)
     {
// 	   printf("LMB ok\n");
	   //Basic inventory
     //------------------------------------------------------------
	   if(y > (int)(resY*0.043) && y < (int)(resY*0.163))
	   {
// 		 printf("row1\n");
		 if(x > (int)(resX*0.043) && x < (int)(resX*0.12))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[0];
			    InvGrid[0] = temp; 
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[0];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.12) && x < (int)(resX*0.237))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[1];
			    InvGrid[1] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[1];
			    infoShow = 120;
		      }
		       
		 }
		 
		 if(x > (int)(resX*0.237) && x < (int)(resX*0.333))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[2];
			    InvGrid[2] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[2];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.333) && x < (int)(resX*0.431))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[3];
			    InvGrid[3] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[3];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.432) && x < (int)(resX*0.529))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[4];
			    InvGrid[4] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[4];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.530) && x < (int)(resX*0.624))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[5];
			    InvGrid[5] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[5];
			    infoShow = 120;
		      } 
		 }
		 
	   }
	   //------------------------------------------------------------
	   else if(y > (int)(resY*0.163) && y < (int)(resY*0.292))
	   {
// 		 printf("row2\n");
		 if(x > (int)(resX*0.043) && x < (int)(resX*0.12))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[6];
			    InvGrid[6] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[6];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.12) && x < (int)(resX*0.237))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[7];
			    InvGrid[7] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[7];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.237) && x < (int)(resX*0.333))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[8];
			    InvGrid[8] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[8];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.333) && x < (int)(resX*0.431))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[9];
			    InvGrid[9] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[9];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.432) && x < (int)(resX*0.529))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[10];
			    InvGrid[10] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[10];
			    infoShow = 120;
		      } 
		 }
		 
		 if(x > (int)(resX*0.530) && x < (int)(resX*0.624))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[11];
			    InvGrid[11] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[11];
			    infoShow = 120;
		      }
		 }
		 
	   }
	   //------------------------------------------------------------
// 	   else if(y > (int)(resY*0.420) && y < (int)(resY*0.539))
	   else if(y > (int)(resY*0.292) && y < (int)(resY*0.419))
	   {
// 		 printf("row3\n");
		 if(x > (int)(resX*0.043) && x < (int)(resX*0.12))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[12];
			    InvGrid[12] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[12];
			    infoShow = 120;
		      } 
		 }
		 
		 if(x > (int)(resX*0.12) && x < (int)(resX*0.237))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[13];
			    InvGrid[13] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[13];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.237) && x < (int)(resX*0.333))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[14];
			    InvGrid[14] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[14];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.333) && x < (int)(resX*0.431))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[15];
			    InvGrid[15] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[15];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.432) && x < (int)(resX*0.529))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[16];
			    InvGrid[16] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[16];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.530) && x < (int)(resX*0.624))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[17];
			    InvGrid[17] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[17];
			    infoShow = 120;
		      }
		 }
		 
	   }
	   //------------------------------------------------------------
// 	   else if(y > (int)(resY*0.540) && y < (int)(resY*0.666))
	   else if(y > (int)(resY*0.420) && y < (int)(resY*0.539))
	   {
// 		 printf("row4\n");
		 if(x > (int)(resX*0.043) && x < (int)(resX*0.12))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[18];
			    InvGrid[18] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[18];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.12) && x < (int)(resX*0.237))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[19];
			    InvGrid[19] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[19];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.237) && x < (int)(resX*0.333))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[20];
			    InvGrid[20] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[20];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.333) && x < (int)(resX*0.431))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[21];
			    InvGrid[21] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[21];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.432) && x < (int)(resX*0.529))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[22];
			    InvGrid[22] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[22];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.530) && x < (int)(resX*0.624))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[23];
			    InvGrid[23] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[23];
			    infoShow = 120;
		      }
		 }
		 
	   }
	   
	   else if(y > (int)(resY*0.540) && y < (int)(resY*0.666))
	   {
// 		 printf("row5\n");
		 if(x > (int)(resX*0.043) && x < (int)(resX*0.12))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[24];
			    InvGrid[24] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[24];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.12) && x < (int)(resX*0.237))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[25];
			    InvGrid[25] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[25];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.237) && x < (int)(resX*0.333))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[26];
			    InvGrid[26] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[26];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.333) && x < (int)(resX*0.431))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[27];
			    InvGrid[27] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[27];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.432) && x < (int)(resX*0.529))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[28];
			    InvGrid[28] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[28];
			    infoShow = 120;
		      }
		 }
		 
		 if(x > (int)(resX*0.530) && x < (int)(resX*0.624))
		 {
		      if(button == LMB)
		      {      
			    temp = selectedItem; 
			    selectedItem =  InvGrid[29];
			    InvGrid[29] = temp;
		      }
		      else if(button == RMB)
		      {
			    infoItem = InvGrid[29];
			    infoShow = 120;
		      }
		 }
		 
	   }
	   //---------------------------------------------------------
		 // End of Basic inventory. Start: helmet
	   //---------------------------------------------------------
	   if(  y > (int)(resY*0.043) && 
		 y < (int)(resY*0.157) && 
		 x > (int)(resX*0.773) && 
		 x < (int)(resX*0.862) &&
		      ((selectedItem >= 0x40 &&
		      selectedItem <= 0x4f)  ||
		      !selectedItem))
	   {
		 if(button == LMB)
		 {      
		      temp = Helm; 
		      Helm = selectedItem;
		      selectedItem = temp;
		      checkLevel();
		 }
		 else if(button == RMB)
		 {
		      infoItem = Helm;
		      infoShow = 120;
		 }
		 
	   }
	   // ------------end of helmet. start boots
	   if(  y > (int)(resY*0.306) && 
		 y < (int)(resY*0.414) && 
		 x > (int)(resX*0.773) && 
		 x < (int)(resX*0.862) &&
		 ((selectedItem >= 0x20 &&
		 selectedItem <= 0x2f)  ||
		 !selectedItem))
	   {
		 if(button == LMB)
		 {      
		      temp = Boots; 
		      Boots = selectedItem;
		      selectedItem = temp;
		      checkLevel();
		 }
		 else if(button == RMB)
		 {
		      infoItem = Boots;
		      infoShow = 120;
		 }
		 
	   }
	   
	   // ------------end of boots. start shield
	   if(  y > (int)(resY*0.174) && 
		 y < (int)(resY*0.285) && 
		 x > (int)(resX*0.870) && 
		 x < (int)(resX*0.962) &&
		 ((selectedItem >= 0x70 &&
		 selectedItem <= 0x7f)  ||
		 !selectedItem))
	   {
		 if(button == LMB)
		 {      
		      temp = RHand; 
		      RHand = selectedItem;
		      selectedItem = temp;
		      checkLevel();
		 }
		 else if(button == RMB)
		 {
		      infoItem = RHand;
		      infoShow = 120;
		 }
		 
	   }
	   // ------------end of shield. start armor
	   if(  y > (int)(resY*0.174) && 
		 y < (int)(resY*0.285) && 
		 x > (int)(resX*0.772) && 
		 x < (int)(resX*0.858) &&
		 ((selectedItem >= 0x10 &&
		 selectedItem <= 0x1f)  ||
		 !selectedItem))
	   {
		 if(button == LMB)
		 {      
		      temp = Armor; 
		      Armor = selectedItem;
		      selectedItem = temp;
		      checkLevel();
		 }
		 else if(button == RMB)
		 {
		      infoItem = Armor;
		      infoShow = 120;
		 }
		 
	   }
	   // ------------end of armor. Weapon start
	   if(  y > (int)(resY*0.174) && 
		 y < (int)(resY*0.285) && 
		 x > (int)(resX*0.672) && 
		 x < (int)(resX*0.758) &&
		 ((selectedItem >= 0x01 &&
		 selectedItem <= 0x0f)  ||
		 !selectedItem))
	   {
		 if(button == LMB)
		 {      
		      temp = LHand; 
		      LHand = selectedItem;
		      selectedItem = temp;
		      checkLevel();
		 }
		 else if(button == RMB)
		 {
		      infoItem = LHand;
		      infoShow = 120;
		 }
		 
	   }
	   // ------------end of Weapon. 
	   
     }
	 
}

void GetItem(int item)
{
     int put = 0;
     int i;
     for(i = 0; i < 30; i++)
	   if(!InvGrid[i])
	   {
		 InvGrid[i] = item;
		 put = 1;
		 break;
	   }
	   
     if(put) return;
     
     for(i = 0; i < 30; i++)
	   if(item >= 128 && InvGrid[i] < 128)// we replace some item with quest item
	   {
		 InvGrid[i] = item;
		 put = 1;
		 break;
	   }
}


