#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    int zi = -1, zj = -1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 0){
                zi = i;
                zj = j;
            }
        }
    }

    int soma_magica = -1, soma_errada = -1;
    for(int i = 0; i < n; i++){
        int soma = 0;
        bool tem_zero = false;
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0) tem_zero = true;
            soma += mat[i][j];
        }
        if(!tem_zero){
            soma_magica = soma;
        }
        else{
            soma_errada = soma;
        }

        if(soma_magica != -1 && soma_errada != -1) break;
    }

    cout << soma_magica - soma_errada << endl;
    cout << zi + 1 << endl;
    cout << zj + 1 << endl;
}