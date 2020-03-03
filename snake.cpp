#include "game_board.h"
using namespace std;
const unsigned int secondsToWait = 100000;
int main (){
	game_board snakeGame; //Costructor default -> Snake
	snakeGame.start(); //Set pacman function && nickname gamer
	while(!snakeGame.getGameOver()){ //gameover is a boolean that control if you lose
		usleep(secondsToWait); //Wait 10 seconds before start
		snakeGame.draw(); //Draw metod - print score, matrix, snake(with the tail) and fruit
		snakeGame.command(); //Use kbhit and getch to take an input command - Watch 'logic()' metod
		snakeGame.logic(); //Tail system - Logic system
	}
	
	snakeGame.finish(); //End program - Use 'toilet' to print "You win!" or "You lose!"
	
}
