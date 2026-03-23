#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y, preco = 0; cin >> x >> y;

    if(x<=17) preco += 15;
    else if(x<=59) preco += 30;
    else preco += 20;

    if(y<=17) preco += 15;
    else if(y<=59) preco += 30;
    else preco += 20;

    cout << preco << "\n";
}