#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;

struct node{
    int idx, dst,hse;
    node(int _idx, int _dst, int _hse){
        idx = _idx;
        dst = _dst;
        hse = _hse;
    };
};

struct cmp{
    bool operator()(node a, node b){
        return a.dst > b.dst;
    }
};

void solve(){
    int n, m, h; cin >> n >> m >> h;
    map<int, bool> horse;
    for(int i = 0; i < h; i++){
        int tmp; cin >> tmp;
        horse[tmp] = true;
    }
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<vector<int>> dist1(n + 1, vector<int>(2, -1)), dist2(n + 1, vector<int>(2, -1));
    priority_queue<node, vector<node>, cmp> pq;
    function<void(vector<vector<int>>&, int)> dijkstra = [&](vector<vector<int>> &dist, int strt) -> void {
        dist[strt][0] = 0;
        pq.push(node(strt, 0 , 0));
        while(!pq.empty()){
            node curr = pq.top();
            pq.pop();
            int idx = curr.idx, dst = curr.dst, hse = curr.hse;
            if(dst > dist[idx][hse]){
                continue;
            }
            if(horse[idx] == true){
                hse = true;
            }
            for(auto [nidx, adst] : adj[idx]){
                int ndst = dst + (hse == true ? adst / 2 : adst);
                if(dist[nidx][hse] != -1 && dist[nidx][hse] <= ndst){
                    continue;
                }
                dist[nidx][hse] = ndst;
                pq.push(node(nidx, ndst, hse));
            }
        }
        for(auto &a : dist){
            for(auto &b : a){
                if(b == -1){
                    b = inf;
                }
            }
        }
        return;
    };
    dijkstra(dist1, 1);
    dijkstra(dist2, n);
    int bst = inf;
    for(int i = 1; i <= n; i++){
        bst = min(bst, max(min(dist1[i][0], dist1[i][1]), min(dist2[i][0], dist2[i][1])));
    }
    cout << (bst >= inf ? -1 : bst) << '\n';
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