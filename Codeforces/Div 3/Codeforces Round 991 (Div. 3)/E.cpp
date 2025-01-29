#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

string a, b, c;
int memo[1002][1002];

int dp(int aidx, int bidx){
    if(memo[aidx][bidx] != -1){
        return memo[aidx][bidx];
    }
    if(aidx == 0 && bidx == 0){
        return  0;
    }
    int now = aidx + bidx;
    int best = LLONG_MAX;
    if(aidx) best = min(best, dp(aidx - 1, bidx) + (a[aidx] != c[now]));
    if(bidx) best = min(best, dp(aidx, bidx - 1) + (b[bidx] != c[now]));
    return memo[aidx][bidx] = best;
}

void solve(){
    memset(memo, -1, sizeof(memo));
    cin >> a >> b >> c;
    a = '.' + a, b = '.' + b, c = '.' + c;
    int ans = dp(a.size() - 1, b.size() - 1);
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