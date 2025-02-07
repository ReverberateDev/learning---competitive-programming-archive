#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    vector<int> no(1 << m), bc(1 << m); 
    for(int bmask = 0; bmask < (1 << m); bmask++){
        int curr = (1 << 30) - 1;
        for(int i = 0; i < m; i++){
            if(bmask & (1 << i)){
                curr &= b[i];
            }
        }
        no[bmask] = curr;
        bc[bmask] = __builtin_popcountll(curr);
    }
    
    vector<int> gains;
    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<int> best(m + 1, 1e18);
        best[0] = a[i];
        ans += a[i];
        for(int bmask = 0; bmask < (1 << m); bmask++){
            best[bc[bmask]] = min(best[bc[bmask]], a[i] & no[bmask]);
        }
        for(int j = 0; j <= m - 1; j++){
            //cout << "hello\n";
            gains.push_back(1);
        }
    }
    /*
    int cnt = 0;
    while(k--){
        if(gains[cnt] <= 0){
            break;
        }
        ans -= gains[cnt++];
    }
    cout << ans << '\n';
    */
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