// intersection
// considering all values are distinct

#include<iostream>
#include<unordered_set>
#include <vector>

using namespace std;

class uset {
vector<int>insertion;

public:

void insertsen(int a[],int b[],int m,int n){
// a umap

unordered_set<int>mp;
  for(int i=0;i<m;i++){

    mp.insert(a[i]);
  }


  for(int i=0;i<n;i++){
   int key = b[i];

  if(mp.find(key)!=mp.end()){
     
     insertion.push_back(key);  // common key inserted in vector
     } 

  }
   

}

 void print_common(){

    for(auto it : insertion)
    {
        cout<<it;
    }
 }
};



int main(){

int arr1[5]={1,5,7,3,2};
int arr2[5]={5,8,1,7,3};
 
 uset m1;
 m1.insertsen(arr1,arr2,5,5);
  m1.print_common();
return 0;
}



// this is ok till we have non repeting values

/*
int arr1[5]={1,5,7,3,5};
int arr2[5]={5,8,1,7,5};
 fail
 
 */