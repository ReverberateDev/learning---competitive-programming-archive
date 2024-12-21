#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int dp[n][3];
    for(int i = 0; i < 3; i++){
        dp[0][i] = b[0] * i;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            int height = a[i] + j;
            int cost = b[i] * j;
            int ans = LLONG_MAX;
            for(int k = 0; k < 3; k++){
                int height2 = a[i - 1] + k;
                if(height == height2){
                    continue;
                }
                ans = min(ans, dp[i - 1][k] + cost);
            }
            dp[i][j] = ans;
        }
    }
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << '\n';
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