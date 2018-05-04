#include <stdio.h>
/* Sort this shit bitch deadass*/
void selectionSort(int array[], int size);
void printArray(int array[], int size);

int readInt(){
  int c=0;
  int total=0;

  while( (c=getchar()) != EOF && c!='\n'&& c!=' '){
    if(c>='0' && c<='9')
      total=total*10+(c-'0');
  }
  return total;
}

int main(){
  int values[100];
  int size = 0;

  do{
    printf("Enter an integer (0-100): ");
    size = readInt();
   }while(size>100);

  int i;
  
  printf("Enter %d positive integers\n",size);
  for(i=0;i<size;i++)
    values[i] = readInt();

  /*finds max and min of the array*/
  int max = values[0];
  int min = values[0];
  double mean = values[0];
  
  for(i=1;i<size;i++){
    if(values[i] > max)
      max = values[i];
    if(values[i] < min)
      min = values[i];

    mean+=values[i];
  }

  mean/=size;

  double variance = 0.0;
  for(i=0;i<size;i++){
    variance += (values[i] - mean)*(values[i]-mean);
  }

  printArray(values,size);
  selectionSort(values, size);
  printArray(values,size);

  double mode, median;

  if(size%2==0)
    median = .5*(values[size/2]+values[(size/2)-1]);
 else
   median = values[size/2];
  
  printf("\nMax: %d\nMin: %d\nMean: %.2f\nVariance: %.2f\nMode: %.2f\nMedian: %.2f\n", max, min, mean, variance, mode, median);
  return 0;
}

void selectionSort(int array[], int size){
  int i,j,smallest;
  
  for(i=0;i<size;i++){
    smallest = i;
    for(j=i+1;j<size;j++)
      if(array[j] < array[smallest])
	smallest = j;

      int temp = array[i];
      array[i] = array[smallest];
      array[smallest] = temp;
  }  
}

void printArray(int array[], int size){
  int i;
  putchar('\n');
  for(i=0;i<size;i++)
    printf("%d ", array[i]);
  putchar('\n');
}
