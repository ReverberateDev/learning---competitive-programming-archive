#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    //Suppose we have constructed B, and bi != i occurs at idx, the later indexes dont rly matter
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == k){
        int ans = -1;
        for(int i = 2; i <= n; i += 2){
            if(a[i] != i / 2){
                ans = i / 2;
                break;
            }
        }
        if(ans == -1){
            ans = k / 2 + 1;
        }
        cout << ans << '\n';
    }
    else{
        int ans = 2;
        for(int i = 1; i < n; i++){
            int grp = n - i + 1;
            if(grp < k){
                break;
            }
            if(a[i + 1] != 1){
                ans = 1;
            }
        }
        cout << ans << '\n';
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