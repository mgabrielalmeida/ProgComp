#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int MAX = 100005;
vector<int> adj[MAX];
bool visitado[MAX];

void dfs_iterativa(int v) {
    stack<int> s;
    s.push(v);
    visitado[v] = true; 

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (!visitado[u]) {
            visitado[u] = true;
            for (int w : adj[u]) {
                if (!visitado[w]) {
                    s.push(w);
                }
            }
        }
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visitado[v] = true; 

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int w : adj[u]) {
            if (!visitado[w]) {
                visitado[w] = true;
                q.push(w);
            }
        }
    }
}

void dfs_rec(int v) {
    visitado[v] = true;
    for (int u : adj[v]) {
        if (!visitado[u]) {
            dfs_rec(u);
        }
    }
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int componentes = 0;
    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            componentes++;
            dfs_iterativa(i);
        }
    }
    cout << "Total de componentes: " << componentes << endl;

    return 0;
}