// now we are about to make a function called the build heap based on heapify 
// improved virsion of heapify
#include<iostream>
#include<algorithm>
#define max_size 100
using namespace std;

class heap{

int *arr;
int size;
int capacity;

/* private functions */
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

heap(int* d_heap,int x){
arr= d_heap;     // constructor 
size = x;
capacity = max_size;
}
/* it will used to cerat heap fo a given array in O(n)*/
/* private it */
private:
void heapify(int i){

int lf= left(i); int rh= right(i);       /* i index ki lift and right values */
int smallest =i;
 
if(lf<size && arr[lf]<=arr[smallest]){
    smallest =lf;
}
if(rh<size && arr[rh]<=arr[smallest])     /* arr[rh] is showing the right side ki value and smallest is left */
{
smallest=rh;
}

if(i!=smallest){
    swap(arr[i],arr[smallest]);
    heapify(smallest);
}
}

/* public it */
public:

/* build heap */
void built_heap(){
int start= (size-2)/2;               // will take us at the parent of the last element 

for(int i= start; i>=0;i--){

    heapify(i);
}


}


/* to print */

void print(){

for(int i=0;i<size;i++)
cout<<arr[i];
}


};

int main(){

 int b_heap[8]={20,9,7,2,14,17,6,19};     
int size = sizeof(b_heap)/sizeof(int);
 heap h1(b_heap,size);

h1.built_heap();

h1.print();

    return 0;

}