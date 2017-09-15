#include "inventory.h"

void DrawItem(int ID, int x, int y)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Itm[ID].texID);
    glTranslatef(x, y, 0.1);
    glBegin(GL_QUADS);// bg
    {
        glTexCoord2i(0, 1);
        glVertex2i(0, 0);    // Texture / Vertex Coord (Bottom Left)
        glTexCoord2i(1, 1);
        glVertex2i(64, 0);    // Texutre / Vertex Coord (Bottom Right)
        glTexCoord2i(1, 0);
        glVertex2i(64, 64);    // Texture / Vertex Coord (Top Right)
        glTexCoord2i(0, 0);
        glVertex2i(0, 64);    // Texture / Vertex Coord (Top Left)
    }
    glEnd();
    glPopMatrix();
}


void DrawItemInfo()
{
    if (infoItem == 0) {
        infoShow = 0;
        return;
    }
    infoShow--;

    glPushMatrix();
    glTranslatef(150, 250, 0.2);

    glBindTexture(GL_TEXTURE_2D, Btn[BtnInfBG].texID);
    glBegin(GL_QUADS);// bg
    {
        glTexCoord2i(0, 1);
        glVertex2i(0, 0);    // Texture / Vertex Coord (Bottom Left)
        glTexCoord2i(1, 1);
        glVertex2i(520, 0);    // Texutre / Vertex Coord (Bottom Right)
        glTexCoord2i(1, 0);
        glVertex2i(520, 300);    // Texture / Vertex Coord (Top Right)
        glTexCoord2i(0, 0);
        glVertex2i(0, 300);    // Texture / Vertex Coord (Top Left)
    }
    glEnd();
    DrawItem(infoItem, 20, 200);
    glPrint(350, 510, "%s", List[infoItem].Name);

    glPrint(250, 470, "%s", List[infoItem].L1);
    glPrint(250, 460, "%s", List[infoItem].L2);
    glPrint(250, 440, "%s", List[infoItem].L3);
    glPrint(250, 430, "%s", List[infoItem].L4);
    if (List[infoItem].Armor)glPrint(250, 420, "Armor: %d", List[infoItem].Armor);
    if (List[infoItem].Damage)glPrint(250, 410, "Damage: %d", List[infoItem].Damage);
    glPrint(250, 400, "Value: %d gold", List[infoItem].Value);
    glPopMatrix();
}

