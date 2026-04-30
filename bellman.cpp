#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int s, int n, vector<vector<int>>& edges) {
    vector<int> dist(n, 1e9);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto e : edges) {
            if (dist[e[0]] != 1e9 && dist[e[0]] + e[2] < dist[e[1]])
                dist[e[1]] = dist[e[0]] + e[2];
        }
    }
}

int main() {

}