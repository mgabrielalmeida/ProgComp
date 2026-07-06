#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; cin >> n;

    while(n--){
        bool flag = false;
        vector<vector<int>> grid(5, vector<int>(5));
        vector<vector<bool>> vis(5, vector<bool>(5, false));

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> grid[i][j];
            }
        }

        queue<pair<int,int>> q;
        if(!grid[0][0]){
            q.push({0, 0});
            vis[0][0] = true;
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            if (x == 4 && y == 4) {
                cout << "COPS\n";
                flag = true;
                break;
            }
            
            for (int k = 0; k < 4; ++k){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !vis[nx][ny] && grid[nx][ny] == 0) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        if(flag) continue;
        cout << "ROBBERS\n";
    }
}