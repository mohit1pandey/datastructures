// linked list implemantation
#include <iostream>
using namespace std;

struct  node
{
    int data;
    node* link;
};
node* top;
void push(int data){
node*temp=new node;
temp->data=data;
temp->link=NULL;
 temp->link=top;
 top=temp;

}
void pop(){
    node*ptr;
    ptr=top;
top=top->link;
delete(ptr);
}
int Top(){
    return top->data;
}
bool isempty(){
    if (top==NULL)return true;
    return false;
}
void print (){
node* temp1;
temp1=top;
while (temp1!=NULL)
{

 cout<<temp1->data<<" ";
 temp1=temp1->link;
 
}
cout<<endl;
}


int main(){
  top=NULL;
 push(10);
 push(20);
 push(30);
 push(40);
 push(50);

  print();
  pop();
  print();
  cout<<Top();
    return 0;
}