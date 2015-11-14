#include "Exit.h"

void Exit(int rt)
{
     int i;
     //We only have one temple, so we dont need to free
     // house[0]. So the index starts with 1
     loaded = 100;
     DrawLoad();
     for(i = 1; i < houses; i++)
	   if(house[i].Vert){free(house[i].Vert);house[i].Vert=NULL;}
     
     loaded = 90;
     DrawLoad();
     for(i = 0; i < fountains; i++)
	   if(fountain[i].Vert){free(fountain[i].Vert);fountain[i].Vert=NULL;}
     
     loaded = 80;
     DrawLoad();
     for(i = 0; i < anC; i++)
     {
	   if(anb[i].Verts) {free(anb[i].Verts);anb[i].Verts = NULL;}
	   if(anb[i].Stand) {free(anb[i].Stand);anb[i].Stand = NULL;}
	   if(anb[i].Walk1) {free(anb[i].Walk1);anb[i].Walk1 = NULL;}
	   if(anb[i].Walk2) {free(anb[i].Walk2);anb[i].Walk2 = NULL;}
	   if(anb[i].Att1)  {free(anb[i].Att1);anb[i].Att1 = NULL;}
	   if(anb[i].Att2) { free(anb[i].Att2);anb[i].Att2 = NULL;}
     }
     
     loaded = 70;
     DrawLoad();
     for(i = 0; i < trees; i++)
	   if(tree[i].Vert){free(tree[i].Vert);tree[i].Vert = NULL;}
	  
     for(i = 0; i < FTrees; i++)
	   if(FTree[i].Vert){free(FTree[i].Vert);FTree[i].Vert=NULL;}
	   
     loaded = 60;
     DrawLoad();
/*     
     if(QList){free(QList);QList = NULL;}
     if(tmpC){free(tmpC);tmpC = NULL;}
     if(BAct1){free(BAct1);BAct1 = NULL;}
     if(BAct2){free(BAct2);BAct2 = NULL;}
     if(BAct3){free(BAct3);BAct3 = NULL;}
     if(BL1) {free(BL1);BL1 = NULL;}
     if(BL2) {free(BL2);BL2 = NULL;}
     if(BL3){ free(BL3);BL3 = NULL;}
     if(BL4){free(BL4);BL4 = NULL;}
     if(BL5) {free(BL5);BL5 = NULL;}*/
     
     
     
     for(i = 0; i < bezers; i++)
	   if(bez[i].Vert){free(bez[i].Vert);bez[i].Vert=NULL;}
 
     loaded = 50;
     DrawLoad();
     
     if(arrow.Vert){free(arrow.Vert);arrow.Vert=NULL;}
     loaded = 45;
     DrawLoad();
     
     for(i = 0; i < anC; i++)
     {
	   if(spd[i].Verts) {free(spd[i].Verts);spd[i].Verts = NULL;}
	   if(spd[i].Stand) {free(spd[i].Stand);spd[i].Stand = NULL;}
	   if(spd[i].Walk1) {free(spd[i].Walk1);spd[i].Walk1 = NULL;}
	   if(spd[i].Walk2) {free(spd[i].Walk2);spd[i].Walk2 = NULL;}
	   if(spd[i].Att1) {free(spd[i].Att1);spd[i].Att1 = NULL;}
	   if(spd[i].Att2) {free(spd[i].Att2);spd[i].Att2 = NULL;}
     }
     loaded = 30;
     DrawLoad();
     
     for(i = 0; i <  Dun0MobC; i++)
     {
	   if(Dun0Mobs[i].Verts) {free(Dun0Mobs[i].Verts);Dun0Mobs[i].Verts = NULL;}
	   if(Dun0Mobs[i].Stand) {free(Dun0Mobs[i].Stand);Dun0Mobs[i].Stand = NULL;}
	   if(Dun0Mobs[i].Walk1) {free(Dun0Mobs[i].Walk1);Dun0Mobs[i].Walk1 = NULL;}
	   if(Dun0Mobs[i].Walk2) {free(Dun0Mobs[i].Walk2);Dun0Mobs[i].Walk2 = NULL;}
	   if(Dun0Mobs[i].Att1) {free(Dun0Mobs[i].Att1);Dun0Mobs[i].Att1 = NULL;}
	   if(Dun0Mobs[i].Att2) {free(Dun0Mobs[i].Att2);Dun0Mobs[i].Att2 = NULL;}
     }
     
     Deinitialize();
     
     loaded = 20;
     DrawLoad();
     
     KillSounds();
     loaded = 0;
     DrawLoad();
     if(rt != 666)exit(rt);
     else display = MainMENU;
     
     
}
