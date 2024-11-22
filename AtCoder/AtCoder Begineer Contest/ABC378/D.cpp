#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1,  0, 0, 1, -1, 1, -1};
int H, W, K;
vector<vector<bool>>visited, mat;
int ans = 0;

void dfs(int x, int y, int k){
    if(k == K){
        ans++;
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0) continue;
        if (nx >= H || ny >= W) continue;
        if (visited[nx][ny]) continue; 
        if (!mat[nx][ny]) continue; //Check other conditions here
        dfs(nx, ny, k + 1);
    }
    visited[x][y] = false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> H >> W >> K;
    visited.resize(H, vector<bool>(W, false));
    mat.resize(H, vector<bool>(W, false));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char t; cin >> t;
            if(t == '.'){
                mat[i][j] = true;
            }
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(!mat[i][j]){
                continue;
            }
            dfs(i, j, 0);
        }
    }
    cout << ans;
}