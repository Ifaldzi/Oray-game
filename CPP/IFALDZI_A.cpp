#include"../snake.h"

void *bk;

bool checkCollisionFood(Coordinat foodCoordinat){
	if(head->x == foodCoordinat.x && head->y == foodCoordinat.y){
		return true;
	}
	return false;
}

bool checkCollisionTembokFood(Coordinat foodCoordinat){
	tNode *p = Head;
	while(p != NULL){
		if(foodCoordinat.x == p->Coordinat.x && foodCoordinat.y == p->Coordinat.y){
			return true;
		}
		p = p->next;
	}
	return false;
}

void printScore(){
	char scoreText[10];
	sprintf(scoreText, "%d", score);
	outtextxy(655,10,"SCORE");	
	outtextxy(655, 30, scoreText);
}

void renderUlar(){
	int page;
	page = getactivepage();
	setactivepage(3);
	void *bk2,*bk3;
	int x1,y1,x2,y2;
	x1 = tail->x;
	y1 = tail->y;
	x2 = tail->prev->x;
	y2 = tail->prev->y;
	int area = imagesize(x1,y1,x1+30,y1+30);
	bk = malloc(area);
	bk2 = malloc(area);
	bk3 = malloc(area);
	getimage(x1, y1, x1+30, y1+30, bk);
	getimage(x2, y2, x2+30, y2+30, bk2);
	getimage(head->x, head->y, head->x+30, head->y+30, bk3);
	setactivepage(page);
	putimage(x1,y1,bk,0);
	putimage(x2,y2,bk2,0);
	putimage(head->x,head->y,bk3,0);
}

void displayUlar(){
	readimagefile(head->imageName, head->x, head->y, head->x+30, head->y+30);
	readimagefile(head->next->imageName, head->next->x, head->next->y, head->next->x+30, head->next->y+30);
	readimagefile(tail->imageName, tail->x, tail->y, tail->x+30, tail->y+30);
	readimagefile(tail->prev->imageName, tail->prev->x, tail->prev->y, tail->prev->x+30, tail->prev->y+30);
}

void resetPage(){
	int i;
	for(i=1;i<=3;i++){
		setactivepage(i);
		cleardevice();
	}
}

void gameOver(){
	int mouseX, mouseY;
	char *scoreText = (char *)malloc(sizeof(LENGTH_TEXT));
	setactivepage(1);
	sprintf(scoreText, "Your Score: %d", score);
	readimagefile("game_over.gif",0,0,MAX_WIDTH, MAX_HEIGHT);
	printFinalScore();
	setvisualpage(getactivepage());
	if(checkHighScore()){
		outtextxy(350,350,"High score");
	}
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
			if(mouseX >= 290 && mouseY >= 430 && mouseX <= 321 && mouseY <=459){
				gameState = MAIN_MENU;
				break;
			}
			else if(mouseX >= 483 && mouseY >= 434 && mouseX <= 511 && mouseY <=462){
				gameState = CLASSIC_GAMEPLAY;
				break;
			}
			printf("x:%d y:%d\n",mouseX, mouseY);
		}
	}
}

void printFinalScore(){
	int endScore[10];
	char *scoreNumber = (char*)malloc(sizeof(LENGTH_TEXT));
	int count = 0, tempScore = score;
	do{
		endScore[count] = tempScore % 10;
		tempScore /= 10;
		count++;
	}
	while(tempScore != 0);
	int i = count;
	int position = 350;
	for(i=count;i>=0;i--){
		sprintf(scoreNumber, "number\\number%d.gif",endScore[i]);
		readimagefile(scoreNumber, position, 410, position+30, 440);
		position += 30;
	}
}

bool checkHighScore(){
	FILE *fp = fopen("High_Score.dat", "rb");
	int tempScore;
	fscanf(fp, "%d", &tempScore);
	if(feof(fp)){
		tempScore = 0;
	}
	else{
		while(! feof(fp)){
			if(score > tempScore) return true;
			fscanf(fp, "%d", &tempScore);
		}
		return false;
	}
}

void putHighScore(){
	
}
