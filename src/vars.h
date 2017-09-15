#ifndef GameVars
#define GameVars

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // Header file for sleeping.
#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include <math.h>       // Header file for trigonometric functions.
#include <SDL/SDL_timer.h>
#include <stdarg.h>
#include <string.h>

extern int ITMindex;

     // 	display modes:
     // 	display modes:
     #define MainMENU     1
     #define ConfMENU     2
     #define LoadMENU     3
     #define CreditMENU   4
     #define GameMENU     5
     #define LOADING      6
     #define StatMENU     7
     #define InventMENU   8
     #define QuestMENU    9
     #define SkillMENU   10
     #define SaveMENU    11
     #define SpellMENU   12
     #define HouseInside 13
     #define DeadScreen  14
     #define DUNG1       15
     #define LAND1       16
     // 	!display modes:

     //	House IDs
     #define TempleI  0
     #define eHouseI  1
     #define eShipI   2
     #define TavernI  3
     #define StansHI  4
     #define DungEnter 5
     #define DungExit  6
     //	!House IDs

     //	texture buttons
     #define BtnBG      0
     #define BtnLeave   1
     #define BtnNewGame 2 
     #define BtnLoad    3
     #define BtnConf    4
     #define BtnCredits 5
     #define BtnExit    6
     #define BtnSave    7
     #define BtnCh0     8
     #define BtnCh1     9
     #define BtnEmpty  10
     #define LoadBar   11
     #define BtnBack   12
     #define Bar       13
     #define BtnSkill  14
     #define BtnInvent 15
     #define BtnQuest  16
     #define BtnStats  17
     #define BtnInfBG  18

     //	!texture buttons	

     //	AI
     #define AttackMode 2
     #define WalkMode   1
     #define StandMode  0
     //	!AI

     // 	mouse
     #define wheel_up    4
     #define wheel_down  3
     #define RMB         2
     #define MMB         1
     #define LMB         0

     #define houses 5
     #define fountains 2
     #define anC 1
     #define SpC 1
     #define trees 64
     #define FTrees 25
     #define bezers 2
     #define true 1
     #define false 0
     #define texcount  20		// number of textures
     #define atexcount  0		// number of textures

     #define intex 6
     #define buttons 32

     #define items 0x90
     
     extern int LastMap;


     extern int mouseX;
     extern int mouseY;
     
     extern int winDemo;
     // 	!mouse

     //	inventory
     extern int infoShow ;
     extern int infoItem  ;
     extern int ShowPassMap ;

     extern int InvGrid[] ;

     extern int selectedItem ;

     extern int Helm ;//  ;
     extern int Armor   ;
     extern int Boots  ;
     extern int RHand   ;
     extern int LHand   ;

typedef struct 
{
     // 	   extern char ID;
      char Name[22];
      char L1[40];
      char L2[40];
      char L3[40];
      char L4[40];
      int Damage;
      int Armor;
      int Value;
      char Atr[3];
      int AtrV;
     // 	   GLuextern int *texID;
}item;

     extern item *List;
//	!inventory

//	quests
typedef struct 
{
     int accepted;
     int complete;
     char Name[22];
     char L1[64];
     char L2[64];
     char L3[64];
     char L4[64];
     char QComplete[64];
     int  XPReward;
     int itemReward;
     int itemNeeded;
     int GoldReward;
} quest;

     extern quest *QList ;
     extern int infoQShow ;
     extern int infoQuest ;
     extern int HQ[15] ;
     extern int sellectedQuest;

//	!quests

     extern int HAtimer ;
     extern int HT ;

     extern int L1map;

     extern int class ;

     extern double lastTime ;
     extern float lastframe,thisframe; 
     extern int ff, fps;

     extern int ShotDelay ;

     extern int drunk;
     //end
     #define DegRad 0.0174532925
     extern int loaded ;
     extern int sound, music,fs;
     extern int texres ;
     extern int resX, resY;
     extern unsigned int display;
     extern int tmp_text;
     extern char *tmpC ;

     //text vars
     extern char *BAct1, *BAct2, *BAct3, *BL1, *BL2, *BL3, *BL4, *BL5;
     extern int BA1H ,BA2H ,BA3H ;
     // !text vars

     extern int ID ;
     extern int window;
     extern float x, y, z;
     extern float yrot ;
     extern float walkAngle ;

     extern short plClass ;

     extern GLfloat lookupdown ;

     extern float heading, xpos, zpos;
     extern float ytrans ;

     extern GLfloat camx , camy , camz ; // camera location.
     extern GLfloat therotate;

     extern int debugY ;

     extern int shoot;

     extern GLuint	base;	// Font Display List

     ///fog 
     extern int fog;
     extern GLuint fogMode[] ;
     extern GLuint fogFilter ;
     extern GLfloat fogColor[] ;
     //light
     extern GLfloat LightAmbient[] ;
     extern GLfloat LightDiffuse[]  ;
     extern GLfloat LightPosition[] ;
     extern GLUquadricObj *quadratic;	// Storage For Our Quadratic Objects



