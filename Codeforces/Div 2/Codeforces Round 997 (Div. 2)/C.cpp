#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n; cin >> n;
    if(n == 6){
        cout << "1 1 2 3 1 2\n";
    }
    else{
        vector<int> ans(n);
        ans[0] = ans[1] = ans[n - 1] = 1;
        for(int i = 2, cnt = 2; i < n - 1; i++){
            ans[i] = cnt++;
        }
        for(auto i : ans){
            cout << i << " ";
        }
        cout << '\n';
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