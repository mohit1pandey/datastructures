//creation of a linled list
//insertion a node at nth pos
#include<iostream>
using namespace std;
//a node in a linked list
struct node
{
    int data;
    node*prev;
    node* next;
};
node * head;  //globle declaration
node*get_node(int data){
    node*temp=new node;
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insert(int data){          //creation of a list of n nodes
node*temp=get_node(data);
if (head==NULL)
{
head=temp;
return;
}
node*ptr=head;
while (ptr->next!=NULL)
{
 ptr=ptr->next;
}
ptr->next=temp;
temp->prev=ptr;
return;
}
void insert_at_n(int pos,int data){    //insert at nth pos
  node*temp=get_node(data);
  if (head==NULL)                      //when list is empty or not crated
  { cout<<"list is empty"<<endl;
    return;
  }
  else if (pos==1)
  {
    temp->next=head;
    head->prev=temp;
    head=temp;
  }
   
  node*ptr1=head,*ptr2;                //at inside any hth
  int i=1;
  for ( i = 1; i <=pos-2; i++)   //pos-1 ascess
  {
    ptr1=ptr1->next;
  }
ptr2=ptr1->next;
ptr1->next=temp;
ptr2->prev=temp;
temp->prev=ptr1;
temp->next=ptr2;

}


void print(){         //to print
    node*ptr=head;
    while (ptr!=NULL)
    { 
        cout<<ptr->data;
     ptr=ptr->next;
    }
    

}
int main(){
    head = NULL;
   int i,n,data;
   insert_at_n(1,7);
   cout<<"how many nodes "<<endl;
   cin>>n;
   cout<<"insert the data "<<endl;
   for ( i = 1; i <=n; i++)
   {
    cin>>data;
    insert(data);
   }
   insert_at_n(1,7);
   insert_at_n(3,9);
  


   print();


    return 0;

}
/*
NOTE: we cannot insert a node at nth pos till the boubly linklist in creataed but in case of singly linked list not true
#nclude<iostream>
using namespace std;
struct node
{
    int data;
    node*prev;
    node*next;
};
node* get_node(int data){
node*temp=new node;
temp->data=data;
temp->next=NULL;
temp->prev=NULL;
return temp;
}
node*insert(node*head,int pos,int data){          //creation of a list of n nodes
node*temp=get_node(data);
if (pos==1)
{
  temp->next=head;
head->prev=temp;   //head ponints to unknown location so head->prev,head->next does not exist 
head=temp;
return head;
}
node*ptr=head;
 node*ptr1=head,*ptr2;                //at inside any hth
  int i=1;
  for ( i = 1; i <=pos-2; i++)   //pos-1 ascess
  {
    ptr1=ptr1->next;
  }
ptr2=ptr1->next;
ptr1->next=temp;
ptr2->prev=temp;   //ptr2 doesnot exit ERROR
temp->prev=ptr1;
temp->next=ptr2;

return head;
}
void print(node*head){         //to print
    node*ptr=head;
    while (ptr!=NULL)
    { 
        cout<<ptr->data;
     ptr=ptr->next;
    }
}
int main(){
   node*head=NULL;
   head=insert(head,1,1);
  head=insert(head,1,2);
  head=insert(head,3,3);
  head=insert(head,4,3);
   print(head);


    return 0;
}
*/