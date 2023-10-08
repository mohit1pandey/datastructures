/* is graph connected */
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class graph{
    int v;
    vector<int>*adj;
   bool visited[];   //check 42graph.c++
    public:

    graph(int v){
    this->v=v;
    adj=new vector<int>[v];
    visited[v]={false};
    }
    void add_edge(int u,int v){
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    bool bfs(int start){
     queue<int>q;
     q.push(start);
     visited[start]=true;
     while (!q.empty())
     {
      int curr=q.front();
      q.pop();

      for(int i=0;i<adj[curr].size();i++){
        int next=adj[curr][i];
       
        if(!visited[next]){
          visited[next]=true;
           q.push(next);// print only one time

        }

      }
     }
     /* the terversal will start from the 0 vertex if the visited array has all element true so the graph is connected */
    for(int i=0; i<v;i++) {
     if(!visited[i]){
      return false;
     }
     
     }
     return true;
    }

  bool is_connected(){
    return bfs(0);
  }


  bool is_edge(){
    cout<<"check for edge";
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

    graph g1(7);
    g1.add_edge(0,1);
    g1.add_edge(1,2);
    g1.add_edge(0,2);
    g1.add_edge(2,3);
    g1.add_edge(4,5);
    g1.add_edge(5,6);
    g1.add_edge(4,6);
    cout<<g1.is_connected()<<endl;
    cout<<g1.is_edge();


return 0;

};