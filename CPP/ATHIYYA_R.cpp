#include "..\snake.h"

void mainMenu(){
	
	int x,y;
	int status = 0;
	bool kembali,back;

	while (status == 0){
		clearviewport();
		setviewport(0,0,800,600,1);
		readimagefile("mainMenu.jpg",0,0,WIDTH,HEIGHT);
		swapbuffers();
		
		kembali = false;
		back = false;
		
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if((x > 270 && x < 518) && (y > 272 && y < 327)){	//select mode
			while(!back){
			clearviewport();
			setviewport(0,0,800,600,1);
			readimagefile("selectMode.jpg",0,0,WIDTH,HEIGHT);
			swapbuffers();
			while (!kembali){
				
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x > 347 && x < 500) && (y > 426 && y<456)){
					kembali = true;
					back = true;								//back to menu sebelumnya
				}else if((x > 283 && x < 476) && (y > 255 && y < 308)){
					clearviewport();
					setviewport(0,0,800,600,1);
   					gameState = CLASSIC_GAMEPLAY;
					swapbuffers(); 
					return;		
				}
				else if((x > 324 && x < 572) && (y > 326 && y < 379)){	//Mode Adventure
						while (!kembali){
						clearviewport();
						setviewport(0,0,800,600,1);
						readimagefile("selectLevel.jpg",0,0,WIDTH,HEIGHT);
						swapbuffers();
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if ((x > 284 && x < 326) && (y > 236 && y < 279)){
								clearviewport();
								setviewport(0,0,800,600,1);	//Level 1
								gameState = ADVENTURE_GAMEPLAY;
								stage = 1;
								snakeSpeed = 50;
								swapbuffers();
								return;
						}else if ((x > 339 && x < 372) && (y > 323 && y < 355)){
								clearviewport();
								setviewport(0,0,800,600,1);	//Level 2
								gameState = ADVENTURE_GAMEPLAY;
								stage = 1;
								snakeSpeed = 45;
								swapbuffers();
								return;
						}else if((x > 406 && x < 454) && (y > 252 && y < 299)){
								clearviewport();
								setviewport(0,0,800,600,1);	
								gameState = ADVENTURE_GAMEPLAY;
								stage = 1;
								snakeSpeed = 40;
								swapbuffers();		//Level 3
								return;
						}else if((x > 436 && x < 486) && (y > 353 && y < 403)){	//level 4
								clearviewport();
								setviewport(0,0,800,600,1);	
								gameState = ADVENTURE_GAMEPLAY;
								stage = 1;
								snakeSpeed = 30;
								swapbuffers();
								return;
						}else if((x > 518 && x < 570) && (y > 279 && y < 332)){	//level 5
								clearviewport();
								setviewport(0,0,800,600,1);	
								gameState = ADVENTURE_GAMEPLAY;
								stage = 1;
								snakeSpeed = 20;
								swapbuffers();
								return;
						}else if((x > 347 && x < 500) && (y > 426 && y<456)){
								kembali = true;
						}
					}
				}
			}kembali = false;
			}
		}
	
		else if ((x > 318 && x < 558) && (y > 335 && y < 381)){
			//Menampilkan High score
//			gameState = LEADER_BOARD;
			printLeaderBoard();
			return;
		}
		else if ((x > 244 && x < 489) && (y > 398 && y < 445)){
			while (!kembali){
			clearviewport();
			setviewport(0,0,800,600,1);
			readimagefile("instruction.gif",0,0,WIDTH,HEIGHT);//Menampilkan Instruction
			swapbuffers();
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x > 636 && x < 696) && (y > 476 && y < 530)){
				printf("kolokolkolkolpo");
				kembali = true;
			}
			}
		}
		else if ((x > 314 && x < 484) && (y > 469 && y < 503)){
			status = 1;
			//Exit			
		}
	}
	closegraph();
}
