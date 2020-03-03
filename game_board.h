#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <iostream>
#include <string>
#include <ctime>
#include <termios.h>
#include <cstdlib>
#include <unistd.h>

#include <cstdio>
#include <fcntl.h>

using namespace std;

class game_board{

	private:
		bool gameover;
		int xHead, yHead;
		int xFruit, yFruit;
		int score;
		const int height = 20;
		const int width = 20;
		enum Direction { LEFT=0,RIGHT,UP,DOWN,GAME_OVER};
		Direction dir;
		
		//Before start
		bool pacmanEffect;
		string nickname;
		
		//After game
		bool winner;
		
		//For the tail
		int eaten;
		int tailX[100];
		int tailY[100];
	
	public:
		game_board(){
			gameover = false;
			xHead = 2;
			yHead = 2;
			srand (time(NULL));
			xFruit = rand()%(height-1)+1;
			yFruit = rand()%(width-1)+1;
			score = 0;
			winner=false;
			eaten=1;
		}
		
		void start(){
			cout<<"Hi!\nWelcome to my firsth game!\nThis is a simple snake game but you can choise some settings like:"<<endl;
			cout<<"1)Do you want PacMan effect or you will die when you touch the wall? If you want it write 'pacman'";
			string pacman;
			cin>>pacman;
			if(pacman=="pacman") { 
				pacmanEffect = true;
				cout<<"Perfect! You choosed the pacman effect!"<<endl;
			}
			else
				cout<<"Perfect! You didn't choose the pacman effect!"<<endl;
			cout<<"2)Insert your nickname: ";
			cin>>nickname;
			cout<<"Perfect "<<nickname<<" it's time to start!";
		}
		
		void command (){
			if(kbhit()){
				switch (getch()){
					case 'a':
						dir = LEFT;
						break;
					case 's':
						dir = DOWN;
						break;
					case 'd':
						dir = RIGHT;
						break;
					case 'w':
						dir = UP;
						break;
					case 'y':
						dir = GAME_OVER;
						break;
					default:
						break;
				}
			}
		}
		
		void logic (){
			//Tail system
			int prevX = tailX[0];
			int prevY = tailY[0];
			int prev2X, prev2Y;
			tailX[0] = xHead;
			tailY[0] = yHead;
			for(int i=0;i<eaten;i++){
				prev2X = tailX[i];
				prev2Y = tailY[i];
				tailX[i] = prevX;
				tailY[i] = prevY;
				prevX = prev2X;
				prevY = prev2Y;
			}
			
			//logic system (watch 'command()' metod)
			switch (dir){
				case LEFT:
					xHead--;
					break;
				case RIGHT:
					xHead++;
					break;
				case UP:
					yHead--;
					break;
				case DOWN:
					yHead++;
					break;
				case GAME_OVER:
					gameover=true;
				default:
					break;
				}
			//Pacman effect
			if(pacmanEffect){
				if(yHead>=height){
					yHead = 1;
				}
				else if(xHead>=width){
					xHead = 1;
				}
				else if(yHead<=0){
					yHead = height-1;
				}
				else if(xHead<=0){
					xHead = width-1;
				}
			}
			else{
				if(yHead>=height||yHead<=0||xHead>=width||xHead<=0)
					gameover = true;
			}
			
			//Eat Fruit effect
			if(xHead==xFruit && yHead==yFruit){//if i eat the fruit				
				xFruit = rand()%(height-1)+1;//I'm changing the fruit posiction
				yFruit = rand()%(width-1)+1;//Random made
				
				score+=50;//You taken the fruit so you win 50 points
				eaten+=1;//You taken the fruit so you will be more big
			}
			//If you want eat your tail you will loose
			for(int i=0;i<eaten;i++){
				if(tailX[i] == xHead && tailY[i] == yHead)
					gameover = true;
			}
			//If you have 1000 points you win! - You can edit it
			if(score==1000){
				winner = true;
				gameover=true;
			}
		}		
		void draw (){
		system ("clear");
			cout<<"Score: "<<score<<endl;
			for(int i=0;i<=height;i++){
				for(int j=0;j<=width;j++){
					if(i==0 || i==height)
						cout<<"#";
					//else if(j==0 || j==width)
						//cout<<"2";
					else if(j==0 || j==width)
						cout<<"#";
					else if(i==yHead && j==xHead)
						cout<<"O";
					else if(i==yFruit && j==xFruit)
						cout<<"F";
					else{
						bool print = false;
						for(int h=0;h<eaten;h++){
							if(tailX[h] == j && tailY[h] == i){
								cout<<"o";
								print = true;
							}
						}
						if(!print)
							cout<<" ";
					}
				}
			cout<<endl;				
			}
		}
		
		void finish (){
		system("clear");
			if(!winner){
				system("toilet You Lose!");
			}
			else{
				system("toilet You Win!");
			}
			string toStamp("toilet ");
			toStamp+=nickname;
			system(toStamp.c_str());
			cout<<"\nAlessandro Greco <3"<<endl;
		}

		string getNickname(){return nickname;}
		bool getGameOver () {return gameover;}
		void setPacmanEffect (bool choise) {pacmanEffect = choise;}
		
	int getch(){ //getch function
		int ch;
    	struct termios t_old, t_new;

    	tcgetattr(STDIN_FILENO, &t_old);
    	t_new = t_old;
    	t_new.c_lflag &= ~(ICANON | ECHO);
    	tcsetattr(STDIN_FILENO, TCSANOW, &t_new);
	
    	ch = getchar();

    	tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    	return ch;
		}
		
	int kbhit(void){//kbhit function
		struct termios oldt, newt;
  		int ch;
  		int oldf;
  		tcgetattr(STDIN_FILENO, &oldt);
  		newt = oldt;
  		newt.c_lflag &= ~(ICANON | ECHO);
  		tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  		oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  		fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  		ch = getchar();
  		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  		fcntl(STDIN_FILENO, F_SETFL, oldf);
 		if(ch != EOF){
		    ungetc(ch, stdin);
    		return 1;
  		}
  		return 0;
		}
		
}; //End class

#endif
