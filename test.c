#include<stdio.h>
#include<curses.h>
void main(){
	char ch;
	initscr();
	while(1){
		ch = getch();
		printf("%c",ch);
	}
	endwin();
}
