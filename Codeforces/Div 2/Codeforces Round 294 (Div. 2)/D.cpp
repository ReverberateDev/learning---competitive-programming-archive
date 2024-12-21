#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int val[26];
    for(int i = 0; i < 26; i++){
        cin >> val[i];
    }
    string s; cin >> s;
    int sz = (int)s.length();
    int curr = 0, ans = 0;
    unordered_map<int, int> dp[26];
    for(int i = 0; i < sz; i++){
        int idx = s[i] - 'a';
        ans += dp[idx][curr];
        if(DEBUG){
            auto mp = dp[idx];
            cout << "Map for " << idx << '\n';
            for(auto [key, value] : mp){
                cout << key << " " << value << '\n';
            }
            cout << "Curr: " << curr << '\n';
        }
        curr += val[idx];
        dp[idx][curr]++;
    }
    cout << ans << '\n';
}