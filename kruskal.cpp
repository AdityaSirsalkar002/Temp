#include <bits/stdc++.h>
using namespace std;

int parent[100005];

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) parent[root_i] = root_j;
}

void kruskal() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++) parent[i] = i;

    int mst_weight = 0;
    for (auto it : edges) {
        if (find(it[1]) != find(it[2])) {
            mst_weight += it[0];
            unite(it[1], it[2]);
        }
    }
}

int main() {

}
