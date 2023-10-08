// heap sort
#include<iostream>
#include<algorithm>
#define MAX_CAP 100
using namespace std;


class max_heap{
int* arr;
int size;
int capacity;

int left(int i){ return (2*i+1);}

int right(int i){return (2*i+2);}

int parent(int i) {return ((i-1)/2);}

public:
max_heap(int* harr,int x){
arr=harr;
size =x;
capacity =MAX_CAP;
}

void heapify(int i){
int lf= left(i); int rh= right(i); 
int largest= i;
if(lf<size && arr[lf]>arr[i]){
    largest =lf;
}
if(rh<size && arr[rh]>arr[largest])     /* arr[rh] is showing the right side ki value and smallest is left */
{
largest=rh;
}

if(i!=largest){
    swap(arr[i],arr[largest]);
    heapify(largest);
}
}

void built_heap(){
int start= (size-2)/2;               // will take us at the parent of the last element 

for(int i= start; i>=0;i--){

    heapify(i);
}


}

/* to print */

void print(){

for(int i=0;i<size;i++)
cout<<arr[i]<<" ";
}


/*heap sort*/

void sort_hp() {
    built_heap();
    int m=size;
   while (size !=0)
   {
    swap(arr[size-1],arr[0]);
    size--;
    heapify(0);
   }
   size=m;
}

};


int main(){

 int b_heap[8]={7,9,17,13,14,20,18,19};     
int size = sizeof(b_heap)/sizeof(int);
 max_heap h1(b_heap,size);

h1.built_heap();
h1.print();
cout<<endl;
h1.sort_hp();
h1.print();

}
