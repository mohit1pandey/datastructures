/* INPLEMENTATION OF BINARY TREES WITH ITRATION */
#include<iostream>
using namespace std;

struct node{
int data;
node*right;
node*left;
};

node* root;

node*get_node(int data){
node *temp=new node;
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
}
void insert (int data){
if(root==NULL){
  root=get_node(data);
  return ;
}
node*current=root,*parent=NULL;
while (current!=NULL)
{
parent=current;
if(data<=current->data){
  current=current->left;
}
else{
  current=current->right;
}

}
if(data<=parent->data) parent->left=get_node(data);
else parent->right=get_node(data);
}

bool search(int data){
node *ptr=root;
while (ptr!=NULL)
{
  if(data<ptr->data)ptr=ptr->left;
  else if(data>ptr->data) ptr=ptr->right;
  else return true;
}
return false;

}
int main(){
root=NULL;
int n;cout<<"Enter the data Number: "<<endl;
cin>>n;
insert(15);
insert(10);
insert(17);
insert(9);
insert(20);
insert(2);

if(search(n))cout<<"found";
else cout<<"not found";

  return 0;
}



/* WITH OBJ ORIENTED LOOK */
// till I know if root is member variable of a class inrecurssion no arg can be passed so we use itration instead of 
// recursion
/*
#include<iostream>
using namespace std;
 struct node
 {
    int data;
    node*left;
    node*right;

    node(int data){
     this->data=data;
     this->left=nullptr;
     this->right=nullptr;
    } 
    };


class tree{
  public:
  node* root;
  tree(){
    root=nullptr;
  }
  void insert(int data){
    if(root==nullptr)root=new node(data);

    node*current=root;
    node*parent=nullptr;
    while (current!=nullptr)
    {
      parent=current;
      if(data<=current->data){
        current=current->left;
      }
      else current=current->right;
   
    }
    if (data<=parent->data) parent->left=new node(data);
    else parent->right=new node(data);

  }



bool search(int data){
node *ptr=root;
while (ptr!=NULL)
{
  if(data<ptr->data)ptr=ptr->left;
  else if(data>ptr->data) ptr=ptr->right;
  else return true;
}
return false;

}
 
 // to print the least 
 int least ( ) {
     if(root==nullptr)return -1;

    node*current=root;
    node*parent=nullptr;
    while (current!=nullptr)
    {
      parent=current;
      current=current->left;
    }
    return parent->data;

 }
 
int biggest(){
if(root==nullptr)return -1;
node*current=root,*parent=nullptr;
while (current!=nullptr)
{
  parent=current;
  current=current->right;
}
return parent->data;


}

};


 
int main(){
  tree t1;
  int n;
  cin>>n;
  t1.insert(50);
  t1.insert(40);
  t1.insert(60);
  t1.insert(30);
  t1.insert(70);
  t1.insert(15);
  t1.insert(80);
  
  cout<<t1.least();

  t1.search(n)?cout<<"found":cout<<"not found";
  cout<<t1.biggest();
    return 0;
}
*/