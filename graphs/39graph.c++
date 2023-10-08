#include<iostream>
#include<vector>
using namespace std;
int find_judge(vector<vector<int>>&trust,int n){
  
  vector<int>trusts(n+1,0);
  vector<int>trusted(n+1,0);
for (int i = 0; i<trust.size() ; i++)
{
 vector<int>&t= trust[i];
  trusts[t[0]]++;
  trusted[t[1]]++;
}
for (int i = 1 ;i <=n; i++)
{
if(trusts[i]==0 && trusted[i]==n-1)return i;

}
return -1;
}


int main(){
   vector<vector<int>>trust={{1,3},{1,4},{2,3},{2,4},{4,3}};
   
cout<<find_judge(trust,4);

return 0;
}