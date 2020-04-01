#include"../snake.h"

#define X_MAX 600
#define Y_MAX 600

Coordinat random(int x){
	
	Coordinat randomFood;
	srand((unsigned)time(NULL)+x);
	do{
		randomFood.x = (rand() % X_MAX);
		randomFood.y = (rand() % Y_MAX);
	} while(randomFood.x%30!=0 || randomFood.y%30!=0 || CheckCollision(randomFood.x, randomFood.y) || checkCollisionTembokFood(randomFood) || !CheckCollisionFood(randomFood,x));
	return randomFood;
	
}

void spawnFood(Coordinat foodCoordinat){
	
	readimagefile("makanan\\apel.gif",foodCoordinat.x,foodCoordinat.y,foodCoordinat.x+30,foodCoordinat.y+30);
	
}

void spawnGoldFood(Coordinat foodCoordinat){

	readimagefile("makanan\\apel_gold.gif",foodCoordinat.x,foodCoordinat.y,foodCoordinat.x+30,foodCoordinat.y+30);
	
}

void spawnMisteryBox(Coordinat foodCoordinat){
	
	readimagefile("makanan\\box.gif",foodCoordinat.x,foodCoordinat.y,foodCoordinat.x+30,foodCoordinat.y+30);
	
}

int misteryBoxRatio(){
	int presentase;
	srand(time(0));
	presentase = rand()%100+1;
	if(presentase>70){
		return PENDEK;
	}else{
		return POISON;
	}	
}

void transisi(){
	if(stage <5){
		readimagefile("stageclear.gif",0,0,630,600);
		stage++;
		setvisualpage(getactivepage());
		delay(5000);
		adventure(stage);
	}
	else{
		gameCompleted();
	}
}

void printMakananSisa(int map,int makanan){
	
	char foodText[10];
	if(map - makanan >= 10){
		sprintf(foodText, "%d",map-makanan);
	}
	else{
		sprintf(foodText,"0%d",map-makanan);
	}
	outtextxy(655,50,"Food Left:");	
	outtextxy(655, 70, foodText);
	
}

void printWaktuPoison(int time){
	
	char poisonText[10];
	sprintf(poisonText, "%d", 10-time);
	outtextxy(655,90,"Time:");	
	outtextxy(655, 110, poisonText);
	
}

