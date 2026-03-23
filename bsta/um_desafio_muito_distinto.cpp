#include <bits/stdc++.h>
using namespace std;

long long soma_entre(long long x, long long y) {
    if(x > y) return 0; 
    return (x + y) * (y - x + 1) / 2;
}

int main(){
    long long p, a, b, l, m;
    cin >> p;

    for(int i = 0; i<p; ++i){
        cin >> l >> a >> b;

        if(soma_entre(a, b) <= l){
            cout << b - a + 1 << "\n";
            continue;
        }

        long long hi = b, lo = a;
        long long ans = a; 

        while(hi >= lo){
            m = (hi + lo) / 2;
            
            long long s = soma_entre(a, m - 1);

            if(s < l){
                ans = m;  
                lo = m + 1;  
            }
            else hi = m - 1;   
        }
        
        cout << ans - a + 1 << "\n";
    }
}