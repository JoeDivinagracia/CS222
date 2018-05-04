#include <stdio.h>

void makeLower(char* letter);

int main(){
  char thing = 'P';
  printf("Uppercase: %c\n",thing);
  makeLower(&thing);
  printf("Lowercase: %c\n",thing);
  
  return 0;
}

void makeLower(char* letter){
  if(*letter >= 'A' && *letter <= 'Z')
    *letter+=('a'-'A');
}
