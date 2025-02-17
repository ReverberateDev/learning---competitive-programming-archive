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
    string s; cin >> s;
    int cnt = 1;
    for(int i = 1; i < s.length(); i++){
        if(s[i] != s[i - 1]){
            cnt++;
        }
    }
    if(s[0] == '0'){
        cnt--;
    }
    cout << cnt << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}