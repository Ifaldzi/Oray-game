#ifndef YORDY_W_H
#define YORDY_W_H

void push(int x,int y, char image[],int dir);
//Push
void pop();
//Pop atau hapus
void display();
//Menggambarkan Ular
void classic();
//Mode classic
void popAll();
//Pop All
bool CheckCollision(int x,int y);
//Check Collision
void spawnUlar(int x,int y,int snakeSize);

bool balikArah(int jamur);

void makanJamur(int *jamur,struct timeb lastTimeFood );

int baka(int jamur,struct timeb lastTimeFood);

void map(int level);

void adventure(int level);

bool CheckCollisionFood(Coordinat food, int x);

#endif
