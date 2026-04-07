#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank_, size_;

    DSU(int n) {
        parent.resize(n);
        rank_.resize(n, 0);
        size_.resize(n, 1);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    // Une os conjuntos de x e y. Retorna false se já estavam unidos.
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        // Union by rank
        if (rank_[x] < rank_[y]) swap(x, y);
        parent[y] = x;
        size_[x] += size_[y];
        if (rank_[x] == rank_[y]) rank_[x]++;
        return true;
    }

    // Verifica se x e y estão no mesmo conjunto
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    // Retorna o tamanho do conjunto de x
    int size(int x) {
        return size_[find(x)];
    }
};
