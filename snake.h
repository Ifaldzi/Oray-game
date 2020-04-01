#ifndef SNAKE_H
#define SNAKE_H

#include"graphics.h"
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
#include<time.h>

/*	Keadaan Ular	*/
#define KANAN 1
#define KIRI 2
#define ATAS 3
#define BAWAH 4

/* Window Game*/
#define MAX_WIDTH 	(800)
#define MAX_HEIGHT 	(600)
#define MAX_X	800
#define MAX_Y	600
#define CENTER_X 	((getmaxwidth()/2)-400)
#define CENTER_Y 	((getmaxheight()/2)-300)
#define LENGTH_TEXT 256

#define CLASSIC 0
#define LEVEL1 10
#define LEVEL2 12
#define LEVEL3 14
#define LEVEL4 16
#define LEVEL5 18

#define PENDEK 2
#define POISON 1

#define FOOD 1
#define GOLD 2
#define BOX 3

#define MAIN_MENU 0
#define CLASSIC_GAMEPLAY 1
#define ADVENTURE_GAMEPLAY 2
#define GAME_OVER 3

struct oray{
	int x, y, dir;
	char imageName[100];
	struct oray *next, *prev;
};

typedef struct{
	int x,y;	
}Tembok;


typedef struct {
	int x,y;
}Coordinat;

typedef struct tNode{
	Tembok Coordinat	;
	tNode *next;
}Node;

typedef struct tList{
	tNode *head, *tail;
}List;

extern Tembok Obstacle;

extern tNode *Head, *pNew,*prev;

extern struct oray *head, *tail;

extern int score, gameState, stage;

extern Coordinat foodCoordinat;

extern Coordinat goldCoordinat;

extern Coordinat misteryBoxCoordinat;

extern void *bk;

#include"Header\\Yordy_W.h"
#include"Header\\AKMAL_R.h"
#include"Header\\IFALDZI_A.h"
#include"Header\\GILANG_L.h"
#include"Header\\Athiyya.h"

#pragma GCC diagnostic ignored "-Wwrite-strings"

#endif
