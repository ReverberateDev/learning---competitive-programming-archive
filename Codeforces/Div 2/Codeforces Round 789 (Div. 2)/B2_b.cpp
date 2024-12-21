#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define DEBUG(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = "." + s;
    vector<int> vect(n + 1), seg(n / 2 + 2);
    for(int i = 1; i <= n; i++){
        vect[i] = (s[i] - '0');
    }
    for(int i = 1; i <= n / 2; i++){
        seg[i] = vect[i * 2] + vect[i * 2 - 1] * 2;
    }
    vector<vector<pair<int, int>>> dp(n / 2 + 2, vector<pair<int, int>>(2, {inf, inf}));
    
    for(int i = 1; i <= n / 2; i++){
        for(int j = 0; j < 2; j++){
            int a = seg[i], b = j ? 3 : 0;
            int cost = (a%2)^(b%2) + (a/2)^(b/2);
            for(int k = 0; k < 2; k++){
                dp[i][j] = min(dp[i][j], {dp[i - 1][k].first + cost, dp[i - 1][k].second + (j != k)});
            }
        }
    }
    auto ans = min(dp[n / 2][0], dp[n / 2][1]);
    cout << ans.first << " " << ans.second + 1 << '\n';
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