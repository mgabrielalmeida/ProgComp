#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, u;
    cin >> n >> k >> u;

    vector<vector<int>> mapa(u+1);
    vector<int> cont(n+1, 0);
    
    int aux;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<k; ++j){
            cin >> aux;
            mapa[aux].push_back(i+1);
        }
    }

    bool flag = false;
    for(int i = 0; i<u; ++i){
        cin >> aux;
        if(flag) continue;
        for(int cartela : mapa[aux]){
            cont[cartela]++;
            if(cont[cartela] >= k){
                flag = true;
            }
        }
    }

    for(int i = 1; i<=n; ++i){
        if(cont[i] >= k) cout << i << " ";
    }
}