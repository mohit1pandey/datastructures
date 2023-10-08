// implementation by circular array
#include<iostream>
#define max_size 51
using namespace std;

class queue{
int a[max_size];
int front;
int rear;

bool is_full(){
if((rear+1)%max_size==front) return true;
else return false;
}
public:
queue(){
    front=-1;
    rear=-1;
}

bool is_empty(){
if(front==-1&&rear==-1) return true;
else return false;
}

void enqueue(int x){
 if(is_full()){
    cout<<" Queue is full ";
    return;
  }
 else if(is_empty()){
    front=0;
    rear= 0;
 }
 else rear=(rear+1)%max_size;

 a[rear] =x;
}
void dequeue(){
  if(is_empty()){
    cout<<"Queue is empty "<<endl;
   return;  
  }
  else if (front==rear)
 {
    front=-1;
    rear=-1;
    cout<<"Queue is empty again "<<endl;
 }
 else{
  front=(front+1)%max_size;
 }
}
int Front(){
     if(front==-1) {
        cout<<"Queue is empty ";
        return -1;
     }
     return a[front];
     }

void print(){
int count=(rear+max_size-front)%max_size+1;
int i;
  for ( i = 0; i < count; i++)
  {
    int index=(front+i)%max_size;
    cout<<a[index];
  }
  


}


};

int main(){
   queue q;
   q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);
   q.enqueue(4);
   q.enqueue(5);
   q.enqueue(6);
   q.enqueue(7);
   q.dequeue();
q.print();

    return 0;
}