void DrawInventory()
{
    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        // Clear The Screen And The Depth Buffer
    glLoadIdentity();

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glMatrixMode(GL_PROJECTION);                    // Select The Projection Matrix
    glPushMatrix();                            // Store The Projection Matrix
    glLoadIdentity();                        // Reset The Projection Matrix
    glOrtho(0, 800, 0, 600, -1, 1);                    // Set Up An Ortho Screen
    glMatrixMode(GL_MODELVIEW);                    // Select The Modelview Matrix

    glBindTexture(GL_TEXTURE_2D, Itm[0].texID);

    glBegin(GL_QUADS);// bg
    {
        glTexCoord2i(0, 1);
        glVertex2i(0, 0);    // Texture / Vertex Coord (Bottom Left)
        glTexCoord2i(1, 1);
        glVertex2i(800, 0);    // Texutre / Vertex Coord (Bottom Right)
        glTexCoord2i(1, 0);
        glVertex2i(800, 600);    // Texture / Vertex Coord (Top Right)
        glTexCoord2i(0, 0);
        glVertex2i(0, 600);    // Texture / Vertex Coord (Top Left)
    }
    glEnd();

    // Main inventory
    int kkk;
    int iii = 0;
    int jjj = 0;

    if (infoShow)DrawItemInfo(infoItem);

    for (kkk = 0x00; kkk < 30; kkk++) {
        if (InvGrid[kkk])
            DrawItem(InvGrid[kkk], 40 + 78 * iii, 505 - 75 * jjj);

        iii++;
        if (iii >= 6) {
            iii = 0;
            jjj++;
        }
    }
    // !Main inventory

    if (selectedItem) {
        DrawItem(selectedItem, mouseX * ((float) resY / (float) resX) * 1.4, 500 - MouseY);
    }

    if (Helm)DrawItem(Helm, 625, 505);
    if (Boots)DrawItem(Boots, 625, 350);
    if (RHand)DrawItem(RHand, 700, 428);
    if (LHand)DrawItem(LHand, 545, 428);
    if (Armor)DrawItem(Armor, 625, 428);

    //text goes here
    glPushMatrix();
    glTranslated(30, 50, 1);
    glBindTexture(GL_TEXTURE_2D, Btn[BtnStats].texID);
    glBegin(GL_QUADS);
    {
        glTexCoord2i(0, 1);
        glVertex2i(0, 0);    // Texture / Vertex Coord (Bottom Left)
        glTexCoord2i(1, 1);
        glVertex2i(128, 0);    // Texutre / Vertex Coord (Bottom Right)
        glTexCoord2i(1, 0);
        glVertex2i(128, 32);    // Texture / Vertex Coord (Top Right)
        glTexCoord2i(0, 0);
        glVertex2i(0, 32);    // Texture / Vertex Coord (Top Left)
    }
    glEnd();

    glTranslated(150, 0, 0);
    glBindTexture(GL_TEXTURE_2D, Btn[BtnSkill].texID);
    glBegin(GL_QUADS);
    {
        glTexCoord2i(0, 1);
        glVertex2i(0, 0);    // Texture / Vertex Coord (Bottom Left)
        glTexCoord2i(1, 1);
        glVertex2i(128, 0);    // Texutre / Vertex Coord (Bottom Right)
        glTexCoord2i(1, 0);
        glVertex2i(128, 32);    // Texture / Vertex Coord (Top Right)
        glTexCoord2i(0, 0);
        glVertex2i(0, 32);    // Texture / Vertex Coord (Top Left)
    }
    glEnd();

    glTranslated(150, 0, 0);
    glBindTexture(GL_TEXTURE_2D, Btn[BtnInvent].texID);
    glBegin(GL_QUADS);
    {
        glTexCoord2i(0, 1);
        glVertex2i(0, 0);    // Texture / Vertex Coord (Bottom Left)
        glTexCoord2i(1, 1);
        glVertex2i(128, 0);    // Texutre / Vertex Coord (Bottom Right)
        glTexCoord2i(1, 0);
        glVertex2i(128, 32);    // Texture / Vertex Coord (Top Right)
        glTexCoord2i(0, 0);
        glVertex2i(0, 32);    // Texture / Vertex Coord (Top Left)
    }
    glEnd();

    glTranslated(150, 0, 0);
    glBindTexture(GL_TEXTURE_2D, Btn[BtnQuest].texID);
    glBegin(GL_QUADS);
    {
        glTexCoord2i(0, 1);
        glVertex2i(0, 0);    // Texture / Vertex Coord (Bottom Left)
        glTexCoord2i(1, 1);
        glVertex2i(128, 0);    // Texutre / Vertex Coord (Bottom Right)
        glTexCoord2i(1, 0);
        glVertex2i(128, 32);    // Texture / Vertex Coord (Top Right)
        glTexCoord2i(0, 0);
        glVertex2i(0, 32);    // Texture / Vertex Coord (Top Left)
    }
    glEnd();

    glTranslated(150, 0, 0);
    glBindTexture(GL_TEXTURE_2D, Btn[BtnLeave].texID);
    glBegin(GL_QUADS);
    {
        glTexCoord2i(0, 1);
        glVertex2i(0, 0);    // Texture / Vertex Coord (Bottom Left)
        glTexCoord2i(1, 1);
        glVertex2i(128, 0);    // Texutre / Vertex Coord (Bottom Right)
        glTexCoord2i(1, 0);
        glVertex2i(128, 32);    // Texture / Vertex Coord (Top Right)
        glTexCoord2i(0, 0);
        glVertex2i(0, 32);    // Texture / Vertex Coord (Top Left)
    }
    glEnd();

    glPopMatrix();


    glMatrixMode(GL_PROJECTION);                // Select The Projection Matrix
    glPopMatrix();                        // Restore The Old Projection Matrix
    glMatrixMode(GL_MODELVIEW);                // Select The Modelview Matrix




    glFlush();
    glDisable(GL_BLEND);
    glBlendFunc(GL_DST_COLOR, GL_ZERO);

    glutSwapBuffers();
    glEnable(GL_LIGHTING);
}

