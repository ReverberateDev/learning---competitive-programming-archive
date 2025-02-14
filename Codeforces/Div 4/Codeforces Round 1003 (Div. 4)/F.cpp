#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n; cin >> n;
    vector<int> lab(n + 1), ans(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> lab[i];
    }
    vector<vector<int>> adj(n + 1, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    function<void(int, int)> dfs = [&](int idx, int par) -> void {
        int curr = lab[idx];
        map<int, int> mp;
        for(auto chi : adj[idx]){
            if(lab[chi] == curr){
                ans[curr] = 1;
            }
            mp[lab[chi]]++;
            if(mp[lab[chi]] == 2){
                ans[lab[chi]] = 1;
            }
            if(chi == par){
                continue;
            }
            dfs(chi, idx);
        }
    };
    dfs(1, -1);
    for(int i = 1; i <= n; i++){
        cout << ans[i];
    }
    cout << '\n';
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