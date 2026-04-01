#include <bits/stdc++.h>
#define int long long
using namespace std;

size_t main(){
    int n, s;
    cin >> n >> s;

    vector<int> dp(n);

    int aux;
    for(int i = 0; i < n; ++i){
        cin >> aux;
        if(i > 0) dp[i] = aux + dp[i-1];
        else dp[i] = aux;
    }

    int ans = 0;

    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            int sum;
            if(i == 0) sum = dp[j];
            else sum = dp[j] - dp[i-1];

            if(sum == s) ans++;
        }
    }

    cout << ans;
}