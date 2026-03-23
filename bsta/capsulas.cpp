#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, f;
    cin >> n >> f;
    vector<int> c(n);

    for(int i = 0; i<n; ++i){
        cin >> c[i];
    }

    int lo = 1, hi = 100000000;
    int ans = hi;

    while(hi >= lo){
        long long m = lo + (hi - lo)/2;

        long long moedas = 0;
        for(int ci : c){
            moedas += m/ci;
        }

        if(moedas >= f){
            ans = m;
            hi = m - 1;
        }
        else lo = m + 1;
    }

    cout << ans << "\n";
}