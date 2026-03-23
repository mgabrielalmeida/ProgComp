#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int matriz[n][m];
    int cont_i = 0, cont_p = 0; 

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cin >> matriz[i][j];
        }
    }

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if((i+j) % 2 == 0 && matriz[i][j] % 2 != 0) cont_p++;
            if((i+j) % 2 != 0 && matriz[i][j] % 2 == 0) cont_p++;
        }
    }
    
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if((i+j) % 2 == 0 && matriz[i][j] % 2 == 0) cont_i++;
            if((i+j) % 2 != 0 && matriz[i][j] % 2 != 0) cont_i++;
        }
    }
                    

    if(cont_i > cont_p){ 
        cout << cont_p << endl;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if((i+j) % 2 == 0 && matriz[i][j] % 2 != 0) cout << matriz[i][j] + 1 << " ";
                else if((i+j) % 2 == 0) cout << matriz[i][j] << " ";
                else if((i+j) % 2 != 0 && matriz[i][j] % 2 == 0) cout << matriz[i][j] + 1 << " ";
                else cout << matriz[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else{ 
        cout << cont_i << endl;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if((i+j) % 2 == 0 && matriz[i][j] % 2 == 0) cout << matriz[i][j] + 1 << " ";
                else if((i+j) % 2 == 0) cout << matriz[i][j] << " ";
                else if((i+j) % 2 != 0 && matriz[i][j] % 2 != 0) cout << matriz[i][j] + 1 << " ";
                else cout << matriz[i][j] << " ";
            }
            cout << "\n";
        }
    }
}