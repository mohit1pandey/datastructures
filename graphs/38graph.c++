/* to check whether a path exist b/w two vertics or not */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class graph{
int v;
vector<int> *adj;
bool visited [];    //check 42graph.c++
public:

graph(int v){
    this->v=v;
    visited[v]={false};
    adj=new vector<int>[v];
}

void add_edge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool bfs(int start,int dest){
    queue<int>q;
    q.push(start);
    visited[start]=true;

    while (!q.empty())
    {
        int curr= q.front();
        q.pop();
       if(curr== dest)return true;       
        for (int i = 0; i < adj[curr].size(); i++)
        {
            int next =adj[curr][i];
            if(!visited[next]){
                q.push(next);
            }
        }
    }
    return false;
}

};
int main(){

graph g1(5);
g1.add_edge(0,1);
g1.add_edge(1,2);g1.add_edge(2,1);g1.add_edge(3,4);
cout<<g1.bfs(1,2);
cout<<endl;
cout<< g1.bfs(4,3);



return 0;
}