#include <stdio.h>
#include <stdlib.h>
//assume lists are sorted
void merge(int array1[], int length1, int array2[], int length2, int result[]);

int main(){
  int length1, length2;
  scanf("%d", &length1);

  scanf("%d", &length2);

  int resultLength = length1+length2;
  int* array1 = malloc(sizeof(int)*length1);
  int* array2 = malloc(sizeof(int)*length2);
  
  int i=0,j=0;

  while(i<length1){
    int num1;
    scanf("%d", &num1);
    array1[i] = num1;
    i++;
  }

  while(j<length2){
    int num2;
    scanf("%d", &num2);
    array2[j] = num2;
    j++;
  }

  printf("List1: ");
  for(i=0;i<length1;i++)
    printf("%d ", array1[i]);
  printf("\nList2: ");
  for(j=0;j<length2;j++)
    printf("%d ", array2[j]);

  int* result = malloc(sizeof(int) * resultLength);

  merge(array1, length1, array2, length2, result);

  printf("\nMerged list: ");
  for(i=0;i<resultLength;i++)
    printf("%d ", result[i]);
  
  free(array1);
  free(array2);
  free(result);
  
  putchar('\n');
  return 0;
}


void merge(int array1[], int length1, int array2[], int length2, int result[]){
  int indexA=0, indexB=0, i;
  
  for(i=0;i<length1+length2;i++){
    if(indexA >= length1){
      result[i] = array2[indexB];
      indexB++;
    }
    else if(indexB >= length2){
      result[i] = array1[indexA];
      indexA++;
    }
    else if(array1[indexA] <= array2[indexB])
      result[i] = array1[indexA++];
    else
      result[i] = array2[indexB++];
  }
}
