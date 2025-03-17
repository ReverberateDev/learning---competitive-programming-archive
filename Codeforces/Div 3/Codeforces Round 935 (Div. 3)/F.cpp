#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

// Ordered multiset with policy-based data structure
template <typename T>
using ordered_multiset = tree<
    pair<T, int>,  // Store a pair (value, index) to handle duplicates
    null_type, 
    less<pair<T, int>>,  // Maintain order
    rb_tree_tag, 
    tree_order_statistics_node_update>;

const int inf = 1e18;

void solve() {
    int n; cin >> n;
    ordered_multiset<int> mset;
    vector<int> a(n), p(n);
    int idx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mset.insert({a[i], idx++});
    }
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    //1 mushroom
    pair<int, int> res = {mset.rbegin()->first, -1ll};
    for(int i = 0; i < n - 1; i++){
        mset.erase(mset.lower_bound({a[p[i] - 1], -inf}));
        int x = i + 2;
        if(x > mset.size()) continue;
        res = max(res, {x * mset.find_by_order(mset.size() - x)->first, -x});
    }
    cout << res.first << " " << -res.second << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}
