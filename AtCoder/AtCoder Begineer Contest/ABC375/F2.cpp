#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define MAXN 200001

const int inf = (int)1e18;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    int a[MAXN], b[MAXN], c[MAXN];
    int op[MAXN], x[MAXN], y[MAXN];
    int dp[300][300];
    bool del[MAXN];
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
    }
    for(int i = 0; i < q; i++){
        cin >> op[i];
        if(op[i] == 1){
            cin >> x[i];
            x[i]--;
            del[x[i]] = true;
        }
        else{
            cin >> x[i] >> y[i];
            x[i]--, y[i]--;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                dp[i][j] = inf;
            }
        }
    }
    for(int i = 0; i < m; i++){
        if(del[i]){
            continue;
        }
        int a2 = a[i], b2 = b[i], c2 = c[i];
        dp[a2][b2] = min(dp[a2][b2], c2);
        dp[b2][a2] = min(dp[b2][a2], c2);
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    vector<int>ans;
    for(int k = q - 1; k >= 0; k--){
        if(op[k] == 1){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    int a2 = a[x[k]], b2 = b[x[k]], c2 = c[x[k]];
                    dp[i][j] = min(dp[i][j], dp[i][a2] + c2 + dp[b2][j]);
                    dp[i][j] = min(dp[i][j], dp[i][b2] + c2 + dp[a2][j]);
                }
            }
        }
        else{
            int a2 = x[k], b2 = y[k];
            ans.push_back((dp[a2][b2] == inf ? -1 : dp[a2][b2]));
        }
    }
    while(!ans.empty()){
        cout << ans.back() << '\n';
        ans.pop_back();
    }
}