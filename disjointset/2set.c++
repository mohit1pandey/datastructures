#include<iostream>
#include<utility>
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

// cycle detection in undirected graph

bool cycel_exist(vector<pair<int,int>> &p1) {
    
    for(auto it: p1){
     int i = find(it.first);
     int j = find(it.second);
    
    if(i==j)return true;

    unite(i,j);
    }
return false;

}




};




int main(){
int n;
n=5;   // no of vertices
disjoint d1(n);              // as all elements are disjoint perform union

// now make a edge list 
vector<pair<int,int>>edge_list={{0,1},{2,3},{1,3},{1,4},{0,2}};

d1.cycel_exist(edge_list)?cout<<"found":cout<<"not found";




return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

#define PARENT 0
#define RANK 1

vector<vector<int>> dset;

int find(int v)
{
    if (dset[v][PARENT] == -1)
        return v;
    return dset[v][PARENT] = find(dset[v][PARENT]); // path compression
}

void union_op(int i, int j)
{
    i = find(i);
    j = find(j);

    // union by rank
    if (dset[i][RANK] > dset[j][RANK])
        dset[j][PARENT] = i;
    else if (dset[i][RANK] < dset[j][RANK])
        dset[i][PARENT] = j;
    else
    {
        dset[i][PARENT] = j;
        dset[j][RANK] += 1;
    }
}

bool iscyclic(vector<pair<int, int>>& edge_list)
{
    for (auto p : edge_list)
    {
        int i = find(p.first);
        int j = find(p.second);

        if (i == j)
            return true;

        union_op(i, j);
    }
    return false;
}

int main()
{
    int e, v;
    cin >> e >> v;

    dset.resize(v, vector<int>(2, -1));

    vector<pair<int, int>> edge_list;
    for (int i = 0; i < e; ++i)
    {
        int from, to;
        cin >> from >> to;
        edge_list.push_back({from, to});  // edge_list.push_back(make_pair(from, to));
    }

    if (iscyclic(edge_list))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
*/