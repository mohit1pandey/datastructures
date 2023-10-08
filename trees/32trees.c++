/* C++ program to find Inorder successor in a BST */

#include<iostream>
using namespace std;
struct node{
int data;
node*right;
node*left;

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
/* find node */
node* find_node(node* root,int data){
if(root==nullptr)return nullptr;
else if(root->data==data)return root;
else if(root->data<data) return find_node(root->right,data);
else return find_node(root->left,data);

}
/* find min */
node*find_min(node* root){
   if(root==nullptr)return nullptr;
   while (root->left!=nullptr)
   {
    root=root->left;

   }
   return root;
   
}
/* grt inorder successor */  // we have deceresed the running time by O(n) to O(log n)= O(h)

node* get_successor(node*root,int data){
node*current=find_node(root,data);  
if(current==nullptr)return nullptr;
/* has right subtree */
else if(current->right!=nullptr){
    return find_min(current->right);
}
/* has no right subtree */ 
else {
node* ancestor=root;
node*successor=nullptr;
while (ancestor!=current)
{
    // when the data is grater then the ancestor.data
    if(current->data<ancestor->data){
        successor=ancestor;
        ancestor=ancestor->left;
    }
    //when the data is less then the ancestor.data
    else{
       ancestor=ancestor->right;

    }
   
}

 return successor;
}

}

 
//Function to visit nodes in Inorder
void Inorder(node *root) {
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

//Print Nodes in Inorder
	cout<<"Inorder Traversal: ";
	Inorder(root);
	cout<<"\n";


// successor
node* successor=get_successor(root,3);
if(successor==nullptr)cout<<" no successor found ";
else cout<<successor->data;
    return 0;
}




