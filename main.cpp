#include"snake.h"

struct oray *head = NULL, *tail = NULL;
int score, gameState, stage;

int main(){
	initwindow(MAX_WIDTH, MAX_HEIGHT, "Oray Game", CENTER_X, CENTER_Y);
	gameState = MAIN_MENU;
	while(true){
		resetPage();
		switch(gameState){
			case MAIN_MENU: mainMenu();
			break;
			case CLASSIC_GAMEPLAY: score = 0; classic();
			break;
			case ADVENTURE_GAMEPLAY: score = 0; adventure(stage);
			break;
			case GAME_OVER: gameOver();
		}
	}
	closegraph();
	printf("\n\n%d",score);
	return 0;
}

