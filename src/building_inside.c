#include "building_inside.h"
void HoSide()
{
     glDisable(GL_LIGHTING);
    
     switch(ID)
     {
	   case TempleI: 
		 HT = TempleI;
		 if(!HAtimer)
		 {
		      glPrint(600,550,"Temple");
		      BAct1 = "Heal";
		      BAct2 = "Donate";
		      BAct3 = "";
		      BL1 = "You can heal your wounds at the temple";
		      BL2 = "or donate some gold for the poor";
		      BL3 = "";
		      BL4 = "";
		      BL5 = "";		      
		 }
		 
		 break;
		 
	   case eHouseI: 
		 HT = eHouseI;
		 if(!HAtimer)
		 {
		      glPrint(600,550,"House");
		      BAct1 = "";
		      BAct2 = "";
		      BAct3 = "";
		      BL1 = "A peasant is living here";
		      BL2 = "";
		      BL3 = "";
		      BL4 = "";
		      BL5 = "";
		      
		 }
		 break;
		 
	   case eShipI:
		 HT = eShipI;
		 if(!HAtimer)
		 {
		      if(QList[0x02].accepted && (QList[0x02].itemNeeded))
		      BAct1 = "";
		      BAct2 = "";
		      BAct3 = "";
		      BL1 = "The captain of this ship is missing";
		      BL2 = "";
		      BL3 = "";
		      BL4 = "";
		      BL5 = "";
		 }
		 if(!QList[0x02].accepted)QList[0x02].accepted = 1;
		 int radom = 0;
		 int i;
		 for(i = 0; i < 30; i++)
		      if(InvGrid[i] == QList[0x02].itemNeeded)
		      {
			    BAct1 = "Take over the ship and leave";	
		      }

		 break;
		 
	   case TavernI:
		 HT = TavernI;
		 if(!HAtimer)
		 {
		      BAct1 = "Get a drink";
		      BAct2 = "Spend the night here";
		      BAct3 = "Quest";
		      BL1 = "The tavern is where everyone comes for a drink";
		      BL2 = "";
		      BL3 = "";
		      BL4 = "";
		      BL5 = "";
		 }

		 break;
		 
	   case DungEnter:
		 HT = DungEnter;
		 if(!HAtimer)
		 {
		      BAct1 = "Enter the dungeon";
		      BAct2 = "";
		      BAct3 = "";
		      BL1 = "There are stairs leading down into the dungeon.";
		      BL2 = "Dare you enter?";
		      BL3 = "";
		      BL4 = "";
		      BL5 = "";
		 }
	   break;
	   
	   case DungExit:
		 HT = DungEnter;
		 if(!HAtimer)
		 {
		      BAct1 = "Leave the dungeon";
		      BAct2 = "";
		      BAct3 = "";
		      BL1 = "There are stairs leading up out of the dungeon.";
		      BL2 = "";
		      BL3 = "";
		      BL4 = "";
		      BL5 = "";
		 }
		 break;
		 
	   case StansHI:
		 HT = eHouseI;
		 if(!HAtimer)
		 {
		      BAct1 = "Buy magic map (50 Gp)";
		      BAct2 = "Missing Captain";
		      BAct3 = "";
		      BL1 = "Hello, I'm Stan. I make maps. Not just simple maps,";
		      BL2 = "but magical too.I have the magic map of this land, ";
		      BL3 = "that shows where you are.";
		      BL4 = "";
		      BL5 = "Are perhaps interested in buying one?";
		 }

		 break;
		 
	   default:
		 HT = ID;
		 glPrint(600,550,"Unknown building");
		 BAct1 = "";
		 BAct2 = "";
		 BAct3 = "";
		 BL1 = "";
		 BL2 = "";
		 BL3 = "";
		 BL4 = "";
		 BL5 = "";
		 break;
     }
     
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
	glLoadIdentity();
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glMatrixMode(GL_PROJECTION);					// Select The Projection Matrix
	glPushMatrix();							// Store The Projection Matrix
	glLoadIdentity();						// Reset The Projection Matrix
	glOrtho(0,800,0,600,-1,1);					// Set Up An Ortho Screen
	glMatrixMode(GL_MODELVIEW);					// Select The Modelview Matrix
	
	glBindTexture(GL_TEXTURE_2D,insideT[HT].texID);
	
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(550,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(550,605);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,605);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glTranslated(660,10,0);
	
	glBindTexture(GL_TEXTURE_2D,Btn[BtnLeave].texID);//leave button
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(128,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(128,32);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,32);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	glTranslatef(-160,-10,-0.01);
	
	glBindTexture(GL_TEXTURE_2D,Btn[BtnBG].texID);//marble
	glBegin(GL_QUADS);		
	{
		glTexCoord2i(0, 1); 	  glVertex2i(0,0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2i(1, 1); 	  glVertex2i(300,0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2i(1, 0);	  glVertex2i(300,605);	// Texture / Vertex Coord (Top Right)
		glTexCoord2i(0, 0);	  glVertex2i(0,605);	// Texture / Vertex Coord (Top Left)
	}
	glEnd();
	
	
	if(BA1H)glColor3f(0.2,0.9,0.2);
	else glColor3f(1,1,1);
	glPrint(550,355,BAct1);
	if(BA2H)glColor3f(0.2,0.9,0.2);
	else glColor3f(1,1,1);
	glPrint(550,320,BAct2);
	if(BA3H)glColor3f(0.2,0.9,0.2);
	else glColor3f(1,1,1);
	glPrint(550,285,BAct3);
	glColor3f(1,1,1);
	glPrint(20,75,BL1);
	glPrint(20,60,BL2);
	glPrint(20,45,BL3);
	glPrint(20,30,BL4);
	glPrint(20,15,BL5);
	
	glMatrixMode(GL_PROJECTION);				// Select The Projection Matrix
	glPopMatrix();						// Restore The Old Projection Matrix
	glMatrixMode(GL_MODELVIEW);				// Select The Modelview Matrix

	glFlush();	
	glDisable(GL_BLEND);
	glBlendFunc(GL_DST_COLOR, GL_ZERO);
	
	glutSwapBuffers();
	glEnable(GL_LIGHTING);
}

void BAction(int Choice)
{
     int i;
     switch(ID)
     {
	   case DungEnter:
		 if(Choice == 1)
		 {
		      display = DUNG1;
		      xpos = D0X;
		      zpos = D0Y;
		 }
	   break;
	   
	   case DungExit:
		 if(Choice == 1)
		 {
		      display = LAND1;
		      xpos = -0.084;
		      zpos = -17.20;
		 }
		 break;
	   	   
	   case TempleI: 
		 
		 switch(Choice)
		 {
		      case 1:
			    if(you[0].Gold - 25 >= 0)
			    {
				  you[0].HP = you[0].HPM;
				  you[0].MP = you[0].MPM;
				  you[0].Gold -=  25;
				  HAtimer = 100;
				  BL1 = "You paid 25 Gold coins";
				  BL2 = "Your Health and Mana is restored";
				  BL3 = "";
				  BL4 = "";
				  BL5 = "";
			    }
			    else 
			    {
				  BL1 = "You don't have enough Gold coins";
				  BL2 = "We don't do charrity";
				  BL3 = "";
				  BL4 = "";
				  BL5 = "";
				  HAtimer = 100;
			    }
		      break;
			   
		      case 2:
			    if(you[0].Gold - 1 >= 0)
			    {
				  you[0].Gold -=  1;
				  HAtimer = 100;
				  BL1 = "You donated 1 Gold coin";
				  BL2 = "Thank you";
				  BL3 = "";
				  BL4 = "";
				  BL5 = "";
			    }
			    else
			    {
				  HAtimer = 100;
				  BL1 = "You have nothing to give";
				  BL2 = "Go away"; 
				  BL3 = "";
				  BL4 = "";
				  BL5 = "";
			    }
		      break;
			   
		      default: break;
		 }
		 
		 break;
		 
	   case eHouseI: break;
	   
	   case StansHI:
		 switch(Choice)
		 {
		      case 1:
			    if(!L1map)
			    {
				  if(you[0].Gold - 50 >= 0)
				  {
					you[0].Gold -=  50;
					HAtimer = 100;
					BL1 = "You paid 50 Gold coins";
					BL2 = "You got the magic map of this land";
					BL3 = "";
					BL4 = "";
					BL5 = "";
					L1map = 1;
				  }
				  else 
				  {
					BL1 = "You don't have enough Gold coins";
					BL2 = "We don't give my maps for free";
					BL3 = "";
					BL4 = "";
					BL5 = "";
					HAtimer = 100;
				  }
			    }
			    else 
			    {
				  HAtimer = 100;
				  BL1 = "You already bought the map. Did you lose it?";
				  BL2 = "";  
				  BL3 = "";
				  BL4 = "";
				  BL5 = "";
			    }
			    break;
			    
		      case 2:

				  BL1 = "I know he went into the mines to look for his friend";
				  BL2 = "He never went back though";
				  BL3 = "";
				  BL4 = "";
				  BL5 = "";
				  HAtimer = 100;

			    break;
			    
		      default: break;
		 }
		 break;
		 
		 
	   case eShipI:
		 
		 if(Choice == 1)
		      if(QList[0x02].accepted && !QList[0x02].complete)
		      {	
			    int radom = 0;
			    for(i = 0; i < 30; i++)
				  if(InvGrid[i] == QList[0x02].itemNeeded)
				  {
					QList[0x02].complete=1;
					you[0].XP += QList[0x02].XPReward;
					you[0].Gold += QList[0x02].GoldReward;
					InvGrid[i] = 0x00;
					BL1 = QList[0x02].QComplete;
					BL2 = "";
					BL3 = "";
					BL4 = "";
					BL5 = "";
					HAtimer = 200;
					radom = 1;
					checkLevel();
					winDemo = 1;
					
				  }
				  HAtimer = 100;
				  
		      }
		 
		 break;

		  
	   case TavernI:
		 switch(Choice)
		 {
		      case 1:
			    if(you[0].Gold - 4 >= 0)
			    {
				  you[0].Gold -=  4;
				  HAtimer = 100;
				  BL1 = "You paid 4 Gold coins";
				  BL2 = "You got drunk";
				  BL3 = "";
				  BL4 = "";
				  BL5 = "";
				  drunk = 1;
			    }
			    else 
			    {
				  BL1 = "You don't have enough Gold coins";
				  BL2 = "We don't give free drinks today";
				  BL3 = "";
				  BL4 = "";
				  BL5 = "";
				  HAtimer = 100;
			    }
			    break;
			    
		      case 2:
			    if(you[0].Gold - 30 >= 0)
			    {
				  you[0].Gold -=  30;
				  HAtimer = 100;
				  BL1 = "You paid 30 Gold coins";
				  BL2 = "You spend the night here";
				  BL3 = "";
				  BL4 = "";
				  BL5 = "";
				  you[0].HP = you[0].HPM;
				  you[0].MP = you[0].MPM;
				  drunk = 0;
			    }
			    else 
			    {
				  BL1 = "You don't have enough Gold coins";
				  BL2 = "Go sleep outside";
				  BL3 = "";
				  BL4 = "";
				  BL5 = "";
				  HAtimer = 100;
			    }
			    break;
			    
		      case 3:
			    if(QList[0x01].accepted && !QList[0x01].complete)
			    {	
				  int radom = 0;
				  for(i = 0; i < 30; i++)
					if(InvGrid[i] == QList[0x01].itemNeeded)
					{
					     QList[0x01].complete=1;
					     you[0].XP += QList[0x01].XPReward;
					     you[0].Gold += QList[0x01].GoldReward;
					     InvGrid[i] = 0x00;
					     BL1 = QList[0x01].QComplete;
					     BL2 = "";
					     BL3 = "";
					     BL4 = "";
					     BL5 = "";
					     HAtimer = 200;
					     radom = 1;
					     checkLevel();
					     
					}
					else if(!radom)
					{
					     BL1 = "I don't see the item I want.";
					     BL2 = "Come back when you have it.";
					     BL3 = "";
					     BL4 = "";
					     BL5 = ""; 
					     
					}
// 					BL5 = "QList[0x01].accepted && !QList[0x01].complete"; //debug
					HAtimer = 100;
					
			    }
			    else if(!QList[0x01].accepted)
			    {
				  QList[0x01].accepted=1;
				  BL1 = QList[0x01].L1;
				  BL2 = QList[0x01].L2;
				  BL3 = QList[0x01].L3;
				  BL4 = QList[0x01].L4;
				  HAtimer = 300;
// 				  BL4 = "!QList[0x01].accepted";//debug
			    }
			    else
			    {
				  BL1 = "Thank you again for helping us";
				  BL2 = "";
				  BL3 = "";
				  BL4 = "";
				  BL5 = "";//debug
				  HAtimer = 100;
			    }
		      break;
		      default: break;
		 }
		 break;
		 
	   default:

		 break;
     }
}

