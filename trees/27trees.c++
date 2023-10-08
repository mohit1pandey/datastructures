// TO GET THE HEIGHT OF A BINARY TREE
#include<iostream>
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
/* to get the height */
int  tree_height(node* root){
	 if(root==nullptr)return -1;
    
    else return(max(tree_height(root->left),tree_height(root->right))+1);

}

int main(){
root=nullptr;
root=insert(root,40);                                                 
root=insert(root,20);                           
root=insert(root,30);                          
root=insert(root,50);                      
root=insert(root,70);                           
root=insert(root,10);                           
root=insert(root,5);   
root=insert(root,2);      

cout<<tree_height(root);
	return 0;
}



