#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr << (#x) << '=' << (x) << endl

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
        res = Info(val + other.val);
        return res;
    }
};