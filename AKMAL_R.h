#ifndef AKMAL_R
#define AKMAL_R

Coordinat random(int x);
//random koordinat makanan
void spawnFood(Coordinat foodCoordinat);
//spawn makanan
void spawnGoldFood(Coordinat foodCoordinat);
//spawn makanan berpoin ganda
void spawnMisteryBox(Coordinat foodCoordinat);
//spawn mistery box
int misteryBoxRatio();
//memberikan presentase antara poison dan pemendekan.

#endif
