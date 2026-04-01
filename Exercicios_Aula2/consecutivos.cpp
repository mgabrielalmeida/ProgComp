#include <iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;

    int v[n];
    for(int i = 0; i<n; ++i){
        cin >> v[i];
    }

    int maior_seq = 1, seq_atual = 1;
    for(int i = 1; i<n; ++i){
        if(v[i] == v[i-1]){
            seq_atual++;
        }
        else{
            if(seq_atual > maior_seq) maior_seq = seq_atual;
            seq_atual = 1;
        }
    }

    if(seq_atual > maior_seq) maior_seq = seq_atual;

    cout << maior_seq;
}