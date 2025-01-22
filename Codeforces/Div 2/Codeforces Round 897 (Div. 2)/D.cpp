#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n, k; cin >> n >> k;
    vector<int> b(n);
    for(auto &i : b){
        cin >> i;
        i--;
    }
    if(k == 1){
        int tmp = 1;
        for(int i = 0; i < n; i++){
            tmp &= (b[i] == i);
        }
        if(tmp){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
        return;
    }
    int tmp = 1;
    for(int i = 0; i < n; i++){
        tmp &= (b[i] != i);
    }
    if(!tmp){
        cout << "No\n";
        return;
    }
    vector<vector<int>> graph(n), revgraph(n);
    for(int i = 0; i < n; i++){
        graph[i].push_back(b[i]);
        revgraph[b[i]].push_back(i);
    }
    vector<int> vis(n), ver(n), ok(n);
    function<void(int, int)> DFS = [&](int u, int x){
        vis[u] = x;
        ver.push_back(u);
        for(auto v : graph[u]){
            if(!vis[v]){
                DFS(v, x + 1);
            }
            else if(vis[v] > 0 && ((x + 1) - vis[v]) == k){
                for(int i = ver.size() - 1; ; i--){
                    ok[ver[i]] = 1;
                    if(ver[i] == v){
                        break;
                    }
                }
            }
        }
        ver.pop_back();
        vis[u] = -1;
    };
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            DFS(i, 1);
        }
    }
    function<void(int)> DFS2 = [&](int u){
        for(auto v : revgraph[u]){
            if(!ok[v]){
                ok[v] = 1;
                DFS2(v);
            }
        }
    };
    for(int i = 0; i < n; i++){
        if(ok[i]){
            DFS2(i);
        }
    }
    if(*min_element(ok.begin(), ok.end()) == 0){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
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