#include <bits/stdc++.h>
using namespace std;

// Including the PBDS library
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// Using the specific PBDS tree structure (an Order Statistic Tree)
using namespace __gnu_pbds;

// Define a PBDS set with type `type`
template<typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


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
    pbds_set<int> st;
    cout << st.order_of_key(5);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; tt = 1;
    while (tt--) {
        solve();
    }
}