// DFS alforithm
/* visit a node if and go to it's ajecent node if visited so don't do any thing if non-visited visit and run the same recursive porcess */
#include<iostream>
#include<vector>
using namespace std;
// make class 

class graph{
int v; 
vector<int> *adj;    // an *vector to vector 
bool visited[];      // check 42graph.c++

public:
graph(int v){
this->v=v;
adj=new vector<int>[v];   //new vector<int>[v] returns the address of [v] vectors and recived by the vector pointer
visited[v]={false};       // initialise every value false
}
void add_edge(int u,int v){

  adj[u].push_back(v);
  adj[v].push_back(u);
  
}

void dfs(int start){
visited[start]=true;        
 cout<<start;
for (int i = 0; i < adj[start].size(); i++)
 {
    int nbr=adj[start][i];
     if(!visited[nbr]){
        dfs(nbr);
     }
 }
}
};

int main(){
    graph g1(6);
    g1.add_edge(0,1);   
    g1.add_edge(0,2);
    g1.add_edge(0,4);
    g1.add_edge(3,5);
    g1.add_edge(1,5);
    g1.add_edge(4,5);
    g1.dfs(1);
    return 0;
}

