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

struct query{
    int ans, x, idx;
    query(int _x, int _idx): x(_x), idx(_idx) {
        ans = -1;
    };
    bool operator<(const query& other) const {
        return x < other.x;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> slimes(n), pre(n + 2, 0);
    for(int i = 0; i < n; i++){
        cin >> slimes[i];
    }
    for(int i = n - 1; i >= 0; i--){
        pre[i] = pre[i + 1] ^ slimes[i];
    }
    vector<query> queries;
    vector<int> ans(q);
    int idx = 0;
    while(q--){
        int tmp; cin >> tmp;
        queries.push_back(query(tmp, idx++));
    }
    sort(queries.begin(), queries.end());
    int curr = n - 1;
    for(auto &current_query : queries){
        function<bool()> check = [&]() -> bool {
            int now = current_query.x ^ pre[curr + 1];
            OUT(now);
            return slimes[curr] <= now;
        };
        while(curr > -1 && check()){
            curr--;
        }
        OUT(curr);
        current_query.ans = (n - 1) - curr;
        ans[current_query.idx] = current_query.ans;
    }
    for(auto i : ans){
        cout << i << " ";
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

/*
The bigger the slime given, the more slimes it will pass
A > B
B passes through k slimes before dying
these k slimes will give C, the final boss is D
A ^ k >= B ^ k
*/