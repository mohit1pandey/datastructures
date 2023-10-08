// sub array with the sum 0
// in O(n)
// will use refix sum array
// but it may be defficult to print element 
#include<iostream>
#include<unordered_set>
using namespace std;

class sol{

 unordered_set<int>s1;   // we will provide the hash value of the prefix sum
 public:
 
 bool is_subarr(int * arr,int n){
  
  int prefix=0;
  for(int i=0;i<n;i++){
   
   prefix +=arr[i];
  
   if(prefix==0){
    return true;
   }
   else if (s1.find(prefix)!=s1.end()){
   
     return true;

   }
   s1.insert(prefix);
  }

 return false;
 }




};

int main(){


int n=6;
int arr[6]={10,20,-10,-5,-5,10};
sol s;

cout<<s.is_subarr(arr,6);
    return 0;
}





// it's time complexity is O(n^2)

/*
#include<iostream>
using namespace std;


void is_sub_0(int *arr,int n){

for(int i=0;i<n;i++){
  int sum=0;
 for(int j=i;j<n;j++){

    sum += arr[j];
   
    if (sum==0){
       cout<< "found";
       for(int k=i;k<=j;k++){           // i value is initial and j value is final 
        cout<< arr[k]<<" ";
       }
        return ;
    }
 }

}


}



int main(){


int n=6;
int arr[6]={10,20,-10,-5,-5,10};

is_sub_0(arr,6);
    return 0;
}

*/