#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

void solve(){
    int n; cin >> n;
    vector<int>h(n + 1), pre(n + 1, LLONG_MIN), suf(n + 2, LLONG_MAX), dp(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        pre[i] = max(pre[i - 1],  h[i]);
    }
    for(int i = n; i >= 1; i--){
        suf[i] = min(h[i], suf[i + 1]);
    }
    dp[n] = pre[n];
    for(int i = n - 1; i >= 1; i--){
        if(pre[i] > suf[i + 1]){
            dp[i] = max(pre[i], dp[i + 1]);
        }
        else{
            dp[i] = pre[i];
        }
    }
    for(int i = 1; i <= n; i++){
        cout << dp[i] << " ";
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