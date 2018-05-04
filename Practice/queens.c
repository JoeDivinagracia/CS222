#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

int attacks(char** board){
  int i,j,k;
  
  for(i=0;i<SIZE;++i){
    for(j=0;j<SIZE;++j){
      if(board[i][j] == 'Q'){
	//same col
	for(k=0;k<i;k++)
	  if(board[k][j] == 'Q')
	    return 1;
	//same row
	for(k=0;k<j;k++)
	  if(board[i][k] == 'Q')
	    return 1;
	
	for(k=0;k<i;k++){
	  int difference = i-k;
	  if((j+difference<SIZE) && board[k][j+difference] == 'Q')
	    return 1;
	}
	for(k=0;k<i;k++){
	  int difference = i-k;
	  if((j-difference>=0) && board[k][j-difference]=='Q')
	     return 1;
	}
      }
    }
  }
}

int main(){
  //can cast before malloc but do not have to
  char** board = malloc(sizeof(char*)*SIZE);
  int i,j;
  
  for(i=0;i<SIZE;i++)
    board[i] = malloc(sizeof(char)*SIZE);

  srand(time(NULL));

  for(i=0;i<SIZE;i++)
    for(j=0;j<SIZE;j++){
      int value = rand()%SIZE;
      if(value == 0)
	board[i][j] = 'Q';
      else
	board[i][j] = ' ';
    }

  
  return 0;
}
