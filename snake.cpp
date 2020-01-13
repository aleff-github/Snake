#include "game_board.h"
using namespace std;
const unsigned int secondsToWait = 100000;
int main (){
	
	game_board snakeGame;
	snakeGame.start();

	while(!snakeGame.getGameOver()){
		usleep(secondsToWait);
		snakeGame.draw();
		snakeGame.command();
		snakeGame.logic();
	}
	
	snakeGame.finish();
	
}