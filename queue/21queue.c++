/* A LIST WITH A CONSTEAINTE OR RESTRICTION THAT INSERTION REAR DELETION MUST HAVE DONE AT FRONT IS QUEUE */
//ARRAY BASED IMPLEMENTION
/*  
functions :
Is_empty();
Enqueue();
Dequeue();
Front();   constant time taking O(1)
*/
#include<iostream>
using namespace std;
#define max_size 51     // max i=50 => max rear= 50
class queue{
    int a[max_size];
    int front ;
    int rear;
    //set to be private
    bool is_full(){
        if(rear==max_size-1)return true;
        else return false;
    }
    public:
    // constructor to initialise
    queue(){
     front=-1;
     rear=-1;
    }

    // returns the queue is empty or not

    bool is_empty(){
    if(front==-1&&rear==-1) return true;
    else return false;
    }

    // to add an data

    void enqueue(int x){
    if(is_full()){ 
        cout<<"queue is full ";
        return; //exception
    }
     else if(is_empty()){
         front=0;
         rear=0;
      }
     else{
        rear++;
        } 

     a[rear]=x;

    }

    // to delete

    void dequeue(){
     if(is_empty()){
        cout<<"queuse is empty ";
        return;}
     else if(front==rear){
        front=-1;
        rear =-1;
        cout<<"now queue is empty again ";
     }
     else{
      front++;
     }

    }

    // gets the value of front

    int Front(){
     if(front==-1) {
        cout<<"Queue is empty ";
        return -1;
     }
     return a[front];
     }

    // not queue member but used

    void print(){
        int i;
    if(front==-1) {
        cout<<"Queue is empty ";
        cout<< -1;
        return;
     }
        for (int i = front; i <= rear; i++)
        {
            cout<<a[i];
        }
            cout<<a[i];
        
    }
};
int main(){
    queue q;
    
    q.print();
    return 0;
}
