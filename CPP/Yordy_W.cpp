#include "../snake.h"

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


int timer(int interval){
	int waktu = 10000;
	if(interval >= waktu || interval == 0){
		return 0;	
	}else{
		return 1;
	}
}

	

int baka(int jamur,struct timeb lastTimeFood){
	if(jamur == 1){
		struct timeb currentTimeFood;
		ftime(&currentTimeFood);
		int interval = 1000 * (currentTimeFood.time - lastTimeFood.time) + (currentTimeFood.millitm - lastTimeFood.millitm);
		printf("Time is A %d\n",interval);
		return interval;
	}else{
		return 0;
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
	int dir = VK_RIGHT, prevDir;
	int arahOray = KANAN;
	int snakeSize = 5;
	int snakeSpeed = 100;
	int status = 1;
	int interval1 = 0;
	struct timeb lastTimeFood;
	Coordinat foodCoordinat;
	head = NULL;
	cleardevice();
	setactivepage(3);
	map1(map);
	setactivepage(1);
	setvisualpage(1);
	map1(map);
	area = imagesize(0,0,800,600);
	p = malloc(area);
//	food(map,)
	Coordinat goldCoordinat,misteryBoxCoordinat;
	background = malloc(area);
	if(map != CLASSIC){
		goldCoordinat = random();
		misteryBoxCoordinat = random();
	}
	foodCoordinat = random();
	spawnFood(random());
	getimage(0,0,630,600,p);
	push(0,0,"ular\\head_kanan.gif",KANAN);
	spawnUlar(x,y,snakeSize);
	push(x,y,"ular\\tail1.gif",KANAN);
	printScore();
	display();
	setactivepage(2);
	display();
	for(;;){
		printf("jamur is %d\n",status);
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
				interval1 = 0;
				popAll();
				break;
		}			
		push(x,y,image,arahOray);
		if(!checkCollisionFood(foodCoordinat)){
			pop();
		}
		else{
//			status = 1;
			ftime(&lastTimeFood);
			foodCoordinat = random();
			goldCoordinat = random();
			spawnFood(foodCoordinat);
			spawnGoldFood(goldCoordinat);
			score+=7;
		}
		interval1 = baka(status,lastTimeFood); 
		status = timer(interval1);
		displayUlar();
		getimage(0,0, 630, 600, p);
		delay(kecepatan);
		swapbuffers();
	}
}

void classic(){
	ular(50,CLASSIC);
	getch();
	popAll();
	gameState = GAME_OVER;
}

void adventure(int level){
	if(level == 1){
		ular(50,LEVEL1);
	}
	else if(level == 2){
		ular(50,LEVEL2);
	}
	else if(level == 3){
		ular(50,LEVEL3);
	}
	else if(level == 4){
		ular(50,LEVEL4);
	}
	else if(level == 5){
		ular(50,LEVEL5);
	}
	gameState = GAME_OVER;
}


