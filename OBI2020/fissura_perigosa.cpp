#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    int n, f; cin >> n >> f;
    string mapa[n];
    bool vis[n][n];

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            vis[i][j] = false;
        }
    }

    for(int i = 0; i<n; ++i){
        cin >> mapa[i];
    }

    queue<pair<int,int>> q;
    q.push({0,0});

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    while(!q.empty()){
        pair<int,int> atual = q.front(); q.pop();
        int x = atual.first, y = atual.second;
        if(mapa[x][y] - '0' <= f){
            mapa[x][y] = '*';
            vis[x][y] = true;
        }

        for(int i = 0; i<4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && vis[x][y])
                if(mapa[nx][ny] - '0' <= f){ 
                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }
        }
    }

    for(int i = 0; i<n; ++i){
        cout << mapa[i] << "\n";
    }
}