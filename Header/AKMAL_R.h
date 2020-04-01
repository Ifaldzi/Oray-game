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
void transisi();
//transisi tiap level pada mode adventure.
void printMakananSisa(int map,int makanan);
//menuliskan maknan sisa pada layar
void printWaktuPoison(int time);
//menuliskan waktu jika terkena poison

#endif
