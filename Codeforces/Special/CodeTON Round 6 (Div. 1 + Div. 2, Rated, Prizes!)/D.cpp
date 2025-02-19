#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

#ifdef DEBUG
    #define OUT(x) cerr << (#x) << '=' << (x) << endl
    #define OUT2(c) cerr << (#c) << " = {"; for (auto it = (c).begin(); it != (c).end(); ++it) cerr << (it == (c).begin() ? "" : ", ") << *it; cerr << "}" << endl;
#else
    #define OUT(x)
    #define OUT2(c)
#endif

const int inf = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 2, 0), suf(n + 2, inf), ans(n + 2, inf);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = n; i >= 0; i--){
        suf[i] = min(suf[i + 1], a[i]);
    }
    OUT2(a);
    OUT2(suf);
    int budget; cin >> budget;
    int curr = budget / suf[1];
    ans[1] = curr;
    budget -= curr * suf[1];
    OUT(budget);
    for(int i = 2; i <= n; i++){
        int add = (suf[i] - suf[i - 1]);
        curr = min(curr, add == 0 ? curr : budget / add);
        budget -= add * curr;
        ans[i] = curr;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}