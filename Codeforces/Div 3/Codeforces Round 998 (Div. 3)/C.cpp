#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n, k; cin >> n >> k;
    map<int, int> mp;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
        if(2 * x == k){
            if(mp[x] >= 2){
                ans++;
                mp[x] -=  2;
            }
        }
        else if(mp[x] > 0 && mp[k - x] > 0){
            ans++;
            mp[x]--;
            mp[k - x]--;
        }
    }
    cout << ans << '\n';
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