#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

void solve(){
    int n, k; cin >> n >> k;
    vector<int>vect(k + 1, 0);
    for(int i = 0; i < k; i++){
        int b, c; cin >> b >> c;
        vect[b] += c;
    }
    sort(vect.begin(), vect.end(), [](const int a, const int b){
        return a > b;
    });
    int ans = 0;
    for(int i = 0; i < min(n, k); i++){
        ans += vect[i];
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