#include <stdio.h>
#include <stdlib.h>
#include "sound.h"

int main (void)
{
	while(1)
	{
		system("arecord -q -r16000 -c1 -f S16_LE -d1 test.wav");
		//RECORD 1 second of sound into test.wav
		//open the wav file and read samples
		displayWAVheader("test.wav");
		//display necessary information (duration, wav header, etc)
		//calculate fast dBs
		displayBar("test.wav");
		//send fast dBs to web (php program on www.cc.puv.fi)
		break; //for testing, just run the loop once
	}
}
