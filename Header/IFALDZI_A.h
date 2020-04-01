#ifndef IFALDZI_A_H
#define IFALDZI_A_H

bool checkCollisionFood(Coordinat foodCoordinat);

bool checkCollisionTembokFood(Coordinat foodCoordinat);

void printScore();

void renderUlar();

void displayUlar();

void resetPage();

void gameOver(int prevGameState);

void printFinalScore(int tempScore, int x, int y);

bool checkHighScore();

void putHighScore();

void printLeaderBoard();

void removeItem(Coordinat itemCoordinate);

void sortScore();

void gameCompleted();

#endif
