#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
//#define DEBUG 1

#ifdef DEBUG
    #define OUT(x) cerr << (#x) << '=' << (x) << endl
    #define OUT2(c) cerr << (#c) << " = {"; for (auto it = (c).begin(); it != (c).end(); ++it) cerr << (it == (c).begin() ? "" : ", ") << *it; cerr << "}" << endl;
#else
    #define OUT(x)
    #define OUT2(c)
#endif

template<class T>
struct segmentTree {
    int n;
    vector<T> info;

    segmentTree(int _n, T _v = T()) {
        init(vector<T>(_n, _v));
    }
    
    segmentTree(vector<T> _vect) {
        init(_vect);
    }

    void init(vector<T> _vect) {
        n = _vect.size();
        int sz = 1 << (__lg(n - 1) + 1);
        info.assign(sz * 2, T());
        function<void(int, int, int)> build = [&](int idx, int s, int e) {
            if (s == e) {
                info[idx] = _vect[s];
                return;
            }
            int m = (s + e) / 2;
            build(2 * idx, s, m);
            build(2 * idx + 1, m + 1, e);
            info[idx] = info[2 * idx] + info[2 * idx + 1];
        };
        build(1, 0, n - 1);
    }

    T query(int idx, int s, int e, int x, int y) {
        if(s == x && e == y){
            return info[idx];
        }
        int m = (s + e) / 2;
        if(y <= m){
            return query(2 * idx, s, m, x, y);
        }
        if(x > m){
            return query(2 * idx + 1, m + 1, e, x, y);
        }
        return query(2 * idx, s, m, x, m) + query(2 * idx + 1, m + 1, e, m + 1, y);
    }

    T query(int x, int y) {
        return query(1, 0, n - 1, x, y);
    }

    void update(int idx, int s, int e, int pos, const T& val) {
        if (s == e) {
            info[idx] = val;
            return;
        }
        int m = (s + e) / 2;
        if (pos <= m) {
            update(2 * idx, s, m, pos, val);
        } 
        else {
            update(2 * idx + 1, m + 1, e, pos, val);
        }
        info[idx] = info[2 * idx] + info[2 * idx + 1];
    }

    void update(int pos, const T& val) {
        update(1, 0, n - 1, pos, val);
    }
};

struct Info {
    int val;

    Info() {
        val = 0;
    }

    Info(int _val) {
        val = _val;
    }

    Info operator+(const Info& other) const {
        Info res;
        res = Info(max(val, other.val));
        return res;
    }
};

void solve(){
    string s; cin >> s;
    int n = s.length();
    vector<int> A(n + 1 , 0), bal(n + 1, 0), pre(n + 1, 0);
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i++){
        A[i] = (s[i - 1] == '(') ? 1ll : -1ll;
        bal[i] = A[i] + bal[i - 1];
        pre[i] = max(bal[i], pre[i - 1]);
        mp[bal[i]].push_back(i);
    }
    vector<Info> tmp(n + 1);
    for(int i = 0; i <= n; i++){
        tmp[i] = Info(bal[i]);
    }
    segmentTree<Info> segTree(tmp);
    function<int(int)> func = [&](int k) -> int {
        int lim = 2 * bal[k];
        int lo = 1, hi = n - k, ans = -1ll;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(lim >= segTree.query(k + 1, k + mid).val){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    };
    OUT2(A);
    OUT2(bal);
    OUT2(pre);
    int ans = 0;
    for(int k = 1; k < n; k++){
        int L = k + 1, x = bal[k], len = func(k);
        if(len == -1){
            continue;
        }
        int R = k + len;
        ans += upper_bound(mp[x].begin(), mp[x].end(), R) - lower_bound(mp[x].begin(), mp[x].end(), L);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}


/*
val1 + val2 + val3 = 0
val1 - val2 + val3 = 0
2val1 + 2val3 = 0
val1 + val3 = 0
val2 = 0

conditions that must be met
val1 + val3 = 0
val2 = 0
val1

number of opening brackets in val1 must be more than or equal to the number of opening brackets in val2

bal[L - 1] = bal[R] -------- (1)
bal[L - 1] >= bal[i] - bal[L - 1]
2bal[L - 1] >= bal[i] ----------- (2)
maximum bal[i] from i{L, R}

solution:
we check for all L - 1

find the largest value of bal[i] that is less than or equal to 2bal[L - 1]
possible targets will be in indexes 1 to idx

find all R infront of s such that bal[L - 1] = bal[R]
and their value is less than or equal to idx and more than or equal to L

*/