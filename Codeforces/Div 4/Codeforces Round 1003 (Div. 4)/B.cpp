#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    string s; cin >> s;
    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == s[i + 1]){
            cout << "1\n";
            return;
        }
    }
    cout << s.length() << '\n';
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