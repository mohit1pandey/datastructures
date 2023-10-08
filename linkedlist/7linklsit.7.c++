//reversal using recursion
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* link;    
};
node* insert (node* head,int data ){
 node *temp = new node;
 temp->data=data;
temp->link=NULL;
if (head==NULL)
{
    head= temp;
return head;
}
node*ptr= head;
while(ptr->link!=NULL){
ptr=ptr->link;
}
ptr->link=temp;

return head;

}
void print(node* ptr ){
    
    if (ptr==NULL)
    {
        return;
    }
    else{
        cout<<ptr->data;
        print(ptr->link);
    }

}
node* revs_link(node* ptr ){
   node* head;
   if (ptr->link==NULL)
   {
    head=ptr;
    return head;
   }
   head=revs_link(ptr->link);//revs_link(ptr->link);
   node* temp=ptr->link;   
   temp->link=ptr;
   ptr->link=NULL;
   return head;
}

int main(){
  node* head=NULL;
head=insert(head,2);
head=insert(head,4);
head=insert(head,5);
head=insert(head,6);
print(head);cout<<endl;
head= revs_link(head);
 print(head);
    return 0;
}