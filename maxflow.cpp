#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& adj , int s , int t , vector<int>& parent){
    queue<int> q;
    q.push(s);
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    
    vector<int> visited(adj.size() , 0);
    visited[s] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int i = 0; i < adj[curr].size(); i++){
            if(adj[curr][i] > 0 && visited[i] == 0){
                parent[i] = curr;
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    return visited[t];
}

int maxflow(vector<vector<int>>& adj , int s , int t){
    int n = adj.size();
    vector<int> parent(n);
    int maxFlow = 0;
    while(bfs(adj , s , t , parent)){
        int curr = INT_MAX;
      
        for(int i = t; i != s; i = parent[i]){
            curr = min(curr , adj[parent[i]][i]);
        }

        for(int i = t; i != s; i = parent[i]){
            adj[i][parent[i]] += curr;
            adj[parent[i]][i] -= curr;
        }
        maxFlow += curr;
    }
    return maxFlow;
}

int main(){

}