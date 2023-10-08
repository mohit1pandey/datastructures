// find first repeting value
#include<iostream>
#include<unordered_map>

using namespace std;

class umap{
// to make umap
public:

int f_repiting(int a[],int n){
unordered_map<int,int>ump;

  for (int i=0;i<n;i++){
    
    int key=a[i];
    ump[key]++;

  }  

  for(int i=0;i<n;i++){
   int key =a[i];
   
   if(ump[key]>1) return key;


  }
 return -1;
   
}




};


int main(){

    umap m;
  int arr[10]={-1,-5,0,2,3,5,2,8,5,6};
  cout<<m.f_repiting(arr,10);
    return 0;
}