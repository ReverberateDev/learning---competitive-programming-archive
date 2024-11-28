#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

void solve(){
    int n, k; cin >> n >> k;
    if(n == 1){
        cout << "1\n1\n";
        return;
    }
    else if(k == 1 || k == n){
        cout << "-1\n";
        return;
    }
    else if(k % 2 == 0){
        cout << "3\n";
        cout << "1 " << k << " " << k + 1 << '\n';
    }
    else{
        cout << "3\n";
        cout << "1 " << k - 1 << " " << k + 2 << '\n';
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