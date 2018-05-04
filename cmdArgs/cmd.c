#include <stdio.h>

int main(int argc, char** argv){
  int i;
  //starting at 1 does not display the ./exe command
  for(i=1;i<argc;i++)
    printf("%s\n", argv[i]);
  return 0;
}
