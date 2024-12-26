#include <bits/stdc++.h>
using namespace std;
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e9 + 5;
const int MAXN = 5001;

int n, m, t;
pair<int, int> memo[MAXN][MAXN];
pair<int, int> nullpair = make_pair(-1, -1);
vector<pair<int, int>> adjlist[MAXN];

pair<int, int> dp(int idx, int tot) {
    if (memo[idx][tot] != nullpair) {
        return memo[idx][tot];
    }
    if (idx == 1 && tot == 1) {
        return make_pair(0, -1);
    }
    if (tot < 1) {
        return make_pair(inf, -1);
    }

    int btime = inf, bpar = -1;
    for (auto [pidx, dst] : adjlist[idx]) {
        auto [time, _] = dp(pidx, tot - 1);
        int ntime = min(inf, time + dst);
        if (ntime < btime) {
            btime = ntime;
            bpar = pidx;
        }
    }

    pair<int, int> res = make_pair(btime, bpar);
    return memo[idx][tot] = res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t;

    // Input adjacency list
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjlist[b].push_back({a, c}); // Path from a to b
    }

    // Initialize memo table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            memo[i][j] = nullpair;
        }
    }

    // Iterate over possible path lengths
    for (int i = n; i >= 1; i--) {
        auto [dist, par] = dp(n, i);
        if (dist <= t) {
            vector<int> path;
            int curr = par;
            path.push_back(n);
            path.push_back(curr);
            for (int j = i - 1; j >= 2; j--) {
                auto [_, par] = dp(curr, j);
                path.push_back(par);
                curr = par;
            }
            reverse(path.begin(), path.end());
            cout << path.size() << '\n';
            for (auto i : path) {
                cout << i << " ";
            }
            break;
        }
    }

    return 0;
}
