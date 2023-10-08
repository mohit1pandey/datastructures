#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define PARENT 0
#define RANK 1

class DisjointSet {
    vector<vector<int>> dset;
    int n;

public:
    DisjointSet(int n) {
        this->n = n;
        dset.resize(n);
        for (int i = 0; i < n; i++) {
            dset[i].resize(2);
            dset[i][PARENT] = -1;
            dset[i][RANK] = 0;
        }
    }

    int find(int i) {
        if (dset[i][PARENT] == -1) {
            return i;
        }
        return dset[i][PARENT] = find(dset[i][PARENT]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (dset[u][RANK] > dset[v][RANK]) {
            dset[v][PARENT] = u;
        } else if (dset[u][RANK] < dset[v][RANK]) {
            dset[u][PARENT] = v;
        } else {
            dset[v][PARENT] = u;
            dset[u][RANK]++;
        }
    }

    int kruskals(vector<vector<int>>& edge_list) {
        sort(edge_list.begin(), edge_list.end(), comparetor);
        int mst_weight = 0;
        for (const auto& edge : edge_list) {
            int u = find(edge[0]);
            int v = find(edge[1]);
            int weight = edge[2];
            if (u != v) {
                unite(u, v);
                mst_weight += weight;
            }
        }
        return mst_weight;
    }

    static bool comparetor(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }
};

int main() {
    int n = 6;
    vector<vector<int>> edge_list = {{0, 1, 1},
                                     {1, 3, 1},
                                     {2, 4, 1},
                                     {0, 2, 2},
                                     {2, 3, 2},
                                     {3, 4, 2},
                                     {1, 2, 3},
                                     {1, 4, 3},
                                     {4, 5, 3},
                                     {3, 5, 4}};

    DisjointSet ds(n);

    int mst_weight = ds.kruskals(edge_list);

    cout << "Minimum Spanning Tree Weight: " << mst_weight << endl;

    return 0;
}
