#include <bits/stdc++.h>
using namespace std;

int meio(int a, int b, int c){ // solução mais elegante usando min/max
    return a + b + c - min(min(a,b),c) - max(max(a,b),c);
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if((a >= b && b >= c) || (c >= b && b >= a)) cout << b;
    else if((b >= a && a >= c) || (c >= a && a >= b)) cout << a;
    else cout << c;
}