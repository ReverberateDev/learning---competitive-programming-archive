#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> asum(n + 2, 0), bsum(m + 2, 0);
    for(int i = 1; i <= n; i++){
        asum[i] = asum[i - 1] + (a[n - i] - a[i - 1]);
    }
    for(int i = 1; i <= m; i++){
        bsum[i] = bsum[i - 1] + (b[m - i] - b[i - 1]);
    }
    vector<int> ans{0};
    for(int k = 1; max(0ll, 2 * k - m) <= min(n - k, k); k++){
        int lo = max(0ll, 2 * k - m), hi = min(n - k, k);
        //4 <= x <= min(3, 5)
        if(lo > hi){
            break;
        }
        auto f = [&](int x){return asum[x] + bsum[k - x];};
        while(hi - lo > 3){
            int mid1 = (lo * 2 + hi) / 3, mid2 = (lo + hi * 2) / 3;
            if(f(mid1) > f(mid2)){
                hi = mid2;
            }
            else{
                lo = mid1;
            }
        }
        int mx = 0;
        for(int i = lo; i <= hi; i++){
            mx = max(mx, f(i));
        }
        ans.push_back(mx);
    }
    int kmax = ans.size() - 1;
    cout << kmax << "\n";
    for(int i = 1; i <= kmax; i++){
        cout << ans[i] << " \n"[i == kmax];
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