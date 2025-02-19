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

bool check(deque<char> &dq, int mid){
    int n = dq.size();
    for(int i = mid; i < n / 2; i++){
        if(dq[i] != dq[n - i - 1]){
            return false;
        }
    }
    map<char, int> mp;
    for(int i = 0; i < mid; i++){
        mp[dq[i]]++;
    }
    for(int i = n - 1; i >= mid && i >= n - mid; i--){
        if(mp.find(dq[i]) == mp.end() || mp[dq[i]] == 0){
            return false;
        }
        mp[dq[i]]--;
    }
    int evens = 0, odds = 0;
    for(auto [_, val] : mp){
        if(val % 2 == 0){
            evens++;
        }
        else{
            odds++;
        }
    }
    if(odds <= 1){
        return true;
    }
    else{
        return false;
    }
}

//0 1 2 3 4
//mid = 2
void solve() {
    deque<char> dq;
    string s; cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++){
        dq.push_back(s[i]);
    }
    while(dq.size() > 1 && dq.front() == dq.back()){
        dq.pop_front();
        dq.pop_back();
    }
    deque<char> dq2 = dq;
    reverse(dq2.begin(), dq2.end());
    int lo = 0, hi = dq.size(), ans;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(dq, mid) || check(dq2, mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}