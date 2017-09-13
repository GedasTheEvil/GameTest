#include "textures.h"

short LoadTGA(TextureImage *texture, char *filename)			// Loads A TGA File Into Memory
{
	GLubyte		TGAheader[12]={0,0,2,0,0,0,0,0,0,0,0,0};	// Uncompressed TGA Header
	GLubyte		TGAcompare[12];					// Used To Compare TGA Header
	GLubyte		header[6];					// First 6 Useful Bytes From The Header
	GLuint		bytesPerPixel;					// Holds Number Of Bytes Per Pixel Used In The TGA File
	GLuint		imageSize;					// Used To Store The Image Size When Setting Aside Ram
	GLuint		temp;						// Temporary Variable
	GLuint		type=GL_RGBA;					// Set The Default GL Mode To RBGA (32 BPP)

	FILE *file = fopen(filename, "rb");				// Open The TGA File

	if(	file==NULL ||						// Does File Even Exist?
		fread(TGAcompare,1,sizeof(TGAcompare),file)!=sizeof(TGAcompare) ||	// Are There 12 Bytes To Read?
		memcmp(TGAheader,TGAcompare,sizeof(TGAheader))!=0		||	// Does The Header Match What We Want?
		fread(header,1,sizeof(header),file)!=sizeof(header))			// If So Read Next 6 Header Bytes
	{
		if (file != NULL)							// Did The File Even Exist? *Added Jim Strong*
			fclose(file);							// If Anything Failed, Close The File

		return false;								// Return False
	}

	texture->width  = header[1] * 256 + header[0];					// Determine The TGA Width	(highbyte*256+lowbyte)
	texture->height = header[3] * 256 + header[2];					// Determine The TGA Height	(highbyte*256+lowbyte)

 	if(	texture->width	<=0	||						// Is The Width Less Than Or Equal To Zero
		texture->height	<=0	||						// Is The Height Less Than Or Equal To Zero
		(header[4]!=24 && header[4]!=32))					// Is The TGA 24 or 32 Bit?
	{
		fclose(file);								// If Anything Failed, Close The File
		return false;								// Return False
	}

	texture->bpp	= header[4];					// Grab The TGA's Bits Per Pixel (24 or 32)
	bytesPerPixel	= texture->bpp/8;				// Divide By 8 To Get The Bytes Per Pixel
	imageSize		= texture->width*texture->height*bytesPerPixel;	// Calculate The Memory Required For The TGA Data

	texture->imageData = (GLubyte *)malloc(imageSize);				// Reserve Memory To Hold The TGA Data

	if(	texture->imageData==NULL ||									// Does The Storage Memory Exist?
		fread(texture->imageData, 1, imageSize, file)!=imageSize)	// Does The Image Size Match The Memory Reserved?
	{
		if(texture->imageData!=NULL)								// Was Image Data Loaded
		{
			free(texture->imageData);								// If So, Release The Image Data
			texture->imageData = NULL;
		}

		fclose(file);												// Close The File
		return false;												// Return False
	}


	GLuint i;

	for(i=0; i<(unsigned int)imageSize; i+=bytesPerPixel)	// Loop Through The Image Data
	{																// Swaps The 1st And 3rd Bytes ('R'ed and 'B'lue)
		temp=texture->imageData[i];									// Temporarily Store The Value At Image Data 'i'
		texture->imageData[i] = texture->imageData[i + 2];			// Set The 1st Byte To The Value Of The 3rd Byte
		texture->imageData[i + 2] = temp;							// Set The 3rd Byte To The Value In 'temp' (1st Byte Value)
	}

	fclose (file);													// Close The File

	// Build A Texture From The Data
	glGenTextures(1, &texture[0].texID);							// Generate OpenGL texture IDs

	glBindTexture(GL_TEXTURE_2D, texture[0].texID);				// Bind Our Texture
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtered
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// Linear Filtered

	if (texture[0].bpp==24)											// Was The TGA 24 Bits
	{
		type=GL_RGB;												// If So Set The 'type' To GL_RGB
	}

	glTexImage2D(GL_TEXTURE_2D, 0, type, texture[0].width, texture[0].height,
		0, type, GL_UNSIGNED_BYTE, texture[0].imageData);

	return true;													// Texture Building Went Ok, Return True
}


