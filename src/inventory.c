#include "inventory.h"

void drawRectangle(int w, int h)
{
    glBegin(GL_QUADS);
    glTexCoord2i(0, 1);
    glVertex2i(0, 0);
    glTexCoord2i(1, 1);
    glVertex2i(w, 0);
    glTexCoord2i(1, 0);
    glVertex2i(w, h);
    glTexCoord2i(0, 0);
    glVertex2i(0, h);
    glEnd();
}

void DrawItem(int ID, int x, int y)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Itm[ID].texID);
    glTranslatef(x, y, 0.1);
    drawRectangle(INVENTORY_GRID_ITEM_W, INVENTORY_GRID_ITEM_H);
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

void drawInventoryButton(int buttonIndex)
{
    glBindTexture(GL_TEXTURE_2D, Btn[buttonIndex].texID);
    drawRectangle(16, 5);
    glTranslated(19, 0, 0);
}

void DrawInventory()
{
    int yItem = 100 - INVENTORY_GRID_ITEM_H;
    int relX = (int) ((float) mouseX / (float) resX * 100);
    int relY = 100 - (int) ((float) mouseY / (float) resY * 100);

    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    glBindTexture(GL_TEXTURE_2D, Itm[0].texID);
    drawRectangle(100, 100);

    int kkk;
    int iii = 0;
    int jjj = 0;

    if (infoShow) {
        DrawItemInfo();
    }

    for (kkk = 0x00; kkk < 30; kkk++) {
        if (InvGrid[kkk])
            DrawItem(
                InvGrid[kkk],
                INVENTORY_GRID_START_X + INVENTORY_GRID_ITEM_W * iii,
                yItem - INVENTORY_GRID_START_Y - INVENTORY_GRID_ITEM_H * jjj
            );

        iii++;
        if (iii >= INVENTORY_GRID_ITEM_ROW_LENGTH) {
            iii = 0;
            jjj++;
        }
    }

    if (selectedItem) {
        DrawItem(selectedItem, relX + INVENTORY_GRID_ITEM_W, relY - INVENTORY_GRID_ITEM_H);
    }

    if (Helm)DrawItem(Helm, INVENTORY_SLOT_HELMET_X, yItem - INVENTORY_SLOT_HELMET_Y);
    if (Boots)DrawItem(Boots, INVENTORY_SLOT_BOOTS_X, yItem - INVENTORY_SLOT_BOOTS_Y);
    if (RHand)DrawItem(RHand, INVENTORY_SLOT_RIGHT_HAND_X, yItem - INVENTORY_SLOT_RIGHT_HAND_Y);
    if (LHand)DrawItem(LHand, INVENTORY_SLOT_LEFT_HAND_X, yItem - INVENTORY_SLOT_LEFT_HAND_Y);
    if (Armor)DrawItem(Armor, INVENTORY_SLOT_TORSO_X, yItem - INVENTORY_SLOT_TORSO_Y);

    //text goes here
    glPushMatrix();
    glTranslated(5, 8, 1);
    drawInventoryButton(BtnStats);
    drawInventoryButton(BtnSkill);
    drawInventoryButton(BtnInvent);
    drawInventoryButton(BtnQuest);
    drawInventoryButton(BtnLeave);
    glPopMatrix();


    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

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
        clickItem(button, &InvGrid[getItemGridPositionIndex(relX, relY)]);
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
            break;
        }
}
