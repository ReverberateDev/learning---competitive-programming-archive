#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

vector<pair<pair<int, int>, pair<int, int>>> shapes;
const int inf = 1e18;

void solve(){
    int n; cin >> n;
    vector<vector<int>> grid(2, vector<int>(n));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            char tmp; cin >> tmp;
            grid[i][j] = (tmp == 'A' ? 1ll : 0ll);
        }
    }
    if(DEBUG){
        cout << "Testing grid\n";
        for(auto a : grid){
            for(auto b : a){
                cout << b << " ";
            }
            cout << '\n';
        }
    }
    function<int(int, int)> calc = [&](int col, int type){
        function<int(int, int)> amt = [&](int i, int j){
            if(j < 0){
                return inf;
            }
            else{
                return grid[i][j];
            }
        };
        if(type == 5 || type == 6 || type == 7){
            int ans = 0, actual = 0;
            int r = 0;
            int c = col - shapes[type].first.first;
            for(int i = 0; i < shapes[type].first.second; i++, c--){
                ans += amt(r, c);
            }
            actual += (ans >= 2);
            if(ans >= inf){
                return -inf;
            }
            ans = 0;
            r = 1;
            c = col - shapes[type].second.first;
            for(int i = 0; i < shapes[type].second.second; i++, c--){
                ans += amt(r, c);   
            }
            actual += (ans >= 2);
            if(ans >= inf){
                return -inf;
            }
            return actual;
        }
        int ans = 0;
        int r = 0;
        int c = col - shapes[type].first.first;
        for(int i = 0; i < shapes[type].first.second; i++, c--){
            ans += amt(r, c);
        }
        r = 1;
        c = col - shapes[type].second.first;
        for(int i = 0; i < shapes[type].second.second; i++, c--){
            ans += amt(r, c);   
        }
        if(ans >= inf){
            return -inf;
        }
        return (ans >= 2 ? 1ll : 0ll);
    };
    vector<vector<int>> memo(n, vector<int>(8, -1));
    function<int(int, int)> dp = [&](int col, int type){
        if(col < 0){
            return -inf;
        }
        if(memo[col][type] != -1){
            return memo[col][type];
        }
        int res = -inf, add = calc(col, type);
        if(type == 1){
            if(col == 1){
                return add;
            }
            res = max(res, dp(col - 2, 3) + add);
            res = max(res, dp(col - 2, 4) + add);
            res = max(res, dp(col - 2, 6) + add);
        }
        else if(type == 2){
            if(col == 1){
                return add;
            }
            res = max(res, dp(col - 2, 3) + add);
            res = max(res, dp(col - 2, 4) + add);
            res = max(res, dp(col - 2, 6) + add);
        }
        else if(type == 3){
            res = max(res, dp(col - 1, 1) + add);
            res = max(res, dp(col - 1, 7) + add);
        }
        else if(type == 4){
            res = max(res, dp(col - 1, 2) + add);
            res = max(res, dp(col - 1, 5) + add);
        }
        else if(type == 5){
            res = max(res, dp(col - 3, 2) + add);
            res = max(res, dp(col - 3, 5) + add);
        }
        else if(type == 6){
            if(col == 2){
                return add;
            }
            res = max(res, dp(col - 3, 3) + add);
            res = max(res, dp(col - 3, 4) + add);
            res = max(res, dp(col - 3, 6) + add);
        }
        else{
            res = max(res, dp(col - 3, 1) + add);
            res = max(res, dp(col - 3, 7) + add);
        }
        return memo[col][type] = res;
    };
    if(DEBUG){
        cout << "Debugging DP\n";
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= 7; j++){
                cout << max(-1ll, dp(i, j)) << " ";
            }
            cout << '\n';
        }
    }
    cout << max(dp(n - 1, 3), max(dp(n - 1, 4), dp(n - 1, 6))) << '\n';
}

void init(){
    shapes.push_back({{-1, -1}, {-1, -1}});
    shapes.push_back({{1, 1}, {0, 2}});
    shapes.push_back({{0, 2}, {1, 1}});
    shapes.push_back({{0, 2}, {0, 1}});
    shapes.push_back({{0, 1}, {0, 2}});
    shapes.push_back({{0, 3}, {1, 3}});
    shapes.push_back({{0, 3}, {0, 3}});
    shapes.push_back({{1, 3}, {0, 3}});
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}