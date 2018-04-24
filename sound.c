#include "sound.h"
#include <stdio.h>
#include <math.h>
#include "comm.h"

/*
	Function definition of displayBar()
	This function opens the "test.wav" file and reads the second part (data) of
	the file. The samples should be in S16_LE format, and there are 16000 of them
	the function processes every 200 samples and calculates their RMS value
 	and renders this value as a bar on terminal screen
 	input argument: char filename[] (the string representing the name of the file)
 	output argument: none
*/

void displayBar(char filename[])
{
	FILE *fp;
	int i, j, sum_200;
	double rms_80[80], dB;
	short int samples[SAMPLERATE];
	WAVHeader myhdr; //dummy header to skip over the reading from the file
	fp = fopen(filename, "r");
	if(fp == NULL)
	{
		printf("Error opening the file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fread(&samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
	// all the samples of one second are read to the array samples[], we need
	// run a loop 80 times for 80 bars on the screen, and each iteration of
	// this loop will calculate a RMS value of 200 samples
	clearScreen();
	for(i=0; i<80; i++)
	{
		for(j=0, sum_200 = 0; j<200; j++)
		{
			sum_200 += samples[j + 200*i]*samples[j + 200*i]; //add all square values together
		}
		rms_80[i] = sqrt(sum_200/200); //find the square root
		dB = 20*log10(rms_80[i]);
#ifdef DEBUG	//conditional compilation
		printf("RMS[%d] = %.4f = %10.4fdB\n", i, rms_80[i], dB);
#else
		bar(i, dB);
#endif
	} // for
#ifdef COMM		//conditional compilation
	sendToServer(rms_80);
#endif
	gotoxy(0,0);								// go to the edge of the screen
 	printf("%c[1;%dm",ESC,37);					// change color to white
	fflush(stdout);
	printf("%s   ", filename);					// print out the file name
 	printf("%c[1;%dm",ESC,32);					// change color to green
	fflush(stdout);
	printf("ch = %d   ", myhdr.numChannels);	// print out the number of channels
 	printf("%c[1;%dm",ESC,36);					// change color to cyan
	fflush(stdout);
	printf("SR = %d   ", myhdr.sampleRate);		// print out the sampling rate
 	printf("%c[1;%dm",ESC,35);					// change color to magenta
	fflush(stdout);
	printf("dur = %ds\n", myhdr.subChunk2Size/(myhdr.sampleRate*myhdr.bitsPerSample/8));	// print out the duration
 	printf("%c[1;%dm",ESC,37);					// change color back to white
	fflush(stdout);
}	// function

/*
	function definition of displayWAVheader()
	This function prints out the details of a WAV header file
	input argument: char filename[] (the name of the file)
	output argument: none
*/
void displayWAVheader(char filename[])
{
	WAVHeader myhdr; //an instance of defined struct
	FILE *fp;
	fp = fopen(filename, "r"); //open the file for reading
	if(fp == NULL) //if fopen is failed
	{
		printf("ERROR of opening file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);		// read the header file
	fclose(fp);										// close the file

	// Each subsequent line helps print out certain details of the header
	printID(myhdr.chunkID); //print chunk ID
	printf("chunk size: %d\n", myhdr.chunkSize); //print chunk size
	printID(myhdr.format); //print format
	printID(myhdr.subchunk1ID); //print subchunk1 ID
	printf("subchunk 1 size: %d\n", myhdr.subchunk1Size); //print subchunk1 size
	printf("audio format: %d\n", myhdr.audioFormat); //print audio format
	printf("number of channels: %d", myhdr.numChannels); //print number of channels
	printf("sample rate: %d\n", myhdr.sampleRate); //print sampling rate
	printf("byte rate: %d\n", myhdr.byteRate); //print byte rate
	printf("block align: %d\n", myhdr.blockAlign); //print block align
	printf("bits per sample: %d\n", myhdr.bitsPerSample); //print number of bits per sample
	printID(myhdr.subChunk2ID); //print subchunk2 ID
	printf("subchunk 2 size: %d\n", myhdr.subChunk2Size); //print subchunk2 size
}

/*
	Function definition of printID()
	This function prints out the four characters given from the input
	Input argument: char id[] (the four characters in string format)
	Output argument: none
*/

void printID(char id[])
{
	int i;
	for(i=0; i<4; i++)
		printf("%c", id[i]);

	printf("\n");
}


