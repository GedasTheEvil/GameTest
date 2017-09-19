#include "sceneSetup.h"

#include "../Maps/land1.h"
#include "../Maps/dungeon1.h"
#include "../Maps/water.h"
#include "../Maps/atmo.h"
#include "../Models/house1.h"
#include "../Models/temple.h"
#include "../Models/anubitas.h"
#include "../Models/anubitas_w1.h"
#include "../Models/anubitas_w2.h"
#include "../Models/fountain1.h"
#include "../Models/signpost.h"
#include "../Models/tree.h"
#include "../Models/tree1.h"
#include "../Models/tree2.h"
#include "../Models/padestal.h"
#include "../Models/bezier.h"
#include <time.h>
#include "../Models/ship.h"
#include "../Models/well.h"
#include "../Models/tavern.h"
#include "../Models/spider2.h"
#include "../Models/spider2w1.h"
#include "../Models/spider2a1.h"

void DrawMapItem(itmL item)
{
    glPushMatrix();

    glRotatef(yrot, 0, 1.0f, 0);
    glRotatef(360 - lookupdown, 1.0f, 0, 0);

    glBindTexture(GL_TEXTURE_2D, Itm[item.id].texID);
    glBegin(GL_QUADS);// bg
    {
        glTexCoord2i(0, 1);
        glVertex3f(0, 0, 0);    // Texture / Vertex Coord (Bottom Left)
        glTexCoord2i(1, 1);
        glVertex3f(0.1, 0, 0);    // Texutre / Vertex Coord (Bottom Right)
        glTexCoord2i(1, 0);
        glVertex3f(0.1, 0.1, 0);    // Texture / Vertex Coord (Top Right)
        glTexCoord2i(0, 0);
        glVertex3f(0, 0.1, 0);    // Texture / Vertex Coord (Top Left)
    }
    glEnd();
    glPopMatrix();
}

void DrawMapItems()
{
    if (display == DUNG1) {
        int i, j;
        for (i = 0; i < 40; i++)
            for (j = 0; j < 47; j++)
                if (Dun0Items[j + i * 47].is) {
                    glPushMatrix();
                    glTranslatef(0.5 * i + 0.3, 0, 0.5 * (j - 1));
                    DrawMapItem(Dun0Items[j + i * 47]);
                    glPopMatrix();
                }
    }
}

///NOTE: Scale, rotate, only then translate

extern float ArrowNormals[], ArrowTexCord[];

void Translate(float *a, int b, float x, float y, float z)
{//translate object once
    int i = 0;
    for (i = 0; i < b * 3; i += 3) {
        a[i] += x;
        a[i + 1] += y;
        a[i + 2] += z;
    }
}

void Scale(float *a, int b, float m)
{//scale the object
    float sumx = 0, sumy = 0, sumz = 0;
    int i = 0;
    for (i = 0; i < b * 3; i += 3) {
        sumx += a[i];
        sumy += a[i + 1];
        sumz += a[i + 2];
    }
    sumx /= b;
    sumy /= b;
    sumz /= b;

    for (i = 0; i < b * 3; i += 3) {
        a[i] = sumx + (-sumx + a[i]) * m;
        a[i + 1] = sumy + (-sumx + a[i + 1]) * m;
        a[i + 2] = sumz + (-sumx + a[i + 2]) * m;
    }
}

void RotateZ(building house)
{

    int i;
    float sa = sin(house.zrot * DegRad);
    float ca = cos(house.zrot * DegRad);

    for (i = 0; i < (house.vertCount) * 3; i += 3) {
        house.Vert[i] = house.Vert[i + 2] * sa + house.Vert[i] * ca;
        house.Vert[i + 2] = house.Vert[i + 2] * ca - house.Vert[i] * sa;
    }

}

void DrawProj(proj ar)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, ar.Vert);
    glNormalPointer(GL_FLOAT, 0, &ArrowNormals[0]);
    glTexCoordPointer(2, GL_FLOAT, 0, &ArrowTexCord[0]);
    glDrawArrays(GL_TRIANGLES, 0, ar.VC);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}

