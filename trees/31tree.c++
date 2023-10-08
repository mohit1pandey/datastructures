//TO DELETE A NODE AT ANY POINT IN BST
#include<iostream>
using namespace std;
struct node{
    int data;
    node*left;
    node*right;
};

node*root;

/* get node */
node*get_node(int data){
node* temp=new node;   
temp->data=data;
temp->left=NULL;
temp->right =NULL;
return temp;
}

/* to insert a node*/
node* Insert(node*root,int data){
if(root==nullptr) root=get_node(data);
else if(data<=root->data){
    root->left=Insert(root->left,data);
}
else root->right=Insert(root->right,data);
return root;

}
/* find min */
node*find_min(node* root){
  while (root->left!=nullptr)
  {
    root=root->left;
  }
  return root;
}

/* to delete */
node*Delete(node*root,int data){
if (root==nullptr)return root;
else if(data<root->data) root->left=Delete(root->left,data);
else if(data>root->data) root->right=Delete(root->right,data);
else{
  /* hey we got the the nood */
  // case 0
  if(root->left==nullptr&&root->right==nullptr){
    delete(root);
    root=nullptr;
  }
  // case 1
  // only right subtree or child

  else if(root->left==nullptr){
    node*current=root;
    root=root->right;
    delete(current);

  }
  // only left subtree or child

  else if(root->right==nullptr){
    node*current=root;
    root=root->left;
    delete(current);
  }
// case 2
// both subtrees or child exist
 else{

node*temp=find_min(root->right);  // min of right sub tree and max of left subtree
root->data=temp->data;
root->right=Delete(root->right,temp->data);
 }

}
return root;
}

//Function to visit nodes in Inorder
void Inorder (node *root) {
if(root == NULL) return;

Inorder(root->left);       //Visit left subtree
printf("%d ",root->data);  //Print data
Inorder(root->right);      // Visit right subtree
}

int main(){

 root =nullptr;
root = Insert(root,5); root = Insert(root,10);
root = Insert(root,3); root = Insert(root,4);
root = Insert(root,1); root = Insert(root,11);

// Deleting node with value 5, change this value to test other cases
root = Delete(root,5);
root=Delete(root,11);

//Print Nodes in Inorder
cout<<"Inorder: ";
Inorder(root);
cout<<"\n";

  return 0;
}

