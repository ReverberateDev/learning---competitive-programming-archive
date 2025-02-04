#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
    int m = 1, ans = 0;
    for(; r2 / m >= l1;){
        int l = (l2 + m - 1) / m;
        int r = r2 / m;
        int mn = max(l, l1), mx = min(r, r1);
        ans += max(mx - mn + 1ll, 0ll);
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