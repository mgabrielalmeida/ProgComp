#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, c, p, tam_cadeia, pessoa;
    cin >> n >> c;

    vector<bool> paciente0 (n+1, true);

    for(int i = 0; i<c; ++i){
        cin >> p >> tam_cadeia;
        for(int j = 0; j<tam_cadeia; ++j){
            cin >> pessoa;
            paciente0[pessoa] = false;
        }
    }

    for(int i = 1; i<=n; ++i){
        if(paciente0[i]) cout << i << "\n";
    }
}