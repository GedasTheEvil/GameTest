#include "keyboard.h"

unsigned int oldDisplayMode = 0;

void changeDisplay(unsigned int newMode) {
    oldDisplayMode = display;
    display = newMode;
}

void restorePreviousDisplayMode()
{
    display = oldDisplayMode;
}

void toggleDisplay(unsigned int newMode)
{
    if (display == newMode) {
        restorePreviousDisplayMode();
    } else {
        changeDisplay(newMode);
    }
}

/* The function called whenever a normal key is pressed. */
void keyPressed(unsigned char key, int x, int y)
{
    /* avoid thrashing this procedure */
    usleep(100);
    if (!inputSw)
        switch (key) {
            case ESCAPE:
                toggleDisplay(GameMENU);
                break;

            case 'w' :
            case 'W':
                if (!ghost && display == LAND1) {
                    if (Land1pm(-(float) sin(yrot * DegRad) * 0.05f, -(float) cos(yrot * DegRad) * 0.05f, 0)) {
                        xpos -= (float) sin(yrot * DegRad) * 0.05f;
                        zpos -= (float) cos(yrot * DegRad) * 0.05f;
                    }
                } else if (!ghost && display == DUNG1) {
                    if (DungeonPM(0, (-(float) sin(yrot * DegRad) * 0.18f), (-(float) cos(yrot * DegRad) * 0.18f),
                                  Passmap0)) {
                        xpos -= (float) sin(yrot * DegRad) * 0.05f;
                        zpos -= (float) cos(yrot * DegRad) * 0.05f;
                    }
                } else {
                    xpos -= (float) sin(yrot * DegRad) * 0.05f;
                    zpos -= (float) cos(yrot * DegRad) * 0.05f;
                }
                break;

            case 'p':
                ShowPassMap = !ShowPassMap;
                break;


            case 'g':
                if (!ghost)ghost = 1;
                else ghost = 0;
                break;

            case 's' :
            case 'S':
                if (!ghost && display == LAND1) {
                    if (Land1pm((float) sin(yrot * DegRad) * 0.03f, (float) cos(yrot * DegRad) * 0.03f, 0)) {
                        xpos += (float) sin(yrot * DegRad) * 0.03f;
                        zpos += (float) cos(yrot * DegRad) * 0.03f;
                    }
                } else if (!ghost && display == DUNG1) {
                    if (DungeonPM(0, (float) sin(yrot * DegRad) * 0.13f, (float) cos(yrot * DegRad) * 0.13f,
                                  Passmap0)) {
                        xpos += (float) sin(yrot * DegRad) * 0.03f;
                        zpos += (float) cos(yrot * DegRad) * 0.03f;
                    }
                } else {
                    xpos += (float) sin(yrot * DegRad) * 0.05f;
                    zpos += (float) cos(yrot * DegRad) * 0.05f;
                }
                break;

            case 'a':
            case 'A':
                if (!ghost && display == LAND1) {
                    if (Land1pm((float) sin((yrot - 90) * DegRad) * 0.05f, (float) cos((yrot - 90) * DegRad) * 0.05f,
                                0)) {
                        xpos += (float) sin((yrot - 90) * DegRad) * 0.05f;
                        zpos += (float) cos((yrot - 90) * DegRad) * 0.05f;
                    }
                } else if (!ghost && display == DUNG1) {
                    if (DungeonPM(0, (float) sin((yrot - 90) * DegRad) * 0.15f,
                                  (float) cos((yrot - 90) * DegRad) * 0.15f, Passmap0)) {
                        xpos += (float) sin((yrot - 90) * DegRad) * 0.05f;
                        zpos += (float) cos((yrot - 90) * DegRad) * 0.05f;
                    }
                } else {
                    xpos += (float) sin((yrot - 90) * DegRad) * 0.05f;
                    zpos += (float) cos((yrot - 90) * DegRad) * 0.05f;
                }
                break;

            case 'c':
                printf("%f -- %f\n", xpos, zpos);
                break;

            case 'd' :
            case 'D':

                if (!ghost && display == LAND1) {
                    if (Land1pm((float) sin((yrot + 90) * DegRad) * 0.04f, (float) cos((yrot + 90) * DegRad) * 0.04f,
                                0)) {
                        xpos += (float) sin((yrot + 90) * DegRad) * 0.04f;
                        zpos += (float) cos((yrot + 90) * DegRad) * 0.04f;
                    }
                } else if (!ghost && display == DUNG1) {
                    if (DungeonPM(0, (float) sin((yrot + 90) * DegRad) * 0.14f,
                                  (float) cos((yrot + 90) * DegRad) * 0.14f, Passmap0)) {
                        xpos += (float) sin((yrot + 90) * DegRad) * 0.04f;
                        zpos += (float) cos((yrot + 90) * DegRad) * 0.04f;
                    }
                } else {
                    xpos += (float) sin((yrot + 90) * DegRad) * 0.04f;
                    zpos += (float) cos((yrot + 90) * DegRad) * 0.04f;
                }

                break;

            case 'i':
                toggleDisplay(InventMENU);
                break;

            case 'u':
                xpos = 2.3;
                zpos = -14.5;
                printf("Got stuck. Teleporting ...\n");
                break;

            default:
                printf("Key %d pressed. No action there yet.\n", key);
                break;
        }
    else {
        if (key == 0x08) {
            tl--;
            TextKey[tl] = 0x00;
        } else {
            TextKey[tl] = key;
            tl++;
        }
    }
}

/* The function called whenever a normal key is pressed. */
void specialKeyPressed(int key, int x, int y)
{
    /* avoid thrashing this procedure */
    usleep(100);

    switch (key) {
        case GLUT_KEY_PAGE_UP: // tilt up
            z -= 0.2f;
            lookupdown -= 0.2f;
            break;

        case GLUT_KEY_PAGE_DOWN: // tilt down
            z += 0.2f;
            lookupdown += 1.0f;
            break;

        case GLUT_KEY_UP: // walk forward (bob head)
            xpos -= (float) sin(yrot * DegRad) * 0.05f;
            zpos -= (float) cos(yrot * DegRad) * 0.05f;
            if (walkAngle >= 359.0f)
                walkAngle = 0.0f;
            else
                walkAngle += 10;
            break;

        case GLUT_KEY_DOWN: // walk back (bob head)
            xpos += (float) sin(yrot * DegRad) * 0.05f;
            zpos += (float) cos(yrot * DegRad) * 0.05f;
            if (walkAngle <= 1.0f)
                walkAngle = 359.0f;
            else
                walkAngle -= 10;
            break;

        case GLUT_KEY_LEFT: // look left
            yrot += 1.5f;
            break;

        case GLUT_KEY_RIGHT: // look right
            yrot -= 1.5f;
            break;

// 	case 

        default:
            printf("Special key %d pressed. .\n", key);
            if (display >= DUNG1)LastMap = display;
            display = key;
            break;
    }
}

