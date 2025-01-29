#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int MAXX = 5001;

void calc(vector<vector<int>> &dp, vector<pair<int, int>> &items){
    int n = items.size();
    dp.resize(n, vector<int>(MAXX, -1));
    function<int(int, int)> rec = [&](int idx, int cal) -> int {
        if(idx < 0){
            return 0;
        }
        if(dp[idx][cal] != -1){
            return dp[idx][cal];
        }
        dp[idx][cal] = rec(idx - 1, cal);
        if(items[idx].second <= cal){
            dp[idx][cal] = max(dp[idx][cal], rec(idx - 1, cal - items[idx].second) + items[idx].first);
        }
        return dp[idx][cal];
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < MAXX; j++){
            dp[i][j] = rec(i, j);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x; cin >> n >> x;
    vector<pair<int, int>> A, B, C;
    for(int i = 0; i < n; i++){
        int v, a, c; cin >> v >> a >> c;
        if(v == 1){
            A.push_back({a, c});
        }
        else if(v == 2){
            B.push_back({a, c});
        }
        else{
            C.push_back({a, c});
        }
    }
    if(A.empty() || B.empty() || C.empty()){
        cout << "0";
        return 0;
    }
    vector<vector<int>> dp1, dp2, dp3;
    calc(dp1, A);
    calc(dp2, B);
    calc(dp3, C);
    if(DEBUG){
        for(int i = 0; i < dp2.size(); i++){
            cout << "Considering first " << i << " items\n";
            for(int j = 0; j < 20; j++){
                cout << dp2[i][j] << " ";
            }
            cout << '\n';
        }
    }
    function<bool(int)> check = [&](int k){
        int amt = 0;
        amt += (int)(lower_bound(dp1.back().begin(), dp1.back().end(), k) - dp1.back().begin());
        amt += (int)(lower_bound(dp2.back().begin(), dp2.back().end(), k) - dp2.back().begin());
        amt += (int)(lower_bound(dp3.back().begin(), dp3.back().end(), k) - dp3.back().begin());
        return amt <= x;
    };
    int lo = 0, hi = 1e9, ans = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << ans << '\n';
}