/* graph */
// 1 to represent a graph 3 ways
// to print thet whether two nodes are connected or not

#include <iostream>
using namespace std;
void add_edge(int adjmrtx[][8],int u,int v){
 
  adjmrtx[u][v]=1;
  adjmrtx[v][u]=1;       // in case of undirected graph

}
bool is_edge(int adjmrtx[][8],int u,int v){
  if(adjmrtx[u][v]==1)return true;
  else return false;
} 

 int main(){
// int m; // n is no of vertices and m is the no of edges
 //cin>>m;

 int adj[8][8];
 add_edge(adj,0,1);//0,1
 add_edge(adj,0,2);//0,2
 add_edge(adj,0,3);//0,3
 add_edge(adj,1,2);//1,2
 add_edge(adj,2,3);//2,3
 cout<<is_edge(adj,3,2);
return 0;
 }