#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &i : a){
        cin >> i;
    }
    for(auto &i : b){
        cin >> i;
    }
    int memo[n][2];
    memset(memo, -1, sizeof(memo));

    function<bool(int, int)> dp = [&](int pos, int use) -> bool {
        if(pos == 0){
            return true;
        }
        if(memo[pos][use] != -1){
            return memo[pos][use];
        }
        int res = 0;
        if(use){
            int curr = b[0] - a[pos];
            if(b[0] - a[pos - 1] <= curr){
                res = res | dp(pos - 1, 1);
            }
            else if(a[pos - 1] <= curr){
                res = res | dp(pos - 1, 0);
            }
        }
        else{
            int curr = a[pos];
            if(b[0] - a[pos - 1] <= curr){
                res = res | dp(pos - 1, 1);
            }
            else if(a[pos - 1] <= curr){
                res = res | dp(pos - 1, 0);
            }
        }
        return memo[pos][use] = res;
    };

    if(dp(n - 1, 0) || dp(n - 1, 1)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
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