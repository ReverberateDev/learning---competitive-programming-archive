#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n; cin >> n;
    vector<int> vect(n);
    string tmp; cin >> tmp;
    for(int i = 0; i < n; i++){
        vect[i] = tmp[i] - '0';
    }
    int ans = 0, buffer = 0;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int goal = i + 1;
        if(i > 0){
            mp[i + buffer]++;
            buffer -= vect[i];
        }
        else{
            mp[vect[0]]++;
        }
        ans += mp[goal + buffer];
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