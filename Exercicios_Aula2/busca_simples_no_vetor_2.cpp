#include <iostream>
using namespace std;

int main(){
    int v[10];
    bool indices[10];
    int cont = 0;
    int x;

    for(int i = 0; i<10; ++i){
        cin >> v[i];
        indices[i] = false;
    }

    cin >> x;

    for(int i = 0; i<10; ++i){
        if(v[i] == x){
            cont++;
            indices[i] = true;
        }
    }

    if(cont > 0){
        cout << cont << endl;
    
        for(int i = 0; i<10; ++i){
            if(indices[i]) cout << i << " ";
        }
    }
    else{
        cout << "Mia x";
    }
    
}