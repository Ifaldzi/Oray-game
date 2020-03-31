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
//		obstacleStage1();
//		obstacleStage2();
//	outtextxy(655,10,"SCORE");	

}

//Obstacle

void obstacleStage1(){
	
while(Head!=NULL){				// Delete semua node sebelumnya
	prev = Head;
	Head = Head -> next;
	free(prev);
	}
border();
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
	
	while(Head!=NULL){				// Delete semua node sebelumnya
	prev = Head;
	Head = Head -> next;
	free(prev);
	}
	border();
	int X = 0;
	int Y = 0;
	int i;
	
	// Middle Obs
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+270,Y+270,X+300,Y+300);
		Obstacle.x = X+270;
		Obstacle.y = 270;
		insertFront(&Head, Obstacle);
		X=X+30;
	}
	X=0;
	Y=0;
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+270,Y+300,X+300,Y+330);
		Obstacle.x = X+270;
		Obstacle.y = 300;
		insertFront(&Head, Obstacle);
		
		X=X+30;
		
	}
	//Horizintal Obs
	X = 0;
	Y = 0;
	//Top
	for( i = 0; i <4; i++){	 
		
		readimagefile("brick.GIF",X+120,Y+120,X+150,Y+150);
		Obstacle.x = X+120;
		Obstacle.y = 120;
		insertFront(&Head, Obstacle);
		X=X+30;
	}
	X = 0;
	Y = 0;
	for( i = 0; i <4; i++){	 	
		readimagefile("brick.GIF",X+390,Y+120,X+420,Y+150);
		Obstacle.x = X+390;
		Obstacle.y = 120;
		insertFront(&Head, Obstacle);
		X=X+30;
	}
	X = 0;
	Y = 0;
		//Bottom
		for( i = 0; i <4; i++){	 
		readimagefile("brick.GIF",X+120,MAX_Y-150,X+150,MAX_Y-180);
		Obstacle.x = X+210;
		Obstacle.y = 450;
		insertFront(&Head, Obstacle);
		X=X+30;
	}
	X = 0;
	Y = 0;
		for( i = 0; i <4; i++){
		readimagefile("brick.GIF",X+390,MAX_Y-150,X+420,MAX_Y-180);
		Obstacle.x = X+390;
		Obstacle.y = 450;
		insertFront(&Head, Obstacle);
		X=X+30;
	}
	
	X = 0;
	Y = 0;
	//Vertical Obs 
	for( i = 0; i <4; i++){	
		//Top
		readimagefile("brick.GIF",X+120,Y+120,X+150,Y+150);
		Obstacle.x = 120;
		Obstacle.y = Y+120;
		insertFront(&Head, Obstacle);
		Y=Y+30;
	}
	X = 0;
	Y = 0;
		for( i = 0; i <4; i++){	
		readimagefile("brick.GIF",X+480,Y+120,X+510,Y+150);
		Obstacle.x = 480;
		Obstacle.y = Y+120;
		insertFront(&Head, Obstacle);
		Y=Y+30;
	}
	
	X = 0;
	Y = 0;
		//	Bottom
	for(i=0;i<4;i++){
		
		readimagefile("brick.GIF",X+120,Y+450,X+150,Y+420);
		Obstacle.x = 120;
		Obstacle.y = Y+450;
		insertFront(&Head, Obstacle);
		Y=Y-30;
	}
	X = 0;
	Y = 0;
	for(i=0;i<4;i++){
		readimagefile("brick.GIF",X+480,Y+450,X+510,Y+420);
		Obstacle.x = 480;
		Obstacle.y = Y+450;
		insertFront(&Head, Obstacle);
		Y=Y-30;
	}
}

