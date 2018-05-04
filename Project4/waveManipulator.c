/*
  CS221: Project4 - Audio (WAV)File Manipulation
  Casey Marshall && Joe Divinagracia
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include "wave.h"

void reverse(short* leftChannel, short* rightChannel, int length);
short* changeSpeed(short* channel, int length, double speed);
short* fadeOut(short* channel, int time, int length);
short* fadeIn(short* channel, double time, int length);
short* volume(short* channel, int length, double scale);
//short echo(short* leftChannel, short* rightChannel, double delay, double scale);

short echo();

//takes a short and splits it into two chars
short putShort(short channel){
  putchar(channel & 0xFF);
  putchar(channel >> 8);
}

//turns a char into two short variables
short getShort(){
  short a = getchar();
  short b = getchar();
  short c = (b<<8)|a;
  return c;
}

int main(int argc, char** argv){
  //set flags
  int commandLine=0;
  
  //set the structs
  FormatChunk formatChunk;
  DataChunk dataChunk;
  WaveHeader waveHeader;

  //reads in the waveHeader
  readHeader(&waveHeader);
  
  int i, sampleRate = waveHeader.formatChunk.sampleRate;//sets sampleRate
  
  //sets waveHeader ID, formatChunk ID && dataChunk ID
  char* headID=waveHeader.ID;
  char* formatID = waveHeader.formatChunk.ID;
  char* dataID = waveHeader.dataChunk.ID;

  int fmtSize = waveHeader.formatChunk.size;
  short fmtCompress = waveHeader.formatChunk.compression;

  short numChannels = waveHeader.formatChunk.channels;
  short bitsPerSample = waveHeader.formatChunk.bitsPerSample;
  
  //set the left&right Channels, as well as the length of each
  int length = waveHeader.dataChunk.size/4;
  short* leftChannel = malloc(sizeof(short)*length);
  if(leftChannel == NULL)
    fprintf(stderr, "Program out of memory\n");
  short* rightChannel = malloc(sizeof(short)*length);
  if(rightChannel == NULL)
    fprintf(stderr, "Program out of memory\n");

  short* temp;
  
  //error handling
  if(headID[0]!='R' && headID[1]!='I' && headID[2]!='F' && headID[3]!='F')
    fprintf(stderr, "File is not a RIFF file\n");
  else if((formatID[0]!='f' && formatID[1]!='m' && formatID[2]!='t') || fmtSize!=16 || fmtCompress!=1)
    fprintf(stderr, "Format chunk is corrupted\n");
  else if(dataID[0]!='d' && dataID[1]!='a' && dataID[2]!='t' && dataID[3]!='a')
    fprintf(stderr, "Format chunk is corrupted\n");
  else if(numChannels!=2)
    fprintf(stderr, "File is not stereo\n");
  else if(sampleRate!=44100)//checks for the correct sampleRate
    fprintf(stderr,"File does not use 44,100Hz sample rate\n");
  else if(bitsPerSample!=16)
    fprintf(stderr, "File does not have 16-bit samples\n");

  //if none of the above errors occur...
  else{
    //populates left and right channel arrays with the initial data of the wave file
    for(i=0;i<length;i++){
      leftChannel[i] = getShort();
      rightChannel[i] = getShort();
    }

    //if the user adds command line arguments
    if(argc > 1){
      //loop through all of the specified argument flags
      for(i=1;i<argc && argv[i][0] == '-';i++){
	switch(argv[i][1]){//checks the char after the '-' for each flag
	case('r'):{//reverse case
	  reverse(leftChannel, rightChannel, length);
	  break;
	}
	  
	case('s'):{//changeSpeed case
	  //checks if the user specified a speed factor
	  if(i+1 < argc){
	    //sets the speed to that value
	    double speed = atof(argv[i+1]);
	    if(speed <= 0.0)//error out if the value is less than 0
	      fprintf(stderr, "A positive number must be supplied for the speed change\n");
	    else{
	      int newLength = length/speed;
	      leftChannel = changeSpeed(leftChannel, length, speed);
	      rightChannel = changeSpeed(rightChannel, length, speed);
	      i++;
	      length = newLength;
	    }

	    //update header size info
	      waveHeader.size /= speed;
	      waveHeader.dataChunk.size /= speed;
	  }
	  else//error out if the user fails to specify a speed factor
	      fprintf(stderr, "A positive number must be supplied for the speed change\n");
	  break;
	}
	  
	case('f'):{//flip channel
	  temp = malloc(sizeof(short)*length);
	  if(temp==NULL)
	    fprintf(stderr, "Program is out of memory\n");
	  temp = rightChannel;
	  rightChannel = leftChannel;
	  leftChannel = temp;
	  break;
	}
	  
	case('o'):{//fade out
	  if(i+1 < argc){//checks if there is a factor at all after the flag
	    int fade = atof(argv[i+1]);
	    if(fade <= 0.0)//checks if given factor is valid 
	      fprintf(stderr, "A positive number must be supplied for fade in and fade out time\n");
	    else{
	      int time = sampleRate*fade;
	      rightChannel = fadeOut(rightChannel, time, length);
	      leftChannel = fadeOut(leftChannel, time, length);
	      i++;
	    }
	  }
	  else//error out if factor is invalid
	      fprintf(stderr, "A positive number must be supplied for fade in and fade out time\n");
	  break;
	}
	  
	case('i'):{//fade in
	  if(i+1 < argc){
	    double fadein = atof(argv[i+1]);
	    if(fadein <= 0.0)
	      fprintf(stderr, "A positive number must be supplied for fade in and fade out time\n");

	    else{
	      double time = sampleRate*fadein;
	      
	      int start = length-(int)time;
	      
	      rightChannel = fadeIn(rightChannel, start, length);
	      leftChannel = fadeIn(leftChannel, start, length);
	      i++;
	    }
	  }
	  else//error out if the user has not speicified a fade factor
	      fprintf(stderr, "A positive number must be supplied for fade in and fade out time\n");
	  break;
	}
	  
	case('v'):{//change volume
	  if(i+1 < argc){
	    double scale = atof(argv[i+1]);
	    if(scale<=0.0)
	      fprintf(stderr, "A positive number must be supplied for the volume scale\n");
	    else{
	      rightChannel = volume(rightChannel, length, scale);
	      leftChannel = volume(leftChannel, length, scale);
	    }
	  }
	  else//error out if the user has not speicified a volume factor
	    fprintf(stderr, "A positive number must be supplied for the volume scale\n");
	  break;
	}
	  
	case('e'):{
	  echo();
	  break;
	}
	  
	default:{//if the user has entered an invalid flag...
	  fprintf(stderr, "Usage: wave [-r] [-s factor] [-f] [-o delay] [-i delay] [-v scale] [-e delay scale] < input > output\n");
	  commandLine=1;//set commandLine flag to 1
	  break;
	}
	  
	}
      }
    }
    
    if(commandLine == 0){//the all commands are valid
      writeHeader(&waveHeader);//write the header
      
      for(i=0;i<length;i++){//loop through each array and convert the shorts to chars
	putShort(leftChannel[i]);
	putShort(rightChannel[i]);
      }
    }
  }

  //free free free
    free(leftChannel);
    free(rightChannel);
    return 0;
}

//reverse the channels
void reverse(short* leftChannel, short* rightChannel, int length){
  int i;
  for(i=0;i<length/2;i++){
    //one 3 line swap for each channel
    short temp = leftChannel[i];
    leftChannel[i] = leftChannel[length-i-1];
    leftChannel[length-i-1] = temp;

    temp = rightChannel[i];
    rightChannel[i] = rightChannel[length-i-1];
    rightChannel[length-i-1] = temp;
  }
}

//change the speed of the file by a given factor
short* changeSpeed(short* channel, int length, double speed){
  int newLength = length/speed;//gets the new length
  short* newChannel = malloc(sizeof(short)*newLength);//mallocs the new channel size

  int i;
  for(i=0;i<newLength;i++)
    //makes the index of newChannel the value of the old channel*factor
    newChannel[i] = channel[(int)(i*speed)];

  free(channel);
  return newChannel;
}

//fade in up to a given time
short* fadeIn(short* channel, double time, int length){
  int i;
  for(i=0;i<time;i++)
    channel[i] = channel[i] * ((i/time) * (i/time));
  
  return channel;
}

//fade out from a given time
short* fadeOut(short* channel, int startF, int length){
  int i;
  for(i=0;i<startF;i++)
    channel[length-startF+i] = channel[length-startF+i] * ((i/startF)*(i/startF));
  return channel;
}

//change the volume by a given factor
short* volume(short* channel, int length, double scale){
  int i;
  for(i=0;i<length;i++){
    if(channel[i]*scale <= SHRT_MAX & channel[i]*scale >= SHRT_MIN)
      channel[i] = channel[i]*scale;
  }
  return channel;
}

//sets a given delay for an echo effect
short echo(){
  fprintf(stderr, "Echoes\n");
}
