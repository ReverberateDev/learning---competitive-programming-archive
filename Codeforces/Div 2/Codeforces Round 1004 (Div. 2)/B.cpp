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
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    deque<int> dq;
    for(int i = 0; i < n; i++){
        dq.push_back(A[i]);
    }
    while(!dq.empty()){
        auto curr = dq.front();
        dq.pop_front();
        if(!dq.empty() && dq.front() != curr){
            cout << "NO\n";
            return;
        }
        dq.pop_front();
        int cnt = 0;
        while(!dq.empty() && dq.front() == curr){
            cnt++;
            dq.pop_front();
        }
        while(cnt--){
            dq.push_front(curr + 1);
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