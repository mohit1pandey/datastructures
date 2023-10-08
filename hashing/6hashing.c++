// find the complement
// if n=10 and n=a+b and given a=8 find b if exist
#include<iostream>
#include<unordered_map>
using namespace std;

class umap{
public:

void complement(int arr[], int n,int value){
// i need to create an umap   
unordered_map<int,int>m1;
  for(int i=0;i<n;i++){
    int key = arr[i];
    m1[key]++;
  }

  for(int i=0;i<n;i++){
   int comp1=arr[i];
   int comp2=value-comp1;

   auto it=m1.find(comp2);        // key ka address (basically)
    
    if(comp1==comp2 && m1[comp1]>1){   // if both equal then frequency should be more then 1
        cout<<"comp1= "<<comp1;
        cout<<"comp2= "<<comp2;
        
        return;
     }
    else if (it!=m1.end()&& m1[comp1]==1){   // the first part is found  and the key is only 1
        if(comp1==comp2){                    // wether both are same 
            cout<<"no complements found"; 
         return;
        }
         cout<<"comp1= "<<comp1;             // if not return the values
         cout<<"comp2= "<<comp2;
        
         return;

    }
    
    }
    

  }

};



int main(){

int arr[8]={4,5,7,4,5,2,8,7};
umap m1;
m1.complement(arr,8,10);

    return 0;
}