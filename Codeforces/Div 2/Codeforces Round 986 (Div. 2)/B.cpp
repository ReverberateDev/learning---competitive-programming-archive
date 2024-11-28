#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

void solve(){
    int n, m, c; cin >> n >> m >> c;
    if(m == 0){
        if(c < n - 2){
            cout << "-1\n";
            return;
        }
        else if(c == n - 2 || c == n -1){
            cout << n - 1 << '\n';
            return;
        }
        else{
            cout << n << '\n';
            return;
        }
    }
    else{
        if(c >= n){
            cout << n << '\n';
            return;
        }
        else{
            cout << n - max(0ll,(1 + ((n - 1 - c) / m))) << '\n';
            return;
        }
    }
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