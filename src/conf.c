#include "conf.h"

void getConf()
{
	char tmp;

	FILE *inp;
	inp = fopen("./Config/game.ini","r");
		if(inp == NULL)printf("fail\n");
		else printf("file opened\n");
	
	tmp = fgetc ( inp ) ;
	resX= 1000 * ((int)tmp - 0x30);
	tmp = fgetc ( inp ) ;
	resX+= 100 *  ((int)tmp - 0x30);
	tmp = fgetc ( inp ) ;
	resX+= 10 *  ((int)tmp - 0x30);
	tmp = fgetc ( inp ) ;
	resX+=  ((int)tmp - 0x30);
	tmp = fgetc ( inp ) ;//tarpas

	tmp = fgetc ( inp ) ;
	resY= 1000 *  ((int)tmp - 0x30);
	tmp = fgetc ( inp ) ;
	resY+= 100 *  ((int)tmp - 0x30);
	tmp = fgetc ( inp ) ;
	resY+= 10 *  ((int)tmp - 0x30);
	tmp = fgetc ( inp ) ;
	resY+=  ((int)tmp - 0x30);

	tmp = fgetc ( inp ) ;//tarpas
	tmp = fgetc ( inp ) ;
	sound =  ((int)tmp - 0x30);

	tmp = fgetc ( inp ) ;//tarpas
	tmp = fgetc ( inp ) ;
	music =  ((int)tmp - 0x30);

	tmp = fgetc ( inp ) ;//tarpas
	tmp = fgetc ( inp ) ;
	fs =  ((int)tmp - 0x30);

	tmp = fgetc ( inp ) ;//tarpas
	tmp = fgetc ( inp ) ;
	texres =  ((int)tmp - 0x30);

	fclose(inp);
	printf("String is x[%d] y[%d],\n", resX,resY);

}

void PutConf()
{
// 	char tmp;

	FILE *inp;
	inp = fopen("./Config/game.ini","w");
		if(inp == NULL)printf("fail\n");
		else printf("file opened\n");

	if(resX < 1000)fprintf(inp,"%d",0);
	fprintf(inp,"%d ",resX);

	if(resY < 1000)fprintf(inp,"%d",0);
	fprintf(inp,"%d ",resY);

	fprintf(inp,"%d %d %d %d\n",sound, music, fs, texres);
	fprintf(inp,"\n//ResX[4];\n//ResY[4];\n//sound[1];\n//music[1];\n//fulscreen[1];\n//texture_quallity[1];\n");
	fclose(inp);
}

