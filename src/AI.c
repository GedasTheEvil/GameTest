#include "AI.h"
void ShowMoveDir(monster m, float vx, float vz)
 {
      glLineWidth(50);
      
      glPushMatrix();
      glTranslatef(0,0.4, 0.0);//konstanta kazkokia
      
      
      glDisable(GL_TEXTURE_2D);
      glDisable(GL_LIGHTING);
      
      glColor3f(0,0,1);
      
      glBegin(GL_LINE);
      glVertex3f(m.pos[0].x,0,m.pos[0].z);
      glVertex3f(m.pos[0].x + vx *10,0,m.pos[0].z + vz*10);
      glEnd(); 
      
      glPopMatrix();
      
      glEnable(GL_TEXTURE_2D);
      glEnable(GL_LIGHTING);
      
 }
 
 int Decide(monster m)
 {
      int status = 0;
      
      if(xpos < m.pos[0].x + 0.2 && xpos > m.pos[0].x - 0.2 && 
	    zpos < m.pos[0].z -9.85 + 0.2 && zpos > m.pos[0].z -9.85  - 0.2 )status = AttackMode;
      
      else if (xpos < m.pos[0].x + 3 && xpos > m.pos[0].x - 3 && 
	    zpos < m.pos[0].z -9.85 + 3 && zpos > m.pos[0].z -9.85 - 3 )status = WalkMode;
      
      else status = StandMode; 
      
      m.status = status;
      

      
      return status;
 }
 
 int DecideD(monster m)
 {
      int status = 0;
      
      if(xpos < m.pos[0].x + 0.4 && xpos > m.pos[0].x - 0.4 && 
	  zpos < m.pos[0].z + 0.4 && zpos > m.pos[0].z - 0.4 )status = AttackMode;
      
      else if (xpos < m.pos[0].x + 3 && xpos > m.pos[0].x - 3 && 
	    zpos < m.pos[0].z + 3 && zpos > m.pos[0].z - 3 )status = WalkMode;
      
      else status = StandMode; 
      
      if( m.status != status)printf("Debug:: Status-new:%d, old:%d\n",status,m.status);
      
      m.status = status;

    
//       return status;
return AttackMode;
 }
 
 void Anim(monster m)
 {
      int i;
      if(m.Nstate != m.state)
	    for(i = 0; i < m.vertC *3; i++)m.Verts[i] = m.morph*m.Nstate[i] + (1.0 - m.morph)* m.state[i];
	    
	    m.morph += 0.01;
 }
 
 void Dung1Anim()
 {
 
      int mobsai;
      for(mobsai = 0; mobsai < Dun0MobC; mobsai++)
      {
	   if(Dun0Mobs[mobsai].morph <= 0.0)
	   {	
		 Dun0Mobs[mobsai].morph += 0.15;
		 Dun0Mobs[mobsai].status = DecideD(Dun0Mobs[mobsai]);//TODO:find out to decide or to decideD
	   }
	   
	   else if(Dun0Mobs[mobsai].morph >= 1.0)
	   {

		 Dun0Mobs[mobsai].morph -= 0.15;
		 Dun0Mobs[mobsai].anm++; 
	   }
	    
	    if(Dun0Mobs[mobsai].status == AttackMode)Dun0Mobs[mobsai].Nstate =  Dun0Mobs[mobsai].Att1;
	    else if(Dun0Mobs[mobsai].status == WalkMode) 
	    {
		  Dun0Mobs[mobsai].Nstate =  Dun0Mobs[mobsai].Walk1;
	    }
	    else Dun0Mobs[mobsai].Nstate =  Dun0Mobs[mobsai].Stand;

	    
	    if(Dun0Mobs[mobsai].status == AttackMode)Dun0Mobs[mobsai].state =  Dun0Mobs[mobsai].Att2;
	    else if(Dun0Mobs[mobsai].status == WalkMode) 
	    {
		  Dun0Mobs[mobsai].state =  Dun0Mobs[mobsai].Walk2;
		  
	    }
	    else   Dun0Mobs[mobsai].state =  Dun0Mobs[mobsai].Stand;
	    
	    if(Dun0Mobs[mobsai].anm >=8 )
		  Dun0Mobs[mobsai].anm = -2; 
	    

	    if(!Dun0Mobs[mobsai].anm)
	   {
		 Dun0Mobs[mobsai].Nstate =  Dun0Mobs[mobsai].Stand;	    
	   }
	   
	   //walking
	   if(Dun0Mobs[mobsai].status == WalkMode && Dun0Mobs[mobsai].alive)
	   {
		 if(xpos > Dun0Mobs[mobsai].pos[0].x)
		      Dun0Mobs[mobsai].VX = 0.015;
		 else if(xpos + 0.01 > Dun0Mobs[mobsai].pos[0].x && xpos - 0.01 < Dun0Mobs[mobsai].pos[0].x) Dun0Mobs[mobsai].VX = 0;
		 else Dun0Mobs[mobsai].VX = -0.015;
		 
		 if(zpos > Dun0Mobs[mobsai].pos[0].z )
		      Dun0Mobs[mobsai].VZ = 0.015;
		 else if(zpos + 0.01 > Dun0Mobs[mobsai].pos[0].z  && zpos - 0.01 < Dun0Mobs[mobsai].pos[0].z) Dun0Mobs[mobsai].VZ = 0;
		 else Dun0Mobs[mobsai].VZ = -0.015;
		 
		 
		 if(DungeonPM(1,Dun0Mobs[mobsai].pos[0].x + Dun0Mobs[mobsai].VX,Dun0Mobs[mobsai].pos[0].z,Passmap0))
		      Dun0Mobs[mobsai].pos[0].x += Dun0Mobs[mobsai].VX;
		 
		 if(DungeonPM(1,Dun0Mobs[mobsai].pos[0].x,Dun0Mobs[mobsai].pos[0].z + Dun0Mobs[mobsai].VZ,Passmap0))
		      Dun0Mobs[mobsai].pos[0].z += Dun0Mobs[mobsai].VZ;
	   }
	   //attacking
	   
	   int MobDMG = 0;
	   
	   if(Dun0Mobs[mobsai].status == AttackMode && Dun0Mobs[mobsai].alive)
	   {
		 if(!Dun0Mobs[mobsai].attDelay)
		 {
		      MobDMG = Dun0Mobs[mobsai].dmg - you[0].armor;
		      if(MobDMG <= 0)MobDMG =1;
		      you[0].HP -=  MobDMG;
		      if(CheckDead())display = DeadScreen;
		      Dun0Mobs[mobsai].attDelay = 60;
		      Mix_PlayChannel(-1, SpdAtt, 0);
		 }
		 else Dun0Mobs[mobsai].attDelay--;
	   }
      
      }//eofor
    
 }
 
 void L1Anim()
 {
      if(!aaaa)
      {	
	    anb[0].morph += 0.15;
	    spd[0].morph += 0.15;
	    
	    anb[0].status = Decide(anb[0]);
	    spd[0].status = Decide(spd[0]);
      }
      else 
      {
	    anb[0].morph -= 0.15; 
	    spd[0].morph -= 0.15;
      }
      
      if (anb[0].morph >= 1.0)
      {
	    aaaa = 1; 
	    ccc++; 
      }
      
      if (anb[0].morph <= 0.0)
	    aaaa = 0;
      
      
//       if(ccc == 4)
      {
	    if(anb[0].status == AttackMode)anb[0].Nstate =  anb[0].Att1;
	    else if(anb[0].status == WalkMode) 
	    {
		  anb[0].Nstate =  anb[0].Walk1;
	    }
	    else anb[0].Nstate =  anb[0].Stand;
	    
	    if(spd[0].status == AttackMode)spd[0].Nstate =  spd[0].Att1;
	    else if(spd[0].status == WalkMode) 
	    {
		  spd[0].Nstate =  spd[0].Walk1;
	    }
	    else spd[0].Nstate =  spd[0].Stand;
      }
      if(ccc == 8)
      {
	    if(anb[0].status == AttackMode)anb[0].state =  anb[0].Att2;
	    else if(anb[0].status == WalkMode)
	    { 
		  anb[0].state =  anb[0].Walk2;
	    }
	    else anb[0].state =  anb[0].Stand;
	    
	    if(spd[0].status == AttackMode)spd[0].state =  spd[0].Att2;
	    else if(spd[0].status == WalkMode) 
	    {
		  spd[0].state =  spd[0].Walk2;
		  
	    }
	    else spd[0].state =  spd[0].Stand;
	    ccc = -2; 
      }
      if(!ccc)
      {
	    anb[0].Nstate =  anb[0].Stand;
	    spd[0].Nstate =  spd[0].Stand;
	    
      }
      
      //walking
      if(anb[0].status == WalkMode && anb[0].alive)
      {
	    if(xpos > anb[0].pos[0].x)
		  anb[0].VX = 0.011;
	    else if(xpos + 0.01 > anb[0].pos[0].x && xpos - 0.01 < anb[0].pos[0].x) anb[0].VX = 0;
	    else anb[0].VX = -0.011;
	    if(zpos > anb[0].pos[0].z -9.8)
		  anb[0].VZ = 0.011;
	    else if(zpos + 0.01 > anb[0].pos[0].z -9.8 && zpos - 0.01 < anb[0].pos[0].z-9.8) anb[0].VZ = 0;
	    else anb[0].VZ = -0.011;
	    
	    
	    if(Land1pm(anb[0].pos[0].x + anb[0].VX,anb[0].pos[0].z,1))
		  anb[0].pos[0].x += anb[0].VX;
	    
	    if(Land1pm(anb[0].pos[0].x,anb[0].pos[0].z + anb[0].VZ,1))
		  anb[0].pos[0].z += anb[0].VZ;
      }
      
      
      if(spd[0].status == WalkMode && spd[0].alive)
      {
	    if(xpos > spd[0].pos[0].x)
		  spd[0].VX = 0.015;
	    else if(xpos + 0.01 > spd[0].pos[0].x && xpos - 0.01 < spd[0].pos[0].x) spd[0].VX = 0;
	    else spd[0].VX = -0.015;
	    if(zpos > spd[0].pos[0].z -9.8)
		  spd[0].VZ = 0.015;
	    else if(zpos + 0.01 > spd[0].pos[0].z -9.8 && zpos - 0.01 < spd[0].pos[0].z-9.8) spd[0].VZ = 0;
	    else spd[0].VZ = -0.015;
	    
	    
	    if(Land1pm(spd[0].pos[0].x + spd[0].VX,spd[0].pos[0].z,1))
		  spd[0].pos[0].x += spd[0].VX;
	    
	    if(Land1pm(spd[0].pos[0].x,spd[0].pos[0].z + spd[0].VZ,1))
		  spd[0].pos[0].z += spd[0].VZ;
      }
      //attacking
      
      int MobDMG = 0;
      
      if(spd[0].status == AttackMode && spd[0].alive)
      {
	    if(!spd[0].attDelay)
	    {
		  MobDMG = spd[0].dmg - you[0].armor;
		  if(MobDMG <= 0)MobDMG =1;
		  you[0].HP -=  MobDMG;
		  if(CheckDead())display = DeadScreen;
		  spd[0].attDelay = 60;
		  Mix_PlayChannel(-1, SpdAtt, 0);
	    }
	    else spd[0].attDelay--;
      }
      
      if(anb[0].status == AttackMode && anb[0].alive)
      {
	    if(!anb[0].attDelay)
	    {
		  
		  MobDMG = anb[0].dmg - you[0].armor;
		  if(MobDMG <= 0)MobDMG =1;
		  you[0].HP -=  MobDMG;
		  if(CheckDead())display = DeadScreen;
		  anb[0].attDelay = 60;
		  Mix_PlayChannel(-1, AnbAtt, 0);
	    }
	    else anb[0].attDelay--;
      }
      
 }
