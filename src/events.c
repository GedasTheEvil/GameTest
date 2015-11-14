#include "events.h"

short eq(float a, float b) //doors
{
	short x = 0;
	if( fabs(a - b) < 0.16 )x =1;
	return x;
}

short eeq(float a, float b) //bigger objects
{
	short x = 0;
	if( fabs(a - b) < 0.54 )x =1;
	return x;
}

itmL DungeonIM(float x, float y, itmL *A)
{
     int i,j;

	   i = /*47 -*/ xpos*2.0 ;
	   j = /*40 -*/ zpos*2.0 + 2;

	   
     if(A == NULL)
     {
	   printf("Error: Got Null Address for ItemMap\n");
	   return A[0];
     }
     
     if(i > 47.0 || j > 40 || i < 0 || j < 0)
     {
	   printf("Position Error i > %d[47], j > %d[40]\n",i,j);
	   return A[0];
     }
     
     printf("Debug:: i > %d[47], j > %d[40] ::: is:%d  id:%d || %No.%d\n",i,j,A[47 * j + i].is,A[47 * j + i].id,47 * j + i);
     
     ITMindex = 47 * j + i;
     
     
     return A[47 * j + i];
}


void L1ProcEvent()
{
     if( eq(xpos,2.86) && eq(zpos,-21.89) ){LastMap = LAND1; ID = TempleI; display = HouseInside;}
	else if(eeq(xpos,0.55) && eeq(zpos,-21.26)){tmpC="Padestal makes you stronger\n"; tmp_text = 90;you[0].Str = you[0].StrM + 5;checkLevel();}
	else if(eeq(xpos,0.735) && eeq(zpos,-17.0)){tmpC="You Drink from the well\n"; tmp_text = 90;}
	else if(eeq(xpos,3.38) && eeq(zpos,-20.7)){tmpC="You wash hand in the fountain\n"; tmp_text = 90;}
	else if(eeq(xpos,2.446) && eeq(zpos,-20.7)){tmpC="You wash hand in the fountain\n"; tmp_text = 90;}
	else if(eq(xpos,-0.084) && eq(zpos,-17.20) ){LastMap = LAND1;ID = DungEnter; display = HouseInside;}
	else if(eq(xpos,-1.182) && eq(zpos,-17.13) ){LastMap = LAND1;ID = eHouseI; display = HouseInside;}
	else if(eq(xpos,-1.18) && eq(zpos,-16.17) ) {LastMap = LAND1;ID = eHouseI; display = HouseInside;}
	else if(eq(xpos,-0.085) && eq(zpos,-16.25) ){LastMap = LAND1;ID = StansHI; display = HouseInside;}
	else if(eq(xpos,-9.842) && eq(zpos,-19.59) ){LastMap = LAND1;ID = eShipI; display = HouseInside;}
	else if(eq(xpos,-4.52) && eq(zpos,-19.67) ){LastMap = LAND1;ID = TavernI; display = HouseInside;}
	else if(eeq(xpos,10.037) && eeq(zpos,-19.36)){tmpC="North: Town, East : ????\n"; tmp_text = 90;}
	else printf("No event at %f -- %f\n\n",xpos,zpos);
}
void D1ProcEvent()
{
     if( eeq(xpos,D0X) && eeq(zpos,D0Y) )
     {
	   LastMap = DUNG1;
	   ID = DungExit; 
	   display = HouseInside;
     }
     
     else if(DungeonIM(0.0,0.0,Dun0Items).is)
     {
	   GetItem(DungeonIM(0.0,0.0,Dun0Items).id);
	   tmpC="You found an item\n";
	   tmp_text = 90;
	   printf("Debug:: found item %d",DungeonIM(0.0,0.0,Dun0Items).id);
	   Dun0Items[ITMindex].is = 0;
     }
     
     else printf("No event at %f -- %f\n\n",xpos,zpos);
}

