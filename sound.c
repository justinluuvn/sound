#include "sound.h"
#include <stdio.h>

// function definition of displayBar()
// this function opens the "test.wav" file and reads the second part (data) of
// the file. The samples should be in S16_LE format, and there are 16000 of them
// the function processes every 200 samples and calculates their RMS value
// and renders this value as a bar on terminal screen
void printBar(char filename[])
{
	FILE *fp;
	int i;
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
	for(i=0; i<80; i++)
	{
		 
	}
}

// function definition of displayWAVheader()
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
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fclose(fp);
	printID(myhdr.chunkID);
	printf("chunk size: %d\n", myhdr.chunkSize);
	printID(myhdr.format);
	printID(myhdr.subchunk1ID);
	printf("subchunk 1 size: %d\n", myhdr.subchunk1Size);
	printf("audio format: %d\n", myhdr.audioFormat);
	printf("number of channels: %d", myhdr.numChannels);
	printf("sample rate: %d\n", myhdr.sampleRate);
	printf("byte rate: %d\n", myhdr.byteRate);
	printf("block align: %d\n", myhdr.blockAlign);
	printf("bits per sample: %d\n", myhdr.bitsPerSample);
	printID(myhdr.subChunk2ID);
	printf("subchunk 2 size: %d\n", myhdr.subChunk2Size);
}

void printID(char id[])
{
	int i;
	for(i=0; i<4; i++)
		printf("%c", id[i]);

	printf("\n");
}


