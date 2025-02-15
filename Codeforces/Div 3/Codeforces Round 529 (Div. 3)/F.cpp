#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
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

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        edges.push_back(make_pair(w, make_pair(x, y)));
    }
    int tmp = min_element(a.begin(), a.end()) - a.begin();
    for(int i = 0; i < n; i++){
        if(i != tmp){
            edges.push_back(make_pair(a[tmp] + a[i], make_pair(tmp, i)));
        }
    }
    DSU dsu1(n + 1);
    int ans = 0;
    sort(edges.begin(), edges.end());
    for(auto edge : edges){
        if(!dsu1.isSameGroup(edge.second.first, edge.second.second)){
            dsu1.merge(edge.second.first, edge.second.second);
            ans += edge.first;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt; tt = 1;
    while(tt--){
        solve();
    }
}

/*
3 2
1 3 3
2 3 5
2 1 1

5, (2, 3)
1, (2, 1)
non special

*/