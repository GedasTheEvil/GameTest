#include "player.h"

void SetPlayerVars()
{
	you[0].class = "Paladin";
	you[0].HP  = 50;
	you[0].HPM = 50;
	you[0].MP  = 10;
	you[0].MPM = 10;
	you[0].Str = you[0].StrM = 20;
	you[0].End = you[0].EndM = 20;
	you[0].Spd = you[0].SpdM = 8;
	you[0].Wsd = you[0].WsdM = 3;
	you[0].HPL = 40;
	you[0].MPL = 10;
	you[0].level = 1;
	you[0].XP = 0;
	you[0].sp = 0;
	you[0].dmg = 10;
	you[0].dmgB = 0;
	you[0].armor = 0;
	you[0].Gold = 50;
}

void checkLevel()
{
     if (you[0].XP >= ((you[0].level + 2)/2)* (you[0].level) * 1000)
     {
	  you[0].level++;
	  you[0].HPM += you[0].HPL;
	  you[0].MPM += you[0].MPL;
	  you[0].dmgB++;
	  you[0].sp += 1 + you[0].level/4;
     }
     you[0].dmg = 10 + (you[0].Str /3) + List[(int)LHand].Damage;
     you[0].armor = List[(int)RHand].Armor + List[(int)Helm].Armor + List[(int)Boots].Armor + List[(int)Armor].Armor;
     
}


