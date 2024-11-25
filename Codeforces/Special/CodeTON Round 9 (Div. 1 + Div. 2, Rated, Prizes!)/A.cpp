#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

#define DEBUG 1

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cout << i * 2 - 1 << " ";
    }
    cout << '\n';
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