void obstacleStage3(){
	while(Head!=NULL){				// Delete semua node sebelumnya
		prev = Head;
		Head = Head -> next;
		free(prev);
	}
	border();
	int X = 0;
	int Y = 0;
	int i;
	
	//Horizontal
	
	//Mid left
	for( i = 0; i <4; i++){ 
		readimagefile("brick.GIF",X+120,Y+300,X+150,Y+330);
		Obstacle.x = X+120;
		Obstacle.y = 300;
		insertFront(&Head, Obstacle);
		X=X+30;
	}
	
	//Mid Right
	X = 0;
	Y = 0;
	for( i = 0; i <4; i++){ 
		readimagefile("brick.GIF",X+390,Y+300,X+420,Y+330);
		Obstacle.x = X+390;
		Obstacle.y = 300;
		insertFront(&Head, Obstacle);
		X=X+30;
	}
	//Top Center
	X = 0;
	Y = 0;
	for( i = 0; i <2; i++){ 
		readimagefile("brick.GIF",X+270,Y+120,X+240,Y+150);
		Obstacle.x = X+270;
		Obstacle.y = 120;
		insertFront(&Head, Obstacle);
		X=X-30;
	}
	//Bot Center
	X = 0;
	Y = 0;
	for( i = 0; i <2; i++){ 
		readimagefile("brick.GIF",X+330,Y+450,X+360,Y+480);
		Obstacle.x = X+330;
		Obstacle.y = 450;
		insertFront(&Head, Obstacle);
		X=X+30;
	}
	
	
	
	//Vertical
	X = 0;
	Y = 0;
	//Mid Top
	for( i = 0; i <4; i++){	
		
		readimagefile("brick.GIF",X+300,Y+120,X+330,Y+150);
		Obstacle.x = 300;
		Obstacle.y = Y+120;
		insertFront(&Head, Obstacle);
		Y=Y+30;
	}
	
	X = 0;
	Y = 0;
	//Mid Bot
	for( i = 0; i <3; i++){	
		
		readimagefile("brick.GIF",X+300,Y+390,X+330,Y+420);
		Obstacle.x = 300;
		Obstacle.y = Y+390;
		insertFront(&Head, Obstacle);
		Y=Y+30;
	}
	X = 0;
	Y = 0;
	//Mid left
	for( i = 0; i <2; i++){	
		
		readimagefile("brick.GIF",X+120,Y+330,X+150,Y+360);
		Obstacle.x = 120;
		Obstacle.y = Y+330;
		insertFront(&Head, Obstacle);
		Y=Y+30;
	}
	
	X = 0;
	Y = 0;
	//Mid Right
	for( i = 0; i <2; i++){	
		
		readimagefile("brick.GIF",X+480,Y+270,X+510,Y+300);
		Obstacle.x = 480;
		Obstacle.y = Y+270;
		insertFront(&Head, Obstacle);
		Y=Y-30;
	}
}

