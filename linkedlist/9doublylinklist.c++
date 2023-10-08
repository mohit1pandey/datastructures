// doubly linked list with tail
#include<iostream>
using namespace std;
struct node
{
 int data;
 node*prev;
 node* next;
};
node*head,*tail;         //has hesd and tail both in it
node* get_node(int data){
node*temp=new node;
temp->data=data;
temp->next=NULL;
temp->prev=NULL;
return temp;
}
void insert_at_end(int data){
    node*temp=get_node(data);
if (head==NULL)
{ 
head=temp;
 temp->prev=NULL;
 temp->next=NULL;
 tail=temp;
 return;
};
node*ptr=head;
while (ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
temp->prev=ptr;
tail=temp;
return;



}
void print_tail(node* edge){
    node*ptr=edge;
    while (ptr!=NULL)
    { printf("%d",ptr->data);
        ptr=ptr->prev;
    }
    
}
void print_head(node* edge){
    node*ptr=edge;
    while (ptr!=NULL)
    { printf("%d",ptr->data);
        ptr=ptr->next;
    }
    
}





int main(){
head=NULL;tail=NULL;  
insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(4);
    insert_at_end(5);
     print_head(head);   //can traverse the link from head to print forward element
     cout<<endl;       
     print_tail(tail);   //can traverse the link from tail to print revarse  element
    return 0;
}
   
/* 
hence we dont need to reverse the list 
*/
//insretion at nth eleent
//deletion of nth element
