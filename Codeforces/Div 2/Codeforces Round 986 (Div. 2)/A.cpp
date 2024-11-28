#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

void solve(){
    int n, a, b; cin >> n >> a >> b;
    int x = 0, y = 0;
    string s; cin >> s;
    int temp = 100;
    if(x == a && y == b){
        cout << "YES\n";
        return;
    }
    while(temp--){
        for(int i = 0; i < n; i++){
            if(s[i] == 'N'){
                y++;
            }
            else if(s[i] == 'S'){
                y--;
            }
            else if(s[i] == 'E'){
                x++;
            }
            else{
                x--;
            }
            if(x == a && y == b){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
    return;
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