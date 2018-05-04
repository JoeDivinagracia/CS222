#include <stdio.h>
#include <stdlib.h>

typedef struct _LinkNode{
  int data;
  struct _LinkNode* next;
}LinkNode;

LinkNode* add(LinkNode* head, int value);
LinkNode* delete(LinkNode* head, int value);
void print(LinkNode* head);
void empty(LinkNode* head);

LinkNode* head = NULL;

void userChoice(){
  int choice;
  
  do{
    printf("1. Add new element\n2. Delete element\n3. Print list\n4. Exit\n");
    scanf("%d", &choice);

    switch(choice){
    case(1):
      printf("Enter a value: ");
      int value;
      scanf("%d", &value);
      head = add(head, value);
      break;
    case(2):
      printf("Enter an element to delete: ");
      int element;
      scanf("%d", &element);
      head = delete(head, element);
      break;
    case(3):
      print(head);
      break;
    }
    printf("\n");
  }while(choice!=4);
  empty(head);
}

LinkNode* add(LinkNode* head, int value){
  LinkNode* node = malloc(sizeof(LinkNode));
  node->data = value;
  node->next = head;
  head = node;
  return head;
}

LinkNode* delete(LinkNode* head, int value){
  if(head == NULL)
    return NULL;

  else if(head->data == value){
    LinkNode* newHead = head->next;
    free(head);
    return newHead;
  }

  else{
    LinkNode* temp = head;
    
    while(temp->next != NULL){
      if(temp->next->data == value){
	LinkNode* removeNode = temp->next;
	temp->next = temp->next->next;
	free(removeNode);
	return head;
      }
      temp = temp->next;
    }
  }  
  return head;
}

void print(LinkNode* head){
  LinkNode* temp = head;  
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void empty(LinkNode* head){
  LinkNode* temp = head;
  while(temp!=NULL){
    temp = temp->next;
    free(temp);
  }
}

int main(){
  userChoice();
  return 0;
}
