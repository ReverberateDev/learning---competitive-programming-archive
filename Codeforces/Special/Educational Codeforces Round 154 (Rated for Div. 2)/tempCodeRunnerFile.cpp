#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

#ifdef DEBUG
    #define OUT(x) cerr << (#x) << '=' << (x) << endl
    #define OUT2(c) cerr << (#c) << " = {"; for (auto it = (c).begin(); it != (c).end(); ++it) cerr << (it == (c).begin() ? "" : ", ") << *it; cerr << "}" << endl;
#else
    #define OUT(x)
    #define OUT2(c)
#endif

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n - 1; i++){
        cnt2 += (a[i] >= a[i + 1]);
    }
    int res = cnt2;
    for(int i = 0; i < n - 1; i++){
        res = min(res, 1ll + cnt1, cnt2);
        cnt1 += (-a[i] >= -a[i + 1]);
        cnt2 -= (a[i] >= a[i + 1]);
    }
    res = min(res, cnt1);
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}