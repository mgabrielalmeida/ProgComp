#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    
    stack<int> pilha;

    for(int i = 0; i<n; ++i){
        int x; cin >> x;

        if(x != 0) pilha.push(x);
        else pilha.pop();
    }

    int soma = 0, l = pilha.size();
    for(int i = 0; i<l; ++i){
        soma += pilha.top(); pilha.pop();
    }

    cout << soma << "\n";
}