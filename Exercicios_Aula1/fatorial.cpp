#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 1;
    for(int i = n; i>0; i--){
        ans *= i; // mesmo que ans = ans * i
    }

    cout << ans;
}