#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 4;
    int ans = 0;
    unordered_map<int, int>mp;
    while(n--){
        int t; cin >> t;
        mp[t]++;
        if(mp[t] == 2){
            ans++;
            mp[t] -= 2;
        }
    }
    cout << ans;
}