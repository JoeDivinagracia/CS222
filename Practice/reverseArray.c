#include <stdio.h>

void reverse(int array[], int length);
void print(int array[], int length);

int main(){
  int values[100];
  int i;
  for(i=0;i<100;i++)
    values[i] = i+1;
  print(values,100);
  reverse(values,100);
  print(values,100);
  return 0;
}

void reverse(int array[], int length){
  int i;
  for(i=0;i<=length/2;i++){
    int temp = array[i];
    array[i] = array[length-1-i];
    array[length-1-i] = temp;
  }
}

void print(int array[], int length){
  int i;
  for(i=0;i<length;i++){
    if(i==length-1)
      printf("%d\n", array[i]);
    else
      printf("%d, ", array[i]);
  }
  putchar('\n');
}
