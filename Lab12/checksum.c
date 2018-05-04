#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char** argv){
  if(argc != 2)
    printf("Usage: ./checksum <filename>");

  else{
    char* fileName = argv[1];
    int file = open(fileName, O_RDONLY);
    if(file == 0)
      printf("./checksum: %s: No such file or directory.\n", fileName);

    else{
      unsigned char buffer;
      
      int bytes = 1;
      int numBytes=0;
      unsigned int sum = 0;
      while(bytes==1){
	bytes = read(file, &buffer, sizeof(char));

	if(bytes==1){
	  sum+=buffer;
	  numBytes++;
	}
      }
      
      int r = (sum%(2<<15)) + (sum/(2<<15));
      int s = (r%(2<<15)) + (r/(2<<15));

      
      int blocks = numBytes/512;

      if(numBytes%512 != 0)
	blocks++;
      
      printf("%d %d %s\n", s, blocks, fileName);
    }
    close(file);
  }
  return 0;
}
