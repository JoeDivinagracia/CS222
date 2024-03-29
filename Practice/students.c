#include <stdio.h>
#include <math.h>
#include <string.h>

struct student{
  char name[100];
  double GPA;
  int ID;
};


int main(){
  struct student roster[100];
  int total,i,j;
  scanf("%d", &total);
  
  for(i=0;i<total;i++){
    scanf("%s", roster[i].name);
    strcat(roster[i].name, " ");
    int length = strlen(roster[i].name);
    scanf("%s", roster[i].name+length);

    scanf("%lf", &roster[i].GPA);
    scanf("%d", &roster[i].ID);
  }

  for(i=0;i<total;i++){
    int min = i;
    for(j=i+1;j<total;j++){
      if(roster[j].GPA < roster[min].GPA)
	min = j;

      struct student temp = roster[min];
      roster[min] = roster[i];
      roster[i] = temp;
    }
  }

  
  for(i=0;i<total;i++){
    printf("%d %s: %lf\n", roster[i].ID, roster[i].name, roster[i].GPA);
  }
  
  return 0;
}
