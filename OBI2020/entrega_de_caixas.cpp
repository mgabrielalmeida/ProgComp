#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if((a + b < c) || (b < c && a < b)) cout << 1;
    else if(a < b || b < c) cout << 2;
    else cout << 3;
}