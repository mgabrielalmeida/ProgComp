#include <bits/stdc++.h>
using namespace std;

int main(){
    map<char, int> pontos;
    map<char, int> pontosD;

    pontos.insert({'A', 10});
    pontos.insert({'J', 11});
    pontos.insert({'Q', 12});
    pontos.insert({'K', 13});
    pontosD.insert({'A', 14});
    pontosD.insert({'J', 15});
    pontosD.insert({'Q', 16});
    pontosD.insert({'K', 17});

    char dominante;
    char figura, naipe;

    cin >> figura >> naipe;
    dominante = naipe;

    int edu = 0, luana = 0;
    for(int i = 0; i<6; ++i){
        cin >> figura >> naipe;
        if(i<3){
            if(naipe == dominante) luana += pontosD[figura];
            else luana += pontos[figura];
        }
        else{
            if(naipe == dominante) edu += pontosD[figura];
            else edu += pontos[figura];
        }
    }

    if(edu > luana) cout << "Edu";
    else if(luana > edu) cout << "Luana";
    else cout << "empate";
}