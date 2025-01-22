#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

int n, m, kk;
vector<vector<vector<int>>> adj, memo;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int inf = 1e18;

void minh(int &a, int b){
    a = min(a, b);
}

int dp(int i, int j, int k){
    if(k < 0 || i > n || j > m || i <= 0 || j <= 0){
        return inf;
    }
    if(k == 0){
        return 0;
    }
    if(memo[i][j][k] != -1){
        return memo[i][j][k];
    }
    int ans = inf;
    for(int x = 0; x < 4; x++){
        int ni = i + dx[x], nj = j + dy[x];
        minh(ans, 2 * adj[i][j][x] + dp(ni, nj, k - 1));
    }
    return memo[i][j][k] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> kk;
    adj.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(4, -1)));
    memo.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(21, -1)));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m - 1; j++){
            int tmp; cin >> tmp;
            adj[i][j][3] = tmp;
            adj[i][j + 1][2] = tmp;
        }
    }
    for(int i = 1; i <= n - 1; i++){
        for(int j = 1; j <= m; j++){
            int tmp; cin >> tmp;
            adj[i][j][1] = tmp;
            adj[i + 1][j][0] = tmp;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(kk % 2 != 0){
                cout << "-1 ";
                continue;
            }
            int ans = dp(i, j, kk / 2);
            cout << ans << " ";
        }
        cout << '\n';
    }
}