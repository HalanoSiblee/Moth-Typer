#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ncurses.h>

using namespace std;

int main(int argc, char** argv) {
	if(argc < 2) {
	return 0;
	}
	fstream f1;
	f1.open(argv[1],ios::in|ios::out);
	char ch;
	int row = 0,column =  0;
	initscr();
	noecho();
	timeout(-1);
	getch();
	while(!f1.eof())
	{
		f1.get(ch);
		if(ch == '\n')
		{
			row++ ;
			if(row > 25)
			{	
				clear();
				row = 0;
			}
			column = 0;
		}
		mvaddch(row,column++,ch);
		getch();
	}	
	f1.close();
	endwin();
	return 0;
}
