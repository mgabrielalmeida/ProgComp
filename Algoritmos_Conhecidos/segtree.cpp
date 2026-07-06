#include <bits/stdc++.h>
using namespace std;

int n = 10;
vector<int> v(n);
vector<int> tree(4*n);

int NEUTRAL = 0;

int merge(int a, int b){
    return a + b;
}

void build(int node, int l, int r){
    if(l == r){
        tree[node] = v[l];
        return;
    }

    int m = (l + r)/2;

    build(2 * node, l, m);
    build(2 * node + 1, m+1, r);

    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int start, int end, int l, int r){
    // Caso 1: Intervalo está totalmente fora
    if(end < l || r < start){
        return NEUTRAL;
    }

    // Caso 2: Intervalo está totalmente dentro
    if(end <= r && l <= start){
        return tree[node];
    }

    // Caso 3: Intervalo está parcialmente dentro
    int m = (start + end)/2;
    int left = query(2 * node, start, m, l, r);
    int right = query(2 * node + 1, m+1, end, l, r);

    return merge(left, right);
}

void update(int node, int start, int end, int idx, int value){
    if(start == end){
        v[idx] = value;
        tree[node] = value;
        return;
    }

    int m = (start + end)/2;

    if(idx <= m) update(2 * node, start, m, idx, value);
    else update(2 * node + 1, m+1, end, idx, value);

    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

int main(){
    for(int i = 0; i<n; ++i){
        cin >> v[i];
    }

    build(1, 0, n-1);

    while(true){
        int a, b;
        cin >> a >> b;

        cout << query(1, 0, n-1, a, b);
        update(1, 0, n-1, 0, v[0] + 1);
    }
}