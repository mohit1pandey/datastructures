//revarsal of a linked list
//by stacks
#include<iostream>
#include<stack>
using namespace std;
/* creation of a linked list */

struct node
{
    int data;
    node* link;
};
node*head;
stack<node*>s1;         //stack of node* values

void insert(int data){
node*temp =new node;
temp->data=data;
temp->link=NULL;
if(head==NULL){
head=temp;
return;
}

node* temp1=head;
while (temp1->link!=NULL)   
{                         
  temp1=temp1->link;        
}                           
temp1->link=temp;           
}
/* reverse function */

void reverse(){
node*ptr=head;
while (ptr!=NULL)     //filling the stack with node*
{ 
    s1.push(ptr); 
    ptr=ptr->link;
}

ptr=s1.top(); head=ptr;
s1.pop();
while (!s1.empty())    
{
  ptr->link=s1.top();
  s1.pop();
  ptr=ptr->link;
}
ptr->link=NULL;




}
/* print */
void print(){
node* ptr=head;
while (ptr!=NULL)
{cout<<ptr->data;
ptr=ptr->link;

}
cout<<endl;
}
int main(){
    head=NULL;
insert(1);
insert(2);
insert(3);
insert(4);
insert(5);
print();
reverse();
print();
    return 0;
}