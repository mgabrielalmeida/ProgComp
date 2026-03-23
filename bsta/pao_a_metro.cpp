#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int maior = 0; 
    vector<int> paes(k); 
    for(int i = 0; i < k; ++i){
        cin >> paes[i];
        if(paes[i] > maior) maior = paes[i];
    }

    int m, soma, ans = 0;
    int hi = maior, lo = 1; 
    
    while(hi >= lo){
        m = lo + (hi - lo) / 2;

        soma = 0;
        for(int pao : paes){
            soma += pao / m;
        }

        if(soma >= n){
            ans = m;
            lo = m + 1; 
        }
        else hi = m - 1;  
    }

    cout << ans << "\n";
}