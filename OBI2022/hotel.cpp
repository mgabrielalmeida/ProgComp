#include <bits/stdc++.h>
using namespace std;

int main(){
    int d, a, n;
    cin >> d >> a >> n;

    int diaria = d + (min((n-1), 14)) * a;

    cout << (31 - (n-1)) * diaria;
}