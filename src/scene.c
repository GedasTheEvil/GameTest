#include "scene.h"

int LockFramesPerSecond(int framerate)
{
     currentTime = (float)SDL_GetTicks() * 0.001f;
     
     if((currentTime - lastTime) > (1.0f / framerate))
     {
	   lastTime = currentTime;
	   return 1;
     }
     
     if(lastTime > 64000.4)
	   lastTime = 0.0;
     
     return 0;
}

void Draw()
{

     if(winDemo)
     {
	   ShowWin();
	   return;
     }
	switch(display)
	{
		case LAND1:
			dLand1(0);
		break;
		
		case DUNG1:
// 			Dungeon1();
		      dDungeon(0);
		      
		break;

		case HouseInside:
			HoSide();
		break;

		case MainMENU:
			DMMenu();
		break;
		
		case ConfMENU:
// 			ShowStats();
			DCMenu();
		break;
		
		case LOADING:
		     DrawLoad();
		break;
		
		case StatMENU:
		     ShowStats();
	        break;
		
		case CreditMENU:
		     DrawCredits();
	        break;
		
		case SaveMENU:
		     DrawSave();
		break;
		
		case GameMENU:
		     GMMenu();
		     break;
		     
		case InventMENU:
		     DrawInventory();
		break;
		
		case QuestMENU:
		     DrawQuests();
		 break;
		    
		case DeadScreen:
		     ShowDead();
		 break;
		
		default:
			printf("Error: unvalid drawing mode\n\n");
		break;
		
	}

}


void Idle()
{
     
     if(LockFramesPerSecond(30))
     {
	   if(display == LAND1)L1Anim();
	   if(display == DUNG1)Dung1Anim();
	   cnt++;
	   if(ShotDelay)ShotDelay--;	
	   
	   if(ytrans > -0.48)
	   {
		 fog = 1; 
		 glEnable(GL_FOG);
	   }
	   else if(!drunk)
	   {
		 fog = 0;
		 glDisable(GL_FOG);
	   }
	   else 
	   {
		 fog = 1; 
		 glEnable(GL_FOG);
	   }
	   
	   if(HAtimer)HAtimer--;
     }
	
	Draw();
	

	  

}

