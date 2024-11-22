#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define MAXN (int)1e4

int dp[MAXN];

int query(int idx){
    if(dp[idx] != -1){
        return dp[idx];
    }
    cout << "? 1 " << idx << '\n';
    cout.flush();
    int ans; cin >> ans;
    return dp[idx] = ans;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    int idx = 2;
    int ans[MAXN];
    if(query(n) == 0){
        cout << "! IMPOSSIBLE\n";
        cout.flush();
        return;
    }
    while(!query(idx) && idx <= n){
        idx++;
    }
    ans[idx] = 1;
    for(int i = idx - 1; i >= idx - query(idx); i--){
        ans[i] = 0;
    }
    for(int i = 1; i < idx - query(idx); i++){
        ans[i] = 1;
    }
    for(int i = idx + 1; i <= n; i++){
        if(query(i) > query(i - 1)){
            ans[i] = 1;
        }
        else{
            ans[i] = 0;
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << ans[i];
    }
    cout << '\n';
    cout.flush();
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