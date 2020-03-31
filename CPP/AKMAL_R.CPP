#include"../snake.h"

#define X_MAX 600
#define Y_MAX 600

Coordinat random(int x){
	
	Coordinat randomFood;
	srand((unsigned)time(NULL)+x);
	do{
		randomFood.x = (rand() % X_MAX);
		randomFood.y = (rand() % Y_MAX);
	} while(randomFood.x%30!=0 || randomFood.y%30!=0 || CheckCollision(randomFood.x, randomFood.y) || checkCollisionTembokFood(randomFood));
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
	int level = 1;
	int makanan = 10;
	
	while(level <5){
		adventure(level);
		while (makanan>=1){
			if (!checkCollisionFood(foodCoordinat)){
				makanan--;
			}
		}
		if(makanan == 0){
			readimagefile("stageclear.jpg",0,0,0,0);
		}
		level++;
		makanan += 5;
	}
}
