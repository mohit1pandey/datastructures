/*  PREORDER INORDER POSTORDER TREVERSAL */
#include<iostream>
#include<queue>
using namespace std;

struct node{
int data;
node*right;
node*left;
}; 
node*root;

node*get_node(int data){
	node*temp=new node;
	temp->data=data;
	temp->left=nullptr;
	temp->right=nullptr;
	return temp;
}

node* insert(node*root,int data){
    if(root== nullptr) root=get_node(data);
    
	else if(data<=root->data){
		root->left=insert(root->left,data);
	}
	else root->right=insert(root->right,data);
   
   return root;
}
void preorder(node* root){       // DLR
    if (root==nullptr){
        return;
    }
   cout<<root->data;
   preorder(root->left);
   preorder(root->right);
    
}
void postorder(node* root){       // LRD
    if (root==nullptr){
        return;
    }
   postorder(root->left);
   postorder(root->right);
   cout<<root->data;
    
}
void inorder(node* root){       // LDR
    if (root==nullptr){
        return;
    }
   inorder(root->left);
   cout<<root->data;
   inorder(root->right);
    
}

int main(){
    root=nullptr;
    root=insert(root,50);
    root=insert(root,40);
    root=insert(root,60);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,20);
    root=insert(root,10);
     cout<<"Hello "<<endl;
    cout<<"preorder  ";
     preorder(root);
     cout<<endl<<"postorder ";
     postorder(root);
     cout<<endl<<"inorder   ";
     inorder(root);
    return 0;
}
