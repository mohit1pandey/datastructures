// heap insert

#include<iostream>
#include <algorithm>
using namespace std;


class minheap{
int* arr;
int size;
int capacity;

int left(int i){
return (2*i+1);
}

int right(int i){
return (2*i+2);
}

int parent(int i){
return ((i-1)/2);
}


public:
 minheap(int n){         // n is the maxsize of heap
 arr=new int[n];         // dyanmic value
 size=0;                 // initalize the heap as blank 
 capacity=n;  
            // max size
 }


void insert(int val){

if (size==capacity) {
    cout<<"heap is empty";
    return;
    }

size++;
arr[size-1]=val;
for(int i=size-1;i>0; i=parent(i)){
    if (arr[parent(i)]>arr[i]){
   
    swap(arr[parent(i)],arr[i]);   // stl    means parent(i)= i; we do not need to write
    
    }                           
  
}

}

void print(){

for(int i=0;i<size;i++)
cout<<arr[i]<<" , ";
}

};



int main(){
    int m;
    cout<<"enter the size of max heap";
    cin>>m;
minheap m1(m);
int arr[9]={10,20,15,40,50,100,25,45,12};
 for(int i=0;i<9;i++){
    m1.insert(arr[i]);
 }
 m1.insert(17);
 m1.print();
    return 0;
}




//while loop

/*
void insert(int val){
    if (size==capacity) {
        cout<<"heap is full";
        return;
    }
    size++;
    arr[size-1]=val;
    int i = size - 1;
    while (i != 0 && arr[parent(i)] > arr[i]) {
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}
*/