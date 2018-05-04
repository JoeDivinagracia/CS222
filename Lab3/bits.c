#include <stdio.h>

int readInt(){
  int c = 0;
  int i = 0;

  while( (c=getchar())!= EOF && c != '\n' ){
    if(c>='0' && c <= '9')
      i = i*10+(c-'0');
  }

  return i;
}


int main(){

  int value=0;
  char choice;
  int bit=0;
  int newValue=0;
  int setBit;
  
    printf("Enter an integer: ");
    value = readInt();

    printf("Do you want to set, unset, or flip a bit? (s, u, f): ");

    choice = getchar();
    readInt();
    printf("Which bit? (0-31): ");
    bit=readInt();

    setBit = 1 << bit;
    
    if(choice == 's')
      printf("The result of setting bit %d in %d is %d\n",bit, value, (value|setBit));
    
    else if(choice == 'u')
      printf("The result of unsetting bit %d in %d is %d\n",bit, value, (value&(~setBit)));
    
    else if(choice == 'f')
      printf("The result of flipping bit %d in %d is %d\n",bit, value, (value^setBit));
      
    else
      printf("Invalid input. Try again.\n");
  return 0;
}
