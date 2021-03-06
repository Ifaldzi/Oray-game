#include "../snake.h"

Coordinat foodCoordinat;
Coordinat goldCoordinat;
Coordinat misteryBoxCoordinat;


void push(int x, int y, char image[],int dir){
	struct oray *node = (struct oray*)malloc(sizeof(oray));
	node->prev = NULL;
	node->next = NULL;
	node->x = x;
	node->y = y;
	node->dir = dir;
	strcpy(node->imageName, image);
	
	if(head == NULL){
		head = tail = node;
	}
	else{
		strcpy(node->imageName, head->imageName);
		strcpy(head->imageName, image);
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pop(){
	if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		strcpy(tail->prev->imageName, tail->imageName);
		tail = tail->prev;
		free(tail->next);
		tail->next = NULL;
	}
}
void popAll(){
	while (head != NULL){
		pop();
	}
}

void display(){
	struct oray *node = head;
	while(node != NULL){
		readimagefile(node->imageName,node->x,node->y,node->x+30,node->y+30);
		node = node->next;
	}
}

bool CheckCollision(int x,int y){
	struct oray *p=head;
	while (p != NULL){
		if (p->x == x && p->y == y ){
			return true;	
		}
		p = p->next;
	}
	return false;
	
}

bool CheckCollisionFood(Coordinat food, int x){
	if(x == 1){
		if(((food.x != goldCoordinat.x)&&(food.x != misteryBoxCoordinat.x) )&&(food.y != goldCoordinat.y != misteryBoxCoordinat.y)){
		printf("apa SADASDASDASya");	
		return true;
		}
	}
	else if(x == 2){
		if((food.x != foodCoordinat.x != misteryBoxCoordinat.x)&&(food.y != foodCoordinat.y != misteryBoxCoordinat.y)){
		printf("apa ysadADASDa");	
		return true;
		}
	}else{
		if((food.x != foodCoordinat.x != goldCoordinat.x)&&(food.y != foodCoordinat.y != goldCoordinat.y)){
		printf("apa yDASDASDSADASa");
		return true;	
		}
	}
	return false;
} 



void spawnUlar(int x,int y,int snakeSize){
	int i;
	for(i=0;i<snakeSize;i++){
		push(i+x,y,"ular\\body2.gif",KANAN);
	}
}

bool balikArah(int jamur){
	if(jamur == 1){
		return true;
	}
	else{
		return false;
	}
}


int timer(int interval,int x){
	int waktu = x;
	if(interval >= waktu || interval == -1 ){
		return 0;	
	}else{
		return 1;
	}
}

	

int baka(int jamur,struct timeb lastTimeFood){
	if(jamur == 1){
		struct timeb currentTimeFood;
		ftime(&currentTimeFood);
		int interval = (currentTimeFood.time - lastTimeFood.time);
//		printf("Time is A %d\n",interval);
		return interval;
	}else if (jamur == 0 || jamur == 2){
		return -1;
	}
}

//Modul map bisa pindah ke gilang

void map1(int level){
	if(level == CLASSIC){
		backgroundClassic();
		border();
	}
	else if(level == LEVEL1){
		backgroundClassic();
		obstacleStage1();
	}else if(level == LEVEL2){
		backgroundClassic();
		obstacleStage2();
	}
	else if(level == LEVEL3){
		backgroundClassic();
		obstacleStage3();
	}
	else if(level == LEVEL4){
		backgroundClassic();
		obstacleStage4();
	}
	else if(level == LEVEL5){
		backgroundClassic();
		obstacleStage5();
	}
}




void ular(int kecepatan,int map){
	int area;
	void *p, *background;;
	char image[100];
	int x=30, y=30;
	int dir = VK_RIGHT;
	int arahOray = KANAN;
	int snakeSize = 5;
	int status = 0;
	int interval = -1;
	int waktu = 0;
	int gold = 0;
	int box = 0;
	int makanan = 0;
	int timeGold = randomwaktu(waktu);
	int timeBox = randomwaktu(waktu);
	struct timeb lastTimeFood;
	struct timeb now;
	struct timeb lastTimeGold;
	struct timeb lastTimeBox;
	head = NULL;
	cleardevice();
	setactivepage(3);
	map1(map);
	setactivepage(1);
	setvisualpage(1);
	map1(map);
	area = imagesize(0,0,800,600);
	p = malloc(area);
	background = malloc(area);
	foodCoordinat = random(FOOD);
	spawnFood(foodCoordinat);
	getimage(0,0,800,600,p);
//	push(0,0,"ular\\head_kanan.gif",KANAN);// Ieu naon sih gunana
	spawnUlar(x,y,snakeSize);
	push(x,y,"ular\\tail1.gif",KANAN);//Apa lagi ini :u
	printScore();
	display();
	setactivepage(2);
	display();
	ftime(&now);
	for(;;){
		putimage(0,0,p,0);
		printScore();
		renderUlar();
		switch(dir){
			case VK_LEFT:
				x = head->x - 30;
				y = head->y;
				arahOray = KIRI;
				strcpy(image, "ular\\body2.gif");
				sprintf(head->imageName,"ular\\head%d.gif",arahOray);
				break;
			case VK_RIGHT:
				x = head->x + 30;
				y = head->y;
				arahOray = KANAN;
				strcpy(image, "ular\\body2.gif");
				sprintf(head->imageName,"ular\\head%d.gif",arahOray);
				break;
			case VK_UP:
				x = head->x;
				y = head->y - 30;
				arahOray = ATAS;
				strcpy(image, "ular\\body.gif");
				strcpy(head->imageName, "ular\\head3.gif");
				break;
			case VK_DOWN:
				x = head->x;
				y = head->y + 30;
				arahOray = BAWAH;
				strcpy(image, "ular\\body.gif");
				strcpy(head->imageName, "ular\\head4.gif");
				break;
		}
		sprintf(tail->imageName,"ular\\tail%d.gif",tail->prev->prev->dir);
		if(GetKeyState(VK_LEFT) < 0 && dir != VK_RIGHT  ) {
			if(dir == VK_UP){
				if(balikArah(status)){
					strcpy(image, "ular\\turn4.gif");
					x = head->x + 30;
					y = head->y;
					arahOray = KANAN;
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_RIGHT;
				}else{
					sprintf(image,"ular\\turn1.gif");
					y = head->y;
					x = head->x - 30;
					arahOray = KIRI;
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_LEFT;	
				}
			}
			else if(dir == VK_DOWN){
				if(balikArah(status)){
					x = head->x + 30;
					y = head->y;
					arahOray = KANAN;
					strcpy(image, "ular\\turn3.gif");
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_RIGHT;
				}else{
					sprintf(image,"ular\\turn2.gif");
					y = head->y;
					x = head->x - 30;
					arahOray = KIRI;
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_LEFT;	
				}
			}
		}
		else if(GetKeyState(VK_RIGHT) < 0 && dir != VK_LEFT){
			if(dir == VK_DOWN){
				if(balikArah(status)){
					sprintf(image,"ular\\turn2.gif");
					y = head->y;
					x = head->x - 30;
					arahOray = KIRI;
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_LEFT;	
				}else{
					x = head->x + 30;
					y = head->y;
					arahOray = KANAN;
					strcpy(image, "ular\\turn3.gif");
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_RIGHT;
				}
			}
			else if(dir == VK_UP){
				if(balikArah(status)){
					sprintf(image,"ular\\turn1.gif");
					y = head->y;
					x = head->x - 30;
					arahOray = KIRI;
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_LEFT;	
				}else{
					strcpy(image, "ular\\turn4.gif");
					x = head->x + 30;
					y = head->y;
					arahOray = KANAN;
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_RIGHT;
					
				}
			}
			
		} 
		else if(GetKeyState(VK_UP) < 0 && dir != VK_DOWN){
			if(dir == VK_RIGHT){
				if(balikArah(status)){
					x = head->x;
					y = head->y + 30;
					arahOray = BAWAH;
					strcpy(image, "ular\\turn1.gif");
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_DOWN;
				}else{
					x = head->x;
					y = head->y - 30;
					arahOray = ATAS;
					strcpy(image, "ular\\turn2.gif");
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_UP;
				}
			}
			else if(dir == VK_LEFT){
				if(balikArah(status)){	
					x = head->x;
					y = head->y + 30;
					arahOray = BAWAH;
					strcpy(image, "ular\\turn4.gif");
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_DOWN;
				}else{
					x = head->x;
					y = head->y - 30;
					arahOray = ATAS;
					strcpy(image, "ular\\turn3.gif");
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_UP;
				}	
			}
		} 
		else if(GetKeyState(VK_DOWN) < 0 && dir != VK_UP){
			if(dir == VK_RIGHT){
				if(balikArah(status)){
					x = head->x;
					y = head->y - 30;
					arahOray = ATAS;
					strcpy(image, "ular\\turn2.gif");
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_UP;
				}else{
					x = head->x;
					y = head->y + 30;
					arahOray = BAWAH;
					strcpy(image, "ular\\turn1.gif");
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_DOWN;
				}
			}
			else if(dir == VK_LEFT){
				if(balikArah(status)){	
					x = head->x;
					y = head->y - 30;
					arahOray = ATAS;
					strcpy(image, "ular\\turn3.gif");
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_UP;
				}else{
					x = head->x;
					y = head->y + 30;
					arahOray = BAWAH;
					strcpy(image, "ular\\turn4.gif");
					sprintf(head->imageName,"ular\\head%d.gif",arahOray);
					dir = VK_DOWN;
				}
			}
		}
		if (CheckCollision(x,y)||collisionTembok()){
				getch();
				interval = 0;
				popAll();
				break;
		}
		if(map != CLASSIC){
			printMakananSisa(map, makanan);
			if(waktu == timeBox && box != 1){
				ftime(&lastTimeBox);
				misteryBoxCoordinat = random(BOX);
				spawnMisteryBox(misteryBoxCoordinat);
				box = 1;
			}else if( box == 0){ 
				removeItem(misteryBoxCoordinat);
				misteryBoxCoordinat.x = 0;
				misteryBoxCoordinat.y = 0;
				if(timeBox < waktu){
					timeBox = randomwaktu(waktu);
				}
			}
			if(makanan == map){
				//Transisi di sini
				transisi();
				break;
			}	
			interval = baka(status,lastTimeFood); 
			printf("interval %d\n",interval);
			status = timer(interval,10);
		}
		if(waktu == timeGold && gold != 1){
				ftime(&lastTimeGold);
				goldCoordinat = random(GOLD);
				spawnGoldFood(goldCoordinat);
				gold = 1;
			}else if (gold == 0){
				removeItem(goldCoordinat);
				goldCoordinat.x = 0;
				goldCoordinat.y = 0;
				if(timeGold < waktu){
				timeGold = randomwaktu(waktu);
				}
			}
			if(gold == 1){
				gold = timer(baka(gold,lastTimeGold),5);
				
			}else if (box == 1){
				box = timer(baka(box,lastTimeBox),5);
			}
		push(x,y,image,arahOray);
		if(!checkCollisionFood(foodCoordinat)&&!checkCollisionFood(goldCoordinat)&&!checkCollisionFood(misteryBoxCoordinat)){
			pop();
		}
		else if(checkCollisionFood(goldCoordinat)){
			score+=50;
			gold = 0;
			timeGold = randomwaktu(waktu);
		}
		else if(checkCollisionFood(misteryBoxCoordinat)){
			status = misteryBoxRatio();
			if(status == 2){
				pop();
				pop();
			}else if(status == 1){
				ftime(&lastTimeFood);
			}
			timeBox = randomwaktu(waktu);
		}
		else{
			foodCoordinat = random(FOOD);
			spawnFood(foodCoordinat);
			score+=7;
			makanan++;
		}
		if(status == 1){
			printWaktuPoison(interval);
		}
		waktu = baka(1,now);
//		printf("%d\n",waktu);
		displayUlar();
		getimage(0,0, 800, 600, p);
		delay(kecepatan);
		swapbuffers();
	}
}

void classic(){
	ular(50,CLASSIC);
	getch();
	popAll();
//	gameState = GAME_OVER;
	gameOver(gameState);
}

void adventure(int level){
	if(level == 1){
		ular(snakeSpeed,LEVEL1);
	}
	else if(level == 2){
		ular(snakeSpeed,LEVEL2);
	}
	else if(level == 3){
		ular(snakeSpeed,LEVEL3);
	}
	else if(level == 4){
		ular(snakeSpeed,LEVEL4);
	}
	else if(level == 5){
		ular(snakeSpeed,LEVEL5);
	}
//	gameState = GAME_OVER;
	gameOver(gameState);
}

int randomwaktu(int waktu){
	int lower = waktu+10;
	int upper = waktu+25;
	int acak = (rand() %  (upper - lower + 1)) + lower;
	srand(time(0));
	return acak;
}

