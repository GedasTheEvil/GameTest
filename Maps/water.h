#ifndef Water
#define Water

float WaterVertex[] = {
	-5.080625, 0.000000, -16.024420,
 	-16.213802, 0.000000, -16.024427,
 	-16.213802, 0.000002, 16.024422,
 	-5.080625, 0.000000, -16.024420,
 	-16.213802, 0.000002, 16.024422,
 	-5.080625, 0.000002, 16.024424,
 };

float WaterNormals[] = {
	0.000000, 1.000000, 0.000000,
 	0.000000, 1.000000, 0.000000,
 	0.000000, 1.000000, 0.000000,
 	0.000000, 1.000000, 0.000000,
 	0.000000, 1.000000, 0.000000,
 	0.000000, 1.000000, 0.000000,
 };

float WaterTexCord[] = {
	1.000000, 0.000000,
 	1.000000, 0.989868,
 	0.000000, 0.989868,
 	1.000000, 0.000000,
 	0.000000, 0.989868,
 	0.000000, 0.000000,
 };

#define kWaterNumberOfVertices	6
void ShowWater()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glVertexPointer(  3, GL_FLOAT, 0, &WaterVertex [0]);
	glNormalPointer(     GL_FLOAT, 0, &WaterNormals[0]);
	glTexCoordPointer(2, GL_FLOAT, 0, &WaterTexCord[0]);
	glDrawArrays(GL_TRIANGLES, 0, kWaterNumberOfVertices);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}
 #endif