int ImageLoad(char *filename, Image *image) {

    FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned short int planes;          // number of planes in image (must be 1) 
    unsigned short int bpp;             // number of bits per pixel (must be 24)
//     char temp;                          // used to convert bgr to rgb color.

	// Make sure the file exists
	if ((file = fopen(filename, "rb"))==NULL)
	{
		printf("File Not Found : %s\n",filename);
		return 0;
	}

	// Skip to bmp header
	fseek(file,18, SEEK_CUR);

	// read width
	if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
		printf("Error reading width from %s.\n", filename);
		return 0;
	}
	printf("Width of %s: %lu\n",filename, image->sizeX);

	//read the height
	if ((i = fread(&image->sizeY,4,1,file)) != 1) {
		printf("Error reading height from %s.\n", filename);
		return 0;
	}
	printf("Height of %s: %lu\n", filename, image->sizeY);

	// calculate the size (assuming 24 bpp)
	size = image->sizeX * image->sizeY * 3;

	// read the planes
	if ((fread(&planes, 2, 1, file)) != 1) {
		printf("Error reading planes from %s. \n", filename);
		return 0;
	}

	if (planes != 1) {
		printf("Planes from %s is not 1: %u\n", filename, planes);
		return 0;
	}

	// read the bpp
	if ((i = fread(&bpp, 2, 1, file)) != 1) {
		printf("Error reading bpp from %s. \n", filename);
		return 0;
	}

	if (bpp != 24) {
		printf("Bpp from %s is not 24: %u\n", filename, bpp);
		return 0;
	}

	// seek past the rest of the bitmap header
	fseek(file, 24, SEEK_CUR);

	// Read the data
	image->data = (char *) malloc(size);
	if (image->data == NULL) {
		printf("Error allocating memory for colour-corrected image data");
		return 0;
	}

	if ((i = fread(image->data,size,1,file)) != 1) {
		printf("Error reading image data from %s.\n", filename);
		return 0;
	}

	// reverse all of the colours bgr => rgb)
// 	for (i=0;i<size;i+=3) {
// 		temp = image->data[i];
// 		image->data[i] = image->data[i+2];
// 		image->data[i+2] = temp;
// 	}

	// Thats all folks
	return 1;


}


//----------------------------------------------------------------------------------
// Load texture into memory
int ImageLoad32(char *filename, Image *image) {

    FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned short int planes;          // number of planes in image (must be 1) 
    unsigned short int bpp;             // number of bits per pixel (must be 24)
//     char temp;                          // used to convert bgr to rgb color.

	// Make sure the file exists
	if ((file = fopen(filename, "rb"))==NULL)
	{
		printf("File Not Found : %s\n",filename);
		return 0;
	}

	// Skip to bmp header
	fseek(file,18, SEEK_CUR);

	// read width
	if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
		printf("Error reading width from %s.\n", filename);
		return 0;
	}
	printf("Width of %s: %lu\n",filename, image->sizeX);

	//read the height
	if ((i = fread(&image->sizeY,4,1,file)) != 1) {
		printf("Error reading height from %s.\n", filename);
		return 0;
	}
	printf("Height of %s: %lu\n", filename, image->sizeY);

	// calculate the size (assuming 24 bpp)
	size = image->sizeX * image->sizeY * 3;

	// read the planes
	if ((fread(&planes, 2, 1, file)) != 1) {
		printf("Error reading planes from %s. \n", filename);
		return 0;
	}

	if (planes != 1) {
		printf("Planes from %s is not 1: %u\n", filename, planes);
		return 0;
	}

	// read the bpp
	if ((i = fread(&bpp, 2, 1, file)) != 1) {
		printf("Error reading bpp from %s. \n", filename);
		return 0;
	}

	if (bpp != 32) {
		printf("Bpp from %s is not 32: %u\n", filename, bpp);
		return 0;
	}

	// seek past the rest of the bitmap header
	fseek(file, 24, SEEK_CUR);

	// Read the data
	image->data = (char *) malloc(size);
	if (image->data == NULL) {
		printf("Error allocating memory for colour-corrected image data");
		return 0;
	}

	if ((i = fread(image->data,size,1,file)) != 1) {
		printf("Error reading image data from %s.\n", filename);
		return 0;
	}

	// Thats all folks
	return 1;


}

