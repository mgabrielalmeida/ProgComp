#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;

vector<int> g[MAXN];

int depth[MAXN];
int parent[MAXN];
int subtree[MAXN];

int n;

void dfs(int u, int p) {
    parent[u] = p;
    subtree[u] = 1; // conta o próprio nó

    for (int v : g[u]) {
        if (v == p) continue;

        depth[v] = depth[u] + 1;
        dfs(v, u);

        subtree[u] += subtree[v];
    }
}

// --------------------
// DFS para achar nó mais distante
// --------------------
void dfs_farthest(int u, int p, int dist, int &bestNode, int &bestDist) {
    if (dist > bestDist) {
        bestDist = dist;
        bestNode = u;
    }

    for (int v : g[u]) {
        if (v == p) continue;
        dfs_farthest(v, u, dist + 1, bestNode, bestDist);
    }
}

// --------------------
// Calcula diâmetro
// --------------------
int getDiameter() {
    int A = 1;
    int distA = -1;

    dfs_farthest(1, -1, 0, A, distA);

    int B = A;
    int diameter = -1;

    dfs_farthest(A, -1, 0, B, diameter);

    return diameter;
}

int main() {
    cin >> n;

    // leitura das arestas
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    // raiz = 1
    depth[1] = 0;
    dfs(1, -1);

    cout << "Profundidades:\n";
    for (int i = 1; i <= n; i++) {
        cout << "depth[" << i << "] = " << depth[i] << "\n";
    }

    cout << "\nSubtree sizes:\n";
    for (int i = 1; i <= n; i++) {
        cout << "subtree[" << i << "] = " << subtree[i] << "\n";
    }

    int diameter = getDiameter();

    cout << "\nDiametro = " << diameter << "\n";

    return 0;
}