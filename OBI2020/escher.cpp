#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int soma;
    int v[10001];
    for(int i = 0; i<n; ++i){
        cin >> v[i];
    }

    soma = v[0] + v[n-1];
    for(int i = 1; i<n-1; ++i){
        if(v[i] + v[n-1-i] == soma) soma = v[i] + v[n-1-i];
        else{
            cout << "N";
            return 0;
        }
    }

    cout << "S";
}