#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

#ifdef DEBUG
    #define OUT(x) cerr << (#x) << '=' << (x) << endl
    #define OUT2(c) cerr << (#c) << " = {"; for (auto it = (c).begin(); it != (c).end(); ++it) cerr << (it == (c).begin() ? "" : ", ") << *it; cerr << "}" << endl;
#else
    #define OUT(x)
    #define OUT2(c)
#endif

const int inf = 1e18;

void solve() {
    int m, x; cin >> m >> x;
    int sumh = 0;
    vector<int> c(m), h(m);
    for(int i = 0; i < m; i++){
        cin >> c[i] >> h[i];
        sumh += h[i];
    }
    vector<vector<int>> memo(m, vector<int>(sumh + 1, -1));
    function<int(int, int)> dp = [&](int idx, int hap) -> int {
        if(memo[idx][hap] != -1){
            return memo[idx][hap];
        }
        if(idx == 0){
            if(hap == 0){
                return 0ll;
            } 
            else if(hap == h[0]){
                if(c[0] == 0){
                    return 0ll;
                } 
                else {
                    return inf;
                }
            }
            else {
                return inf;
            }
        }
        int res = inf;
        // Option 1: do not take current item
        res = dp(idx - 1, hap);
        // Option 2: take current item if possible
        if(hap >= h[idx]){
            int prev_hap = hap - h[idx];
            int prev_cost = dp(idx - 1, prev_hap);
            if(prev_cost != inf && prev_cost + c[idx] <= idx * x){
                res = min(res, prev_cost + c[idx]);
            }
        }
        return memo[idx][hap] = res;
    };
    for(int i = sumh; i >= 0; i--){
        if(dp(m - 1, i) != inf){
            cout << i << '\n';
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}