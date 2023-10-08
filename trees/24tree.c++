/* BINARY SEARCH TREE WITH RECURSION */
// if we have used the obj oriented apreoach so we need to decelare root as local of main which is quite complicated
#include<iostream>
using namespace std;

struct bstNode
{
 int data;
 bstNode*left;
 bstNode*right;
};
/*To get node */ 
bstNode* get_node(int data){
bstNode* temp=new bstNode;   
temp->data=data;
temp->left=NULL;
temp->right =NULL;
return temp;
}
/* to add a node in tree with recursion   */
bstNode* insert(bstNode* root,int data){
 if(root== NULL) {
    root=get_node(data);
 }
else if(data<=root->data){
    root->left=insert(root->left,data);
}
else root->right=insert(root->right,data);
return root;
}

/*to find any element*/

bool search(bstNode*root,int data){
    if(root==NULL)return false;
    else if(root->data==data)return true;
    else if(data<=root->data){
        return(search(root->left,data));

    }
    else return search(root->right,data);
}

int main(){
  bstNode * root=NULL;
 int n;cin>>n;
 root=insert(root,20);
 root=insert(root,15);
 root=insert(root,30);
 root=insert(root,35);

  if(search(root,n)==true) cout<<"found ";
  else cout<<"not found";

    return 0;
}