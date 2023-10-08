// union of two sets

#include<iostream>
#include<unordered_set>

using namespace std;

class solution{
   
unordered_set<int>s1;
public:

void uinte(int a[],int b[],int m, int n){

   for(int i=0;i<m;i++){

    s1.insert(a[i]); 

   } 

   for(int i=0;i<n;i++){

    s1.insert(b[i]);

   } 


}

void print_uset(){
for(auto it=s1.begin();it != s1.end();it++){
  cout<< *it;                       // first second se koi matlab nhi hai 
}
}
};



int main(){

int arr1[5]={1,5,7,3,6};
int arr2[5]={5,8,1,7,2};

solution s1;
s1.uinte(arr1,arr2,5,5);
s1.print_uset();

    return 0;
}