int getItemGridPositionIndex(int relX, int relY)
{
    int x = (relX - INVENTORY_GRID_START_X) / INVENTORY_GRID_ITEM_W;
    int y = (relY - INVENTORY_GRID_START_Y) / INVENTORY_GRID_ITEM_H;

    return INVENTORY_GRID_ITEM_ROW_LENGTH * y + x;
}

void clickItem(int button, int *clickedItem)
{
    int lastItem;

    if (button == RMB) {
        infoItem = *clickedItem;
        infoShow = 120;
    }

    if (button == LMB) {
        lastItem = selectedItem;
        selectedItem = *clickedItem;
        *clickedItem = lastItem;
        checkLevel();
    }
}

void TakeItem(int x, int y, int button)
{
    int relX = (int) ((float) x / (float) resX * 100);
    int relY = (int) ((float) y / (float) resY * 100);

    if (relX >= INVENTORY_GRID_START_X && relX <= INVENTORY_GRID_END_X &&
        relY >= INVENTORY_GRID_START_Y && relY <= INVENTORY_GRID_END_Y) {
        int hoverItemIndex = getItemGridPositionIndex(relX, relY);
        clickItem(button, &InvGrid[hoverItemIndex]);
    }

    if (relX >= INVENTORY_SLOT_HELMET_X && relX <= INVENTORY_SLOT_HELMET_X + INVENTORY_GRID_ITEM_W &&
        relY >= INVENTORY_SLOT_HELMET_Y && relY <= INVENTORY_SLOT_HELMET_Y + INVENTORY_GRID_ITEM_H) {
        clickItem(button, &Helm);
    }

    if (relX >= INVENTORY_SLOT_BOOTS_X && relX <= INVENTORY_SLOT_BOOTS_X + INVENTORY_GRID_ITEM_W &&
        relY >= INVENTORY_SLOT_BOOTS_Y && relY <= INVENTORY_SLOT_BOOTS_Y + INVENTORY_GRID_ITEM_H) {
        clickItem(button, &Boots);
    }

    if (relX >= INVENTORY_SLOT_LEFT_HAND_X && relX <= INVENTORY_SLOT_LEFT_HAND_X + INVENTORY_GRID_ITEM_W &&
        relY >= INVENTORY_SLOT_LEFT_HAND_Y && relY <= INVENTORY_SLOT_LEFT_HAND_Y + INVENTORY_GRID_ITEM_H) {
        clickItem(button, &LHand);
    }

    if (relX >= INVENTORY_SLOT_RIGHT_HAND_X && relX <= INVENTORY_SLOT_RIGHT_HAND_X + INVENTORY_GRID_ITEM_W &&
        relY >= INVENTORY_SLOT_RIGHT_HAND_Y && relY <= INVENTORY_SLOT_RIGHT_HAND_Y + INVENTORY_GRID_ITEM_H) {
        clickItem(button, &RHand);
    }

    if (relX >= INVENTORY_SLOT_TORSO_X && relX <= INVENTORY_SLOT_TORSO_X + INVENTORY_GRID_ITEM_W &&
        relY >= INVENTORY_SLOT_TORSO_Y && relY <= INVENTORY_SLOT_TORSO_Y + INVENTORY_GRID_ITEM_H) {
        clickItem(button, &Armor);
    }
}

void GetItem(int item)
{
    int put = 0;
    int i;
    for (i = 0; i < 30; i++)
        if (!InvGrid[i]) {
            InvGrid[i] = item;
            put = 1;
            break;
        }

    if (put) return;

    for (i = 0; i < 30; i++)
        if (item >= 128 && InvGrid[i] < 128)// we replace some item with quest item
        {
            InvGrid[i] = item;
            put = 1;
            break;
        }
}
