//daubly linkedlist

//creation of a linled list
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

void insert_at_head(int data){   //insertion at head
node*temp=get_node(data );
if (head==NULL)
{
head =temp;
}
else{
temp->next=head;
head->prev=temp;
head=temp;
}

}
 void insert_at_end(int data){  //inserton at tail
node*temp=get_node(data ),*ptr;
while (ptr->next!=NULL)
{
 ptr=ptr->next;
}
ptr->next=temp;
temp->prev=ptr;
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
   cout<<"how many nodes "<<endl;
   cin>>n;
   cout<<"insert the data "<<endl;
   for ( i = 1; i <=n; i++)
   {
    cin>>data;
    insert(data);
   }
   insert_at_head(1); 
   insert_at_end(4);
   print();


    return 0;

}
/*
1. cration
2. insertion at end at head
3. printing 
 */