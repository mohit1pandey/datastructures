/* implementation using vectors */
#include<iostream>
#include<vector>
using namespace std;

class graph{   // class to represent a graph
int v;
vector<int>* adj;    // an pointer array stores the addresses of vector<int> obj 
public:
graph(int v){        //constructor
    this->v=v;
    adj= new vector<int>[v];    // dynamic vector whose each element is an obj to vecot <int>  class
}
void add_edge(int u,int v){
    adj[u].push_back(v);        /* because the graph is non-dirctionl*/
    adj[v].push_back(u);
}
void print(){
    for (int i = 0; i < v; i++)         // itreate over the pointer array
    {
        for (int j = 0; j<adj[i].size(); j++)   // itrate on the pointer array 
        {
            cout<<adj[i][j];         
            cout<<" ";
        }
        
    }
    
    
}
/* to check that is there is an edge b/w two nodes or not */
bool is_edge(){
    int u,v;
    cin>>u>>v;
int i;
for ( i = 0; i <adj[u].size(); i++)
{
     if(adj[u][i]==v) return true;
}
return false;

}
};

int main(){
    int v;
    cin>>v;
    graph g1(v);
     g1.add_edge(0,1);
     g1.add_edge(0,2);
     g1.add_edge(2,1);
     g1.add_edge(2,3);
     cout<<"h";
     g1.print();
     cout<<g1.is_edge();
    return 0;
}