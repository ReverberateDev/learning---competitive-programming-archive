#include <bits/stdc++.h>
using namespace std;
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e9;

void solve(){
    int n; cin >> n;
    vector<int> arr(n), amt;
    map<int, int> mp;
    for(auto &i : arr){
        cin >> i;
        mp[i]++;
    }
    for(auto [_, b] : mp){
        amt.push_back(b);
    }
    vector<vector<int>> memo(amt.size() + 3, vector<int>(5001, -1));
    //dp[i][j] = maximum cakes that can be bought out when this is new
    function<int(int, int)> dp = [&](int idx, int debt){
        if(idx == -1){
            if(debt == 0){
                return 0;
            }
            else{
                return -inf;
            }
        }
        if(memo[idx][debt] != -1){
            return memo[idx][debt];
        }
        int res = -inf;
        //take
        res = max(res, dp(idx - 1, debt + amt[idx]) + 1);
        //don't take
        res = max(res, dp(idx - 1, max(0, debt - 1)));
        return memo[idx][debt] = res;
    };
    cout << amt.size() - dp(amt.size() - 1, 0) << '\n';
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