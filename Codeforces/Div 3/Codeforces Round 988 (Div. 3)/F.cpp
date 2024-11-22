#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

pair<int, int> func(int power, int m, int x){
    return make_pair(x - (m - power), (x + m - power) + 1);
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int>h(n), x(n);
    for(auto &i : h){ 
        cin >> i;
    }
    for(auto &i : x){
        cin >> i;
    }
    
    int lo = 1, hi = 1e9 + 10, ans = -1;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        map<int, int>mp;
        for(int i = 0; i < n; i++){
            int power = (h[i] + mid - 1) / mid;
            if(power > m){
                continue;
            }
            auto t = func(power, m, x[i]);
            mp[t.first]++;
            mp[t.second]--;
        }
        int best = 0, curr = 0;
        for(auto [_, t] : mp){
            curr += t;
            best = max(curr, best);
        }
        if(best >= k){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    
    cout << ans << '\n';
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