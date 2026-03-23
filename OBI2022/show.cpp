#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, n, m;
    cin >> a >> n >> m;

    vector<vector<int>> lugares(n, vector<int>(m));

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cin >> lugares[i][j];
        }
    }

    int tamanho_seq;
    for(int i = 0; i<n; ++i){
        tamanho_seq = 0;
        for(int j = 0; j<m; ++j){
            if(!lugares[n-1-i][j]) tamanho_seq++;
            if(tamanho_seq >= a){
                cout << i+1 << endl;
                return 0;
            }
            if(lugares[n-1-i][j]) tamanho_seq = 0;
        }
    }

    cout << -1 << endl;
}