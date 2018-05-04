#include <string.h>
#include "Student.h"
#include <stdlib.h>

Student* findMin(Student *root, Student *parent);
Student* insert(Student** root, Student* node){
  if((*root)==NULL){
    node->left = NULL;
    node->right = NULL;
    (*root) = node;
  }
  else if( strcmp(node->last, (*root)->last) == 0 && strcmp(node->first, (*root)->first) == 0)
    return NULL;
  else if( strcmp(node->last, (*root)->last) < 0)
    (*root)->left = insert(&(*root)->left, node);
  else
    (*root)->right = insert(&(*root)->right, node);
  return (*root);
}
  
Student* search(char* first, char* last, Student* root){
  if(root == NULL)
    return NULL;
  else if(strcmp(last, root->last) == 0 && strcmp(first, root->first) == 0)
    return root;
  else if(strcmp(last, root->last) < 0 || (strcmp(last, root->last) == 0 && strcmp(first, root->first) < 0))
    return search(first, last, root->left);
  else if(strcmp(last, root->last) > 0 || (strcmp(last, root->last) == 0 && strcmp(first, root->first) > 0))
    return search(first, last, root->right);
}

Student* delete(Student* root, char* first, char* last){
	Student* temp = root;
	Student* temp2;
	if(root == NULL)
		return NULL;
		
	else if (strcmp(last, temp->last) < 0 || (strcmp(last, temp->last) == 0 && strcmp(first, temp->first) < 0))
		temp->left = delete(temp->left, first, last);
	else if (strcmp(last, temp->last) > 0 || (strcmp(last, temp->last) == 0 && strcmp(first, temp->first) > 0))
		temp->right = delete(temp->right, first, last);
	else{
		if(temp->left == NULL){
			return temp->right;
		}else if(temp->right == NULL){
			return temp->left;
		}else{
			temp2 = findMin(temp->right, temp);
			temp2->left = temp->left;
			temp2->right = temp->right;
			return temp2;

	
		}
		


	}
	return root;

}

Student* findMin(Student *root, Student *parent) {

   if (root->left != NULL) {
      return findMin(root->left, root); 
   }
	if(parent->right == root)
		parent->right = root->right;
	else
		parent->left = root->right;


   return root;
}








