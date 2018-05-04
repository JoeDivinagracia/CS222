#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"
#include "trees.c"

void add(char* firstName, char* lastName, int points, int year, char* house, Student** houses);
void changePoints(Student** root, int points);
void clean(Student* root);
void inorder(Student* root, int index);
void preorder(Student* root, int index);
void postorder(Student* root, int index);
void save(Student* root, FILE* file);
void printStudent(const Student* student);
int sumScore(Student* root);
int findIndex(char* house);


int main(){  
  Student* gryffindor = NULL;
  Student* ravenclaw = NULL;
  Student* hufflepuff = NULL;
  Student* slytherin = NULL;
  Student* deceased = NULL;
  //array that holds the houses
  Student* houses[5] = {gryffindor, ravenclaw, hufflepuff, slytherin, deceased};
  
  //used to check if the specified house is a valid house
  int houseFlag, i;
  char command[100];  
  char firstName[100];
  char lastName[100];
  int points;
  int year;
  char house[100];
  int index;
  
  //loops through all of the options until the user quits
  do{
    houseFlag=0;
    printf("Enter command: ");
    scanf("%s", command);

    //prints out the help menu
    if(strcmp(command, "help")==0){
      printf("help\nPrints this display\n");
      printf("\nload <filename>\nAdds the contents of a file to the current roster\n");
      printf("\nsave <filename>\nSaves the current roster to a file\n");
      printf("\nclear\nClear the current roster\n");
      printf("\ninorder\nPrint out an inorder traversal for each house\n");
      printf("\npreorder\nPrint out a preorder traversal for each house\n");
      printf("\npostorder\nPrint out a postorder traversal for each house\n");
      printf("\nadd <firstname> <lastname> <points> <year> <house>\nAdds a student to the roster\n");
      printf("\nkill <firstname> <lastname> <house>\nMoves a student to the deceased list\n");
      printf("\nfind <firstname> <lastname> <house>\nSearches for a student in a house\n");
      printf("\npoints <firstname> <lastname> <house> <points>\nChanges the points a student has earned by a specified amount\n");
      printf("\nscore\nLists the point totals for all four houses\n");
      printf("\nquit\nQuits the program\n\n");
    }
    //loads a specified file into the roster
    else if(strcmp(command, "load")==0){
      char fileName[100];
      scanf("%s", fileName);
      FILE* file = fopen(fileName, "r");
	
      if(file!=NULL){
	//reads in student data and adds to the roster until EOF
	while(!feof(file)){
	  fscanf(file, "%s %s %d %d %s", firstName, lastName, &points, &year, house);
	  int index = findIndex(house);
	  add(firstName, lastName, points, year, house, houses);
	}  
	printf("Successfully loaded data from %s\n", fileName);
	
      }
      else
	printf("Load failed. Invalid file: %s\n", fileName);

      fclose(file);
    }
    else if(strcmp(command, "save")==0){
       char fileName[100];
       scanf("%s", fileName);
       FILE* file = fopen(fileName, "w");

       //if the specified fileName is invalid
       if(file == NULL)
	 printf("Save failed. Invalid file: %s.\n", fileName);

       else{
	 //calls save function
	 save(houses[0], file);
	 save(houses[1], file);
	 save(houses[2], file);
	 save(houses[3], file);
	 
	 printf("Successfully saved data to %s.\n", fileName);
       }
       fclose(file);
    }

    //clears and frees the data from the roster
    else if(strcmp(command, "clear")==0){
      clean(gryffindor);
      clean(ravenclaw);
      clean(hufflepuff);
      clean(slytherin);
      clean(deceased);
    }

    //inorder travseral for each house and the deceased tree
    else if(strcmp(command, "inorder")==0){
      printf("Inorder print-out of roster:\n\n");
      for(i=0;i<HOUSES;i++){
	printf("\n%s House\n\n", HOUSE_NAMES[i]);
	inorder(houses[i], i);
      }
      printf("\nDeceased\n\n");
      inorder(deceased, i);
    }
    
    //preorder travseral for each house and the deceased tree
    else if(strcmp(command, "preorder")==0){
      printf("Preorder print-out of roster:\n\n");
      for(i=0;i<HOUSES;i++){
	printf("\n%s House\n\n", HOUSE_NAMES[i]);
	preorder(houses[i], i);
      }
      printf("\nDeceased\n\n");
      inorder(deceased, i);
    }
    
    //postorder travseral for each house and the deceased tree
    else if(strcmp(command, "postorder")==0){
      printf("Inorder print-out of roster:\n\n");
      for(i=0;i<HOUSES;i++){
	printf("\n%s House\n\n", HOUSE_NAMES[i]);
	inorder(houses[i], i);
      }
      printf("\nDeceased\n\n");
      inorder(deceased, i);
    }

    //adds a student to the roster
    else if(strcmp(command, "add")==0){
      scanf("%s", firstName); 
      scanf("%s", lastName);
      scanf("%d", &points);
      scanf("%d", &year);
      scanf("%s", house);

      int index = findIndex(house);
      if((year>0 && year<=7) && (index!=-1)){
	add(firstName, lastName, points, year, house, houses);
	printf("Added %s %s to roster.\n", firstName, lastName);
      }
    }

    //moves a student to the list of deceased students
    else if(strcmp(command, "kill")==0){
      Student* temp;
      scanf("%s", firstName);
      scanf("%s", lastName);
      scanf("%s", house);

      int index = findIndex(house);
      temp = search(firstName, lastName, houses[index]);
      houses[index] = delete(houses[index], firstName, lastName);
      temp->left = NULL;
      temp->right == NULL;
      insert(&deceased, temp);
    }

    //finds a specified student
    else if(strcmp(command, "find")==0){
      Student* temp;
      scanf("%s", firstName);
      scanf("%s", lastName);      
      scanf("%s", house);

      int index = findIndex(house);
      if(index<0 || index>3)
	printf("Find failed. Invalid house: %s\n", house);
      else{
	temp = search(firstName, lastName, houses[index]);
	if(temp==NULL)
	  printf("Find failed. %s %s was not found in %s House.\n", firstName, lastName, house);
	else
	  printStudent(temp);
      }
    }

    //updates a student's points by a specified amount
    else if(strcmp(command, "points")==0){
      Student* temp;
      scanf("%s", firstName);
      scanf("%s", lastName);
      scanf("%s", house);
      scanf("%d", &points);

      int index = findIndex(house);
      if(index<0 || index>3)
	printf("Point change failed. Invalid house: %s.\n", house);
      else{
	temp = search(firstName, lastName, houses[index]);
	if(temp==NULL)
	  printf("Point change failed. %s %s not found in %s House.\n",firstName, lastName, house);
	else{
	  changePoints(&temp, points);
	  printf("Points for %s %s changed to %d.\n", firstName, lastName, points);
	}
      }
    }

    //prints the total scores for each house
    else if(strcmp(command, "score")==0){
      int score = 0;
      printf("Gryffindor: %d\n", sumScore(houses[0]));
      printf("Ravenclaw: %d\n", sumScore(houses[1]));
      printf("Hufflepuff: %d\n", sumScore(houses[2]));
      printf("Slytherin: %d\n", sumScore(houses[3]));
    }

    //prints if specified command is unknown
    else if(strcmp(command, "quit") != 0){
      fprintf(stderr,"Unknown command: %s\n", command);
      while(getchar() != '\n')
	getchar();
    }
  }while(strcmp(command, "quit") != 0);

  clean(gryffindor);
  clean(ravenclaw);
  clean(hufflepuff);
  clean(slytherin);
  clean(deceased);
  printf("All data cleared.\n");

  return 0;
}

