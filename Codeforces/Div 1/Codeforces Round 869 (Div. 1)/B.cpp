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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int, int>> edges;
    for(int i = 0; i < n; i++){
        if(adj[i].size() >= 4){
            vector<bool> nei(n, false);
            for(int j : adj[i]){
                nei[j] = true;
            }
            vector<int> pv(n, -1);
            int win = -1;
            pv[i] = -2;
            for(int j : adj[i]){
                if(pv[j] == -1){
                    vector<int> que(1, j);
                    pv[j] = i;
                    for(int idx = 0; idx < (int) que.size(); idx++){
                        int v = que[idx];
                        for(int nv : adj[v]){
                            if(pv[nv] == -1){
                                que.push_back(nv);                            
                                pv[nv] = v;
                                if(win == -1 && nei[nv]){
                                    win = nv;
                                }
                            }                            
                        }
                    }
                }
            }
            if(win != -1){
                edges.push_back({i, win});
                for(int v = win; v != i; v = pv[v]){
                    edges.push_back({v, pv[v]});
                }
                vector<bool> used(n, false);
                for(auto &[u, v] : edges){
                    used[u] = true;
                    used[v] = true;
                }
                vector<int> tail;
                for(auto j : adj[i]){
                    if(!used[j]){
                        tail.push_back(j);
                    }
                }
                for(int j = 0; j < 2; j++){
                    edges.push_back({tail[j], i});
                }
                break;
            }
        }
    }
    if(!edges.empty()){
        cout << "YES\n";
        cout << edges.size() << '\n';
        for(auto [u, v] : edges){
            cout << u + 1 << ' ' << v + 1 << '\n';
        }
    } 
    else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}