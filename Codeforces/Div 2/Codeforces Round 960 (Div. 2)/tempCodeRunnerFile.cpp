#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void mino(int& x, int y){
    x = min(x, y);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int b1 = 0; //first 2
    int b2 = 0; //last 2
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!b1 && !b2){
            if(a[i] == 0){
                continue;
            }
            else if(a[i] <= 2){
                ans++, b1 = 1;
            }
            else{
                ans++;
            }
        }
        else if(b1){
            if(a[i] <= 2){
                continue;
            }
            if(a[i] <= 3){
                ans++, b2 = 1;
            }
            else{
                ans++;
            }
            b1 = 0;
        }
        else{
            if(a[i] == 0){
                continue;
            }
            if(a[i] <= 4){
                ans++, b1 = 1;
            }
            else{
                ans++;
            }
            b2 = 0;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}