#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void solve(){
    int k; cin >> k;
    unordered_map<int, int>mp;
    for(int i = 0; i < k; i++){
        int t; cin >> t;
        mp[t]++;
    }
    int n = k - 2;
    for(int i = 1; i <= (int)sqrt(n); i++){
        if(n % i != 0) continue;
        if(mp[i]){
            if(n / i == i && mp[i] == 2){
                cout << i << " " << i << '\n';
                break;
            }
            else if(mp[n / i]){
                cout << i << " " << n / i << '\n';
                break;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    while(q--){
        solve();
    }
}