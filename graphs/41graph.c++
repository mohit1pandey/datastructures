// To detect cycle

#include<iostream>
#include<vector>
using namespace std;
// make class 

class graph{
int v; 
vector<int> *adj;    // an *vector to vector 
bool visited[];




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

~graph(){
  delete [] adj;
}

bool dfs(int start, int parent){
  visited[start]=true;
  
  for (int i=0;i<adj[start].size();i++){
   int nbr= adj[start][i];
   
   if(!visited[nbr]){
     if(dfs(nbr,start))  // it will set the nbr visited and if dfs(nbr) returns true then dfs start will also retun true
     return true;
  }
   else if(nbr!=parent){
    
   return true;
  }
  
} 
return false;
}

bool detect_cycle(){
  for (int i = 0; i < v; i++)
  {
    if(!visited[i]){
     if(dfs(i,-1))
      {return true;}
    }
  }
  return false;
}
};


int main(){
    graph g1(3);
    
    g1.add_edge(0,1);
    g1.add_edge(1,2);
    
    cout<<g1.detect_cycle();
    return 0;
}

/* some explenations 
see the below statement

 1) if(node is unvisited){
     if(dfs(node,parent))  
     return true;}

  means if a node is unvisted then dfs(node) only return true if the dfs(child) returns true.



let take a graph 
  1-2-3-4-5-6    (no cycle)

  dfs(1)->dfs(2)->dfs(3)->dfs(4)->dfs(5)->dfs(6)

  here to return true all the function below should be returning true.

  2)   
   else if(nbr!=parent){
    
   return true;
  }
 if the node is visited then it should be not parent to return true
  
3) to return false both 1) and 2) should not execute.


conclusion :
 i) if adj[node][i] it is non visited the the dfs(node) will only return true if the dfs(child) returns true.
 ii) and if the dfs(child) returns false then then the second if condition will not executed and the loop will iterate to new i. 
 
 
  eg.  for some graphs like this 
         1----4---5
        / \   |
       2---3--6

       1->2,3,4
       2->1,3
       3->1,2,6
       4->1,6,5
       6->4,3
       5->4
  when we will reach at 5:(false should be return)
     
     dfs(1)->dfs(4)->dfs(5)(false)
    then for loop will return nothing and it will iterate to new value.
    
*/