void obstacleStage4(){
	
	while(Head!=NULL){				// Delete semua node sebelumnya
		prev = Head;
		Head = Head -> next;
		free(prev);
	}
	border();
	
	int X = 0;
	int Y = 0;
	int i;
	
	//Horizontal
	
	//Mid left
	for( i = 0; i <4; i++){ 
		readimagefile("brick.GIF",X+120,Y+300,X+150,Y+330);
		Obstacle.x = X+120;
		Obstacle.y = 300;
		insertFront(&Head, Obstacle);
		X=X+30;
	}
	
	//Mid Right
	X = 0;
	Y = 0;
	for( i = 0; i <4; i++){ 
		readimagefile("brick.GIF",X+390,Y+300,X+420,Y+330);
		Obstacle.x = X+390;
		Obstacle.y = 300;
		insertFront(&Head, Obstacle);
		X=X+30;
	}
	
	
	
	
	//Vertical
	X = 0;
	Y = 0;
	//Mid Top
	for( i = 0; i <4; i++){	
		
		readimagefile("brick.GIF",X+300,Y+120,X+330,Y+150);
		Obstacle.x = 300;
		Obstacle.y = Y+120;
		insertFront(&Head, Obstacle);
		Y=Y+30;
	}
	
	X = 0;
	Y = 0;
	//Mid Bot
	for( i = 0; i <4; i++){	
		
		readimagefile("brick.GIF",X+300,Y+390,X+330,Y+420);
		Obstacle.x = 300;
		Obstacle.y = Y+390;
		insertFront(&Head, Obstacle);
		Y=Y+30;
	}
	
	//Cross Obstacle
	X = 0;
	Y = 0;
	//Kiri atas
	for( i = 0; i <6; i++){ 
		readimagefile("brick.GIF",X+90,Y+90,X+120,Y+120);
		Obstacle.x = X+90;
		Obstacle.y = Y+90;
		insertFront(&Head, Obstacle);
		X=X+30;
		Y=Y+30;
	}
	
	X = 0;
	Y = 0;
	//Kanan atas
	for( i = 0; i <6; i++){ 
		readimagefile("brick.GIF",X+510,Y+90,X+540,Y+120);
		Obstacle.x = X+510;
		Obstacle.y = Y+90;
		insertFront(&Head, Obstacle);
		X=X-30;
		Y=Y+30;
	}
	
	X = 0;
	Y = 0;
	//Kiri bawah
	for( i = 0; i <6; i++){ 
		readimagefile("brick.GIF",X+90,Y+510,X+120,Y+540);
		Obstacle.x = X+90;
		Obstacle.y = Y+510;
		insertFront(&Head, Obstacle);
		X=X+30;
		Y=Y-30;
	}
	
	X = 0;
	Y = 0;
	//Kanan Bawah
	for( i = 0; i <6; i++){ 
		readimagefile("brick.GIF",X+510,Y+510,X+540,Y+540);
		Obstacle.x = X+510;
		Obstacle.y = Y+510;
		insertFront(&Head, Obstacle);
		X=X-30;
		Y=Y-30;
	}

	
}
void obstacleStage5(){
	
	while(Head!=NULL){				// Delete semua node sebelumnya
		prev = Head;
		Head = Head -> next;
		free(prev);
	}
	border();
	
	
	//Mid Obstacle
	int X = 0;
	int Y = 0;
	int i;
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+270,Y+270,X+300,Y+300);
		Obstacle.x = X+270;
		Obstacle.y = 270;
		insertFront(&Head, Obstacle);
		X=X+30;
		
	}
	
	X = 0;
	Y = 0;
	
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+270,Y+300,X+300,Y+330);
		Obstacle.x = X+270;
		Obstacle.y = 300;
		insertFront(&Head, Obstacle);
		X=X+30;
		
	}
	
	X = 0;
	Y = 0;
	
	//Cross mid Obstacle
	
	//kiri atas
	for( i = 0; i <2; i++){ 
		readimagefile("brick.GIF",X+240,Y+240,X+270,Y+270);
		Obstacle.x = X+240;
		Obstacle.y = Y+240;
		insertFront(&Head, Obstacle);
		X=X-30;
		Y=Y-30;
	}
	
	X = 0;
	Y = 0;
	//kanan atas
	for( i = 0; i <2; i++){ 
		readimagefile("brick.GIF",X+360,Y+240,X+390,Y+270);
		Obstacle.x = X+360;
		Obstacle.y = Y+240;
		insertFront(&Head, Obstacle);
		X=X+30;
		Y=Y-30;
	}
	
	X = 0;
	Y = 0;
	//kiri bawah
	for( i = 0; i <2; i++){ 
		readimagefile("brick.GIF",X+240,Y+330,X+270,Y+360);
		Obstacle.x = X+240;
		Obstacle.y = Y+330;
		insertFront(&Head, Obstacle);
		X=X-30;
		Y=Y+30;
	}
	
	X = 0;
	Y = 0;
	//kanan bawah
	for( i = 0; i <2; i++){ 
		readimagefile("brick.GIF",X+360,Y+330,X+390,Y+360);
		Obstacle.x = X+360;
		Obstacle.y = Y+330;
		insertFront(&Head, Obstacle);
		X=X+30;
		Y=Y+30;
	}
	
	//Vertical Obstacle			
	
	X = 0;
	Y = 0;
	//Kiri atas
	for( i = 0; i <2; i++){ 
		readimagefile("brick.GIF",X+150,Y+150,X+180,Y+180);
		Obstacle.x = 150;
		Obstacle.y = Y+150;
		insertFront(&Head, Obstacle);
	
		Y=Y-30;
	}
	
	X = 0;
	Y = 0;
	//Kanan Atas
	for( i = 0; i <2; i++){ 
		readimagefile("brick.GIF",X+450,Y+150,X+480,Y+180);
		Obstacle.x = 450;
		Obstacle.y = Y+150;
		insertFront(&Head, Obstacle);
	
		Y=Y-30;
	}
	
	X = 0;
	Y = 0;
	//Kiri Bawah
	for( i = 0; i <2; i++){ 
		readimagefile("brick.GIF",X+150,Y+420,X+180,Y+450);
		Obstacle.x = 150;
		Obstacle.y = Y+420;
		insertFront(&Head, Obstacle);
	
		Y=Y+30;
	}
	
	X = 0;
	Y = 0;
	//Kanan Bawah
	for( i = 0; i <2; i++){ 
		readimagefile("brick.GIF",X+450,Y+420,X+480,Y+450);
		Obstacle.x = 450;
		Obstacle.y = Y+420;
		insertFront(&Head, Obstacle);
	
		Y=Y+30;
	}
	
	//Horizontal Obstacle
	
	X = 0;
	Y = 0;	
	//Atas
	for( i = 0; i <10; i++){ 
		readimagefile("brick.GIF",X+150,Y+120,X+180,Y+150);
		Obstacle.x = X+150;
		Obstacle.y = 120;
		insertFront(&Head, Obstacle);
	
		X=X+30;
	}

	X = 0;
	Y = 0;	
	//Bawah
	for( i = 0; i <10; i++){ 
		readimagefile("brick.GIF",X+150,Y+450,X+180,Y+480);
		Obstacle.x = X+150;
		Obstacle.y = 450;
		insertFront(&Head, Obstacle);
	
		X=X+30;
	}
	
	//Cross bingkai
	
	X = 0;
	Y = 0;	
	//Kiri Atas
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+60,Y+120,X+90,Y+150);
		Obstacle.x = X+60;
		Obstacle.y = Y+120;
		insertFront(&Head, Obstacle);
		
		X=X+30;
		Y=Y-30;	
	}
	
	X = 0;
	Y = 0;	
	//Kanan Atas
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+540,Y+120,X+570,Y+150);
		Obstacle.x = X+540;
		Obstacle.y = Y+120;
		insertFront(&Head, Obstacle);
		
		X=X-30;
		Y=Y-30;	
	}
	
	X = 0;
	Y = 0;	
	//Kiri bawah
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+60,Y+450,X+90,Y+480);
		Obstacle.x = X+60;
		Obstacle.y = Y+450;
		insertFront(&Head, Obstacle);
		
		X=X+30;
		Y=Y+30;	
	}
	X = 0;
	Y = 0;	
	//Kanan bawah
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+540,Y+450,X+570,Y+480);
		Obstacle.x = X+540;
		Obstacle.y = Y+450;
		insertFront(&Head, Obstacle);
		
		X=X-30;
		Y=Y+30;	
	}
	
	//Horizontal Mid Obstacle
	
	X = 0;
	Y = 0;	
	//Kiri Mid
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+60,Y+240,X+90,Y+270);
		Obstacle.x = X+60;
		Obstacle.y = 240;
		insertFront(&Head, Obstacle);
		
		X=X+30;
	
	}
	
	X = 0;
	Y = 0;	
	//Kiri Mid
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+60,Y+330,X+90,Y+360);
		Obstacle.x = X+60;
		Obstacle.y = 330;
		insertFront(&Head, Obstacle);
		
		X=X+30;
	
	}
	
	X = 0;
	Y = 0;	
	//Kanan Mid
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+480,Y+240,X+510,Y+270);
		Obstacle.x = X+480;
		Obstacle.y = 240;
		insertFront(&Head, Obstacle);
		
		X=X+30;
	
	}
	
	X = 0;
	Y = 0;	
	//Kanan Mid
	for( i = 0; i <3; i++){ 
		readimagefile("brick.GIF",X+480,Y+330,X+510,Y+360);
		Obstacle.x = X+480;
		Obstacle.y = 330;
		insertFront(&Head, Obstacle);
		
		X=X+30;
	
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
