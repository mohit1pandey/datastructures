//deletion of nth node
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
void Delete(int pos){
node*temp1,*temp2;
temp1=head;
if (pos==1)
{
  head=temp1->link;
  delete(temp1);
  return;
}
for (int  i = 0; i < pos-2; i++)
{
    temp1=temp1->link;
}
temp2=temp1->link;
temp1->link=temp2->link;
delete(temp2);

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
Delete(3);
print();
return 0;

}
/*
algorithm
1. creat linkd list
2. define delete function
  {
   1: access the n-1th element (temp1)
   2: then with this access the nth element(temp2=temp1->link)
   3: do temp1.link=temp2.link;
   4: delete temp2
*/