void DrawHouse(building house)
{
    glBindTexture(GL_TEXTURE_2D, (GLuint) house.tex);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &house.Vert[0]);
    glNormalPointer(GL_FLOAT, 0, &house.Norm[0]);
    glTexCoordPointer(2, GL_FLOAT, 0, &house.Tex[0]);
    glDrawArrays(GL_TRIANGLES, 0, house.vertCount);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}

void DrawMon(monster m)
{
    glPushMatrix();

    glTranslatef(m.pos[0].x, m.pos[0].y, m.pos[0].z);
    glRotatef(280.0 + m.rot + fabs(atan(-((m.pos[0].x - xpos)) / (m.pos[0].z - zpos - 9.7))) / DegRad, 0, 1, 0);

    Anim(m);
    glBindTexture(GL_TEXTURE_2D, (GLuint) m.tex);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &m.Verts[0]);
    glNormalPointer(GL_FLOAT, 0, &m.Norm[0]);
    glTexCoordPointer(2, GL_FLOAT, 0, &m.Tex[0]);
    glDrawArrays(GL_TRIANGLES, 0, m.vertC);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);

    glTranslatef(0, 0.55, 0);
// 	   gluSphere(quadratic,0.01f,8,8);
    glPopMatrix();
}

void NormalizeZ(float *A, int b)
{
    int i;
    float MinX = 999.0, MinY = 999.0, MinZ = 999.0;
    for (i = 0; i < b * 3; i += 3) {
        if (A[i] < MinX)MinX = A[i];
        if (A[i + 1] < MinY)MinY = A[i + 1];
        if (A[i + 2] < MinZ)MinZ = A[i + 2];
    }

    for (i = 0; i < b * 3; i += 3) {
        A[i] -= MinX;
        A[i + 1] -= MinY;
        A[i + 2] -= MinZ;
    }
}

void setupBuilding(building a)
{
    if (a.scale != 1.0)
        Scale(a.Vert, a.vertCount, a.scale);
    Translate(a.Vert, a.vertCount, a.pos.x, a.pos.y, a.pos.z);
}


