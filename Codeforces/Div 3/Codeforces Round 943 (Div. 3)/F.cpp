#include <bits/stdc++.h>
using namespace std;
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
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), b(n + 1, 0);
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = b[i - 1] ^ a[i];
        mp[b[i]].push_back(i);
    }
    while(q--){
        int l, r; cin >> l >> r;
        if(b[l - 1] == b[r]){
            cout << "YES\n";
            continue;
        }
        auto M2 = upper_bound(mp[b[l - 1]].begin(), mp[b[l - 1]].end(), r);
        if(M2 == mp[b[l - 1]].begin()){
            cout << "NO\n";
            continue;
        }
        M2--;
        auto M1 = lower_bound(mp[b[r]].begin(), mp[b[r]].end(), l);
        if(M1 == mp[b[r]].end()){
            cout << "NO\n";
            continue;
        }
        if(*M1 < *M2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}