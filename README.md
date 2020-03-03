# Eng
# NoNameoN
Computer Science at the Department of Computer Science and Mathematics, Unical university. 

# Game created with the C ++ programming language version 11.
This game is entirely open source, you can download and edit it as you wish without necessarily including the source.

If you want you can write my nickname: NoNameoN

# External functions included
Having failed to include some library functions, I had to look for them on the internet and below I report what you will find by reading the file 'game_board.h'

# getch()
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
    
 # kbhit(void)
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
    
# Ita
Studente d'iformatica presso il Dipartimento di Informatica e Matematica, Università Unical.

# Gioco creato con il linguaggio di programmazione C ++ versione 11.
Questo gioco è interamente open source, puoi scaricarlo e modificarlo come desideri senza necessariamente includere la fonte.

Se vuoi puoi scrivere il mio nickname: NoNameoN

# Funzioni esterne incluse
Non essendo riuscito ad includere alcune funzioni necessarie le ho dovuto cercare sull'Internet e di seguito riporto ciò che troverai leggendo il file "game_board.h"

# getch()
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
    
 # kbhit(void)
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
