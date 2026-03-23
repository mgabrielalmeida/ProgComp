#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long A;

    while(cin >> N >> A && (N || A)){
        vector<int> C(N);

        long long soma = 0;
        int maior = -1;
        for(int i = 0; i < N; i++){
            cin >> C[i];
            soma += C[i];
            if(C[i] > maior) maior = C[i];
        }

        if(soma == A){
            cout << ":D\n";
            continue;
        }

        if(soma < A){
            cout << "-.-\n";
            continue;
        }

        double lo = 0, hi = maior;
        double ans = 0.0; 
        double EPS = 1e-5;
        
        while(hi - lo > EPS){ 
            double mid = lo + (hi - lo) / 2.0;

            double area = 0;
            for (int i = 0; i < N; i++) {
                if(C[i] > mid) area += (C[i] - mid);
            }

            if (area >= A){
                ans = mid;  
                lo = mid;
            } 
            else {
                hi = mid;
            }
        }

        cout << fixed << setprecision(4) << ans << "\n";
    }
    
    return 0;
}