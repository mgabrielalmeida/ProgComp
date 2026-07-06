#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);

    for(int i = 0; i < N; i++) cin >> v[i];

    vector<int> dp(N);

    dp[0] = v[0];
    for(int i = 1; i < N; i++) dp[i] = max(v[i], dp[i-1] + v[i]);
    

    int melhor = 0;
    for(int x : dp) melhor = max(melhor, x);
    
    cout << melhor << endl;
}