Image* allocateBitmap(char filename[])
{
    printf("Loading bitmap '%s'\n", filename);
    Image *image = (Image *) malloc(sizeof(Image));

    if (image == NULL) {
        printf("Error allocating space for image '%s'\n", filename);
        exit(0);
    }

    image->data = NULL;

    if (!ImageLoad(filename, image)) {
        printf("Failed to allocate image '%s'\n", filename);
    }

    printf("Loaded bitmap '%s' sized %d x %d\n", filename, (int)image->sizeX, (int)image->sizeY);

    return image;
}


void LoadGLTexturesLow() {

//-----------------------------------------------------------------------------------------------------------
	// Stores the texture
	Image *image[texcount];
	Image *aimage[atexcount];
    int textureIndex = 0;

	// Allocate space for texture
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/land1.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/house1.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/house2.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/anub.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/fountain.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/signpost.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/temple.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/tree1.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/tree2.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/padestal.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/bezer.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/water.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/sky.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/ship.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/well.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/dung1.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/tavern.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/arrow.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/spider.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/Low/Objects/dung1E.bmp");
//----------------------------------------------------------------------------------------------------------------	

	// create Texture
    glGenTextures(texcount, &texture[0]);
    glGenTextures(atexcount, &atexture[0]);
//------------------------------------------------------------------------------------------------------------------------
    // texturos is image'u
    	int j = 0;
	for(j=0; j< texcount; j++)
	{
    	 	glBindTexture(GL_TEXTURE_2D, texture[j]);   // 2d texture (x and y size)
   	 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
   	 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
   	 	glTexImage2D(GL_TEXTURE_2D, 0, 3, image[j]->sizeX, image[j]->sizeY, 0, GL_BGR, GL_UNSIGNED_BYTE, image[j]->data);
	}//eofor

	for(j=0; j< atexcount; j++)
	{
    	 	glBindTexture(GL_TEXTURE_2D, atexture[j]);   // 2d texture (x and y size)
   	 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
   	 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
   	 	glTexImage2D(GL_TEXTURE_2D, 0, 3, aimage[j]->sizeX, aimage[j]->sizeY, 0, GL_BGRA, GL_UNSIGNED_BYTE, aimage[j]->data);
	}//eofor
	LoadTGA(&insideT[0],"./Textures/Low/Buildings/temple_i.tga");
	LoadTGA(&insideT[1],"./Textures/Low/Buildings/house_i.tga");
	LoadTGA(&insideT[2],"./Textures/Low/Buildings/ship_i.tga");
	LoadTGA(&insideT[3],"./Textures/Low/Buildings/tavern_i.tga");
	LoadTGA(&insideT[4],"./Textures/Low/Buildings/house_i.tga");
	if(!LoadTGA(&insideT[DungEnter],"./Textures/Low/Buildings/dungI.tga"))printf("Dungeon bitmap fail\n");

//------------------------------------------------------------------------------------------------------------------------

}


