//disjoint sets DS

#include<iostream>
#include<vector>
using namespace std;
#define PARENT 0
#define RANK 1


class disjoint{

vector<vector<int>>dset;
int n;
public:

disjoint(int n){
    this->n=n;                    // provide the no of vertex
    dset.resize(n);
    for(int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            dset[i].resize(2);
            dset[i][PARENT]=-1;    // set the parent as -1
            dset[i][RANK]=0;        // rank as 0
            }
    }
    }


int find(int i){
 
   if(dset[i][PARENT]==-1){
    return i; 
   }
   return find(dset[i][PARENT]);   // recursivly call the function till we get the parent

}

void unite(int u,int v){
// if u's rank > v's rank
    u=find(u);                        // we need to compare the rank of the parent 
    v=find(v);                        // so do this 

    if(dset[u][RANK]>dset[v][RANK]){
        dset[v][PARENT]=u;
    }
    else if(dset[u][RANK]<dset[v][RANK]){
        dset[u][PARENT]=v;
    }
    else{
          dset[v][PARENT]=u;                  // if the reank of both parents increment
          dset[u][RANK]++;
    }

}

};




int main(){
int n;
cin>>n;   // no of edges
disjoint d1(n);              // as all elements are disjoint perform union
d1.unite(0,1);
d1.unite(2,3);
d1.unite(4,5);
d1.unite(6,7);
d1.unite(0,2);

int i; cout<<" enter the value to get the parent ";
cin>>i;
cout<<d1.find(i);



return 0;
}
