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
    segmentTree(int _n, T _v = T()){
        init(vector<T>(_n, _v));
    }

    segmentTree(vector<T> _vect){
        init(_vect);
    }

    void init(vector<T> _vect){
        n = _vect.size();
        int sz = (1 << (__lg(n - 1) + 1));
        info.assign(sz * 2, T());
        function<void(int, int, int)> build = [&](int idx, int l, int r){
            if(l == r){
                info[idx] = _vect[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * idx, l, m);
            build(2 * idx + 1, m + 1, r);
            info[idx] = info[2 * idx].combine(info[2 * idx + 1]);
        };
        build(1, 0, n - 1);
    }

    void update(int idx, int l, int r, int ti, const T &val){
        if(l == r){
            info[idx] = val;
            return;
        }
        int m = (l + r) / 2;
        if(ti <= m){
            update(2 * idx, l, m, ti, val);
        }
        else{
            update(2 * idx + 1, m + 1, r, ti, val);
        }
        info[idx] = info[2 * idx].combine(info[2 * idx + 1]);
    }
    void update(int ti, const T &val){
        update(1, 0, n - 1, ti, val);
    }
};

struct Info{
    int A, B, C, D, ans;
    Info(){
        A = B = C = D = ans = 0;
    }
    Info(int Ai, int Av){
        A = -Av + Ai;
        B = Av - Ai;
        C = Av + Ai;
        D = -Av - Ai;
        ans = 0;
    }
    Info combine(const Info y){
        Info res = Info();
        res.A = max(A, y.A);
        res.B = max(B, y.B);
        res.C = max(C, y.C);
        res.D = max(D, y.D);
        res.ans = max({A + y.B, C + y.D, ans, y.ans});
        return res;
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<Info> vect;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        vect.push_back(Info(i, a));
    }
    segmentTree<Info> st(vect);
    cout << st.info[1].ans << '\n';
    while(q--){
        int a, b; cin >> a >> b;
        a--;
        st.update(a, Info(a, b));
        cout << st.info[1].ans << '\n';
    }
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