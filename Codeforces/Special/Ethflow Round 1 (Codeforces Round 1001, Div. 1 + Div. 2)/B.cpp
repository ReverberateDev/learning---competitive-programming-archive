#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n; cin >> n;
    bool flag = false;
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        int dist = max(2 * (n - (i + 1)), 2 * i);
        if(v <= dist){
            flag = true;
        }
    }
    if(flag){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
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