#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void solve(){
    int ans = 0;
    int n; cin >> n;
    unordered_map<int, int>mp;
    while(n--){
        int t; cin >> t;
        mp[t]++;
    }
    for(auto [k, v] : mp){
        ans += v/2;
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    while(q--){
        solve();
    }
}