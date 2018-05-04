#include <stdio.h>

typedef struct _Tree{
  int data;
  struct _Tree* left;
  struct _Tree* right;
}Tree;

Tree* find(Tree* root, int value){
  if(root == NULL)
    return NULL;
  else if(value == root->data)
    return root;
  else if(value < root->data)
    return find(root->left, value);
  else
    return find(root->right, value);
}

Tree* add(Tree* root, int value){
  if(root == NULL){
    Tree* temp = malloc(sizeof(Tree));
    temp.data = value;
    temp.left = NULL;
    temp.right = NULL;
    root = temp;
    return temp;
  }
  else if(value < root->data)
    root->left = add(root->left, value);
  else
    root->right = add(root->right, value);
  return root;
}



int main(){

  return 0;
}
