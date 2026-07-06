#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj(n);
vector<int> subtree(n);
vector<int> parent(n);

void dfs(int v, int pai){
    subtree[v] = 1;

    for(int u : adj[v]){
        dfs(u, v);
        subtree[v] += subtree[u];
    }
}

int main(){
    
}