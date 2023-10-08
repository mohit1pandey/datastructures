// get min and extact min

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

void heapify(int i){

int lf= left(i); int rh= right(i);       /* i index ki lift and right values */
int smallest =i;
 
if(lf<size && arr[lf]<arr[i]){
    smallest =lf;
}
if(rh<size && arr[rh]< arr[smallest])     /* arr[rh] is showing the right side ki value and smallest is left */
{
smallest=rh;
}

if(i!=smallest){
    swap(arr[i],arr[smallest]);
    heapify(smallest);
}
}

/* to print */

void print(){

for(int i=0;i<size;i++)
cout<<arr[i];
}


/* get min */

void get_min(){
    cout<<arr[0];
}

/*extract min*/

void extract_min(){

swap(arr[0],arr[size-1]);
size--;
heapify(0);

}


};

int main(){

 int b_heap[8]={7,9,17,13,14,20,18,19};     
int size = sizeof(b_heap)/sizeof(int);
 heap h1(b_heap,size);
 //h1.get_min();
h1.extract_min();
h1.print();

    return 0;
}