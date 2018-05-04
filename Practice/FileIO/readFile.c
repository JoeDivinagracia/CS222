#include <stdio.h>

int main(){
  printf("Enter a file name: ");
  char fileName[100];
  scanf("%s", fileName);

  FILE* file = fopen(fileName, "r");
  int total;
  fscanf(file, "%d", &total);

  int i;
  int number, sum=0;

  for(i=0;i<total;i++){
    fscanf(file, "%d", &number);
    sum += number;
  }

  double average = (double)sum/total;
  
  printf("Avergae: %f\n", average);
  
  fclose(file);
  return 0;
}
