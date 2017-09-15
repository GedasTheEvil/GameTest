#include "vars.h"
     
     int winDemo = 0;
     
     int mouseX;
     int mouseY;
     
     int ITMindex = 0;
// 	!mouse

//	inventory
     int infoShow =  0;
     int infoItem = -1;
     int ShowPassMap = 0;
     
     int LastMap = LAND1;
     
     int InvGrid[] = /*6 x 5*/
     {
	   0x00, 0x01, 0x20, 0x00, 0x00, 0x00, 
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	   0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
	   0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00
     };
     
     int selectedItem = 0x00;
     
     int Helm =    0x40;
     int Armor   = 0x00;
     int Boots   = 0x00;
     int RHand   = 0x00;
     int LHand   = 0x00;
     
     item *List = NULL;
//	!inventory

//	quests

     quest *QList = NULL;
     int infoQShow = 0;
     int infoQuest = 0;
     int HQ[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     int sellectedQuest = 0;

//	!quests

	int HAtimer = 0; //house action text delay
	int HT = 0; //house texture ID
	
	int L1map = 0; // If we have the minimap 
	
	int class = 0;
	
	double lastTime = 0.0f; // FPS limit
	float lastframe,thisframe; 
	int ff, fps;
	
	int ShotDelay = 0;
		
	int drunk = 0;
	int loaded = 0;
	int sound, music,fs;
	int texres = 0;
	int resX= 800, resY= 600;
	unsigned int display = MainMENU;
	int tmp_text = 0;
	char *tmpC = NULL;
	
	//text vars
	char *BAct1, *BAct2, *BAct3, *BL1, *BL2, *BL3, *BL4, *BL5;
	int BA1H = 0,BA2H = 0,BA3H = 0;
	// !text vars

	int ID = 0; //ID of building inside texture

	int window;
	float x=0.0, y=0.1, z=0.0;
	float yrot = 0.0;
	float walkAngle = 0.0;

	short plClass = 0;

	GLfloat lookupdown = 0.0;
	
	float heading, xpos=2.0, zpos=-15.0;
	float ytrans = -0.5;

	GLfloat camx = 0, camy = 0, camz = 0; // camera location.
	GLfloat therotate;

	int debugY = 0;
	int shoot  = 0;

	GLuint		base;	// Font Display List

	///fog 
	int fog;
	GLuint fogMode[] = { GL_EXP, GL_EXP2, GL_LINEAR };  /* three types of fog */
	GLuint fogFilter = 1;   /* which fog to use */
	GLfloat fogColor[] = { 0.3f, 0.3f, 0.6f, 1.0f };    /* fog color */
	//light
	GLfloat LightAmbient[]  = {0.5f, 0.5f, 0.5f, 1.0f}; 
	GLfloat LightDiffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f}; 
	GLfloat LightPosition[] = {0.0f, 0.0f, 2.0f, 1.0f};
	GLUquadricObj *quadratic;	// Storage For Our Quadratic Objects



	int ghost = 0;//ghost mode

building house[houses];

building fountain[fountains];

monster anb[anC];

monster spd[SpC];

building tree[trees];

building FTree[FTrees];

building pade;

building bez[bezers];

proj arrow;

building ship;

building well;

building tavern;

//	text inputs
     char TextKey[32];
     int  inputSw = 0;
     int tl = 0;
//	!text inputs

player you[1];

int audio_rate      = 22050;
Uint16 audio_format = AUDIO_S16;
int audio_channels  = 2;
int audio_buffers   = 4096;

Mix_Chunk *Shot = NULL; //Mix_PlayChannel(-1, Shot, 0);

Mix_Chunk *AnbAtt = NULL;
Mix_Chunk *AnbDie = NULL;

Mix_Chunk *SpdAtt = NULL;
Mix_Chunk *SpdDie = NULL;

int cnt = 0;
int L1;

int ItemInfo = 0;
int cull = 0;
int dx = 0, dy = 0;
float currentTime = 0.0;
char tmppp[128];
int miniMAp;
int miniMe;

GLuint	texture[texcount];	// Storage for all textures.
GLuint	atexture[atexcount];	// Storage for all textures.

TextureImage  texttex = {NULL, 1, 2, 3, 4};
TextureImage  minimap = {NULL, 1, 2, 3, 4};
TextureImage  insideT[intex] = { {NULL, 1, 2, 3, 4}, {NULL, 1, 2, 3, 4} };
TextureImage  Btn[buttons] = { {NULL, 1, 2, 3, 4}, {NULL, 1, 2, 3, 4} };
TextureImage	cross  = {NULL, 1, 2, 3, 4};
TextureImage	Itm[items]  = {{NULL, 1, 2, 3, 4}, {NULL, 1, 2, 3, 4}, {NULL, 1, 2, 3, 4} ,{NULL, 1, 2, 3, 4}, {NULL, 1, 2, 3, 4}};

//pagalbiniai scenos kint
int aaaa  = 0;
int ccc   = 0;
// float aVX, aVZ , sVX, sVZ;