void setupLand1()
{
    LoadGLTexturesHigh();
    Make0Segment();
    CreateDungeon0();

    InitMobs0();
    Init0Items();

    printf("setting up the map Land1... \n\n");

    house[0].Norm = TempleNormals;
    house[0].Tex = TempleTexCord;
    house[0].vertCount = kTempleNumberOfVertices;
    house[0].pos.x = 2.9;
    house[0].pos.y = -0.32;
    house[0].pos.z = -12;
    house[0].scale = 2;
    house[0].tex = (int *) texture[6];

    int i = 0;
    house[0].Vert = TempleVertex;;

    setupBuilding(house[0]);

    house[0].visible = 1;

    house[1].Norm = house1Normals;
    house[1].Tex = house1TexCord;
    house[1].vertCount = khouse1NumberOfVertices;
    house[1].pos.x = -1.8;
    house[1].pos.y = 0.2;
    house[1].pos.z = -8.5;
    house[1].scale = 0.5;
    house[1].tex = (int *) texture[1];

    house[1].Vert = (float *) malloc(sizeof(float) * 3 * house[1].vertCount);

    for (i = 0; i < house[1].vertCount * 3; i++)
        house[1].Vert[i] = house1Vertex[i];

    NormalizeZ(house[1].Vert, house[1].vertCount);

    setupBuilding(house[1]);

    house[1].visible = 1;

    house[2].Norm = house1Normals;
    house[2].Tex = house1TexCord;
    house[2].vertCount = khouse1NumberOfVertices;
    house[2].pos.x = -0.7;
    house[2].pos.y = 0.2;
    house[2].pos.z = -8.5;
    house[2].scale = 0.5;
    house[2].tex = (int *) texture[1];

    house[2].Vert = (float *) malloc(sizeof(float) * 3 * house[2].vertCount);

    for (i = 0; i < house[2].vertCount * 3; i++)
        house[2].Vert[i] = house1Vertex[i];

    NormalizeZ(house[2].Vert, house[2].vertCount);
    setupBuilding(house[2]);

    house[2].visible = 1;


    house[3].Norm = house1Normals;
    house[3].Tex = house1TexCord;
    house[3].vertCount = khouse1NumberOfVertices;
    house[3].pos.x = -1.8;
    house[3].pos.y = 0.2;
    house[3].pos.z = -7.5;
    house[3].scale = 0.5;
    house[3].tex = (int *) texture[2];
    house[3].zrot = 90;

    house[3].Vert = (float *) malloc(sizeof(float) * 3 * house[3].vertCount);

    for (i = 0; i < house[3].vertCount * 3; i++)
        house[3].Vert[i] = house1Vertex[i];

    NormalizeZ(house[3].Vert, house[3].vertCount);
    setupBuilding(house[3]);

    house[3].visible = 1;

    house[4].Norm = house1Normals;
    house[4].Tex = house1TexCord;
    house[4].vertCount = khouse1NumberOfVertices;
    house[4].pos.x = -0.7;
    house[4].pos.y = 0.2;
    house[4].pos.z = -7.5;
    house[4].scale = 0.5;
    house[4].tex = (int *) texture[2];

    house[4].Vert = (float *) malloc(sizeof(float) * 3 * house[4].vertCount);

    for (i = 0; i < house[4].vertCount * 3; i++)
        house[4].Vert[i] = house1Vertex[i];

    NormalizeZ(house[4].Vert, house[4].vertCount);
    setupBuilding(house[4]);

    house[4].visible = 1;

    //fountain near temple 1
    fountain[0].Norm = Fountain1Normals;
    fountain[0].Tex = Fountain1TexCord;
    fountain[0].vertCount = kFountain1NumberOfVertices;
    fountain[0].Vert = (float *) malloc(sizeof(float) * 3 * fountain[0].vertCount);
    for (i = 0; i < fountain[0].vertCount * 3; i++)fountain[0].Vert[i] = Fountain1Vertex[i];
    fountain[0].pos.x = 3.4;
    fountain[0].pos.y = 0.36;
    fountain[0].pos.z = -11.5;
    fountain[0].scale = 0.2;
    fountain[0].tex = (int *) texture[4];
    setupBuilding(fountain[0]);

    fountain[0].visible = 1;

    //fountain near temple 2
    fountain[1].Norm = Fountain1Normals;
    fountain[1].Tex = Fountain1TexCord;
    fountain[1].vertCount = kFountain1NumberOfVertices;
    fountain[1].Vert = (float *) malloc(sizeof(float) * 3 * fountain[0].vertCount);
    for (i = 0; i < fountain[1].vertCount * 3; i++)fountain[1].Vert[i] = Fountain1Vertex[i];
    fountain[1].pos.x = 2.4;
    fountain[1].pos.y = 0.36;
    fountain[1].pos.z = -11.5;
    fountain[1].scale = 0.2;
    fountain[1].tex = (int *) texture[4];
    setupBuilding(fountain[1]);

    fountain[1].visible = 1;

    //signpost
    Scale(SignpostVertex, kSignpostNumberOfVertices, 0.02);
    NormalizeZ(SignpostVertex, kSignpostNumberOfVertices);
    Translate(SignpostVertex, kSignpostNumberOfVertices, 10.0, 0.3, -10);

    //anubis
    anb[0].Norm = AnubisNormals;
    anb[0].Tex = AnubisTexCord;
    anb[0].vertC = kAnubisNumberOfVertices;
    anb[0].tex = (int *) texture[3];

    anb[0].Stand = (float *) malloc(sizeof(float) * 3 * anb[0].vertC);
    anb[0].Walk1 = (float *) malloc(sizeof(float) * 3 * anb[0].vertC);
    anb[0].Walk2 = (float *) malloc(sizeof(float) * 3 * anb[0].vertC);
    anb[0].Att1 = (float *) malloc(sizeof(float) * 3 * anb[0].vertC);
    anb[0].Att2 = (float *) malloc(sizeof(float) * 3 * anb[0].vertC);
    anb[0].Verts = (float *) malloc(sizeof(float) * 3 * anb[0].vertC); //Main array

    for (i = 0; i < anb[0].vertC * 3; i++) {
        anb[0].Stand[i] = AnubisVertex[i];
        anb[0].Walk1[i] = Anubis_W1Vertex[i];
        anb[0].Walk2[i] = Anubis_W2Vertex[i];
        anb[0].Att2[i] = Anubis_W2Vertex[i];
        anb[0].Att1[i] = Anubis_W1Vertex[i];
        anb[0].Verts[i] = AnubisVertex[i];
    }

    anb[0].scale = 0.3;
    anb[0].pos = (cord *) malloc(sizeof(cord));
    anb[0].pos[0].x = 8.3;
    anb[0].pos[0].y = 0.48;
    anb[0].pos[0].z = -6.6;

    anb[0].morph = 0.1;
    anb[0].state = anb[0].Stand;
    anb[0].Nstate = anb[0].Stand;
    anb[0].Hp = anb[0].HpMax = 300;
    anb[0].XP = 1800;
    anb[0].dmg = 3;
    anb[0].attDelay = 0;
    anb[0].rot = 90;
    anb[0].VX = 0;
    anb[0].VZ = 0;

// 	setupMon(anb[0]);
    anb[0].status = 1;
    anb[0].alive = 1;

    //the trees
    tree[0].Norm = Tree1Normals;
    tree[0].Tex = Tree1TexCord;
    tree[0].vertCount = kTree1NumberOfVertices;
    tree[0].Vert = (float *) malloc(sizeof(float) * 3 * tree[0].vertCount);
    for (i = 0; i < tree[0].vertCount * 3; i++)tree[0].Vert[i] = Tree1Vertex[i];
    tree[0].pos.x = 1.8;
    tree[0].pos.y = 0.296;
    tree[0].pos.z = -10.1;
    tree[0].scale = 1;
    tree[0].tex = (int *) texture[7];
    tree[0].blend = 1;

    tree[1].Norm = Tree1Normals;
    tree[1].Tex = Tree1TexCord;
    tree[1].vertCount = kTree1NumberOfVertices;
    tree[1].Vert = (float *) malloc(sizeof(float) * 3 * tree[1].vertCount);
    for (i = 0; i < tree[1].vertCount * 3; i++)tree[1].Vert[i] = Tree1Vertex[i];
    tree[1].pos.x = 1.8;
    tree[1].pos.y = 0.296;
    tree[1].pos.z = -10.5;
    tree[1].scale = 1;
    tree[1].tex = (int *) texture[7];
    tree[1].blend = 1;


    tree[2].Norm = Tree1Normals;
    tree[2].Tex = Tree1TexCord;
    tree[2].vertCount = kTree1NumberOfVertices;
    tree[2].Vert = (float *) malloc(sizeof(float) * 3 * tree[2].vertCount);
    for (i = 0; i < tree[2].vertCount * 3; i++)tree[2].Vert[i] = Tree1Vertex[i];
    tree[2].pos.x = 1.8;
    tree[2].pos.y = 0.296;
    tree[2].pos.z = -10.9;
    tree[2].scale = 1;
    tree[2].tex = (int *) texture[7];
    tree[2].blend = 1;

    tree[3].Norm = Tree1Normals;
    tree[3].Tex = Tree1TexCord;
    tree[3].vertCount = kTree1NumberOfVertices;
    tree[3].Vert = (float *) malloc(sizeof(float) * 3 * tree[3].vertCount);
    for (i = 0; i < tree[3].vertCount * 3; i++)tree[3].Vert[i] = Tree1Vertex[i];
    tree[3].pos.x = 1.8;
    tree[3].pos.y = 0.296;
    tree[3].pos.z = -11.3;
    tree[3].scale = 1;
    tree[3].tex = (int *) texture[7];
    tree[3].blend = 1;


    tree[4].Norm = Tree1Normals;
    tree[4].Tex = Tree1TexCord;
    tree[4].vertCount = kTree1NumberOfVertices;
    tree[4].Vert = (float *) malloc(sizeof(float) * 3 * tree[4].vertCount);
    for (i = 0; i < tree[4].vertCount * 3; i++)tree[4].Vert[i] = Tree1Vertex[i];
    tree[4].pos.x = 3.8;
    tree[4].pos.y = 0.296;
    tree[4].pos.z = -10.1;
    tree[4].scale = 1;
    tree[4].tex = (int *) texture[7];
    tree[4].blend = 1;


    tree[5].Norm = Tree1Normals;
    tree[5].Tex = Tree1TexCord;
    tree[5].vertCount = kTree1NumberOfVertices;
    tree[5].Vert = (float *) malloc(sizeof(float) * 3 * tree[5].vertCount);
    for (i = 0; i < tree[5].vertCount * 3; i++)tree[5].Vert[i] = Tree1Vertex[i];
    tree[5].pos.x = 3.8;
    tree[5].pos.y = 0.296;
    tree[5].pos.z = -10.5;
    tree[5].scale = 1;
    tree[5].tex = (int *) texture[7];
    tree[5].blend = 1;


    tree[6].Norm = Tree1Normals;
    tree[6].Tex = Tree1TexCord;
    tree[6].vertCount = kTree1NumberOfVertices;
    tree[6].Vert = (float *) malloc(sizeof(float) * 3 * tree[6].vertCount);
    for (i = 0; i < tree[6].vertCount * 3; i++)tree[6].Vert[i] = Tree1Vertex[i];
    tree[6].pos.x = 3.8;
    tree[6].pos.y = 0.296;
    tree[6].pos.z = -10.9;
    tree[6].scale = 1;
    tree[6].tex = (int *) texture[7];
    tree[6].blend = 1;


    tree[7].Norm = Tree1Normals;
    tree[7].Tex = Tree1TexCord;
    tree[7].vertCount = kTree1NumberOfVertices;
    tree[7].Vert = (float *) malloc(sizeof(float) * 3 * tree[7].vertCount);
    for (i = 0; i < tree[7].vertCount * 3; i++)tree[7].Vert[i] = Tree1Vertex[i];
    tree[7].pos.x = 3.8;
    tree[7].pos.y = 0.296;
    tree[7].pos.z = -11.3;
    tree[7].scale = 1;
    tree[7].tex = (int *) texture[7];
    tree[7].blend = 1;


    int j = 0, k = 0;

    for (j = 8; j < 8 * 7; j += 6)
        for (k = 0; k < 6; k++) {
            tree[j + k].Norm = Tree2Normals;
            tree[j + k].Tex = Tree2TexCord;
            tree[j + k].vertCount = kTree2NumberOfVertices;
            tree[j + k].Vert = (float *) malloc(sizeof(float) * 3 * tree[j + k].vertCount);
            for (i = 0; i < tree[j + k].vertCount * 3; i++)tree[j + k].Vert[i] = Tree2Vertex[i];
            tree[j + k].pos.x = 4.5 + (0.1 * (j - 8)) + 0.2 * (k % 2);
            tree[j + k].pos.y = 0.296;
            tree[j + k].pos.z = -13.9 + 0.65 * k;
            tree[j + k].scale = 1;
            tree[j + k].tex = (int *) texture[8];
            tree[j + k].blend = 1;

        }

    for (i = 0; i < trees; i++) {
        NormalizeZ(tree[i].Vert, tree[i].vertCount);
        setupBuilding(tree[i]);
        tree[i].visible = 1;
    }

    srand((unsigned) time(0));

    for (i = 0; i < FTrees; i++) {
        FTree[i].Norm = Tree2Normals;
        FTree[i].Tex = Tree2TexCord;
        FTree[i].vertCount = kTree2NumberOfVertices;


        FTree[i].Vert = (float *) malloc(sizeof(float) * 3 * FTree[i].vertCount);
        for (j = 0; j < FTree[0].vertCount * 3; j++)
            FTree[i].Vert[j] = Tree2Vertex[j];
        FTree[i].pos.x = -4.5 + 0.4 * i;
        FTree[i].pos.y = 0.32;
        FTree[i].pos.z = -4.5 + (rand() % 5) * 0.1;
        FTree[i].scale = 1.5 - (rand() % 10) * 0.1;
        FTree[i].blend = 0;
        FTree[i].tex = (int *) texture[8];
        NormalizeZ(FTree[i].Vert, FTree[i].vertCount);
        setupBuilding(FTree[i]);
        FTree[i].visible = 1;
    }

    pade.Norm = PadestalNormals;
    pade.Tex = PadestalTexCord;
    pade.vertCount = kPadestalNumberOfVertices;
    pade.Vert = PadestalVertex;
    pade.pos.x = -0.8;
    pade.pos.y = -3.35;
    pade.pos.z = -13.2;
    pade.scale = 0.04;
    pade.tex = (int *) texture[9];
    NormalizeZ(pade.Vert, pade.vertCount);
    setupBuilding(pade);
    pade.visible = 1;

    bez[0].Norm = BezierNormals;
    bez[0].Tex = BezierTexCord;
    bez[0].vertCount = kBezierNumberOfVertices;
    bez[0].Vert = (float *) malloc(sizeof(float) * 3 * bez[0].vertCount);
    for (i = 0; i < bez[0].vertCount * 3; i++)bez[0].Vert[i] = BezierVertex[i];
    bez[0].tex = (int *) texture[10];
    bez[0].pos.x = house[0].pos.x - 0.92;
    bez[0].pos.y = -1.07;
    bez[0].pos.z = house[0].pos.z - 0.71;
    bez[0].scale = 0.07;
    NormalizeZ(bez[0].Vert, bez[0].vertCount);
    setupBuilding(bez[0]);
    bez[0].visible = 1;

    bez[1].Norm = BezierNormals;
    bez[1].Tex = BezierTexCord;
    bez[1].vertCount = kBezierNumberOfVertices;
    bez[1].Vert = (float *) malloc(sizeof(float) * 3 * bez[1].vertCount);
    for (i = 0; i < bez[1].vertCount * 3; i++)bez[1].Vert[i] = BezierVertex[i];
    bez[1].tex = (int *) texture[10];
    bez[1].pos.x = house[0].pos.x - 0.1;
    bez[1].pos.y = -1.07;
    bez[1].pos.z = house[0].pos.z - 0.71;
    bez[1].scale = 0.07;
    NormalizeZ(bez[1].Vert, bez[1].vertCount);
    setupBuilding(bez[1]);
    bez[1].visible = 1;

    ship.Norm = ShipNormals;
    ship.Tex = ShipTexCord;
    ship.vertCount = kShipNumberOfVertices;
    ship.tex = (int *) texture[13];
    ship.Vert = ShipVertex;
    ship.pos.x = -13.5;
    ship.pos.y = -0.56;
    ship.pos.z = -12;
    ship.scale = 0.3;
    NormalizeZ(ship.Vert, ship.vertCount);
    setupBuilding(ship);
    ship.visible = 1;

    well.Norm = WellNormals;
    well.Tex = WellTexCord;
    well.vertCount = kWellNumberOfVertices;
    well.tex = (int *) texture[14];
    well.Vert = WellVertex;
    well.pos.x = -0.6;
    well.pos.y = -0.78;
    well.pos.z = -8.3;
    well.scale = 0.05;
    NormalizeZ(well.Vert, well.vertCount);
    setupBuilding(well);
    well.visible = 1;

    arrow.beg.x = 0.0;
    arrow.beg.y = 0.5;
    arrow.beg.z = 0.0;
    arrow.end.z = 0.0;
    arrow.end.y = 0.5;
    arrow.end.z = 0.0;
    arrow.VC = 336;
    arrow.Vert = (float *) malloc(sizeof(float) * 3 * arrow.VC);;
// 	NormalizeZ(arrow.Vert, arrow.VC);
    arrow.visible = 1;

    tavern.Norm = TavernNormals;
    tavern.Tex = TavernTexCord;
    tavern.vertCount = kTavernNumberOfVertices;
    tavern.tex = (int *) texture[16];
    tavern.Vert = TavernVertex;
    tavern.pos.x = -5.6;
    tavern.pos.y = 0.65;
    tavern.pos.z = -13.3;
    tavern.scale = 0.5;
    NormalizeZ(tavern.Vert, tavern.vertCount);
    setupBuilding(tavern);
    tavern.visible = 1;

    spd[0].Norm = Spider2Normals;
    spd[0].Tex = Spider2TexCord;
    spd[0].vertC = kSpider2NumberOfVertices;
    spd[0].Stand = (float *) malloc(sizeof(float) * 3 * spd[0].vertC);
    spd[0].Walk1 = (float *) malloc(sizeof(float) * 3 * spd[0].vertC);
    spd[0].Walk2 = (float *) malloc(sizeof(float) * 3 * spd[0].vertC);
    spd[0].Verts = (float *) malloc(sizeof(float) * 3 * spd[0].vertC);
    spd[0].Att1 = (float *) malloc(sizeof(float) * 3 * spd[0].vertC);
    spd[0].Att2 = (float *) malloc(sizeof(float) * 3 * spd[0].vertC);
    spd[0].scale = 0.01;
    spd[0].pos = (cord *) malloc(sizeof(cord));
    spd[0].pos[0].x = 9.3;
    spd[0].pos[0].y = 0.38;
    spd[0].pos[0].z = -6.1;
    spd[0].tex = (int *) texture[18];
    spd[0].HpMax = spd[0].Hp = 100;
    spd[0].XP = 900;
    spd[0].dmg = 3;
    spd[0].attDelay = 0;
    spd[0].rot = 0.0;
    spd[0].VX = 0;
    spd[0].VZ = 0;

    spd[0].morph = 0.1;
    spd[0].state = spd[0].Walk1;
    spd[0].Nstate = spd[0].Stand;

    for (i = 0; i < spd[0].vertC * 3; i++) {
        spd[0].Stand[i] = Spider2Vertex[i];
        spd[0].Walk1[i] = Spider2w1Vertex[i];
        spd[0].Walk2[i] = Spider2Vertex[i];
        spd[0].Verts[i] = Spider2Vertex[i];
        spd[0].Att1[i] = Spider2a1Vertex[i];
        spd[0].Att2[i] = Spider2Vertex[i];
    }

    spd[0].status = 1;

    spd[0].alive = 1;


    compL1();

}

