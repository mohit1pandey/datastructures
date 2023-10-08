//detect and print any one cycle

#include <iostream>
#include <vector>
using namespace std;

class graph {
    int v;
    vector<int>* adj;
    bool* visited;
    vector<int> path;

public:
    graph(int v) {
        this->v = v;
        adj = new vector<int>[v];
        visited = new bool[v];
        for (int i = 0; i < v; i++) {
            visited[i] = false;
        }
    }

    ~graph() {
        delete[] adj;
        delete[] visited;
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool dfs(int start, int parent) {
        visited[start] = true;
        path.push_back(start);

        for (int i = 0; i < adj[start].size(); i++) {
            int nbr = adj[start][i];
            if (!visited[nbr]) {
                if (dfs(nbr, start)) {   // cycle has found inside
                    return true;
                }
            }
            else if (parent != nbr) {
                path.push_back(nbr);
                return true;
            }
        }

        path.pop_back();
        return false;
    }


    void print_cycle() {
        int last = path[path.size() - 1];
        for (int i = path.size() - 2; i >= 0; i--) {
            cout << path[i] << " ";
            if (path[i] == last) {
                break;
            }
        }
        cout << endl;
    }
    void visited_node(){
    for(int i=0;i<v;i++){
        cout<<i<<visited[i]<<" ";
    
    }


    }
};

int main() {
    graph g1(5);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2,3);
    g1.add_edge(2,4);
    g1.add_edge(3,4);
    g1.add_edge(4,1);
    g1.dfs(0, -1);
    g1.print_cycle();
    g1.visited_node();
    return 0;

}

/*
explenation:  Algorithm

1) if the node is not visited then visit it and then call for its adj nodes.
2) if the adj node is not visited then call dfs and visit it and also check if the function returns true.
3) if recursive function returns true,that means the cycle has been detected, stop by returnig true.
4) if the node is visited then check whether it is parent or not if not the cycle is detected then retun true, the parent functuon will also retun true.
5) keep the teck of every visited node int a path.
6) as the cycle is detected the path will have two value same keep it in var the print the path from second last node.
7) as the twin value found immedeatly break the loop. 

*/














