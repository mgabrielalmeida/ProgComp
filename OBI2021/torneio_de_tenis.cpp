#include <bits/stdc++.h>
using namespace std;

int main(){
    int v = 0;

    char m;
    for(int i = 0; i<6; ++i){
        cin >> m;
        if(m == 'V') v++;
    }

    if(v>4) cout << 1;
    else if(v>2) cout << 2;
    else if(v>0) cout << 3;
    else cout << -1;
}