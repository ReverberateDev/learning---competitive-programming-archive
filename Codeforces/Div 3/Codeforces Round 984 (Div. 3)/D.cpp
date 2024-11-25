#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
vector<int>vect;
vector<vector<int>>visited, mat;

void prop(int i, int j){
    visited[i][j] = true;
    vect.push_back(mat[i][j]);
    for(int x = 0; x < 4; x++){
        int di = i + dx[x], dj = j + dy[x];
        if(di < 0 || di >= n){
            continue;
        }
        if(dj < 0 || dj >= m){
            continue;
        }
        if(visited[di][dj]){
            continue;
        }
        prop(di, dj);
        cout << "prop";
        return;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    mat.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char t; cin >> t;
            mat[i][j] = (int) t - '0';
        }
    }
    for(int i = 0; i < min(n / 2, m / 2); i++){
        vect.clear();
        prop(i, i);
        for(auto i : vect){
            cout << i << " ";
        }
        cout << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}