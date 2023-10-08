//deletion at any point
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
/*  to delete at head */

void remove_at_head(){// remove_at_haed(){
head=head->next;     //   node*temp=head;
delete(head->prev);  //   head=head->next;
head->prev=NULL;    //    delete temp;
}                   //    head->prev=NULL;  }
 

/* to delete at nth pos */
void delete_at_n(int pos){
 node*ptr=head;
 while (pos>1)
 {
  ptr=ptr->next;
  pos--;
 }
 node*ptr2=ptr->prev;
  ptr2->next=ptr->next;
  ptr->next->prev=ptr2;
  delete ptr;
}
/*delete at end */
 void delete_at_end(){
  node*ptr=head,*ptr2;

while (ptr->next!=NULL)
{
 ptr=ptr->next;

}
ptr2=ptr->prev;
ptr2->next=NULL;
delete(ptr);

}

/* to print */
void print(){         
    node*ptr=head;
    while (ptr!=NULL)
    { 
        cout<<ptr->data;
     ptr=ptr->next;
    }
    cout<<endl;

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
   print();
  remove_at_head();  
    print();
   delete_at_n(3);
   print();
   delete_at_end();
   print();
}
