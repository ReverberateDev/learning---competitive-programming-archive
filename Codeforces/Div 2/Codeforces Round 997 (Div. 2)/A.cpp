#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> mov(n);
    for(int i = 0; i < n; i++){
        cin >> mov[i].first >> mov[i].second;
    }
    int ans = 0;
    for(int i = 1; i < n; i++){
        ans += 2 * mov[i].first + 2 * mov[i].second;
    }
    ans += 4 * m;
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