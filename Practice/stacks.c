#include <stdio.h>
#include <stdlib.h>

int global = 10;

int main(){
  int stack = 5;
  int* heap = malloc(sizeof(int)*100);
  printf("Stack: %p\n", &stack);
  printf("Heap: %p\n", heap);
  printf("Gloabl: %p\n", &global);
  printf("text: %p\n", main);
  return 0;
}