#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int lst = -1, x = 0, y = 0;
    for(int i = 0; i < n; i += 2){
        if(s[i] != s[i + 1]){
            x++;
        }
        else{
            if(s[i] - '0' == lst){
                y++;
            }
            lst = s[i] - '0';
        }
    }
    cout << x << " " << max(y, 1ll) << "\n";
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