// reversal print using recurssion
 #include<iostream>
 using namespace std;

 struct node{
int data;
node* link;
 };
 node* insert(node* head,int data){
node*temp=new node;
temp->data=data;
temp->link=NULL;
if (head==NULL)
{
head=temp;
}else{
node*ptr=head;
while (ptr->link!=NULL)
{
 ptr=ptr->link;
}
ptr->link=temp;

}
return head; 
}
void print(node* head){    //printing via reversal
node* ptr=head;
 if (ptr==NULL)
 {
   return;
 }
 
 cout<<ptr->data;
 print(ptr->link);
}
void revs_print(node* head){    //printing via reversal    
node* ptr=head;                 // using recursion
 if (ptr==NULL)
 {
   return;
 }
 
 revs_print(ptr->link);
 cout<<ptr->data; 
}




 int main(){
 node* head=NULL,*x;  
 int data;
 x=insert(head,1);//head=insert(head,1)  //head=insert(head,1)
 x=insert(x,2);   //head=insert(head,2)  //x=insert(x,1)
 x=insert(x,3);   //head=insert(head,3)  //x=insert(x,1)
 x=insert(x,4);   //head=insert(head,4)  //x=insert(x,1)
 print(x);        //print(head)          //print(x)
 cout<<endl;
 revs_print(x);
    return 0;
 }