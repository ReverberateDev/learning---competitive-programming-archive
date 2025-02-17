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
    vector<int> vect(n);
    unordered_map<int, int> distinct;
    for(int i = 0; i < n; i++){
        cin >> vect[i];
        distinct[vect[i]]++;
    }
    pair<int, int> ans;
    int res = n - distinct.size();
    function<bool(int)> check = [&](int k) -> bool {
        int window_size = n - k;
        unordered_map<int, int> mp;
        int distincts = 0;
        for(int i = 0; i < window_size; i++){
            mp[vect[i]]++;
            if(mp[vect[i]] == distinct[vect[i]]){
                distincts++;
            }
        }
        if(k - (distinct.size() - distincts) == res){
            ans = make_pair(0, window_size - 1);
            return true;
        }
        for(int i = window_size; i < n; i++){
            mp[vect[i]]++;
            if(mp[vect[i]] == distinct[vect[i]]){
                distincts++;
            }
            if(mp[vect[i - window_size]] == distinct[vect[i - window_size]]){
                distincts--;
            }
            mp[vect[i - window_size]]--;
            if(k - (distinct.size() - distincts) == res){
                ans = make_pair(i - window_size + 1, i);
                return true;
            }
        }
        return false;
    };
    int lo = 0, hi = n, temp = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            temp = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    if(temp == n){
        cout << "0\n";
        return;
    }
    cout << ans.first + 1 << " " << ans.second + 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}