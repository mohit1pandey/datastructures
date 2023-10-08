/* LEAVEL ORDER TREVERSAL */
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

void level_order(node*root){
    if(root==nullptr)return;
    queue<node*>q;
    q.push(root);
    //root is pushed into quqeue
    while (!q.empty())
    {
        node*current=q.front();
        
        q.pop();  //pop the element
        cout<<current->data<<" ";
       if(current->left!=nullptr){
        q.push(current->left);
       }
       if(current->right!=nullptr){
        q.push(current->right);
       }
    }
    
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
     cout<<"hello";
     level_order(root); 
    return 0;
}
