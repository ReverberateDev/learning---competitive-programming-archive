#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define MAXN (int)1e3
//0 indexed
int ans = 0;
vector<int>dp(MAXN, 0);
vector<int>adj[MAXN];
vector<int>deg(MAXN, 0);

void dfs(int idx, int par){
    dp[idx] = (deg[idx] == 2);
    int v = 0;
    for(auto nidx : adj[idx]){
        if(nidx == par){
            continue;
        }
        dfs(nidx, idx);
        if(deg[idx] == 3){
            ans += v * dp[nidx];
            dp[idx] += dp[nidx];
        }
        v += dp[nidx];
    }
    if(deg[idx] == 2){
        ans+=v;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int e = n - 1;
    for(int i = 0; i < e; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        deg[u]++; deg[v]++;
    }
    dfs(0, -1);
    cout << dp[2];
    cout << ans;
}