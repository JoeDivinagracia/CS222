#include <stdio.h>

long long factorial(int amount);

int readInt(){
  int c = 0;
  int i = 0;

  while( (c=getchar())!=EOF && c!='\n' ){
    if(c>='0' && c <= '9')
      i = i*10+(c-'0');
  }
  return i;
}

int main(){
  int rows;
  printf("How many rows of Pascal's Triangle do you want to output?(0-20):  ");
  rows = readInt();

  if(rows>0 && rows<=20){
     int i,j;
     for(i=0;i<=rows;i++){
       for(j=0;j<=i;j++){
         printf("%lld ",factorial(i)/( (factorial(i-j)*factorial(j) ) ) );
       }
       printf("\n");
     }
  }

  else if(rows<0 || rows > 20)
    printf("Invalid input\n");
  return 0;
}

/*
Should be recursive
Takes in amount of rows as input  
*/
long long factorial(int n){
  if(n==0 || n==1) return 1;
  else
    return n*factorial(n-1);
}

