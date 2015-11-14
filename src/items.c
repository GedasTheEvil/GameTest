#include "items.h"

// 0x00 -- no item
// 0x01 -- 0x0f Weapons
// 0x10 -- 0x1f Armor
// 0x20 -- 0x2f Boots
// 0x30 -- 0x3f Cloaks
// 0x40 -- 0x4f Helmets
// 0x50 -- 0x5f Amulets
// 0x60 -- 0x6f Rings
// 0x70 -- 0x7f Shields
// 0x80 -- 0x9f Quest items

void InitItemList()
{
     List = (item *) malloc(sizeof(item)* 0x9f); 
     
     int i;
     for(i = 0; i < 0x9f; i++)
     {     
	   List[i].Armor = 0;
	   List[i].Damage = 0;
	   List[i].Value = 0;
	   strcpy(List[i].Name , "NULL item\0\n");
	   strcpy(List[i].L1   , "NULL item\0\n");
	   strcpy(List[i].L2   , "NULL item\0\n");
	   strcpy(List[i].L3   , "NULL item\0\n");
	   strcpy(List[i].L4   , "NULL item\0\n");
	   List[i].Atr[0] = 0x00;
	   List[i].AtrV = 0;
	   

     }
     
     
     strcpy(List[0x01].Name , "Crude Gun\0");
     strcpy(List[0x01].L1   , "The most common gun found. It is crude\0");
     strcpy(List[0x01].L2   , "and not made well. However its\0");
     strcpy(List[0x01].L3   , "the cheapest one so it is the first\0");
     strcpy(List[0x01].L4   , "choice for starting adventurers.\0");
     List[0x01].Armor = 0;
     List[0x01].Value = 50;
     List[0x01].Damage = 4;
     
     strcpy(List[0x10].Name , "Zvejo liemene\0");
     strcpy(List[0x10].L1   , "Puiki liemene zvejybai\0");
     strcpy(List[0x10].L2   , "Bet sarvai netike\0");
     strcpy(List[0x10].L3   , "\0");
     strcpy(List[0x10].L4   , "\0");
     List[0x10].Armor = 2;
     List[0x10].Value = 120;
     List[0x10].Damage = 0;
     
     strcpy(List[0x20].Name , "Zvejo Batai\0");
     strcpy(List[0x20].L1   , "Geri batai ...\0");
     strcpy(List[0x20].L2   , "Tiesiog batai\0");
     strcpy(List[0x20].L3   , "\0");
     strcpy(List[0x20].L4   , "\0");
     List[0x20].Armor = 1;
     List[0x20].Value = 25;
     List[0x20].Damage = 0;
     
     strcpy(List[0x40].Name , "Statybinis Salmas\n\0");
     strcpy(List[0x40].L1,    "Paimtas is statybu.\n\0");
     strcpy(List[0x40].L2, "Labiau saugo nuo pauksciu sh\n\0");
     strcpy(List[0x40].L3, "negu nuo zalos\n\0");
     strcpy(List[0x40].L4, "Bet pigus\n\0");
     List[0x40].Armor = 1;
     List[0x40].Value = 30;
     List[0x40].Damage = 0;
     
     strcpy(List[0x70].Name,"Wooden Shield\0");
     strcpy(List[0x70].L1, "Made from wood.\0");
     strcpy(List[0x70].L2, "Cheap, light, durable\0");
     strcpy(List[0x70].L3, "\0");
     strcpy(List[0x70].L4, "\0");
     List[0x70].Armor = 3;
     List[0x70].Value = 100;
     List[0x70].Damage = 0;
     
     strcpy(List[0x81].Name,"Beer Mug\0");
     strcpy(List[0x81].L1, "Quest item.\0");
     strcpy(List[0x81].L2, "\0");
     strcpy(List[0x81].L3, "\0");
     strcpy(List[0x81].L4, "\0");
     List[0x81].Armor  = 0;
     List[0x81].Value  = 0;
     List[0x81].Damage = 0;
     
     strcpy(List[0x82].Name,"World Map\0");
     strcpy(List[0x82].L1, "Quest item.\0");
     strcpy(List[0x82].L2, "\0");
     strcpy(List[0x82].L3, "\0");
     strcpy(List[0x82].L4, "\0");
     List[0x82].Armor  = 0;
     List[0x82].Value  = 0;
     List[0x82].Damage = 0;
     
}
