// adding node at the end
//to creat a linked list of n elements
#include<iostream>
using namespace std;
struct node
{
  int data;
  node* link;

};
node*head;


void add_at_end(int data){
node*temp,*ptr;
ptr=head;
temp=new node;
temp->data=data;
temp->link=NULL;
while (ptr->link!=NULL)
{
  ptr=ptr->link;

}
ptr->link=temp;

}
void print (){
node* temp1;
temp1=head;
while (temp1!=NULL)
{

 cout<<temp1->data<<" ";
 temp1=temp1->link;
 
}

}

int main(){
head=NULL;
int x,i,n;
cout<<"how many element ?"<<endl;
cin>>n;
cout<<"enter the elements "<<endl;
cin>>x;
node*temp=new node;
temp->data=x;
temp->link=NULL;
head=temp;

for ( i = 1; i <n; i++)
{
  cin>>x;
  add_at_end(x);

}
cout<<"the list is ";
print();

return 0;
}
//first creat first node (line 45)
// then call add_at_end (x);


//with head tail method
/*
#include<iostream>
using namespace std;
struct node
{
 int data;
 node*link;

};
node*head,*tail;
void insert(int data){
node*temp=new node;
temp->data=data;
temp->link=NULL;
if (head==NULL)
{
    head=temp;
    tail=temp;
}
else
{
    tail->link=temp;
    tail=temp;
}



}

void print (){
node* temp1;
temp1=head;
while (temp1!=NULL)
{

 cout<<temp1->data<<" ";
 temp1=temp1->link;
};
}

int main(){
head=NULL;
int x,i,n;
cout<<"how many element ?"<<endl;
cin>>n;
cout<<"enter the elements "<<endl;


for ( i = 1; i <=n; i++)
{
  cin>>x;
  insert(x);

}
cout<<"the list is ";
print();


    return 0;
}
*/