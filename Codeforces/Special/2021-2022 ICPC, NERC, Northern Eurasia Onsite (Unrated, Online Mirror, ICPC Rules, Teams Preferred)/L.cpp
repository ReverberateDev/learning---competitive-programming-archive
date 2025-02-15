#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<int>> adj(n + 1);
    vector<int> ans1, ans2;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<pair<int, int>> path(n + 1, {-1, -1});

    // Function to construct the path
    auto construct_path = [&](vector<int> &ans, int vert) {
        while (vert != -1) {
            ans.push_back(vert);
            vert = path[vert].first;
        }
        reverse(ans.begin(), ans.end());
    };

    // DFS function to detect cycles
    function<bool(int, int, int)> dfs = [&](int vert, int strt, int par) -> bool {
        if(vert == s){
            return false;
        }
        if (path[vert].second != strt && path[vert].first != -1) {  // Found a cycle
            construct_path(ans1, vert);
            path[vert].first = par;
            construct_path(ans2, vert);
            cout << "Possible\n";
            cout << ans1.size() << "\n";
            for (auto i : ans1) cout << i << " ";
            cout << '\n';

            cout << ans2.size() << "\n";
            for (auto i : ans2) cout << i << " ";
            cout << '\n';

            return true;
        }
        path[vert] = {par, strt};
        for (auto nvert : adj[vert]) {
            if (path[nvert].second != strt && path[nvert].first != -1) {  // Found a cycle
                construct_path(ans1, nvert);
                path[nvert].first = vert;
                construct_path(ans2, nvert);
                cout << "Possible\n";
                cout << ans1.size() << "\n";
                for (auto i : ans1) cout << i << " ";
                cout << '\n';

                cout << ans2.size() << "\n";
                for (auto i : ans2) cout << i << " ";
                cout << '\n';

                return true;
            }
            if(path[nvert].first != -1){
                continue;
            }
            if (dfs(nvert, strt, vert)) return true;
        }
        return false;
    };

    for (auto i : adj[s]) {
        if(DEBUG){
            for(auto [a, b] : path){
                OUT(a);
                OUT(b);
            }
            OUT(i);
        }
        if (dfs(i, i, s)) {
            return 0;
        }
    }

    cout << "Impossible\n";
    return 0;
}
