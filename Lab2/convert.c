#include <stdio.h>
#include "convert.h"

int main(){

  int c;

  c = getchar();
  while( (c != EOF) ){
    if(c != LF)/*uses the #define LF from convert.h in place of \r */
      putchar(c);
    c = getchar();
  }
  
  return 0;
}
