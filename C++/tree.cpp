#include <iostream>
using namespace std;

struct TreeNode{
  int value;
  TreeNode* left;
  TreeNode* right;
};

void insert(TreeNode* &root, int data){
  if(root == NULL){
    root = new TreeNode();
    root->value = data;
    root->left = NULL;
    root->right = NULL;
  }

  else if(data < root->value)
    return insert(root->left, data);
  else
    return insert(root->right, data);
}

void inorder(TreeNode* root){//doesn't use &root because you dont want to change value of root
  if(root!=NULL){
    inorder(root->left);
    cout << root->value << endl;
    inorder(root->right);
  }
}

void clean(TreeNode* &root){//use '&root' when you want to change the parameter
  if(root!=NULL){
    clean(root->left);
    clean(root->right);
    delete root;
    root = NULL;
  }
}

int main(){
  TreeNode* root = NULL;

  int numbers;
  cout << "How many numbers do you want? ";
  cin >> numbers;

  for(int i=0;i<numbers;i++){
    int add;
    cout << "Number " << i+1 << ": ";
    cin >> add;
    insert(root, add);
    
  }

  cout << "Values in the tree:" << endl;
  inorder(root);
  clean(root);
  return 0;
}
