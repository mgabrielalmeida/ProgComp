#include <bits/stdc++.h>
using namespace std;

int convert(char c){
    c = tolower(c);
    if(c == 'c') return 0;
    else if(c == 'e') return 1;
    else if(c == 'u') return 2;
    else return 3;
}

int main(){
    vector<vector<bool>> cartas(4, vector<bool>(14, false));
    vector<bool> erros(4, false);

    string s; cin >> s;

    for(int i = 0; i<s.size(); ++i){
        int n;
        if(i%3 == 0) n = (s[i] - '0') * 10;
        else if(i%3 == 1) n += s[i] - '0';
        else{
            if(cartas[convert(s[i])][n] == false) cartas[convert(s[i])][n] = true;
            else erros[convert(s[i])] = true;
        }
    }

    int i = 0;
    for(auto naipe : cartas){
        if(erros[i]){
            cout << "erro\n";
            ++i;
            continue;
        }

        int cont = 0;
        for(int j = 1; j<=13; ++j){
            if(!naipe[j]) ++cont;
        }
        cout << cont << "\n";
        ++i;
    }

}