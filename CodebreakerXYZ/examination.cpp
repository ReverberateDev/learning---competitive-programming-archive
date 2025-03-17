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

#ifdef DEBUG
    #define OUT(x) cerr << (#x) << '=' << (x) << endl
    #define OUT2(c) cerr << (#c) << " = {"; for (auto it = (c).begin(); it != (c).end(); ++it) cerr << (it == (c).begin() ? "" : ", ") << *it; cerr << "}" << endl;
#else
    #define OUT(x)
    #define OUT2(c)
#endif

int cnt = 0;
const int inf = 1e18;

struct node{
    int s, e, m;
    pbds_set<pair<int, int>> st;
    node *l, *r;
    node(int _s, int _e): s(_s), e(_e), m((s + e) >> 1), l(NULL), r(NULL) {
    }
    void create_children() {
        if (s == e) return;
        if (l != NULL) return;
        l = new node(s, m);
        r = new node(m + 1, e);
    }
    void add(int idx, int val){
        create_children();
        st.insert({val, cnt++});
        if(s == e){
            return;
        }
        if(idx <= m){
            l->add(idx, val);
        }
        else{
            r->add(idx, val);
        }
    }
    int query(int x, int y, int val){
        create_children();
        if(s == x && e == y){
            return st.size() - st.order_of_key({val, -inf});
        }
        if(y <= m){
            return l->query(x, y, val);
        }
        if(x > m){
            return r->query(x, y, val);
        }
        return l->query(x, m, val) + r->query(m + 1, y, val);
    }
} *root;

struct query_struct {
    int a, b, c, idx;
    query_struct(int _a, int _b, int _c, int _idx): a(_a), b(_b), c(_c), idx(_idx) {}
};

void solve() {
    int n, q; cin >> n >> q;
    vector<query_struct> queries;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        queries.push_back(query_struct(a, b, a + b, -1));
    }
    root = new node(0, 1e9);
    for(int i = 0; i < q; i++){
        int a, b, c; cin >> a >> b >> c;
        queries.push_back(query_struct(a, b, c, i));
    }
    sort(queries.begin(), queries.end(), [&](query_struct x, query_struct y){
        if(x.c == y.c){
            return x.idx < y.idx;
        }
        return x.c > y.c;
    });
    vector<int> ans(q);
    for(auto &query : queries){
        int a = query.a, b = query.b, c = query.c, ix = query.idx;
        if(ix == -1){
            //cout << "Adding to tree\n";
            OUT(a);
            OUT(b);
            OUT(c);
            root->add(a, b);
        }
        else{
            //cout << "Processing query\n";
            OUT(a);
            OUT(b);
            OUT(c);
            ans[ix] = root->query(a, 1e9, b);
            OUT(ans[ix]);
        }
    }
    for(auto x : ans){
        cout << x << '\n';
    }
}

signed main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int tt; tt = 1;
    while (tt--) {
        solve();
    }
}