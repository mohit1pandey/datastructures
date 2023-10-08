// insertion at any given pos
//NOTE in doubly linked list without creating a list insersion at nth is kinda imposible  
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* link;
};
node* head;
void insert(int data,int pos){
node * temp= new node;
temp->data=data;
temp->link=NULL;
if (pos==1)
{   temp->link=head;
    head=temp;
    return;
}
node *temp2=head;
for (int  i = 1; i < pos-1; i++)//if there are 3 nodes we have to traverse at the 2nd node
{
 temp2=temp2->link;            //temp2==first node
}
temp->link=temp2->link;       // condition false: temp2 is inceremanted and reprentes 2nd node
temp2->link=temp;
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
   head=NULL;
    insert(23,1);
    insert(33,2);
    insert(55,3);        //output: 23 33 55 
    insert(66,2);        //output: 23 66 33 55
     print();
    return 0;
}