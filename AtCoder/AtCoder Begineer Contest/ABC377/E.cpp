#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int>p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }

    vector<bool>visited(n, false);
    vector<int>cycle;
    auto dfs = [&](auto dfs, int v) -> void {
        if(visited[v]){
            return;
        }
        visited[v] = true;
        cycle.push_back(v);
        dfs(dfs, p[v]);
    };
    auto power = [&](int a, int b, int mod) -> int {
        int res = 1;
        while(b > 0){
            if(b & 1) res = res * a;
            res %= mod;
            a = a * a;
            a %= mod;
            b >>= 1;
        }
        return res;
    };
    vector<int>ans(n);
    for(int i = 0; i < n; i++){
        if(visited[i]){
            continue;
        }
        dfs(dfs, i);
        int sz = cycle.size();
        int len = power(2, k, sz);
        for(int j = 0; j < sz; j++){
            ans[cycle[j]] = cycle[(j + len) % sz];
        }
        cycle.clear();
    }
    for(auto i : ans){
        cout << i + 1 << " ";
    }
}