float getZ()
{
    int x = xpos, z = zpos;
    if (x < -5 && x > -8 && z < -2 && z > -24)return -0.5;
    if (x > -14 && x < -8.5)return 2.3;
    return -0.5;

}

void Dungeon1()
{
    GLfloat xtrans, ztrans;
    GLfloat sceneroty;
    xtrans = -xpos;
    ztrans = -9.6 - zpos;
    sceneroty = 360.0f - yrot;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        // Clear The Screen And The Depth Buffer
    glLoadIdentity();
    glRotatef(lookupdown, 1.0f, 0, 0);
    glRotatef(sceneroty, 0, 1.0f, 0);

    glTranslatef(xtrans, ytrans, ztrans);

    glColor4f(1.0, 1.0, 1.0, 0.98);

    glBindTexture(GL_TEXTURE_2D, texture[0xf]);
    ShowDungeon();

    if (arrow.visible)DrawProj(arrow);
    UpdProj();

    Text();

    glutSwapBuffers();

}

void compL1()
{
    L1 = glGenLists(1);

    glNewList(L1, GL_COMPILE);
    {
        //land
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, &Land1Vertex[0]);
        glNormalPointer(GL_FLOAT, 0, &Land1Normals[0]);
        glTexCoordPointer(2, GL_FLOAT, 0, &Land1TexCord[0]);
        glDrawArrays(GL_TRIANGLES, 0, kLand1NumberOfVertices);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glBindTexture(GL_TEXTURE_2D, texture[11]);
        glEnable(GL_BLEND);
        ShowWater();
        glDisable(GL_BLEND);
        glBindTexture(GL_TEXTURE_2D, texture[12]);
        ShowAtmosphere();

        //houses
        int k;
        for (k = 0; k < houses; k++)
            if (house[k].visible)DrawHouse(house[k]);

        for (k = 0; k < fountains; k++)
            if (fountain[k].visible)DrawHouse(fountain[k]);

        //	signpost
        glBindTexture(GL_TEXTURE_2D, texture[5]);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, &SignpostVertex[0]);
        glNormalPointer(GL_FLOAT, 0, &SignpostNormals[0]);
        glTexCoordPointer(2, GL_FLOAT, 0, &SignpostTexCord[0]);
        glDrawArrays(GL_TRIANGLES, 0, kSignpostNumberOfVertices);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);

        //padestal
        if (pade.visible)DrawHouse(pade);

        //bezers of fire
        for (k = 0; k < bezers; k++)
            if (bez[k].visible)DrawHouse(bez[k]);

        //trees
        for (k = 0; k < trees; k++)
            if (tree[k].visible)DrawHouse(tree[k]);


        for (k = 0; k < FTrees; k++)
            if (FTree[k].visible)DrawHouse(FTree[k]);

        if (ship.visible)DrawHouse(ship);
        if (well.visible)DrawHouse(well);
        if (tavern.visible)DrawHouse(tavern);
    }
    glEndList();
}

