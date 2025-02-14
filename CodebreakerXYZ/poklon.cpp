#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

struct query{
    int l, r, idx;
    query(int _l, int _r, int _idx): l(_l), r(_r), idx(_idx){

    };
    bool operator<(const query &other) const {
        return l < other.l;
    }
};

struct datastruct1{
    map<int, vector<int>> mp;
    void add(int val, int idx){
        mp[val].push_back(idx);
        if(mp[val].size() > 1){
            sort(mp[val].begin(), mp[val].end());
            while(mp[val].size() > 3){
                mp[val].pop_back();
            }
        }
    }
    int query(int val, int idx){
        if(mp[val].size() < idx){
            cout << "Error\n";
            return -1;
        }
        else{
            return mp[val][idx - 1];
        }
    }
};

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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> vect(n);
    for(int i = 0; i < n; i++){
        cin >> vect[i];
    }
    vector<query> queries;
    for(int idx = 0; idx < q; idx++){
        int l, r; cin >> l >> r;
        l--, r--;
        queries.push_back(query(l, r, idx));
    }
    sort(queries.begin(), queries.end());
    reverse(queries.begin(), queries.end());
    if(DEBUG){
        cout << "Debugging queries\n";
        for(auto i : queries){
            OUT(i.l);
            OUT(i.r);
            OUT(i.idx);
        }
    }
    segmentTree<int> segTree1(n + 1, 0);
    segmentTree<int> segTree2(n + 1, 0);
    datastruct1 ds1;
    map<int, int> occurences;
    int ptr = n;
    vector<pair<int, int>> ans;
    for(query curr : queries){
        int l = curr.l, r = curr.r, idx = curr.idx;
        int p, q;
        int adv, prev;
        while(ptr > l){
            ptr--;
            occurences[vect[ptr]]++;
            if(DEBUG){
                cout << "Debugging querying\n";
                OUT(ptr);
            }
            if(occurences[vect[ptr]] == 1){
                ds1.add(vect[ptr], ptr);
            }
            else if(occurences[vect[ptr]] == 2){
                //2 new
                ds1.add(vect[ptr], ptr);
                adv = ds1.query(vect[ptr], 2);
                segTree1.update(adv, 1);
            }
            else if(occurences[vect[ptr]] == 3){
                //2 change
                prev = ds1.query(vect[ptr], 2);
                segTree1.update(prev, -1);
                //2 new
                ds1.add(vect[ptr], ptr);
                adv = ds1.query(vect[ptr], 2);
                segTree1.update(adv, 1);
                //3 new
                adv = ds1.query(vect[ptr], 3);
                segTree2.update(adv, 1);
            }
            else if(occurences[vect[ptr]] > 3){
                //2 change
                prev = ds1.query(vect[ptr], 2);
                segTree1.update(prev, -1);
                //3 change
                prev = ds1.query(vect[ptr], 3);
                segTree2.update(prev, -1);
                //2 new
                ds1.add(vect[ptr], ptr);
                adv = ds1.query(vect[ptr], 2);
                segTree1.update(adv, 1);
                //3 new
                adv = ds1.query(vect[ptr], 3);
                segTree2.update(adv, 1);
            }
        }
        p = segTree1.query(l, r);
        q = segTree2.query(l, r);
        if(DEBUG){
            cout << "Debugging answering\n";
            OUT(l);
            OUT(r);
            OUT(idx);
            OUT(q);
            OUT(p);
        }
        int res = p - q;
        ans.push_back(make_pair(idx, res));
    }
    sort(ans.begin(), ans.end());
    for(auto [_, res] : ans){
        cout << res << '\n';
    }
}