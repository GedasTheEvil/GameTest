#include "passage.h"

short Land1pm(float x, float z, int mob)
{
     
      
	short bool = 1;

	float az,ax;
	
	if(!mob)
	{	
	     ax = xpos + x;
	     az = zpos + z;
	}
	else 
	{
	    ax =  x;
	    az =  z -9.66 ;
// 	    printf("Z.real =%f , Z.now = %f\n",z,az);
	}
	


	if(ax < -5.8)  bool = 0; //eomap
	if(az <-23.5)   bool = 0;//eomap
	if(az > -10.4)    bool = 0;//eomap
	if(ax > 14.1)   bool = 0;//eomap
	     
	if(ax >= 1.99 && ax <= 3.72 && az >= -23.8 && az <= -21.3) bool = 0;//temple
	if(ax >= 2.73 && ax <= 3.08 && az >= -22.0 && az <= -21.140)bool = 1; //temple entrance
	if(ax >= -0.4 && ax <= 0.2 && az >= -17.95 && az <= -17.23)bool = 0;//house 
	if(ax >= -1.62 && ax <= -0.84 && az >= -18.06 && az <= -17.25)bool = 0;//house 
	if(ax >= -1.62 && ax <= -0.84 && az >= -17.06 && az <= -16.25)bool = 0;//house 
	if(ax >= -0.44 && ax <= 0.2 && az >= -16.95 && az <= -16.275)bool = 0;//house 
	if(ax >= -5.11 && ax <= -3.92 && az >= -20.95 && az <= -19.71)bool = 0;//tavern
	     
	     
	   if(ax >= -10.3 && ax <= -5.8 && az >= -18.7 && az <= -18.2)bool = 1;//bridge
	   if(ax >= -10.4 && ax <= -9.7 && az >= -19.9 && az <= -18.2)bool = 1;//bridge
	return bool;
	
}

void DrawPassage()
{
     glDisable(GL_TEXTURE_2D);
     glDisable(GL_LIGHTING);

     
     glLineWidth(50);
     
     glPushMatrix();
          glTranslatef(0,0.5, 9.6);//konstanta kazkokia
	   
     glColor3f(0,1,0);
     glBegin(GL_LINE_LOOP);
	   glVertex3f(-5.8,0,-23.5);
	   glVertex3f(14.1,0,-23.5);
	   glVertex3f(14.1,0, -10.4);
	   glVertex3f(-5.8,0, -10.4);
     glEnd();
     
     //bridge
     glColor3f(0,1,0);
     glBegin(GL_LINE_LOOP);
	   glVertex3f(-5.6,0,-18.7);
	   glVertex3f(-10.3,0,-18.7);
	   glVertex3f(-10.3,0, -18.2);
	   glVertex3f(-5.6,0, -18.2);
     glEnd();
     
     glColor3f(0,1,0);
     glBegin(GL_LINE_LOOP);
	   glVertex3f(-9.7, 0, -19.9);
	   glVertex3f(-10.4,0, -19.9);
	   glVertex3f(-10.0,0, -18.2);
	   glVertex3f(-9.7, 0, -18.2);
     glEnd();
     // !bridge
     
     glColor3f(1,0,0);
     glBegin(GL_LINE_LOOP);
	   glVertex3f(-5.11,0,-20.95);
	   glVertex3f(-3.92,0,-20.95);
	   glVertex3f(-3.92,0, -19.71);
	   glVertex3f(-5.11,0, -19.71);
     glEnd();   
     
     glColor3f(1,0,0);
     glBegin(GL_LINE_LOOP);
	   glVertex3f(-0.4,0,-17.95);
	   glVertex3f(0.2,0,-17.95);
	   glVertex3f(0.2,0, -17.23);
	   glVertex3f(-0.4,0, -17.23);
     glEnd();     
     
     glColor3f(1,0,0);
     glBegin(GL_LINE_LOOP);
	   glVertex3f(-1.62,0,-18.06);
	   glVertex3f(-0.84,0,-18.06);
	   glVertex3f(-0.84,0, -17.25);
	   glVertex3f(-1.62,0, -17.25);
     glEnd();     
     
     glColor3f(1,0,0);
     glBegin(GL_LINE_LOOP);
	   glVertex3f(-1.62,0,-17.06);
	   glVertex3f(-0.84,0,-17.06);
	   glVertex3f(-0.84,0, -16.25);
	   glVertex3f(-1.62,0, -16.25);
     glEnd();   
     
     glColor3f(1,0,0);
     glBegin(GL_LINE_LOOP);
	   glVertex3f(-0.44,0,-16.95);
	   glVertex3f(0.2,0,-16.95);
	   glVertex3f(0.2,0, -16.275);
	   glVertex3f(-0.44,0, -16.275);
     glEnd();      

	   glTranslatef(1.99,0, -23.8 );
	   
	   glColor3f(1,0,0);
	   glBegin(GL_LINE_LOOP);
		 glVertex3f(0,0,0);
		 glVertex3f(1.73,0,0);
		 glVertex3f(1.73,0, 2.5);
		 glVertex3f(0,0, 2.5);
	   glEnd();
	   glColor3f(0,1,0);
	   glBegin(GL_LINE_LOOP);
		 glVertex3f(0.74,0,0.16);
		 glVertex3f(1.08,0,0.16);
		 glVertex3f(1.08,0, 4.3);
		 glVertex3f(0.75,0, 4.3);
	   glEnd();
	   
     glPopMatrix();
     glEnable(GL_TEXTURE_2D);
     glEnable(GL_LIGHTING);
}


int DungeonPM(int mob, float x, float y, int *A)
{
     int i,j;
     if(!mob)
     {
	  i = /*47 -*/ (xpos+x-0.2)*2.0;
	  j = /*40 -*/ (y+zpos+0.5)*2.0;
     }
     else 
     {
	   i = /*47 -*/ (x-0.2)*2.0;
	   j = /*40 -*/ (y+0.5)*2.0;  
     }
     
     if(A == NULL)
     {
	   printf("Got Null Address for passmap\n");
	   return 0;
     }
     
     if(i > 47.0 || j > 40 || i < 0 || j < 0)
     {
	   printf("PassError i > %d[47], j > %d[40]\n",i,j);
	   return 0;
     }
     
//      printf("PassSuccess i > %d[47], j > %d[40] :\n",i,j);
//      printf("PassSuccess A[%d][%d] = %d\n",i,j,A[47 * j + i]);
     
     return A[47 * j + i];
}
