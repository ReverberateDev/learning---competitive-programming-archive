#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

#define DEBUG 1

string s = "1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2";

void solve(){
    int n; cin >> n;
    if(n % 2 == 0){
        for(int i = 0, curr = 1; i < n; i+=2, curr++){
            cout << curr << " " << curr << " ";
        }
        cout << '\n';
    }
    else{
        if(n >= 27){
            cout << s << " ";
            n -= 27;
            for(int i = 0, curr = 14; i < n; i+=2, curr++){
                cout << curr << " " << curr << " ";
            }
            cout << '\n';
        }
        else{
            cout << "-1\n";
            return;
        }
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