#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n; cin >> n;
    int sum = 0, ans = 0, odds = 0, evens = 0;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        if(tmp % 2 == 0){
            evens++;
        }
        else{
            odds++;
        }
    }
    ans += (evens > 0);
    if(evens > 0){
        ans += odds;
    }
    else{
        odds--;
        ans += odds;
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