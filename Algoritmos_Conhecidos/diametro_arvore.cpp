#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000;

vector<int> adj[MAXN];
int diametro = 0;

int dfs(int v, int pai){
    int maior1 = 0, maior2 = 0;

    for(auto u : adj[v]){
        if(u == pai) continue;

        int h = dfs(u, v) + 1;

        if(h > maior1){
            maior2 = maior1;
            maior1 = h;
        }

        else if(h > maior2) maior2 = h;
    }

    diametro = max(diametro, maior1 + maior2);

    return maior1;
}


int main(){
    int n; cin >> n;
    for(int i = 0; i<n-1; ++i){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    cout << diametro << endl;
}