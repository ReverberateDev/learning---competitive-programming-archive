#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

#define DEBUG 1

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int>vect(n);
    for(auto &i : vect){
        cin >> i;
    }
    vector<int>dp(n);
    vector<int>check(n, -1), table(n + 1, -1);
    for(int i = 0; i < n; i++){
        if(table[vect[i]] != -1){
            check[i] = table[vect[i]];
        }
        table[vect[i]] = i;
    }
    int ans = 0;
    dp[0] = 1;
    if(vect[0] == vect[1]){
        dp[1] = 0;
        ans = 2;
    }
    else{
        dp[1] = 2;
    }
    for(int i = 2; i < n; i++){
        if(vect[i - 1] != vect[i]){
            dp[i] = i + 1;
        }
        else if(check[i - 1] == -1 && dp[i - 2]){
            dp[i] = dp[i - 2];
        }
        else{
            dp[i] = max(check[i - 1] + 1, dp[i - 2]);
        }
        ans = max(ans, i - dp[i] + 1);
    }
    cout << ans;
}
