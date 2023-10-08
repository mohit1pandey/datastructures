// binary heap implementation
#include<iostream>
using namespace std;


class minheap{
int* arr;
int size;
int capacity;

public:
 minheap(int n){         // n is the maxsize of heap
 arr=new int[n];         // dyanmic value
 size=0;                 // initalize the heap as blank 
 capacity=n;             // max size
 }
// returns the index of the left child
int left(int i){
return (2*i+1);
}

int right(int i){
return (2*i+2);
}
int parent(int i){
return ((i-1)/2);
}

};



int main(){


    return 0;
}