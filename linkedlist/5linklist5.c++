//reverse of a linked list
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* link;
};
node*head;
void insert(int data){
node*temp =new node;
temp->data=data;
temp->link=NULL;
if(head==NULL){
head=temp;
return;
}

node* temp1=head;
while (temp1->link!=NULL)   //         while (temp1!=NULL)
{                           //         {
  temp1=temp1->link;        //         temp1=temp1->link;   //not good beacuse head will return the addres of anknown (type) location
}                           //         }
temp1->link=temp;           //         temp1=temp; 

}

void print(){
node* ptr=head;
while (ptr!=NULL)
{cout<<ptr->data;
ptr=ptr->link;

}
}
void rvrs_link(){
node*prev,*curr,*next;
curr=head;
prev=NULL;
while (curr!=NULL)
{
  next=curr->link;
  curr->link=prev;
  prev=curr;//1
  curr=next;//2
}
head=prev;

}

int main(){

int i,n,x;   
cout<<"how many elements"<<endl;
cin>>n;
for ( i = 0; i < n; i++)
{   cin>>x;
    insert(x);
}
cout<<"THE LIST IS"<<endl;
print();
cout<<endl<<"the reverse list ";
rvrs_link();
print();


  return 0;
}
