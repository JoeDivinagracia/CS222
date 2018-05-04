#include <stdio.h>
#incldude "stack.h"
#include "term.h"

double evaluate(Term terms[], int size);

int main(){

  return 0;
}

double evaluate(Term terms[], int size){
  Stack stack;
  stack->size = 0;
  stack->capacity =5;
  stack->values = malloc(sizeof(double)*stack->capacity);

  int i;
  for(i=0;i<size;i++){
    if(term[i].type == OPERAND){
      push(&stack, term[i].OPERAND);
    }
  }
  
}
