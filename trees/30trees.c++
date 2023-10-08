// TO CKECK THAT WEATHER THE TREE IS BST OR NOT
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
node* insert(node*root,int data){
if(root==nullptr) root=get_node(data);
else if(data<=root->data){
    root->left=insert(root->left,data);
}
else root->right=insert(root->right,data);
return root;

}

bool is_tree_greater(node*root,int value);

/* is whole sub trees every_node->data <= the data of  root node */
bool is_tree_lesser(node*root,int value){
if(root==nullptr)return true;
else if(root->data<=value
&& is_tree_lesser(root->left,value)
&&is_tree_greater(root->right,value)
){
    return true;
}
else return false;
}

/* to check the data in every right subtree is greater or not*/
bool is_tree_greater(node*root,int value){
if(root==nullptr)return true;
else if(root->data>value
&&is_tree_lesser(root->left,value)
&&is_tree_greater(root->right,value)
){
    return true;
}
else return false;
}



/* to check for binry tree */

bool is_binaryS_tree(node* root){
    if(root==nullptr)return true;
     else if(is_tree_lesser(root->left,root->data)
    &&is_tree_greater(root->right,root->data)
    &&is_binaryS_tree(root->left)
    &&is_binaryS_tree(root->right)){
        return true;
    }
    else return false;

}



int main(){
root=nullptr;

 root=insert(root,20);
 root=insert(root,15);
 root=insert(root,30);
 root=insert(root,35);

cout<<is_binaryS_tree(root);

    return 0;
}