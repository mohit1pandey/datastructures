#include <iostream>
using namespace std;

struct node{
int data;
node*link;
};
node*front,*rear;


bool isempty(){
if(front==NULL&&rear==NULL)
return true;
else return false;

}

void enqueue(int data){
node*temp=new node;
temp->data=data;
temp->link=NULL;
if(isempty()) {
    front=rear=temp;
     return;
}
 
 rear->link=temp;
 rear=temp;


}
void dequeue(){
node*ptr=front;
if(isempty()){
    cout<<"Queue is empty "<<endl;
    return;
}
if(front== rear){
    front=NULL;
    rear =NULL;
    cout<<"Queue is empty "<<endl;
}
else {
    front=front->link;
    
}
delete(ptr);

}
int at_front(){
return front->data;
}

void print(){
node*ptr=front;
while (ptr!=NULL)
{
    cout<<ptr->data;
    ptr=ptr->link;
}

}

int main(){
front=rear=NULL;

enqueue(1);
enqueue(2);
dequeue();
dequeue();
enqueue(3);
enqueue(4);
print();
    return 0;
}