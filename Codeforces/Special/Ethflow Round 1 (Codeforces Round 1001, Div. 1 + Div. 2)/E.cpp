#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

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
            info[idx] += val;
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
        res = Info(val + other.val);
        return res;
    }
};

void solve(){
    int n; cin >> n;
    map<int, vector<int>> mp;
    vector<vector<int>> adj(n + 1, vector<int>());
    for(int i = 1; i <= n; i++){
        int tmp; cin >> tmp;
        mp[tmp].push_back(i);
    }
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    vector<int> start(n + 1), end(n + 1);
    function<void(int, int)> euler_tour = [&](int idx, int par) {
        start[idx] = ++cnt;
        for(int nidx : adj[idx]){
            if(nidx == par){
                continue;
            }
            euler_tour(nidx, idx);
        }
        end[idx] = cnt;
    };
    euler_tour(1, -1);
    segmentTree<int> segTree(n + 5, 0);
    int lim = 0;
    for(auto itr = mp.rbegin(); itr != mp.rend(); itr++){
        for(auto idx : itr->second){
            if(DEBUG){
                cout << "start idx: " << start[idx] << '\n';
                cout << "end idx: " << end[idx] << '\n';
                cout << "idx: " << idx << '\n';
                cout << "weight: " << itr->first << '\n';
            }
            int amt = segTree.query(0, start[idx] - 1);
            amt += segTree.query(end[idx] + 1, n + 1);
            if(amt >= 1){
                cout << idx << '\n';
                return;
            }
        }
        for(auto idx : itr->second){
            segTree.update(start[idx], 1);
        }
    }
    cout << "0\n";
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