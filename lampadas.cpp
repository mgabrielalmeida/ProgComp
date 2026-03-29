#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    bool a = false, b = false;

    int interruptor;
    for(int i = 0; i<n; ++i){
        cin >> interruptor;

        if(interruptor == 1){
            if(!a) a = true; // em if-else statements, se só houver uma linha de código dentro, as chaves são opcionais
            else a = false;
        }
        else{
            if(a) a = false;
            else a = true;

            if(b) b = false;
            else b = true;
        }
    }

    if(a) cout << 1 << endl;
    else cout << 0 << endl;

    if(b) cout << 1 << endl;
    else cout << 0 << endl;
}