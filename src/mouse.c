#include "mouse.h"

void processMouse(int button, int state, int x, int y)
{
    if (state == GLUT_UP) {
        if (display >= DUNG1)
            switch (button) {
                case wheel_up:
                    if (ghost)ytrans = ytrans + 0.2;
                    break;
                case wheel_down:
                    if (ghost)ytrans = ytrans - 0.2;
                    break;
                case LMB://LMB
                    if (!ShotDelay) {
                        SetProj();
                        if (sound)Mix_PlayChannel(-1, Shot, 0);
                    }
                    break;
                case RMB://RMB
                    if (display == LAND1)L1ProcEvent();
                    else if (display == InventMENU)TakeItem(x, y, button);
                    else if (display == DUNG1)D1ProcEvent();
                    break;
                case MMB:
                    printf("Anubis state:%d   Spider state: %d\n", anb[0].status, spd[0].status);
                    printf("Anubis x:%f , z%f ... VX %f, VZ %f   \n", anb[0].pos[0].x, anb[0].pos[0].z, anb[0].Verts[0],
                           anb[0].Verts[2]);
                    break;

                default:
                    printf("button %x pressed. No action yet\n", button);
            }
        else if (display == HouseInside) {
            if (x > (int) ((float) resX / 1.212) && x < (int) ((float) resX / 1.017)//leave
                && y > (int) ((float) resY / 1.071) && y < (int) ((float) resY / 1.017)) {
                display = LastMap;
                HAtimer = 0;
            }

            if (x > (int) (resX * 0.69531) && x < (int) (resX * 0.995) &&
                y > (int) (resY * 0.372) && y < (int) (resY * 0.417))
                BAction(1);

            if (x > (int) (resX * 0.69531) && x < (int) (resX * 0.995) &&
                y > (int) (resY * 0.421) && y < (int) (resY * 0.463))
                BAction(2);

            if (x > (int) (resX * 0.69531) && x < (int) (resX * 0.995) &&
                y > (int) (resY * 0.474) && y < (int) (resY * 0.522))
                BAction(3);
        } else if (display == MainMENU) {


            if (x > (int) (resX * 0.422) && x < (int) (resX * 0.58) &&
                y > (int) (resY * 0.285) && y < (int) (resY * 0.33)) {
                display = LOADING;
                LoadAll();/*display = 1;*/}


            if (x > (int) (resX * 0.420) && x < (int) (resX * 0.58) &&
                y > (int) (resY * 0.456) && y < (int) (resY * 0.503))
                display = ConfMENU;

            if (x > (int) (resX * 0.420) && x < (int) (resX * 0.58) &&
                y > (int) (resY * 0.542) && y < (int) (resY * 0.603))
                display = CreditMENU;

            if (x > (int) (resX * 0.420) && x < (int) (resX * 0.58) &&
                y > (int) (resY * 0.628) && y < (int) (resY * 0.681))
                Exit(0);
        } else if (display == GameMENU) {


            if (x > (int) (resX * 0.422) && x < (int) (resX * 0.58) &&
                y > (int) (resY * 0.285) && y < (int) (resY * 0.33)) { display = LastMap; }


            if (x > (int) (resX * 0.420) && x < (int) (resX * 0.58) &&
                y > (int) (resY * 0.456) && y < (int) (resY * 0.503))
                display = ConfMENU;

            if (x > (int) (resX * 0.420) && x < (int) (resX * 0.58) &&
                y > (int) (resY * 0.542) && y < (int) (resY * 0.603))
                display = CreditMENU;

            if (x > (int) (resX * 0.420) && x < (int) (resX * 0.58) &&
                y > (int) (resY * 0.628) && y < (int) (resY * 0.681)) {
                Exit(666);
                display = MainMENU;
            }
        } else if (display == ConfMENU) {
            if (x > (int) (resX * 0.22) && x < (int) (resX * 0.26) &&
                y > (int) (resY * 0.445) && y < (int) (resY * 0.498))
                texres = 1;

            if (x > (int) (resX * 0.22) && x < (int) (resX * 0.26) &&
                y > (int) (resY * 0.385) && y < (int) (resY * 0.434))
                texres = 0;


            if (x > (int) (resX * 0.186) && x < (int) (resX * 0.226) &&
                y > (int) (resY * 0.116) && y < (int) (resY * 0.166))
                music = !music;

            if (x > (int) (resX * 0.186) && x < (int) (resX * 0.226) &&
                y > (int) (resY * 0.216) && y < (int) (resY * 0.266))
                sound = !sound;

            if (x > (int) (resX * 0.675) && x < (int) (resX * 0.714) &&
                y > (int) (resY * 0.266) && y < (int) (resY * 0.318))
                fs = !fs;

            if (x > (int) (resX * 0.613) && x < (int) (resX * 0.771) &&
                y > (int) (resY * 0.916) && y < (int) (resY * 0.966)) {
                PutConf();
                system("./rr.sh");
            }

            if (x > (int) (resX * 0.788) && x < (int) (resX * 0.946) &&
                y > (int) (resY * 0.916) && y < (int) (resY * 0.966))
                display = MainMENU;

        } else if (display == SaveMENU) {
            inputSw = !inputSw;
        } else if (display == InventMENU) {
            if (!infoShow)
                TakeItem(x, y, button);
            else infoShow = 0;
        } else if (display == QuestMENU) {
            if (!infoQShow)
                SelectQuest(x, y, button);
            else infoQShow = 0;

        }

        if (display == InventMENU || display == SkillMENU || display == QuestMENU || display == StatMENU) {
            if (y > (int) (resY * 0.862) && y < (int) (resY * 0.913)) {
                if (x > (int) (resX * 0.037) && x < (int) (resX * 0.197))display = StatMENU;
                if (x > (int) (resX * 0.225) && x < (int) (resX * 0.386))display = SkillMENU;
                if (x > (int) (resX * 0.412) && x < (int) (resX * 0.570))display = InventMENU;
                if (x > (int) (resX * 0.6) && x < (int) (resX * 0.759))display = QuestMENU;
                if (x > (int) (resX * 0.786) && x < (int) (resX * 0.946))display = LastMap;
            }
        }


        if (display == QuestMENU) {
            printf("%f  %f\n%d/%d  %d/%d\n\n", (float) x / (float) resX, (float) y / (float) resY, resX, x, resY, y);
        }
    }
}

