#include <iostream>
using namespace std;

int main(){
    int x, r = 0; 
    cin >> x;

    for(int i = 0; i<x; ++i){
        int aux; 
        cin >> aux;
        r += aux;
    }

    cout << r;
}
