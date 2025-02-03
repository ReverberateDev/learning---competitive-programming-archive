#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

/*
Try all k^n, let this number be m
y / x = m => y = m * x
y / m = x
*/

void solve(){
    int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
    int m = 1, ans = 0;
    for(; r2 / m >= l1;){
        int l = (l2 - 1) / (m + 1);
        int r = r2 / m;
        int mn = max(l, l1), mx = min(r, r1);
        ans += max(mx - mn + 1, 0ll);
        m *= k;
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