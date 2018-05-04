#include <stdio.h>
#include <string.h>

void backwards(char** argv, int count);
void reverse(char** argv, int count);
void sort(char** argv, int count);

int main(int argc, char** argv){
  int i=1,j;
    if(argv[1][0] == '-'){
      for(j=1;j!='\0';j++){
	if(argv[i][j] == 'b')
      	  backwards(argv, argc);
	else if(argv[i][j] == 'r')
	  reverse(argv, argc);
	else if(argv[i][j] == 's')
	  sort(argv, argc);
      }
    }
    for(i=1;i!='\0';i++)
      printf("%c", argv[1][i]);
    putchar('\n');
  return 0;
}

void backwards(char** argv, int count){
  char* temp;
  int i;
  for(i=0;i!='\0';i++)
    temp[i] = argv[1][i];
}

void reverse(char** argv, int count){

}

void sort(char** argv, int count){

}
