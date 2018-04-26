# ------------------------------------------------SOUND SENSOR PROJECT------------------------------------------------------------------ 

This project is meant to collect sound level at a proximity of a Raspberry Pi device. The RPI is equippeed with a USB sound card (C-Media 
Electronics, Inc. Audio Adapter) and a microphone. The sound is received at 16000Hz sample rate and every second will produce 80 pieces of 
RMS values as a bar-diagram.

Table of content

1. Confiuration
2. Installation
3. Operation
4. Manifest
5. Copyright and License
6. Contact Information

1. Configuration
	This project makes use of several devices which are listed below:
	a) One Raspberry Pi 3 device.
	b) One Straight-through RJ45 cable for Raspberry Pi 3 to access the internet.
	c) One 16GB SD Card element 14 pre-installed with NOOBS for Raspberry Pi.
	d) One USB cable (type A to type B) to power the Raspberry Pi device.
	e) One sound card for recording sound.
	f) One micro phone for recording sound.
	g) Internet access and the server ready.  
2. Installation
	a) Insert the SD card into the Raspberry device, and also plug the RJ45 cable in to access the internet.
	b) Power on the device by using the USB cable.
	c) Initialize the Raspberry device, change its default setting for sound card and network.
	d) Check the email for IP address.
	e) Use Putty application to remotely interact with Raspberry device.
	d) Plug in the sound card along with the microphone.
3. Operation
	a) Open the Putty terminal, enter the IP address received in the email and then click "Open".
	b) Log in to the device using the name "pi" and accompanying password.
	c) Go to the "appdev" folder by utilizing the command "cd" and then check the presence of all the files by the command "ls".
	d) Type in the command "make" to start the compilation process.
	e) Run the command "./sound.a" to start executing the resulting file.
	f) Using the microphone, start recording the sequence of 1-second WAV files. For each file, the program will calculate the rms value for 
	   every 200 samples of data, for a total of 80 values.	
	e) For each 10 rms values, one rms value of all of them will be calculated, and finally these 8 pieces of data will be sent to the server 
	   for convenient display.
4. Manifest (list of files and short description of their roles)
	a) main.c
		This is the root file.
	b) sound.c
		This file contains code for extracting information from the WAV file and processes it, then display the result.
	c) sound.h
		This is the header file for sound.c
	d) screen.c
		This file contains code for displaying the rms result on the screen.
	e) screen.h
		This is the header file for screen.c
	f) comm.c
		This file contains code for the Raspberry Pi communicating with online server
	g) comm.h
		This is the header file for comm.c
	h) makefile
		This file sets the rule for the compilation of the code and several other actions
	i) sound.php
		This file is stored in the server so as to process the data received from the pi and display to the user
5. Copyright and License
	Raspberry Pi is a trademark of the Raspberry Pi Foundation.
	The Bluetooth word mark and logos are registered trademarks owned by Bluetooth SIG, Inc. and any use of such
	marks by Raspberry Pi Trading Ltd is under license. 
	Other trademarks and trade names are those of their respective owners.
	The person mentioned in the contact information content has the copyright for the code, and Mr. Gao Chao greatly assisted in the making.		
6. Contact Information
	Tin Luu,
	Department of Information Technology
	Vaasa University of Applied Sciences
	Wolffintie 30, Vaasa, Finland
	Home: http://www.cc.puv.fi/~e1700674
	Email: e1700674(at)edu.vamk.fi
