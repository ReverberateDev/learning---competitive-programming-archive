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
    vector<int> b(n - 2);
    for(int i = 0; i < n - 2; i++){
        cin >> b[i];
    }
    for(int i = 0; i <= n - 2 - 3; i++){
        if(b[i] == 1 && b[i + 1] == 0 && b[i + 2] == 1){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
1,2,2,2,3,3,4,4,4,4
  0,1,0,0,0,0,1,1
*/