void processMouseActiveMotion(int x, int y)
{

}

float getMouseDegree(int position, int resolution, float maxDegree)
{
    float relPos = (float)position / (float)resolution;

    return maxDegree * relPos;
}

void processMousePassiveMotion(int x, int y)
{
    if (display >= DUNG1) {
        yrot = getMouseDegree(x, resX, -360.0f);
        dx = x;
        lookupdown += (y - dy) * 0.1;
        dy = y;
        if (lookupdown > 60)lookupdown = 60;
        if (lookupdown < -60)lookupdown = -60;
    }

    if (display == HouseInside) {
        if (x > (int) (resX * 0.69531) && x < (int) (resX * 0.995) &&
            y > (int) (resY * 0.372) && y < (int) (resY * 0.417))
            BA1H = 1;
        else BA1H = 0;

        if (x > (int) (resX * 0.69531) && x < (int) (resX * 0.995) &&
            y > (int) (resY * 0.421) && y < (int) (resY * 0.463))
            BA2H = 1;
        else BA2H = 0;

        if (x > (int) (resX * 0.69531) && x < (int) (resX * 0.995) &&
            y > (int) (resY * 0.474) && y < (int) (resY * 0.522))
            BA3H = 1;
        else BA3H = 0;


    }

    if (display == InventMENU || display >= DUNG1) {
        mouseX = x;
        mouseY = y;
    }

}

void processMouseEntry(int state)
{

}
