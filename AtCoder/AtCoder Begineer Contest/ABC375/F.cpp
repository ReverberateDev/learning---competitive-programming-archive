#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    set<pair<int, int>>adjlist[n + 1];
    vector<vector<int>>queries;
    int dp[n + 1][n + 1];

    vector<vector<int>>roads;
    vector<int>tmp = {-1};
    roads.push_back(tmp);
    for(int i = 0; i < m; i++){
        tmp.clear();
        int a, b, c; cin >> a >> b >> c;
        tmp.push_back(1);
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        roads.push_back(tmp);
    }
    for(int i = 0; i < q; i++){
        vector<int>tmp;
        int t; cin >> t;
        tmp.push_back(t);
        if(t == 1){
            int x; cin >> x;
            tmp.push_back(x);
            queries.push_back(tmp);
            roads[x][0] = 0;
        }
        else{
            int x, y; cin >> x >> y;
            tmp.push_back(x);
            tmp.push_back(y);;
            queries.push_back(tmp);
        }
    }

    if(DEBUG){
        cout << "roads\n";
        for(auto a : roads){
            for(auto b : a){
                cout << b << " ";
            }
            cout << '\n';
        }
    }
    
    for(int x = 1; x <= m; x++){
        auto i = roads[x];
        if(i[0]){
            int a = i[1], b = i[2], c = i[3];
            if(dp[a][b] == -1){
                dp[a][b] = c;
                dp[b][a] = c;
            }
            else{
                dp[a][b] = min(dp[a][b], c);
                dp[b][a] = min(dp[b][a], c);
            }
        }
    }
    if(DEBUG){
        cout << "dp\n";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << dp[i][j] << " ";
            }
            cout << '\n';
        }
    }
    for(int i = 1; i <= n; i++){
        dp[i][i] = 0;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dp[i][k] == -1 || dp[k][j] == -1){
                    continue;
                }
                if (dp[i][j] == -1 || dp[i][j] > dp[i][k] + dp[k][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    vector<int>ans;
    for(int i = q - 1; i >= 0; i--){
        auto query = queries[i];
        if(query[0] == 1){
            int x = query[1];
            int a = roads[x][1], b = roads[x][2], c = roads[x][3];
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    int best = dp[i][j];
                    if(dp[i][a] != -1 && dp[b][j] != -1){
                        best = dp[i][a] + c + dp[b][j];
                    }
                    if(dp[i][b] != -1 && dp[j][a] != -1){
                        if(best == -1){
                            best = dp[i][b] + c + dp[a][j];
                        }
                        else{
                            best = min(best, dp[i][b] + c + dp[a][j]);
                        }
                    }
                    if(dp[i][j] == -1){
                        dp[i][j] = best;
                    }
                    else{
                        dp[i][j] = min(dp[i][j], best);
                    }
                }
            }
            if(DEBUG){
                cout << "c\n";
                cout << c << '\n';
                cout << "dp\n";
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j <= n; j++){
                        cout << dp[i][j] << " ";
                    }
                    cout << '\n';
                }
            }
        }
        else{
            int x = query[1];
            int y = query[2];
            ans.push_back(dp[x][y]);
        }
    }
    while(!ans.empty()){
        cout << ans.back() << '\n';
        ans.pop_back();
    }
}