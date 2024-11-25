#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

#define DEBUG 1

void solve(){
    int n; cin >> n;
    int a = -1, b;
    int best = 0, curr = 0;
    for(int i = 0; i < n; i++){
        cin >> b;
        if(a == b){
            curr++;
        }
        else{
            curr = 1;
        }
        a = b;
        best = max(best, curr);
    }
    cout << n - best << '\n';
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