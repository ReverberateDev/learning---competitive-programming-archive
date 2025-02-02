#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> vect(n + 1);
    vector<pair<int, int>> dp(n + 2);
    for(int i = 1; i <= n; i++){
        vect[i] = (int)(s[i - 1] - '0');
    }
    pair<int, int> curr = {-1, -1};
    for(int i = n; i >= 1; i--){
        auto &[val, amt] = curr;
        if(val == vect[i]){
            amt++;
        }
        else{
            val = vect[i];
            amt = 1;
        }
        amt = min(amt, k);
        pair<int, int> res;
        if(amt == k){
            if(vect[i + k] != vect[i]){
                res = dp[i + k];
                res.first++;
            }
            else{
                res = {1, 0};
            }
        }
        else{
            res = {0, amt};
        }
        dp[i] = res;
    }
    if(DEBUG){
        cout << "Testing dp\n";
        for(int i = 1; i <= n; i++){
            cout << dp[i].first << " " << dp[i].second << '\n';
        }
    }
    curr = {0, 0};
    for(int p = 1; p < n; p++){
        if(DEBUG){
            cout << "Testing P = " << p << '\n';
        }
        if(curr < dp[1]){
            curr.second++;
            if(curr.second == k){
                curr.first++;
                curr.second = 0;
            }
        }
        auto [amt, left] = dp[p + 1];
        int tmp = p + k * amt + left;
        if(tmp != n){
            continue;
        }
        if(DEBUG){
            cout << "Passed test 1\n";
        }
        int lst;
        if(amt % 2 == 0){
            lst = vect[p + 1];
        }
        else{
            lst = vect[p + 1] ^ 1;
        }
        tmp = k * curr.first + curr.second;
        if(tmp != p){
            continue;
        }
        if(DEBUG){
            cout << "Passed test 2\n";
        }
        int nxt;
        if(curr.first % 2 == 0){
            if(curr.second == 0){
                nxt = vect[1] ^ 1;
            }
            else{
                nxt = vect[1];
            }
        }
        else{
            if(curr.second == 0){
                nxt = vect[1];
            }
            else{
                nxt = vect[1] ^ 1;
            }
        }
        if(DEBUG){
            cout << "lst " << lst << '\n';
            cout << "nxt " << nxt << '\n';
            cout << curr.first << " " << curr.second << '\n';
        }
        if(lst != nxt){
            continue;
        }
        if(DEBUG){
            cout << "Passed test 3\n";
        }
        cout << p << '\n';
        return;
    }
    if(k * dp[1].first + dp[1].second == n){
        cout << n << '\n';
        return;
    }
    cout << "-1\n";
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