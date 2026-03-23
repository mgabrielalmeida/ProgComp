#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, I, r, tam_reuniao, p, ans = 1;
    cin >> n >> m >> I >> r;

    vector<bool> inf (n+1, false);
    bool reuniao_infectada = false;
    vector<vector<int>> reuniao (m);
    inf[I] = true;

    for(int i = 0; i<m; ++i){
        cin >> tam_reuniao;

        for(int j = 0; j<tam_reuniao; ++j){ // analisando se uma reuniao tem um infectado
            cin >> p;
            reuniao[i].push_back(p);
            if(inf[p] && i>=r-1) reuniao_infectada = true;
        }

        if(reuniao_infectada){  // se tiver um infectado na reuniao, infectamos todos os participantes dela
            for(int j = 0; j<tam_reuniao; ++j){
                if(!inf[reuniao[i][j]]){
                    inf[reuniao[i][j]] = true;
                    ++ans;
                }
            }
            reuniao_infectada = false;
        }
    }

    cout << ans << "\n";
}