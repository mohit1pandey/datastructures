/* bredth first search treversal bfs */
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class graph{
int v;
vector<int>*adj;
bool visited[];  // declering array like this not a goot practice if we declare some thing below of it it will give error
public:          // so use vecotor or any dynamic array check 42graph.c++
graph(int v){
    this->v=v;
    adj=new vector<int>[v];
    visited[v]={true};
}
void add_edge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void bfs(int start){
    queue<int>q;
    q.push(start);
    visited[start]=true;

while (!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr;
        for (int i = 0; i< adj[curr].size(); i++)
        {
            int next=adj[curr][i];
            if(!visited[next]){
                visited[next]=true;
                q.push(next);
            }
        }
        
    }
    

}

};
int main(){
    graph g1(5);
    g1.add_edge(0,1);
    g1.add_edge(0,2);
    g1.add_edge(1,2);
    g1.add_edge(1,4);
    g1.add_edge(2,3);

    g1.bfs(0);
}