#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void solve(){
    int n; cin >> n;
    bool pass = true;
    int a, b; cin >> a;
    for(int i = 1; i < n; i++){
        cin >> b;
        if(abs(a - b) != 5 && abs(a - b) != 7){
            pass = false;
        }
        a = b;
    }
    if(pass){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
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