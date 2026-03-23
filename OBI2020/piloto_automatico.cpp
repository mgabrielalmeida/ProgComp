#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if(b-a < c-b) cout << 1;
    else if (b-a > c-b) cout << -1;
    else cout << 0;
}