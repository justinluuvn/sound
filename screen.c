//contains screen manipulation functions, such as clearscreen(0, gotoxy(),
//setColor(), etc
#include "screen.h"
#include <stdio.h>
#include "comm.h"

/*
	Function definition of clearscreen()
	This function will use VT100 escape sequence "/ESC[2J" to erase the total
	terminal screen
	input argument: none
	return argument: none
*/

void clearScreen(void)
{
        printf("%c[2J", ESC);
        fflush(stdout);
}

/*
	Function definition of gotoxy()
	This function uses VT100 escape sequence "/ESC[row;colH" to set the cursor
	to the specific location of the terminal screen
	input argument:
		int row: row number (1 is top)
		int col: col number (1 is left)
	return argument: none
*/

void gotoxy(int row, int col)
{
        printf("%c[%d;%dH", ESC, row, col);
        fflush(stdout);
}

/*
	Function definition of bar()
	This function makes use of gotoxy() function and then draws the bar representing
	the dB value input
	input argument:
		int col: col number
		double dB: the deciBel value of sound
	output argument: none
*/

void bar(int col, double dB)
{
        int i;
	for(i = 0; i < dB/4; i++)
        {
                gotoxy(25-i, col+1);    // the first bar starts from col 1
#ifndef UNICODE
                printf("%c", '*');		// if in debug mode, just print '*' out
#else									// otherwise
		if(i < 15)						// if the dB value<60, use white color
			setColor(37);
		else if(i < 20)					// if the 60<=dB value<80, use yellow color
			setColor(33);
		else
			setColor(31);				// if the 80<=dB value, use red color
		printf("%s", BAR);

#endif
        }
}

/*
	Function definition of setColor()
	This function uses VT100 escape sequence "/ESC[1;colorm" to change the terminal
	text color
	input argument: int color (the color codes)
	output argument: none
*/

void setColor(int color)
{
	printf("%c[1;%dm",ESC,color);
	fflush(stdout);
}
