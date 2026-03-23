#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int,int>>> adj;
vector<vector<int>> dp;
int ans = 0;

void dfs(int v, int pai){
    int best[2] = {0,0};

    for(auto p : adj[v]){
        int u = p.first, w = p.second;
        if(u == pai) continue;

        dfs(u,v);

        int val = 1 + dp[u][1-w];

        if(val > best[w]) best[w] = val;
    }

    dp[v][0] = best[0];
    dp[v][1] = best[1];

    ans = max(ans, best[0] + best[1]);
}

int main(){
    cin >> n;

    adj.resize(n+1);
    dp.resize(n+1, vector<int>(2));

    for(int i = 0; i < n-1; i++){
        int u,v,w;
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dfs(1,-1);

    cout << ans+1 << "\n";
    
    return 0;
}