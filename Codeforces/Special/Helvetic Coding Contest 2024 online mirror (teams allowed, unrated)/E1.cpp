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

const int MOD = 1e9 + 7;

void solve() {
    int m, n; cin >> m >> n;
    vector<int> s(m), l(m);
    for(int i = 0; i < m; i++){
        cin >> s[i];
    }
    for(int i = 0; i < m; i++){
        cin >> l[i];
    }
    vector<vector<int>> memo(n + 1, vector<int>(m, -1));
    function<int(int, int)> dp = [&](int stp, int idx) -> int {
        if(memo[stp][idx] != -1){
            return memo[stp][idx];
        }
        if(stp == 1){
            int res = 0;
            res += s[0] * s[idx];
            res += s[0] * l[idx];
            res += l[0] * s[idx];
            return memo[stp][idx] = res;
        }
        int res = 0;
        for(int nidx = 0; nidx < m; nidx++){
            //s s
            res += dp(stp - 1, nidx) * s[nidx] * s[idx];
            //s l
            res += dp(stp - 1, nidx) * s[nidx] * l[idx];
            //l s
            res += dp(stp - 1, nidx) * l[nidx] * s[idx];
        }
        return memo[stp][idx] = res;
    };
    int ans = 0;
    for(int i = 0; i < m; i++){
        ans += dp(n, i);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; tt = 1;
    while (tt--) {
        solve();
    }
}

/*
dp[i][j] = number of ways to get to node j after performing i moves
*/