#include <bits/stdc++.h>
using namespace std;

bool ehVogal(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char vogal_mais_prox(char c){
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};
    char mais_prox = 'a';
    int min_dif = 100; 
    
    for(char v : vogais) {
        int dif = abs(c - v);
        if(dif < min_dif || (dif == min_dif && v < mais_prox)){
            min_dif = dif;
            mais_prox = v;
        }
    }
    return mais_prox;
}

char prox_consoante(char c){
    if (c == 'z') return 'z'; 
    
    string cons = "bcdfghjklmnpqrstvxz";
    for(char con : cons) if(con > c) return con;
}

int main(){
    string s; cin >> s;
    string ans = ""; 

    for(char c : s){
        if(ehVogal(c)){
            ans += c; // Vogais não mudam
        } 
        else{
            ans += c;                        
            ans += vogal_mais_prox(c);       
            ans += prox_consoante(c);
        }
    }

    cout << ans << "\n";
}