#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n; cin >> n;
    vector<int> L(n + 1), R(n + 1), C(n + 1), dp(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> L[i] >> R[i];
    }
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    function<void(int, int)> dfs1 = [&](int idx, int par){
        int ma = 0;
        for(auto chi : adj[idx]){
            if(chi == par){
                continue;
            }
            dfs1(chi, idx);
            ma = max(ma, C[chi]);
        }
        C[idx] = max(L[idx], min(ma, R[idx]));
    };
    dfs1(1, -1);
    function<void(int, int)> dfs2 = [&](int idx, int par){
        for(auto chi : adj[idx]){
            if(chi == par){
                continue;
            }
            dfs2(chi, idx);
            dp[idx] += dp[chi];
            if(C[idx] < C[chi]){
                dp[idx] += C[chi] - C[idx];
            }
        }
    };
    dfs2(1, -1);
    cout << dp[1] + C[1] << '\n';
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