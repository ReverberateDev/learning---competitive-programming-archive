#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

struct DSU {
    int n, num_groups;
    vector<int> p, grpsize;
    
    DSU(int _n) : n(_n), num_groups(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        grpsize.resize(n, 1);
    }
    int par(int x) {
        return (p[x] == x) ? x : (p[x] = par(p[x]));
    }
    int getGrpSize(int x){
        return grpsize[par(x)];
    }
    bool isSameGroup(int a, int b) {
        return par(a) == par(b);
    }

    void merge(int a, int b) {
        a = par(a), b = par(b);
        if (a == b) return;

        num_groups--;
        if (grpsize[a] < grpsize[b]) {
            p[a] = b;
            grpsize[b] += grpsize[a];
        } else {
            p[b] = a;
            grpsize[a] += grpsize[b];
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    DSU dsu1(3);
    dsu1.merge(1, 2);
    dsu1.merge(1, 3);
    cout << dsu1.grpsize[1]; // Should print 1 (true)
}
