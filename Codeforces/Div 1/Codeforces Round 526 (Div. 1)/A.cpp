#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int e = n - 1;
    vector<int> gas(n + 1);
    vector<pair<int, int>> adj[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> gas[i];
    }
    for(int i = 0; i < e; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, -c});
        adj[b].push_back({a, -c});
    }
    int ans = 0;
    function<int(int, int)> dfs = [&](int idx, int par) -> int {
        vector<int> sums;
        sums.push_back(0);
        sums.push_back(0);
        int res = gas[idx];
        for(auto [chi, w] : adj[idx]){
            if(chi == par){
                continue;
            }
            sums.push_back(dfs(chi, idx) + w);
        }
        sort(sums.begin(), sums.end());
        reverse(sums.begin(), sums.end());
        res += sums[0];
        ans = max(ans, res + sums[1]);
        return res;
    };
    dfs(1, -1);
    cout << ans;
}