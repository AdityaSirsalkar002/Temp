#include <bits/stdc++.h>
using namespace std;

void prim(int n, vector<pair<int, int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(n, 0);
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        if (vis[node]) continue;
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edW = it.second;
            if (!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }
}

int main() {

}
