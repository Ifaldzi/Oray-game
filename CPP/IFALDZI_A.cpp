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
	void *bk;
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

void gameOver(int prevGameState){
	int mouseX, mouseY;
	char *scoreText = (char *)malloc(sizeof(LENGTH_TEXT));
	setactivepage(1);
	sprintf(scoreText, "Your Score: %d", score);
	readimagefile("game_over.gif",0,0,MAX_WIDTH, MAX_HEIGHT);
	printFinalScore(score, 350, 410);
	setvisualpage(getactivepage());
	if(checkHighScore()){
		outtextxy(350,350,"In leaderboard");
		putHighScore();
	}
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
			if(mouseX >= 290 && mouseY >= 430 && mouseX <= 321 && mouseY <=459){
				gameState = MAIN_MENU;
				break;
			}
			else if(mouseX >= 483 && mouseY >= 434 && mouseX <= 511 && mouseY <=462){
				gameState = prevGameState;
				break;
			}
			printf("x:%d y:%d\n",mouseX, mouseY);
		}
	}
}

void printFinalScore(int tempScore, int x, int y){
	int endScore[10];
	char *scoreNumber = (char*)malloc(sizeof(LENGTH_TEXT));
	int count = 0;
	do{
		endScore[count] = tempScore % 10;
		tempScore /= 10;
		count++;
	}
	while(tempScore > 0);
	int i;
	count--;
	int position = x; // 350  410//
	for(i=count;i>=0;i--){
		sprintf(scoreNumber, "number\\number%d.gif",endScore[i]);
		readimagefile(scoreNumber, position, y, position+30, y+30);
		position += 30;
	}
}

bool checkHighScore(){
	sortScore();
	FILE *fp = fopen("High_Score.dat", "rb");
	int tempScore, position = 0;
	fread(&tempScore,sizeof(int),1,fp);
	if(feof(fp)){
		printf("%d", tempScore);
		tempScore = 0;
		return true;
	}
	else{
		while(! feof(fp) && position < 5){
			if(score > tempScore) return true;
			fread(&tempScore,sizeof(int),1,fp);
			position++;
		}
		if(position == 5) return false;
		else return true;
	}
}

void putHighScore(){
	sortScore();
	FILE *fp = fopen("High_Score.dat", "rb+");
	int position = 0, tempScore;
	fread(&tempScore, sizeof(int), 1, fp);
	while(! feof(fp) && position <5){
		position++;
		printf("%d\n",tempScore);
		fread(&tempScore, sizeof(int), 1, fp);
	}
	fseek(fp,sizeof(int)*position, SEEK_SET);
	fwrite(&score, sizeof(int),1,fp);
	fclose(fp);
}

void printLeaderBoard(){
	sortScore();
	FILE *fp = fopen("High_Score.dat", "rb");
	setactivepage(1);
	readimagefile("leaderboard.gif", 0, 0, MAX_WIDTH, MAX_HEIGHT);
	int tempScore;
	int x, y;
	x = 350;
	y = 200;
	fread(&tempScore, sizeof(int), 1, fp);
	while(! feof(fp)){
		printFinalScore(tempScore, x, y);
		printf("%d\n", tempScore);
		fread(&tempScore, sizeof(int), 1, fp);
		y+=50;
	}
	fclose(fp);
	setvisualpage(1);
	while(true){
		Coordinat mouse;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, mouse.x, mouse.y);
//			printf("x=%d, y=%d", mouse.x, mouse.y);
			if(mouse.x>=695 && mouse.y>=503 && mouse.x<=742 && mouse.y<=548){
				return;
			}
		}
	}
}

void removeItem(Coordinat itemCoordinate){
	int page = getactivepage();
	void *p;
	int area;
	setactivepage(3);
	area = imagesize(0,0,30,30);
	p = malloc(area);
	getimage(itemCoordinate.x, itemCoordinate.y, itemCoordinate.x+30, itemCoordinate.y+30, p);
	setactivepage(page);
	putimage(itemCoordinate.x, itemCoordinate.y, p, 0);
}

void sortScore(){
	FILE *fp = fopen("High_Score.dat","rb+");
	int tempScore1, tempScore2;
	int i=0;
	int j;
	fread(&tempScore1, sizeof(int), 1, fp);
	while(!feof(fp)){
		j=i+1;
		fseek(fp,j*sizeof(int),SEEK_SET);
		fread(&tempScore2, sizeof(int), 1, fp);
		while(!feof(fp)){
			if(tempScore2 > tempScore1){
				//swap//
				fseek(fp,i*sizeof(int),SEEK_SET);
				fwrite(&tempScore2,sizeof(int),1,fp);
				fseek(fp,j*sizeof(int),SEEK_SET);
				fwrite(&tempScore1,sizeof(int),1,fp);
				tempScore1 = tempScore2;
			}
			j++;
			fseek(fp,j*sizeof(int),SEEK_SET);
			fread(&tempScore2,sizeof(int),1,fp);
		}
		i++;
		fseek(fp,i*sizeof(int),SEEK_SET);
		fread(&tempScore1,sizeof(int),1,fp);
	}
	fclose(fp);
}

void gameCompleted(){
	readimagefile("win-game.gif",0,0,MAX_WIDTH, MAX_HEIGHT);
	Coordinat mouse;
	setvisualpage(getactivepage());
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, mouse.x, mouse.y);
			printf("%d %d\n", mouse.x, mouse.y);
			if(mouse.x>=499 && mouse.y>=345 && mouse.x<=553 && mouse.y <=398){
				stage = 1;
				score = 0;
				return;
			}
			else if(mouse.x>=647 && mouse.y>=475 && mouse.x<=695 && mouse.y<=520){
				gameState = MAIN_MENU;
				return;
			}
		}
	}
}
