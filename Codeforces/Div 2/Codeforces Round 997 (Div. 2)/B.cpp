#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

vector<vector<int>> adj;
vector<bool> visited;
stack<int> stk;

void dfs(int idx){
    visited[idx] = true;
    for(auto nidx : adj[idx]){
        if(visited[nidx]){
            continue;
        }
        dfs(nidx);
    }
    stk.push(idx);
}

void solve(){
    int n; cin >> n;
    visited.resize(n + 1);
    visited.assign(n, false);
    adj.resize(n + 1, vector<int>(0));
    adj.assign(n + 1, vector<int>(0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char tmp; cin >> tmp;
            if(tmp == '1'){
                if(i < j){
                    adj[i].push_back(j);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << '\n';
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