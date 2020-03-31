#include "../snake.h"



Tembok Obstacle;
tNode *Head, *pNew,*prev;


void createNode(tNode** node, Tembok data){
	tNode* p = (tNode*)malloc(sizeof(tNode));
 	p->Coordinat.x = data.x; 
 	p->Coordinat.y = data.y;
	p->next = NULL;
	*node = p;
}

void insertFront(tNode** head, Tembok data){
	tNode* pNew;
	createNode(&pNew, data);
	pNew->next = *head;
	*head = pNew;
}
  void backgroundClassic(){
  
   //load image from directory
   readimagefile("Border.jpg",0,0,620,600);
   //Image size(480x360)
	
	
//	int area,score = 10;
//	void *p;
//	area = imagesize(margLeft,margTop, 600, 500);
//	p = malloc(area);
}	

void printList(tNode* head){
	while(head != NULL){
		printf("x = %d\n ", head->Coordinat.x);
		printf("\ty = %d\n ", head->Coordinat.x);
//		printf("%d\n ", head->coordinat.x);
		head = head->next;
	}
}


void deleteAllNodeObs(tNode *p){
	while(p!=NULL){
	prev = p;
	p = p -> next;
	free(prev);
	}
	}

  void border(){

	int i, X,Y;
	Head = NULL;
	//Border Top
	X=0;
	Y=0;
	
	for( i = 0; i<20;i++){
		readimagefile("brick.GIF",X,Y,X+30,Y+30);
		
		Obstacle.x = X;
		Obstacle.y = Y;
		insertFront(&Head, Obstacle);
////	Obstacle[i].x = X;
//		Obstacle[i].y = Y;
		
		X= X+30;
//		printList(Head);
//		printf("%d\n",Obstacle[i].x);
//		Tampil_List (Head);
	}
	
	//Border Bot
		X=0;
		Y=0;
		
	for(i = 0; i<20;i++){
	
		readimagefile("brick.GIF",X,Y+570,X+30,Y+600);
		
		Obstacle.x = X;
		Obstacle.y = 570;
		insertFront(&Head, Obstacle);
//		Obstacle[i+20].x = X;
//		Obstacle[i+20].y = 570;

		X= X+30;
//		printf("\t %d\n",Obstacle[i+20].x);
	}
	
	//Border Left
	X=0;
	Y=0;
	for(int j = 0; j<20;j++){
		readimagefile("brick.GIF",X,Y,X+30,Y+30);
		
		Obstacle.x = X;
		Obstacle.y = Y;
		insertFront(&Head, Obstacle);
//		Obstacle[j+41].x = X;
//		Obstacle[j+41].y = Y;

		Y = Y +30;
//		printf("\t\t%d\n",Obstacle[j+41].y);
	}
	
	//Border Right
	Y = 0;
	for(int j = 0; j<20;j++){
	
		readimagefile("brick.GIF",X+600,Y,X+630,Y+30);
		
		Obstacle.x = 600;
		Obstacle.y = Y+30;
		insertFront(&Head, Obstacle);
//		Obstacle[j+61].x = 600;
//		Obstacle[j+61].y = Y+30;

		Y = Y +30;
	}
	
		printf("\t\t\t %d\n",11);
	
//	outtextxy(655,10,"SCORE");	

}

//Obstacle

void obstacleStage1(){
	
	deleteAllNodeObs(Head);

	int X = 0;
	int Y = 0;
	int i;
	for( i = 0; i <7; i++){
		readimagefile("brick.GIF",X+210,Y+210,X+240,Y+240); 	//gambar tembok belum fix
		
		Obstacle.x = X+210;
		Obstacle.y = 210;
		insertFront(&Head, Obstacle);
//		Obstacle[i+81].x = X+210;	
//		Obstacle[i+81].y = 210;
		
//		printf("\t %d\n",Obstacle[i+81].x);
		X=X+30;
	}
	X = 0;
	Y = 0;
	for( i = 0; i <7; i++){
		
	 readimagefile("brick.GIF",X+210,Y+360,X+240,Y+390);
	 	
		Obstacle.x = X+210;
		Obstacle.y = 360;
		insertFront(&Head, Obstacle);
//		 Obstacle[i+91].x = X+210;
//		Obstacle[i+91].y = 360;
		
//		printf("\t %d\n",Obstacle[i+20].x);
		X=X+30;
	}
}
  
void obstacleStage2(){				//gambar tembok belum fix
	int X = 0;
	int Y = 0;
	int i;
	
	for( i = 0; i <3; i++){ // Middle Obs
		readimagefile("brick.GIF",X+270,Y+270,X+300,Y+300);
		readimagefile("brick.GIF",X+270,Y+300,X+300,Y+330);
		X=X+30;
		
	}
	X = 0;
	Y = 0;
	for( i = 0; i <4; i++){	//Horizintal Obs 
		//Top
		readimagefile("brick.GIF",X+120,Y+120,X+150,Y+150);
		readimagefile("brick.GIF",X+390,Y+120,X+420,Y+150);
		
		//Bottom
		readimagefile("brick.GIF",X+120,MAX_Y-150,X+150,MAX_Y-180);
		readimagefile("brick.GIF",X+390,MAX_Y-150,X+420,MAX_Y-180);
		X=X+30;
	}
	
	X = 0;
	Y = 0;
	for( i = 0; i <4; i++){	//Vertical Obs 
		//Top
		readimagefile("brick.GIF",X+120,Y+120,X+150,Y+150);
		readimagefile("brick.GIF",X+480,Y+120,X+510,Y+150);
		
		Y=Y+30;
	}
	X = 0;
	Y = 0;
	for(i=0;i<4;i++){
		
		//	Bottom
		readimagefile("brick.GIF",X+120,Y+450,X+150,Y+420);
		readimagefile("brick.GIF",X+480,Y+450,X+510,Y+420);
		Y=Y-30;
	}
}

bool collisionTembok(){
	struct oray *p = head;
	tNode *temp = Head;
	while(temp !=NULL){
		if(p->x == temp->Coordinat.x && p->y == temp->Coordinat.y){
			return true;
		}
		temp = temp->next;
	}
	return false;
}
