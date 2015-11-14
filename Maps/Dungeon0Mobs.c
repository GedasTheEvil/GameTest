#include "../src/vars.h"
#include "../Models/spider2.h"
#include "../Models/spider2w1.h"
 #include "../Models/spider2a1.h"

int Dun0MobC = 1;

monster Dun0Mobs[1];

void InitMobs0()
{
	int i;
	Dun0Mobs[0].Norm = Spider2Normals;
	Dun0Mobs[0].Tex  = Spider2TexCord;
	Dun0Mobs[0].vertC = kSpider2NumberOfVertices;
	Dun0Mobs[0].Stand = (float *) malloc(sizeof(float)*3*Dun0Mobs[0].vertC);
	Dun0Mobs[0].Walk1 = (float *) malloc(sizeof(float)*3*Dun0Mobs[0].vertC);
	Dun0Mobs[0].Walk2 = (float *) malloc(sizeof(float)*3*Dun0Mobs[0].vertC);
	Dun0Mobs[0].Verts = (float *) malloc(sizeof(float)*3*Dun0Mobs[0].vertC);
	Dun0Mobs[0].Att1  = (float *) malloc(sizeof(float)*3*Dun0Mobs[0].vertC);
	Dun0Mobs[0].Att2  = (float *) malloc(sizeof(float)*3*Dun0Mobs[0].vertC);
	Dun0Mobs[0].scale = 0.01;
	Dun0Mobs[0].pos = (cord *) malloc(sizeof(cord));
	Dun0Mobs[0].pos[0].x = 13.000000;
	Dun0Mobs[0].pos[0].y = 0.01;
	Dun0Mobs[0].pos[0].z = 12.500000;
	Dun0Mobs[0].tex =( int *) texture[18];
	Dun0Mobs[0].HpMax = Dun0Mobs[0].Hp = 100;
	Dun0Mobs[0].XP = 100;
	Dun0Mobs[0].dmg = 3;
	Dun0Mobs[0].attDelay = 0;
	Dun0Mobs[0].rot = 0.0;
	Dun0Mobs[0].VX = 0;
	Dun0Mobs[0].VZ = 0;
	Dun0Mobs[0].anm = 0;
	Dun0Mobs[0].morph = 0.1;
	Dun0Mobs[0].state  = Dun0Mobs[0].Walk1;
	Dun0Mobs[0].Nstate = Dun0Mobs[0].Stand;
	for(i = 0; i < Dun0Mobs[0].vertC *3;i++)
	 {
		Dun0Mobs[0].Stand[i] = Spider2Vertex    [i];
		Dun0Mobs[0].Walk1[i] = Spider2w1Vertex [i];
		 Dun0Mobs[0].Walk2[i] = Spider2Vertex [i];
		 Dun0Mobs[0].Verts[i] = Spider2Vertex    [i];
		 Dun0Mobs[0].Att1[i]  = Spider2a1Vertex [i];
		 Dun0Mobs[0].Att2[i]  = Spider2Vertex [i];
	}
	Dun0Mobs[0].status = 1;
	Dun0Mobs[0].alive = 1;


}