void mouseWrap()
{
    int changed = 0;

    if (mouseX >= resX - 15) {
        mouseX = 20;
        ++changed;
    }

    if (mouseX <= 15) {
        mouseX = resX - 20;
        ++changed;
    }

    if (mouseY >= resY - 15) {
        mouseY = resY - 20;
        ++changed;
    }

    if (mouseY <= 15) {
        mouseY = 20;
        ++changed;
    }

    if (changed > 0) {
        glutWarpPointer(mouseX, mouseY);
    }
}

void dDungeon(int selection)
{
    GLfloat xtrans, ztrans;
    GLfloat sceneroty;

    //fps mouse warp
    mouseWrap();
    // calculate translations and rotations.
    xtrans = -xpos;
    ztrans = -zpos;

    sceneroty = 360.0f - yrot;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Clear The Screen And The Depth Buffer
    glLoadIdentity();

    glRotatef(lookupdown, 1.0f, 0, 0);
    glRotatef(sceneroty, 0, 1.0f, 0);

    glTranslatef(xtrans, ytrans + 0.2, ztrans);

    glColor4f(1.0, 1.0, 1.0, 0.98);

    if (!selection)glCallList(DungList0);//

    DrawMapItems();

    glBindTexture(GL_TEXTURE_2D, texture[17]);
    if (!selection)if (arrow.visible)DrawProj(arrow);
    if (!selection)UpdProj();

    glLoadName(1);

    int mobsai;

    for (mobsai = 0; mobsai < Dun0MobC; mobsai++) {
        if (Dun0Mobs[mobsai].alive) {
            glLoadName(3 + mobsai);
            DrawMon(Dun0Mobs[mobsai]);
        }
        if (ShowPassMap)ShowMoveDir(Dun0Mobs[mobsai], Dun0Mobs[mobsai].VX, Dun0Mobs[mobsai].VZ);
    }

    glLoadName(2);

//      if(ShowPassMap)DrawPassage();//debug
// 	   if(ShowPassMap)ShowMoveDir(anb[0],anb[0].VX, anb[0].VZ);
// 	   if(ShowPassMap)ShowMoveDir(spd[0],spd[0].VX, spd[0].VZ);

    if (!selection)Text();

    glutSwapBuffers();
}