extern int ghost ;
typedef struct
{
     float x, y,z;
} cord;

typedef struct 
{
     short visible;
     float *Vert, *Norm, *Tex;
     int vertCount;
     cord pos;
     float scale;
     int *tex;
     float zrot;
     int blend;
} building;

building house[houses];

building fountain[fountains];


typedef struct
{
     short alive;
     short status;
     float *Norm, *Tex;
     int Hp, HpMax;
     float *state, *Nstate;
     int dmg;
     cord *pos;
     int vertC;
     float *Verts;
     float *Stand, *Walk1, *Walk2, *Att1, *Att2;
     float morph;
     int *tex;
     float scale;
     int XP;
     int attDelay;
     float VZ;
     float VX;
     float rot;
     int anm;
     
} monster;

     
    
     extern monster anb[anC];
     
     extern monster spd[SpC];

     extern building tree[trees];
     
     extern building FTree[FTrees];
     
     extern building pade;

     extern building bez[bezers];
     
     typedef struct
     {
	   cord beg;
	   cord end;
	   float *Vert;
	   int VC;
	   short visible;
	   // 	monList *List;
	   short mons;
	   short life;
     } proj;
     
     extern proj arrow;
     
     extern building ship;
     
     extern building well;
     
     extern  building tavern;
     
     //	text inputs
     extern char TextKey[32];
     extern int  inputSw ;
     extern int tl ;
     //	!text inputs
     
     struct player
     {
	   char *class;
	   char *name;
	   int HP;
	   int HPM;
	   int MP; 
	   int MPM;
	   int Str; int StrM;
	   int End; int EndM;
	   int Spd; int SpdM;
	   int Wsd; int WsdM;
	   int HPL; 
	   int MPL;
	   int level;
	   int XP;
	   int sp;
	   int dmg;
	   int dmgB;
	   int armor;
	   int Gold;
     };
     typedef struct player player;
     
     extern player you[];
     
     extern int audio_rate      ;// 22050;
     extern Uint16 audio_format ;// AUDIO_S16;
     extern int audio_channels  ;// 2;
     extern int audio_buffers   ;// 4096;
     
     extern Mix_Chunk *Shot ;// NULL; //Mix_PlayChannel(-1, Shot, 0);
     
     extern Mix_Chunk *AnbAtt ;// NULL;
     extern Mix_Chunk *AnbDie ;// NULL;
     
     extern Mix_Chunk *SpdAtt ;// NULL;
     extern Mix_Chunk *SpdDie ;// NULL;
     
     extern int cnt ;// 0;
     extern int L1;
     
     extern int ItemInfo ;// 0;
     extern int cull ;// 0;
     extern int dx , dy;// 0, dy ;// 0;
     extern float currentTime ;// 0.0;
     extern char tmppp[128];
     extern int miniMAp;
     extern int miniMe;
     
//      extern int true ;
//      extern int false ;
     
     struct Image {
	   GLsizei sizeX;
       GLsizei sizeY;
	   char *data;
     };
     typedef struct Image Image;
     
     typedef struct			// Create A Structure
     {
	   GLubyte	*imageData;	// Image Data (Up To 32 Bits)
	   GLuint	bpp;		// Image Color Depth In Bits Per Pixel.
	   GLuint	width;		// Image Width
	   GLuint	height;		// Image Height
	   GLuint	texID;		// Texture ID Used To Select A Texture
     } TextureImage;	
      
     extern GLuint	texture[];	// Storage for all textures.
     extern GLuint	atexture[];	// Storage for all textures.
     
     extern TextureImage  texttex ;// {NULL, 1, 2, 3, 4};
     extern TextureImage  minimap ;// {NULL, 1, 2, 3, 4};
     extern TextureImage  insideT[] ;// { {NULL, 1, 2, 3, 4}, {NULL, 1, 2, 3, 4} };
     extern TextureImage  Btn[] ;// { {NULL, 1, 2, 3, 4}, {NULL, 1, 2, 3, 4} };
     extern TextureImage	cross  ;// {NULL, 1, 2, 3, 4};
     extern TextureImage	Itm[]  ;// {{NULL, 1, 2, 3, 4}, {NULL, 1, 2, 3, 4}, {NULL, 1, 2, 3, 4} ,{NULL, 1, 2, 3, 4}, {NULL, 1, 2, 3, 4}};
     
    
     extern int aaaa  ;// 0;
     extern int ccc   ;// 0;
     extern float aVX, aVZ , sVX, sVZ;
     
     typedef struct
     {
	   int is;
	   int id;
     } itmL;
     

#endif
