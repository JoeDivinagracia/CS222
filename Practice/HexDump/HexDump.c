#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
  printf("What file do you want to open? ");
  char fileName[256];
  scanf("%s", fileName);

  //Low-level I/O returns file descriptor
  int fd = open(fileName, O_RDONLY);
  unsigned char buffer[16];
  
  int bytes=16;;
  int place = 0;
  
  while(bytes==16){
    bytes = read(fd, buffer, sizeof(char)*16);    
    printf("0x%06x :", place);
    place+=bytes;

    int i;
    for(i=0;i<bytes;i++)
      printf(" %02x ", (unsigned int)buffer[i]);
    printf("\n");
  }
  close(fd);
  return 0;
}
