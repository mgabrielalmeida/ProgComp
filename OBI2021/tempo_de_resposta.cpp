#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    map<int,int> pendente; // registra o tempo em que recebemos a mensagem de um amigo
    map<int,int> tempo_total; // registra o tempo total de cada amigo

    int tempo_atual = 0;
    bool anterior_foi_evento = false;

    for(int i = 0; i<n; ++i){
        char tipo;
        int x;
        cin >> tipo >> x;

        if(tipo == 'T'){
            anterior_foi_evento = false;
            tempo_atual += x;
        }
        else{
            if(anterior_foi_evento) tempo_atual++;

            if(tipo == 'R'){
                if(tempo_total.find(x) == tempo_total.end()) tempo_total[x] = 0;
                pendente[x] = tempo_atual;
            }
            else{ // tipo 'E'
                tempo_total[x] += tempo_atual - pendente[x];
                pendente[x] = -1;
            }

            anterior_foi_evento = true;
        }
    }

    for(auto p : tempo_total){
        int amigo = p.first, tempo = p.second;

        if(pendente[amigo] != -1) cout << amigo << " -1\n";
        else cout << amigo << " " << tempo << "\n";
    }
}