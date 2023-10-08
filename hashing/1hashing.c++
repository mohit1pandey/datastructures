// first non repeating element

#include<iostream>
#include<unordered_map>

using namespace std;

class umap{
public:

int non_rep(int* arr,int n){

unordered_map<int,int>m1;

for(int i=0;i<n;i++){

 int key = arr[i];
  m1[key]++;    // m1 [key]  eg it key =-1 then the m1[key] will be incemented
}


for(int i=0;i<n;i++){
int key = arr[i];

auto it =m1.find(key);   // now this it is pointing to the location where the value is saved

 if (it->second==1) return key;               // m1[key]
 //if(m1[key]==1) return key;               // m1[key]

}
return -1;
}

};




int main(){

int arr[5]={-1,2,3,-1,2};

umap u;
cout<<u.non_rep(arr,5);




    return 0;
}