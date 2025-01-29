#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

template<class T>
struct segmentTree{
    int n;
    vector<T> info;
    segmentTree(){
        
    }
    segmentTree(int sz){
        vector<T> _info(sz, T());
        init(_info);
    }
    void init(vector<T> _info){
        n = _info.size();
        int sz = 2 * (1 << (__lg(n - 1) + 1));
        info.assign(sz, T());
        function<void(int, int, int)> build = [&](int idx, int s, int e){
            if(s == e){
                info[idx] = _info[s];
                return;
            }
            int m = (s + e) / 2;
            build(2 * idx, s, m);
            build(2 * idx + 1, m + 1, e);
            combine(idx);
        };
        build(1, 1, n);
    }
    void update(int idx, int s, int e, int x, const T &val){
        if(s == e){
            info[idx] = val;
            return;
        }
        int m = (s + e) / 2;
        if(x <= m){
            update(2 * idx, s, m, x, val);
        }
        else{
            update(2 * idx + 1, m + 1, e, x, val);
        }
        combine(idx);
    }
    void update(int x, const T &val){
        update(1, 1, n, x, val);
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
            return query(2 * idx + 1, s, m + 1, x, y);
        }
        return query(2 * idx, s, m, x, m) + query(2 * idx + 1, m + 1, e, m + 1, y);
    }

    T query(int x, int y) {
        return query(1, 1, n, x, y);
    }
    void combine(int idx){
        info[idx].combine(info[2 * idx], info[2 * idx + 1]);
    }
};


struct Info{
    bool possible;
    int card;
    Info(){
        possible = false;
        card = -1;
    }
    Info(bool _possible, int _card){
        possible = _possible;
        card = _card;
    }
    void combine(Info &a, Info &b){
        possible = a.possible | b.possible;
        if(a.possible == 1){
            card = a.card;
        }
        else{
            card = b.card;
        }
    }
    Info operator+(const Info &other){
        Info res;
        res.possible = possible | other.possible;
        if(possible == 1){
            res.card = card;
        }
        else{
            res.card = other.card;
        }
        return res;
    }
};

void solve(){
    int n; cin >> n;
    vector<map<int, int>> values(3);
    vector<segmentTree<Info>> segTrees(3);
    vector<pair<int, int>> dp(n + 1);
    if(DEBUG){
        cout << "test" << '\n';
    }
    for(int i = 0; i < 3; i++){
        segTrees[i] = segmentTree<Info>(n + 1);
    }
    /*
    for(int i = 0; i < 3; i++){
        segTrees[i] = segmentTree<Info>(n + 1);
        for(int no = 1; no <= n; no++){
            int val; cin >> val;
            values[i][no] = val;
            Info tmp;
            if(no == n){
                tmp = Info(true, no);
            }
            else{
                tmp = Info(false, no);
            }
            segTrees[i].update(val, tmp);
        }
    }
    */
    if(DEBUG){
        cout << "Testing initial segment trees\n";
        for(int i = 0; i < 3; i++){
            for(int val = 1; val <= n; val++){
                auto tmp = segTrees[i].query(val, val);
                cout << "Segment tree " << i << " val: " << val << '\n';
                cout << tmp.possible << " " << tmp.card << '\n';
            }
        }
    }
    /*
    for(int no = n - 1; no >= 1; no--){
        for(int i = 0; i < 3; i++){
            int val = values[i][no];
            if(val == n){
                continue;
            }
            Info tmp = segTrees[i].query(val + 1, n);
            if(!tmp.possible){
                continue;
            }
            dp[no] = {tmp.card, i};
            for(int j = 0; j < 3; j++){
                val = values[j][no];
                Info tmp2 = Info(true, no);
                segTrees[j].update(val, tmp2);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        auto [a, b] = dp[i];
        cout << a << " " << b << '\n';
    }
    */
}

signed main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}