void LoadGLTexturesHigh() {

//-----------------------------------------------------------------------------------------------------------
	// Stores the texture
	Image *image[texcount];
	Image *aimage[atexcount];
    int textureIndex = 0;

    // Allocate space for texture
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/land1.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/house1.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/house2.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/anub.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/fountain.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/signpost.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/temple.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/tree1.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/tree2.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/padestal.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/bezer.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/water.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/sky.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/ship.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/well.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/dung1.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/tavern.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/arrow.bmp");
    image[textureIndex++] = allocateBitmap("./Textures/High/Objects/spider.bmp");
    image[textureIndex] = allocateBitmap("./Textures/High/Objects/dung1E.bmp");

//----------------------------------------------------------------------------------------------------------------	

	// create Texture
    glGenTextures(texcount, &texture[0]);
    glGenTextures(atexcount, &atexture[0]);
//------------------------------------------------------------------------------------------------------------------------
    // texturos is image'u
    	int j = 0;
	for(j=0; j< texcount; j++)
	{
    	 	glBindTexture(GL_TEXTURE_2D, texture[j]);   // 2d texture (x and y size)
   	 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
   	 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
   	 	glTexImage2D(GL_TEXTURE_2D, 0, 3, image[j]->sizeX, image[j]->sizeY, 0, GL_BGR, GL_UNSIGNED_BYTE, image[j]->data);
	}//eofor

	for(j=0; j< atexcount; j++)
	{
    	 	glBindTexture(GL_TEXTURE_2D, atexture[j]);   // 2d texture (x and y size)
   	 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
   	 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
   	 	glTexImage2D(GL_TEXTURE_2D, 0, 3, aimage[j]->sizeX, aimage[j]->sizeY, 0, GL_BGRA, GL_UNSIGNED_BYTE, aimage[j]->data);
	}//eofor
	LoadTGA(&insideT[0],"./Textures/High/Buildings/temple_i.tga");
	LoadTGA(&insideT[1],"./Textures/High/Buildings/house_i.tga");
	LoadTGA(&insideT[2],"./Textures/High/Buildings/ship_i.tga");
	LoadTGA(&insideT[3],"./Textures/High/Buildings/tavern_i.tga");
	if(!LoadTGA(&insideT[DungEnter],"./Textures/High/Buildings/dungI.tga"))printf("Dungeon bitmap fail\n");

//------------------------------------------------------------------------------------------------------------------------

}

void LoadIntefaceTex()
{
     if(!LoadTGA(&texttex, "./Textures/Font.tga"))printf("Failed to load fonts\n");
     if(!LoadTGA(&minimap, "./Textures/minimap.tga"))printf("Failed to load minimap\n");

     LoadTGA(&Btn[BtnBG],"./Textures/Buttons/marble.tga");
     LoadTGA(&Btn[BtnLeave],"./Textures/Buttons/Btn_leave.tga");
     LoadTGA(&Btn[BtnNewGame],"./Textures/Buttons/Btn_ng.tga");
     LoadTGA(&Btn[BtnLoad],"./Textures/Buttons/Btn_load.tga");
     LoadTGA(&Btn[BtnConf],"./Textures/Buttons/Btn_conf.tga");
     LoadTGA(&Btn[BtnCredits],"./Textures/Buttons/Btn_credits.tga");
     LoadTGA(&Btn[BtnExit],"./Textures/Buttons/Btn_exit.tga");
     LoadTGA(&Btn[BtnSave],"./Textures/Buttons/Btn_save.tga");
     LoadTGA(&Btn[BtnCh0],"./Textures/Buttons/check0.tga");
     LoadTGA(&Btn[BtnCh1],"./Textures/Buttons/check1.tga");
     LoadTGA(&Btn[BtnEmpty],"./Textures/Buttons/Btn_temp.tga");
     LoadTGA(&Btn[LoadBar],"./Textures/Buttons/loading.tga");
     LoadTGA(&Btn[BtnBack],"./Textures/Buttons/Btn_back.tga");
     LoadTGA(&Btn[Bar],"./Textures/Buttons/bar.tga");
     LoadTGA(&Btn[BtnSkill],"./Textures/Buttons/Btn_skills.tga");
     LoadTGA(&Btn[BtnStats],"./Textures/Buttons/Btn_stats.tga");
     LoadTGA(&Btn[BtnInvent],"./Textures/Buttons/Btn_invent.tga");
     LoadTGA(&Btn[BtnQuest],"./Textures/Buttons/Btn_quest.tga");
     LoadTGA(&Btn[BtnInfBG],"./Textures/Buttons/info.tga");
     LoadTGA(&cross,"./Textures/cross.tga");
}

void LoadItems()
{
     LoadTGA(&Itm[0x00],"./Textures/Items/inventory.tga");
     LoadTGA(&Itm[0x01],"./Textures/Items/gun01.tga");
     LoadTGA(&Itm[0x10],"./Textures/Items/armor01.tga");
     LoadTGA(&Itm[0x20],"./Textures/Items/boots01.tga");
     LoadTGA(&Itm[0x40],"./Textures/Items/helm01.tga");
     LoadTGA(&Itm[0x70],"./Textures/Items/shield01.tga");
     LoadTGA(&Itm[0x81],"./Textures/Items/quest01.tga");
     LoadTGA(&Itm[0x82],"./Textures/Items/quest02.tga");
}