void dLand1(int selection)
{

    mouseWrap();

    GLfloat xtrans, ztrans;
    GLfloat sceneroty;

    // calculate translations and rotations.
    xtrans = -xpos;
    ztrans = -9.6 - zpos;

    sceneroty = 360.0f - yrot;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Clear The Screen And The Depth Buffer
    glLoadIdentity();

    glRotatef(lookupdown, 1.0f, 0, 0);
    glRotatef(sceneroty, 0, 1.0f, 0);

    glTranslatef(xtrans, ytrans, ztrans);

    glColor4f(1.0, 1.0, 1.0, 0.98);

// 	   if(!selection)glCallList(DungList0);//
    if (!selection)glCallList(L1);

    glBindTexture(GL_TEXTURE_2D, texture[17]);
    if (!selection)if (arrow.visible)DrawProj(arrow);
    if (!selection)UpdProj();

    glLoadName(5);

    if (anb[0].alive) {
        glLoadName(1);
        DrawMon(anb[0]);
    }

    if (spd[0].alive) {
        glLoadName(2);
        DrawMon(spd[0]);
    }

    glLoadName(6);

    if (ShowPassMap)DrawPassage();//debug
    if (ShowPassMap)ShowMoveDir(anb[0], anb[0].VX, anb[0].VZ);
    if (ShowPassMap)ShowMoveDir(spd[0], spd[0].VX, spd[0].VZ);

    if (!selection)Text();

    glutSwapBuffers();
}
