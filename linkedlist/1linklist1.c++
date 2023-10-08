//at the bigening
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* link;

};
node * head;
void insert(int data){
node* temp=new node;
temp->link=NULL;
temp->data=data;
if (head!=NULL)
{
    temp->link=head;

}

head=temp;

}
void print (){
node* temp1;
temp1=head;
while (temp1!=NULL)
{

 cout<<temp1->data;
 temp1=temp1->link;
};


}
int main(){
   head =NULL;
   insert(10);
   insert(60);
   insert(90);
   insert(70);
   
   print();


    return 0;
}
/*   with looop

#include<iostream>
using namespace std;
struct node
{
   int data;
   node* link;

};
node* head;

void insert(int x){
node* temp=new node;        //node* temp=(node*) malloc(sizeof(node));
temp->link=NULL;
temp->data=x;
if (head!=NULL)
{
    temp->link=head;
}

head=temp;
}
void print(){

node* temp1;
temp1=head;
void print(){
node* ptr=head;           //NEW IMPLEMENTAION OF Print();
while (ptr->link!=NULL)
{
    cout<<ptr->data;
ptr=ptr->link;

}
    cout<<ptr->data;
}int main(){
    
    head=NULL;
int i,n,x;   
5cout<<"how many elements"<<endl;
cin>>n;
for ( i = 0; i < n; i++)
{   cin>>x;
    insert(x);
}
cout<<"THE LIST IS"<<endl;
print();


    return 0;
}

*/



// when head is an local variable

/*
#include<iostream>
using namespace std;
struct node
{
   int data;
   node* link;

};

node* insert(node*head,int x){
node* temp=new node;        //node* temp=(node*) malloc(sizeof(node));
temp->link=NULL;
temp->data=x;
if (head!=NULL)
{
    temp->link=head;
}

head=temp;
return head;
}
void print(node* head){
                    
while (head!=NULL)          //no need to write temp now head itself is a temp;
{
    cout<<head->data; 
    head=head->link;
    cout<<" ";
}
cout<<head->link;
}
int main(){
   node* head; 
    head=NULL;
int i,n,x;   
cout<<"how many elements"<<endl;
cin>>n;
for ( i = 0; i < n; i++)
{   cin>>x;
    head=insert(head,x);   //head is now re-modefied
}
cout<<"THE LIST IS"<<endl;
print(head);  //print needed to take head as arg so the insert function should return the modified head;


    return 0;
}

*/