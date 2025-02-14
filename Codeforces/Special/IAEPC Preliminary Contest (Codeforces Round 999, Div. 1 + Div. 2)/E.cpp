#include <bits/stdc++.h>
using namespace std;
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    vector<int> bm(1 << m), sb(1 << m);
    for(int bmask = 0; bmask < (1 << m); bmask++){
        int x = (1 << 30) - 1;
        for(int i = 0; i < m; i++){
            if(bmask & (1 << i)){
                x &= b[i];
            }
        }
        bm[bmask] = x;
        sb[bmask] = __builtin_popcountll(bmask);
    }
    vector<int> gain, c(m + 1);
    for(int i = 0; i < n; i++){
        fill(c.begin(), c.end(), (1 << 30) - 1);
        for(int bmask = 0; bmask < (1 << m); bmask++){
            c[sb[bmask]] = min(c[sb[bmask]], a[i] & bm[bmask]);
        }
        for(int j = 0; j <= m - 1; j++){
            gain.push_back(c[j] - c[j + 1]);
        }
    }
    int64_t ans = 0;
    for(int i = 0; i < n; i++){
        ans += a[i];
    }
    sort(gain.rbegin(), gain.rend());
    for(int i = 0; i < k; i++){
        ans -= gain[i];
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