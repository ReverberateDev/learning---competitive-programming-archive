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

const int inf = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 2, inf), pre1(n + 2), suf1(n + 2, 0), pre2(n + 2), suf2(n + 2, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == a[i - 1]){
            pre1[i] = pre1[i - 1];
        }
        else{
            pre1[i] = i;
        }
        pre2[i] = pre2[i - 1] + a[i];
    }
    for(int i = n; i >= 1; i--){
        if(a[i] == a[i + 1]){
            suf1[i] = suf1[i + 1];
        }
        else{
            suf1[i] = i;
        }
        suf2[i] = suf2[i + 1] + a[i];
    }
    //1 2 2 2 3 3 3 (3, 6)
    for(int i = 1; i <= n; i++){
        int val = a[i];
        if(a[i - 1] != inf && a[i - 1] > a[i]){
            cout << "1 ";
            continue;
        }
        if(a[i + 1] != inf && a[i + 1] > a[i]){
            cout << "1 ";
            continue;
        }
        //left
        int res = inf;
        int lo = i - pre1[i - 1] + 1, hi = i - 1, ans = inf;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(suf2[i - mid] - suf2[i] > val){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        res = min(res, ans);
        //right
        lo = suf1[i + 1] - i + 1, hi = n - i - 1, ans = inf;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(pre2[i + mid] - pre2[i] > val){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        res = min(res, ans);
        if(res == inf){
            cout << "-1 ";
        }
        else{
            cout << res << " ";
        }
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
ans = fastest time for neighbouring nodes to become larger than current node
either the left side or right side
must be a pre or suf of our current index
let this be of length k, all of these elements MUST be eaten together

*/