int findIndex(char* house){
  if(strcmp(house, "Gryffindor") == 0)
    return 0;
  else if(strcmp(house, "Ravenclaw") == 0)
    return 1;
  else if(strcmp(house, "Hufflepuff") == 0)
    return 2;
  else if(strcmp(house, "Slytherin") == 0)
    return 3;
  else
    return -1;
}

//adds a student with all specified characteristics
void add(char* firstName, char* lastName, int points, int year, char* house, Student** houses){
  Student* node = malloc(sizeof(Student));

  int index = findIndex(house);
  if(index<0 || index>3){
    printf("Add failed. Invalid house: %s.\n", house);
    return;
  }
  
  if(year<0 || year>7){
    printf("Add failed. Invalid year.\n");
    return;
  }

  node->first = strdup(firstName);
  node->last = strdup(lastName);
  node->points = points;
  node->year = year;
  node->house = index;

  //calls insert on the desired house and the node
  houses[index] = insert(&houses[index], node);
}

//recursively cleans the root it's called with 
void clean(Student* root){
  if(root != NULL){
    clean(root->left);
    clean(root->right);
    free(root);
  }
}

//used to print student info for every student in the roster
void printStudent(const Student* student){
  char* name = strdup(student->first);
  strcat(name, " ");
  strcat(name, student->last);

  printf("%-25s\t\tPoints: %d\tYear: %d House: %s\n", name, student->points, student->year, HOUSE_NAMES[student->house]);
}

//recursive inorder traversal
void inorder(Student* root, int index){
  if(root!=NULL){
    inorder(root->left, index);
    printStudent(root);
    inorder(root->right, index);
  }
}

//recursive preorder traversal
void preorder(Student* root, int index){
  if(root!=NULL){
    printStudent(root);
    preorder(root->left, index);
    preorder(root->right, index);
  }
}

//recursive postorder traversal
void postorder(Student* root, int index){
  if(root!=NULL){
    postorder(root->left, index);
    postorder(root->right, index);
    printStudent(root);
  }
}

void changePoints(Student** root, int points){
  (*root)->points += points;
}

//sums the points for all students in a house
int sumScore(Student* root){
  if(root==NULL)
    return 0;
  return (root->points + sumScore(root->left)+sumScore(root->right));
}

//writes student data to the spcified file
void save(Student* root, FILE* file){ 
  if(root!=NULL){
    fprintf(file, "%s %s %d %d %s\n", root->first, root->last, root->points, root->year, HOUSE_NAMES[root->house]);
    save(root->left, file);
    save(root->right, file);
  }
}
