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

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1,  0, 0, 1, -1, 1, -1};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    unordered_map<int, int> mp;
    function<bool(int, int)> check = [&](int i, int j) -> bool {
        int val = grid[i][j];
        for(int x = 0; x < 4; x++){
            int ni = i + dx[x], nj = j + dy[x];
            if(val == grid[ni][nj]){
                return true;
            }
        }
        return false;
    };
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mp.find(grid[i][j]) == mp.end()){
                mp[grid[i][j]] = 1;
            }
            if(check(i, j)){
                mp[grid[i][j]] = 2;
            }
        }
    }
    vector<int> colours;
    for(auto [c, v] : mp){
        colours.push_back(v);
    }
    sort(colours.rbegin(), colours.rend());
    int ans = 0;
    for(int i = 1; i < colours.size(); i++){
        ans += colours[i];
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}

/*
We choose a final colour, all other colours must change to this colour
is there a point changing a -> b -> c? no
we need to change each colour to the final colour
for each colour, what is the fastest to change all of them?
*/