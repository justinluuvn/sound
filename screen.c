//contains screen manipulation functions, such as clearscreen(0, gotoxy(),
//setColor(), etc
#include "screen.h"
#include <stdio.h>

void clearScreen(void)
{
        printf("%c[2J", ESC);
        fflush(stdout);
}

void gotoxy(int row, int col)
{
        printf("%c[%d;%dH", ESC, row, col);
        fflush(stdout);
}

void bar(int col, double dB)
{
        int i;
	for(i = 0; i < dB/4; i++)
        {
                gotoxy(25-i, col+1);    //the first bar starts from col 1
#ifndef UNICODE
                printf("%c", '*');
#else
		if(i < 15)
			setColor(37);
		else if(i < 20)
			setColor(33);
		else
			setColor(31);
		printf("%s", BAR);

#endif
        }
}

void setColor(int color)
{
	printf("%c[1;%dm",ESC,color);
	fflush(stdout);
}
